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
class NodeChildrenVisitor : public ExprVisitor<std::vector<std::shared_ptr<Expr>>> {
  std::vector<std::shared_ptr<Expr>> visit_binary_expr(std::shared_ptr<Binary> expr) override {
    return std::vector {expr->left, expr->right};
  }

  std::vector<std::shared_ptr<Expr>> visit_unary_expr(std::shared_ptr<Unary> expr) override {
    return std::vector {expr->expr};
  }

  std::vector<std::shared_ptr<Expr>> visit_grouping_expr(std::shared_ptr<Grouping> expr) override {
    return std::vector {expr->expr};
  }

  std::vector<std::shared_ptr<Expr>> visit_literal_expr(std::shared_ptr<Literal> expr) override {
    return {};
  }
};

// Returns the node's name as a string.
class NodeNameVisitor : public ExprVisitor<std::string> {
  std::string visit_binary_expr(std::shared_ptr<Binary> expr) override {
    switch (expr->op.type) {
      case TOKEN_STAR: return "binary *";
      case TOKEN_STAR_STAR: return "binary **";
      case TOKEN_MINUS: return "binary -";
      case TOKEN_PLUS: return "binary +";
      case TOKEN_DOT_DOT: return "binary ..";
      case TOKEN_DOT_DOT_LT: return "binary ..<";
      case TOKEN_QUEST_COLON: return "binary ?:";
      case TOKEN_GT: return "binary >";
      case TOKEN_GT_GT: return "binary >>";
      case TOKEN_GT_EQ: return "binary >=";
      case TOKEN_LT: return "binary <";
      case TOKEN_LT_LT: return "binary <<";
      case TOKEN_LT_EQ: return "binary <=";
      case TOKEN_SLASH: return "binary /";
      case TOKEN_PERCENT: return "binary %";
      case TOKEN_PIPE: return "binary |";
      case TOKEN_CARET: return "binary ^";
      case TOKEN_AMPERSAND: return "binary &";
      case TOKEN_BANG_EQ: return "binary !=";
      case TOKEN_EQ_EQ: return "binary ==";
      case TOKEN_AND: return "binary and";
      case TOKEN_IN: return "binary (not) in"; // expr.op is the last token, so in this case it's ambiguous. TODO: if the AST can't store that, then ...
      case TOKEN_IS: return "binary is";       // at least "is" and "is not" work.
      case TOKEN_NOT: return "binary is not";
      case TOKEN_OR: return "binary or";
      default: return "binary";
    }
  }

  std::string visit_unary_expr(std::shared_ptr<Unary> expr) override {
    switch (expr->op.type) {
      case TOKEN_MINUS: return "unary -";
      case TOKEN_BANG: return "unary !";
      case TOKEN_TILDE: return "unary ~";
      case TOKEN_MINUS_MINUS: return "prefix --";
      case TOKEN_PLUS_PLUS: return "prefix ++";
      case TOKEN_NOT: return "unary not";
      default: return "unary";
    }
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
