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

// Forward declaration so visit_block_stmt can walk().
static void walk(const std::vector<StmtNode>& vec, int parent_id);
// These variables are static for the same reason.
static int id_counter {};
static std::ostringstream out {};

// Returns a vector of a node's EXPRESSION children.
class StmtChildrenVisitor : public StmtVisitor<std::vector<ExprNode>> {
public:
  std::vector<ExprNode> visit_block_stmt(std::shared_ptr<Statements::Block> stmt) override {
    walk(stmt->statements, id_counter - 1);
    return {};
  }

  std::vector<ExprNode> visit_expression_stmt(std::shared_ptr<Statements::Expression> stmt) override { return {stmt->expression}; }

  std::vector<ExprNode> visit_if_stmt(std::shared_ptr<Statements::If> stmt) override {
    walk(std::vector {stmt->then_body, stmt->else_body}, id_counter - 1);
    return {stmt->condition};
  }

  std::vector<ExprNode> visit_while_stmt(std::shared_ptr<Statements::While> stmt) override {
    walk(std::vector {stmt->loop_body, stmt->else_body}, id_counter - 1);
    return {stmt->condition};
  }

  std::vector<ExprNode> visit_each_stmt(std::shared_ptr<Statements::Each> stmt) override {
    walk(std::vector {stmt->loop_body, stmt->else_body}, id_counter - 1);
    return {stmt->iterator};
  }

  std::vector<ExprNode> visit_for_stmt(std::shared_ptr<Statements::For> stmt) override {
    walk(std::vector {stmt->begin, stmt->loop_body, stmt->else_body}, id_counter - 1);
    return {stmt->condition, stmt->end};
  }

  std::vector<ExprNode> visit_break_stmt(std::shared_ptr<Statements::Break> stmt) override { return {}; }
  std::vector<ExprNode> visit_continue_stmt(std::shared_ptr<Statements::Continue> stmt) override { return {}; }
  std::vector<ExprNode> visit_return_stmt(std::shared_ptr<Statements::Return> stmt) override { return {}; }
  std::vector<ExprNode> visit_pass_stmt(std::shared_ptr<Statements::Pass> stmt) override { return {}; }
};

class ExprChildrenVisitor : public ExprVisitor<std::vector<ExprNode>> {
public:
  std::vector<ExprNode> visit_binary_expr(std::shared_ptr<Expressions::Binary> expr) override { return {expr->left, expr->right}; }

  std::vector<ExprNode> visit_comparison_expr(std::shared_ptr<Expressions::Comparison> expr) override { return expr->expressions; }

  std::vector<ExprNode> visit_unary_expr(std::shared_ptr<Expressions::Unary> expr) override { return {expr->expr}; }

  std::vector<ExprNode> visit_grouping_expr(std::shared_ptr<Expressions::Grouping> expr) override { return {expr->expr}; }

  std::vector<ExprNode> visit_number_expr(std::shared_ptr<Expressions::Number> expr) override { return {}; }
  std::vector<ExprNode> visit_boolean_expr(std::shared_ptr<Expressions::Boolean> expr) override { return {}; }
  std::vector<ExprNode> visit_nil_expr(std::shared_ptr<Expressions::Nil> expr) override { return {}; }
  std::vector<ExprNode> visit_char_expr(std::shared_ptr<Expressions::Char> expr) override { return {}; }
  std::vector<ExprNode> visit_string_expr(std::shared_ptr<Expressions::String> expr) override { return {}; }

  std::vector<std::shared_ptr<Expr>> visit_variable_expr(std::shared_ptr<Expressions::Variable> expr) override { return {}; }

  std::vector<ExprNode> visit_print_expr(std::shared_ptr<Expressions::Print> expr) override {
    return {expr->expr};
  }
};

// Returns the node's name as a string.
class StmtNameVisitor : public StmtVisitor<std::string> {
public:
  std::string visit_block_stmt(std::shared_ptr<Statements::Block> stmt) override { return "block"; }
  std::string visit_expression_stmt(std::shared_ptr<Statements::Expression> stmt) override { return "expression"; }

  std::string visit_if_stmt(std::shared_ptr<Statements::If> stmt) override {
    if (std::dynamic_pointer_cast<Statements::Pass>(stmt->else_body))
      return "if";
    return "if else";
  }

