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

void print_error(const Lexer& lexer, const LexerError& err, const std::string_view module, int type) {
  const auto [line, col] {lexer.offset_to_line_col(err.offset)};
  print_error(line, col, module, lexer.offset_to_line_string(err.offset), err.what(), type);
  if (err.context) print_error(lexer, *err.context, module, 2);
}

void print_error(const Lexer& lexer, const ParserError& err, const std::string_view module, int type) {
  const auto [line, col] {lexer.offset_to_line_col(err.token->start_offset)};
  print_error(line, col, module, lexer.offset_to_line_string(err.token->start_offset), err.what(), type);
  if (err.context) print_error(lexer, *err.context, module, 2);
}

// Returns a vector of a node's children.
class NodeChildrenVisitor : public ExprVisitor<std::vector<Expression>> {
  std::vector<Expression> visit_binary_expr(std::shared_ptr<Binary> binary) override {
    return {binary->left, binary->right};
  }

  std::vector<Expression> visit_unary_expr(std::shared_ptr<Unary> unary) override {
    return {unary->expr};
  }

  std::vector<Expression> visit_grouping_expr(std::shared_ptr<Grouping> group) override {
    return {group->expr};
  }

  std::vector<Expression> visit_literal_expr(std::shared_ptr<Literal> literal) override {
    return {};
  }

  std::vector<Expression> visit_print_expr(std::shared_ptr<Print> print) override {
    return {print->expr};
  }
};

// Returns the node's name as a string.
class NodeNameVisitor : public ExprVisitor<std::string> {
  std::string visit_binary_expr(std::shared_ptr<Binary> expr) override {
    const std::string blah {"binary "};
    const std::string bluh {expr->fn_name};
    return blah + bluh;
  }

  std::string visit_unary_expr(std::shared_ptr<Unary> expr) override {
    const std::string blah {"unary "};
    const std::string bluh {expr->fn_name};
    return blah + bluh;
  }

  std::string visit_grouping_expr(std::shared_ptr<Grouping> expr) override {
    return "( )";
  }

  std::string visit_literal_expr(std::shared_ptr<Literal> expr) override {
    if (expr->value.type() == typeid(double)) {
      return std::to_string(std::any_cast<double>(expr->value));
    }
    if (expr->value.type() == typeid(char)) {
      return std::to_string(std::any_cast<char>(expr->value));
    }
    if (expr->value.type() == typeid(std::string)) {
      return std::any_cast<std::string>(expr->value);
    }
    if (expr->value.type() == typeid(bool)) {
      if (std::any_cast<bool>(expr->value))
        return "true";
      return "false";
    }
    if (expr->value.type() == typeid(nullptr)) {
      return "nil";
    }
    return "unknown literal";
  }

  std::string visit_print_expr(std::shared_ptr<Print> print) override {
    return "print";
  }
};

static void walk(
  const std::shared_ptr<Expr>& node, std::ostringstream& out, int& id_counter, int parent_id, NodeNameVisitor& name_visitor,
  NodeChildrenVisitor& children_visitor
) {
  const int my_id = id_counter++;
  const std::string label {node->accept(name_visitor)};

  out << "  n" << my_id << " [label=\"" << label << "\", shape=box, color=cornflowerblue, fontcolor=blue];\n";

  if (parent_id != -1)
    out << "  n" << parent_id << " -> n" << my_id << ";\n";

  for (const auto& child : node->accept(children_visitor))
    walk(child, out, id_counter, my_id, name_visitor, children_visitor);
}

std::string to_dot(const std::shared_ptr<Expr>& tree) {
  NodeNameVisitor name_visitor {};
  NodeChildrenVisitor children_visitor {};
  std::ostringstream out;
  out << "digraph Expr {\n";
  out << "  rankdir=TB;\n";
  out << "  node [fontname=\"Iosevka Term SS09\"];\n";
  int id_counter {};
  walk(tree, out, id_counter, -1, name_visitor, children_visitor);
  out << "}\n";
  return out.str();
}
