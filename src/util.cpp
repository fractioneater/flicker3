/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "util.h"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

#include "common.h"

void formatting(int type) {
  if (type == 0) { // Error.
    #if PRINT_COLORS
    std::cout << ERROR_COLOR << BOLD;
    #else
    std::cout << "Error: ";
    #endif
  } else if (type == 1) { // Warning.
    #if PRINT_COLORS
    std::cout << WARNING_COLOR << BOLD;
    #else
    std::cout << "Warning: ";
    #endif
  } else { // Note.
    #if PRINT_COLORS
    std::cout << NOTE_COLOR << BOLD;
    #endif
    std::cout << "  Note: ";
  }
}

void print_error(size_t line, size_t col, const std::string_view module, const std::string_view line_str, const char* message, int type) {
  // moduleName@39:14 Block comment is missing closing '-#'
  //    39 │ print 0xABCD #- unclosed!
  //                      ^
  formatting(type);
  std::cout << module << "@" << line << ":" << col << CLEAR_FORMAT << ' ' << message << '\n';
  std::cout << std::setw(5) << line << " │ " << line_str << '\n';
  #if PRINT_COLORS
  std::cout << "        " << std::string(col - 1, ' ') << POINTER_COLOR << BOLD << '^' << CLEAR_FORMAT << '\n';
  #else
  std::cout << "        " << std::string(col - 1, ' ') << "^\n";
  #endif
}

void print_positionless_error(const char* message, int type) {
  formatting(type);
  std::cout << CLEAR_FORMAT << message << '\n';
}

void print_error(const Lexer& lexer, const LexerError& err, const std::string_view module, int type) {
  const auto [line, col] {lexer.offset_to_line_col(err.offset)};
  print_error(line, col, module, lexer.offset_to_line_string(err.offset), err.what(), type);
  if (err.context) print_error(lexer, *err.context, module, 2);
}

void print_error(const Lexer& lexer, const ParserError& err, const std::string_view module, int type) {
  if (err.token) {
    const auto [line, col] {lexer.offset_to_line_col(err.token->start_offset)};
    print_error(line, col, module, lexer.offset_to_line_string(err.token->start_offset), err.what(), type);
  } else
    print_positionless_error(err.what(), type);

  if (err.context) print_error(lexer, *err.context, module, 2);
}

void DotTreeWalker::walk(const ExprNode& node, int parent_id) {
  const int my_id = id_counter_++;
  const std::string label {node->accept(expr_name_visitor_)};

  out_ << "  n" << my_id << " [label=\"" << label << "\", shape=box, color=royalblue, fontcolor=royalblue4];\n";
  out_ << "  n" << parent_id << " -> n" << my_id << ";\n";

  const int previous_parent {current_parent_id_};
  current_parent_id_ = my_id;
  node->accept(expr_children_visitor_);
  current_parent_id_ = previous_parent;
}

void DotTreeWalker::walk(const std::vector<StmtNode>& vec, int parent_id) {
  for (const auto& node : vec) {
    const int my_id = id_counter_++;
    const std::string label {node->accept(stmt_name_visitor_)};

    out_ << "  n" << my_id << " [label=\"" << label << "\", shape=box, color=indianred, fontcolor=maroon];\n";
    out_ << "  n" << parent_id << " -> n" << my_id << ";\n";

    const int previous_parent {current_parent_id_};
    current_parent_id_ = my_id;
    node->accept(stmt_children_visitor_);
    current_parent_id_ = previous_parent;
  }
}

// Types aren't AST nodes, but they behave similarly. Instead of using a visitor pattern, they're just handled with a switch.
void DotTreeWalker::walk(const TypePtr& type, int parent_id) {
  const int my_id = id_counter_++;

  if (!type) {
    out_ << "  n" << my_id << " [label=\"inferred\", shape=box, color=plum4, fontcolor=rebeccapurple];\n";
    out_ << "  n" << parent_id << " -> n" << my_id << ";\n";
    return;
  }

  std::string label {};
  switch (type->kind()) {
    case TypeKind::NAMED: {
      const auto named = std::dynamic_pointer_cast<NamedType>(type);
      label            = named && !named->name().empty() ? named->name() : "named";
      break;
    }
    case TypeKind::APPLIED: label = "applied";
      break;
    case TypeKind::OPTIONAL: label = "optional";
      break;
    case TypeKind::FUNCTION: label = "function (...+) -> ...";
      break;
    case TypeKind::TYPE_VAR: {
      const auto type_var = std::dynamic_pointer_cast<TypeVar>(type);
      label               = type_var ? type_var->name() : "type_var";
      break;
    }
    case TypeKind::OVERLOAD_SET: label = "overload set";
      break;
  }

  out_ << "  n" << my_id << " [label=\"" << label << "\", shape=box, color=plum4, fontcolor=rebeccapurple];\n";
  out_ << "  n" << parent_id << " -> n" << my_id << ";\n";

  if (const auto applied = std::dynamic_pointer_cast<AppliedType>(type)) {
    walk(applied->constructor(), my_id);
    for (const auto& arg : applied->args()) walk(arg, my_id);
  } else if (const auto optional = std::dynamic_pointer_cast<OptionalType>(type)) {
    walk(optional->inner(), my_id);
  } else if (const auto fn = std::dynamic_pointer_cast<FunctionType>(type)) {
    for (const auto& param : fn->params()) walk(param, my_id);
    walk(fn->result(), my_id);
  } else if (const auto overload_set = std::dynamic_pointer_cast<OverloadSetType>(type)) {
    for (const auto& signature : overload_set->functions()) walk(signature, my_id);
  }
}

std::string DotTreeWalker::render(const std::vector<StmtNode>& tree) {
  out_.str("");
  out_.clear();
  out_ << "digraph Program {\n";
  out_ << "  rankdir=TB;\n";
  out_ << "  node [fontname=\"Iosevka Term SS09\"];\n";
  out_ << "  n0 [label=\"PROGRAM\", shape=box, color=darkorange2, fontcolor=black];\n";
  id_counter_        = 1;
  current_parent_id_ = 0;
  walk(tree, 0);
  out_ << "}\n";
  return out_.str();
}

std::string to_dot(const std::vector<StmtNode>& tree) {
  DotTreeWalker walker {};
  return walker.render(tree);
}