  std::string visit_while_stmt(std::shared_ptr<Statements::While> stmt) override {
    if (std::dynamic_pointer_cast<Statements::Pass>(stmt->else_body))
      return "while";
    return "while else";
  }

  // TODO: Include labels and other nice things (needs Lexer data...)
  std::string visit_each_stmt(std::shared_ptr<Statements::Each> stmt) override { return "each"; }
  std::string visit_for_stmt(std::shared_ptr<Statements::For> stmt) override { return "for"; }
  std::string visit_break_stmt(std::shared_ptr<Statements::Break> stmt) override { return "break"; }
  std::string visit_continue_stmt(std::shared_ptr<Statements::Continue> stmt) override { return "continue"; }
  std::string visit_return_stmt(std::shared_ptr<Statements::Return> stmt) override { return "return"; }
  std::string visit_pass_stmt(std::shared_ptr<Statements::Pass> stmt) override { return "pass"; }
};

class ExprNameVisitor : public ExprVisitor<std::string> {
public:
  std::string visit_binary_expr(std::shared_ptr<Expressions::Binary> expr) override {
    const std::string blah {expr->fn_name};
    return "binary " + blah;
  }

  std::string visit_comparison_expr(std::shared_ptr<Expressions::Comparison> expr) override {
    std::string blah {"..."};
    for (const auto& comparison : expr->fn_names) {
      blah += " ";
      blah += static_cast<std::string>(comparison);
      blah += " ...";
    }
    return blah;
  }

  std::string visit_unary_expr(std::shared_ptr<Expressions::Unary> expr) override {
    const std::string blah {expr->fn_name};
    return "unary " + blah;
  }

  std::string visit_grouping_expr(std::shared_ptr<Expressions::Grouping> expr) override { return "( )"; }

  std::string visit_number_expr(std::shared_ptr<Expressions::Number> expr) override { return std::to_string(expr->value); }
  std::string visit_boolean_expr(std::shared_ptr<Expressions::Boolean> expr) override { return expr->value ? "true" : "false"; }
  std::string visit_nil_expr(std::shared_ptr<Expressions::Nil> expr) override { return "nil"; }
  std::string visit_char_expr(std::shared_ptr<Expressions::Char> expr) override { return std::string {expr->value}; }
  std::string visit_string_expr(std::shared_ptr<Expressions::String> expr) override { return expr->value; }

  std::string visit_variable_expr(std::shared_ptr<Expressions::Variable> expr) override { return "variable"; }

  std::string visit_print_expr(std::shared_ptr<Expressions::Print> expr) override { return std::string {expr->fn_name}; }
};

static StmtNameVisitor snv {};
static StmtChildrenVisitor scv {};
static ExprNameVisitor env {};
static ExprChildrenVisitor ecv {};

static void walk(const ExprNode& node, int parent_id) {
  const int my_id = id_counter++;
  const std::string label {node->accept(env)};

  out << "  n" << my_id << " [label=\"" << label << "\", shape=box, color=cornflowerblue, fontcolor=blue];\n";
  out << "  n" << parent_id << " -> n" << my_id << ";\n";

  for (const auto& child : node->accept(ecv))
    walk(child, my_id);
}

static void walk(const std::vector<StmtNode>& vec, int parent_id) {
  for (const auto& stmt : vec) {
    const int my_id = id_counter++;
    const std::string label {stmt->accept(snv)};

    out << "  n" << my_id << " [label=\"" << label << "\", shape=box, color=red, fontcolor=maroon];\n";
    out << "  n" << parent_id << " -> n" << my_id << ";\n";

    for (const auto& child : stmt->accept(scv))
      walk(child, my_id);
  }
}

std::string to_dot(const std::vector<StmtNode>& tree) {
  out.clear(); // Make sure to reset the static vars.
  out << "digraph Program {\n";
  out << "  rankdir=TB;\n";
  out << "  node [fontname=\"Iosevka Term SS09\"];\n";
  out << "  n0 [label=\"program\", shape=box, color=purple, fontcolor=black];\n";
  id_counter = 1; // Another static var.
  walk(tree, 0);
  out << "}\n";
  return out.str();
}
