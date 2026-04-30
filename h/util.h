/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#pragma once

#include <sstream>
#include <vector>

#include "ast.h"

class Lexer;
class LexerError;
class ParserError;

/**
 * Prints an error, warning, or note, and all of its child contexts.
 * @param line Line number (1-based)
 * @param col Column number (1-based)
 * @param module Name of the module being compiled
 * @param line_str Line in the source code where the error occurs
 * @param message Error message
 * @param type 0 for error, 1 for warning, 2 for note
 */
void print_error(size_t line, size_t col, std::string_view module, std::string_view line_str, const char* message, int type);

/**
 * Wrapper around print_error(line, col, module, line_str, message, type).
 */
void print_error(const Lexer& lexer, const LexerError& err, std::string_view module, int type);

/**
 * Wrapper around print_error(line, col, module, line_str, message, type).
 */
void print_error(const Lexer& lexer, const ParserError& err, std::string_view module, int type);

class DotTreeWalker {
  int id_counter_ {};
  int current_parent_id_ {};
  std::ostringstream out_ {};

  class StmtChildrenVisitor : public StmtVisitorVoid {
    DotTreeWalker& owner_;

    public:
    explicit StmtChildrenVisitor(DotTreeWalker& owner) : owner_ {owner} {}

    void visit_block_stmt(std::shared_ptr<Statements::Block> stmt) override {
      for (const auto& inner_stmt : stmt->statements)
        owner_.walk(inner_stmt, owner_.current_parent_id_);
    }

    void visit_expression_stmt(std::shared_ptr<Statements::Expression> stmt) override {
      owner_.walk(stmt->expression, owner_.current_parent_id_);
    }

    void visit_variable_stmt(std::shared_ptr<Statements::Variable> stmt) override {
      owner_.walk(stmt->type, owner_.current_parent_id_);
      owner_.walk(stmt->initializer, owner_.current_parent_id_);
    }

    void visit_function_stmt(std::shared_ptr<Statements::Function> stmt) override {
      const int parent_id {owner_.current_parent_id_};
      for (const auto& [_, type] : stmt->params)
        owner_.walk(type, parent_id);
      if (stmt->return_type)
        owner_.walk(stmt->return_type, parent_id);
      owner_.walk(stmt->body, parent_id);
    }

    void visit_namespace_stmt(std::shared_ptr<Statements::Namespace> stmt) override {
      for (const auto& decl : stmt->declarations)
        owner_.walk(decl, owner_.current_parent_id_);
    }

    void visit_if_stmt(std::shared_ptr<Statements::If> stmt) override {
      const int parent_id {owner_.current_parent_id_};
      owner_.walk(stmt->condition, parent_id);
      owner_.walk(stmt->then_body, parent_id);
      if (!std::dynamic_pointer_cast<Statements::Pass>(stmt->else_body))
        owner_.walk(stmt->else_body, parent_id);
    }

    void visit_while_stmt(std::shared_ptr<Statements::While> stmt) override {
      const int parent_id {owner_.current_parent_id_};
      owner_.walk(stmt->condition, parent_id);
      owner_.walk(stmt->loop_body, parent_id);
      if (!std::dynamic_pointer_cast<Statements::Pass>(stmt->else_body))
        owner_.walk(stmt->else_body, parent_id);
    }

    void visit_each_stmt(std::shared_ptr<Statements::Each> stmt) override {
      const int parent_id {owner_.current_parent_id_};
      owner_.walk(stmt->iterator, parent_id);
      owner_.walk(stmt->loop_body, parent_id);
      if (!std::dynamic_pointer_cast<Statements::Pass>(stmt->else_body))
        owner_.walk(stmt->else_body, parent_id);
    }

    void visit_for_stmt(std::shared_ptr<Statements::For> stmt) override {
      const int parent_id {owner_.current_parent_id_};
      owner_.walk(stmt->begin, parent_id);
      owner_.walk(stmt->condition, parent_id);
      owner_.walk(stmt->end, parent_id);
      owner_.walk(stmt->loop_body, parent_id);
      if (!std::dynamic_pointer_cast<Statements::Pass>(stmt->else_body))
        owner_.walk(stmt->else_body, parent_id);
    }

    void visit_break_stmt(std::shared_ptr<Statements::Break> stmt) override {}
    void visit_continue_stmt(std::shared_ptr<Statements::Continue> stmt) override {}

    void visit_return_stmt(std::shared_ptr<Statements::Return> stmt) override {
      owner_.walk(stmt->value, owner_.current_parent_id_);
    }

    void visit_pass_stmt(std::shared_ptr<Statements::Pass> stmt) override {}
  };

  class ExprChildrenVisitor : public ExprVisitorVoid {
    DotTreeWalker& owner_;

    public:
    explicit ExprChildrenVisitor(DotTreeWalker& owner) : owner_ {owner} {}

    void visit_binary_expr(std::shared_ptr<Expressions::Binary> expr) override {
      const int parent_id {owner_.current_parent_id_};
      owner_.walk(expr->left, parent_id);
      owner_.walk(expr->right, parent_id);
    }

    void visit_comparison_expr(std::shared_ptr<Expressions::Comparison> expr) override {
      const int parent_id {owner_.current_parent_id_};
      for (const auto& operand : expr->expressions) {
        owner_.walk(operand, parent_id);
      }
    }

    void visit_if_expr(std::shared_ptr<Expressions::If> expr) override {
      const int parent_id {owner_.current_parent_id_};
      owner_.walk(expr->then, parent_id);
      owner_.walk(expr->condition, parent_id);
      owner_.walk(expr->else_expr, parent_id);
    }

    void visit_call_expr(std::shared_ptr<Expressions::Call> expr) override {
      const int parent_id {owner_.current_parent_id_};
      owner_.walk(expr->object, parent_id);
      for (const auto& arg : expr->arguments)
        owner_.walk(arg, parent_id);
    }

    void visit_subscript_expr(std::shared_ptr<Expressions::Subscript> expr) override {
      const int parent_id {owner_.current_parent_id_};
      owner_.walk(expr->object, parent_id);
      for (const auto& arg : expr->arguments)
        owner_.walk(arg, parent_id);
    }

    void visit_member_expr(std::shared_ptr<Expressions::Member> expr) override {
      owner_.walk(expr->object, owner_.current_parent_id_);
    }

    void visit_namespace_member_expr(std::shared_ptr<Expressions::NamespaceMember> expr) override {}

    void visit_unary_expr(std::shared_ptr<Expressions::Unary> expr) override {
      owner_.walk(expr->expr, owner_.current_parent_id_);
    }

    void visit_interpolation_expr(std::shared_ptr<Expressions::Interpolation> expr) override {
      const int parent_id {owner_.current_parent_id_};
      for (const auto& sub_expr : expr->expressions)
        owner_.walk(sub_expr, parent_id);
    }

    void visit_lambda_expr(std::shared_ptr<Expressions::Lambda> expr) override {
      const int parent_id {owner_.current_parent_id_};
      for (const auto& [_, type] : expr->params)
        owner_.walk(type, parent_id);
      owner_.walk(expr->body, parent_id);
    }

    void visit_grouping_expr(std::shared_ptr<Expressions::Grouping> expr) override {
      owner_.walk(expr->expr, owner_.current_parent_id_);
    }

    void visit_list_expr(std::shared_ptr<Expressions::List> expr) override {
      const int parent_id {owner_.current_parent_id_};
      for (const auto& item : expr->items)
        owner_.walk(item, parent_id);
    }

    void visit_map_expr(std::shared_ptr<Expressions::Map> expr) override {
      const int parent_id {owner_.current_parent_id_};
      for (const auto& item : expr->values)
        owner_.walk(item, parent_id);
    }

    void visit_number_expr(std::shared_ptr<Expressions::Number> expr) override {}
    void visit_boolean_expr(std::shared_ptr<Expressions::Boolean> expr) override {}
    void visit_nil_expr(std::shared_ptr<Expressions::Nil> expr) override {}
    void visit_char_expr(std::shared_ptr<Expressions::Char> expr) override {}
    void visit_string_expr(std::shared_ptr<Expressions::String> expr) override {}
    void visit_variable_expr(std::shared_ptr<Expressions::Variable> expr) override {}
    void visit_this_expr(std::shared_ptr<Expressions::This> expr) override {}
    void visit_super_expr(std::shared_ptr<Expressions::Super> expr) override {}

    void visit_print_expr(std::shared_ptr<Expressions::Print> expr) override {
      owner_.walk(expr->expr, owner_.current_parent_id_);
    }
  };

  class StmtNameVisitor : public StmtVisitor<std::string> {
    [[maybe_unused]] DotTreeWalker& owner_;

    public:
    explicit StmtNameVisitor(DotTreeWalker& owner) : owner_ {owner} {}

    std::string visit_block_stmt(std::shared_ptr<Statements::Block> stmt) override { return "BLOCK"; }
    std::string visit_expression_stmt(std::shared_ptr<Statements::Expression> stmt) override { return "EXPRESSION"; }

    std::string visit_variable_stmt(std::shared_ptr<Statements::Variable> stmt) override {
      std::string blah {stmt->is_mutable ? "var " : "val "};
      blah += stmt->identifier->src_string;
      blah += ": ... = ...";
      return blah;
    }

    std::string visit_function_stmt(std::shared_ptr<Statements::Function> stmt) override {
      std::string blah {"function "};
      blah += stmt->identifier->src_string;
      // Generic.
      if (!stmt->type_params.empty()) {
        blah += " for ";
        for (const auto& param : stmt->type_params) {
          blah += param->src_string;
          blah += " ";
        }
      }
      // Params.
      blah += "(";
      for (size_t i {0}; i < stmt->params.size(); ++i) {
        if (i > 0) blah += ", ";
        blah += stmt->params[i].identifier->src_string;
      }
      blah += ")";
      // Return type.
      if (stmt->return_type)
        blah += " -> ...";

      return blah;
    }

    std::string visit_namespace_stmt(std::shared_ptr<Statements::Namespace> stmt) override { return "namespace " + std::string {stmt->identifier->src_string}; }

    std::string visit_if_stmt(std::shared_ptr<Statements::If> stmt) override {
      if (std::dynamic_pointer_cast<Statements::Pass>(stmt->else_body))
        return "if ... do ...";
      return "if ... do ... else ...";
    }

    std::string visit_while_stmt(std::shared_ptr<Statements::While> stmt) override {
      std::string blah {"while"};
      if (stmt->label) {
        blah += ":";
        blah += stmt->label->src_string;
      }
      blah += " ... do ...";
      if (!std::dynamic_pointer_cast<Statements::Pass>(stmt->else_body))
        blah += " else ...";
      return blah;
    }

    std::string visit_each_stmt(std::shared_ptr<Statements::Each> stmt) override {
      std::string blah {"each"};
      if (stmt->label) {
        blah += ":";
        blah += stmt->label->src_string;
      }
      blah += " ";
      blah += stmt->iter_var->src_string;
      if (stmt->index_var) {
        blah += "[";
        blah += stmt->index_var->src_string;
        blah += "]";
      }
      blah += " in ... do ...";
      if (!std::dynamic_pointer_cast<Statements::Pass>(stmt->else_body))
        blah += " else ...";
      return blah;
    }

    std::string visit_for_stmt(std::shared_ptr<Statements::For> stmt) override {
      std::string blah {"for"};
      if (stmt->label) {
        blah += ":";
        blah += stmt->label->src_string;
      }
      blah += " ...; ...; ... do ...";
      if (!std::dynamic_pointer_cast<Statements::Pass>(stmt->else_body))
        blah += " else ...";
      return blah;
    }

    std::string visit_break_stmt(std::shared_ptr<Statements::Break> stmt) override {
      std::string blah {"break"};
      if (stmt->label) {
        blah += ":";
        blah += stmt->label->src_string;
      }
      return blah;
    }

    std::string visit_continue_stmt(std::shared_ptr<Statements::Continue> stmt) override {
      std::string blah {"continue"};
      if (stmt->label) {
        blah += ":";
        blah += stmt->label->src_string;
      }
      return blah;
    }

    std::string visit_return_stmt(std::shared_ptr<Statements::Return> stmt) override { return "return ..."; }
    std::string visit_pass_stmt(std::shared_ptr<Statements::Pass> stmt) override { return "pass"; }
  };

  class ExprNameVisitor : public ExprVisitor<std::string> {
    [[maybe_unused]] DotTreeWalker& owner_;

    public:
    explicit ExprNameVisitor(DotTreeWalker& owner) : owner_ {owner} {}

    std::string visit_binary_expr(std::shared_ptr<Expressions::Binary> expr) override { return "binary " + std::string {expr->fn_name}; }

    std::string visit_comparison_expr(std::shared_ptr<Expressions::Comparison> expr) override {
      std::string blah {"..."};
      for (const auto& comparison : expr->fn_names) {
        blah += " ";
        blah += static_cast<std::string>(comparison);
        blah += " ...";
      }
      return blah;
    }

    std::string visit_if_expr(std::shared_ptr<Expressions::If> expr) override { return "... if ... else ..."; }

    std::string visit_call_expr(std::shared_ptr<Expressions::Call> expr) override { return "...(...*)"; }

    std::string visit_subscript_expr(std::shared_ptr<Expressions::Subscript> expr) override { return "...[...*]"; }

    std::string visit_member_expr(std::shared_ptr<Expressions::Member> expr) override {
      const std::string blah {"(...)"};
      return blah + (expr->is_safe ? "?." : ".") + std::string {expr->member->src_string};
    }

    std::string visit_namespace_member_expr(std::shared_ptr<Expressions::NamespaceMember> expr) override {
      return std::string {expr->namespace_id->src_string} + "::" + std::string {expr->member->src_string};
    }

    std::string visit_unary_expr(std::shared_ptr<Expressions::Unary> expr) override { return "unary " + std::string {expr->fn_name}; }

    std::string visit_interpolation_expr(std::shared_ptr<Expressions::Interpolation> expr) override {
      std::string blah {"\\\"" + expr->start};
      for (const auto& interpolation : expr->end_strings) {
        blah += "=(...)";
        blah += interpolation;
      }
      return blah + "\\\"";
    }

    std::string visit_lambda_expr(std::shared_ptr<Expressions::Lambda> expr) override {
      std::string blah {"lambda ("};
      if (!expr->params.empty()) {
        for (size_t i {0}; i < expr->params.size(); ++i) {
          if (i > 0) blah += ", ";
          blah += expr->params[i].identifier->src_string;
        }
      }
      blah += ") -> ...";
      return blah;
    }

    std::string visit_grouping_expr(std::shared_ptr<Expressions::Grouping> expr) override { return "()"; }

    std::string visit_list_expr(std::shared_ptr<Expressions::List> expr) override { return "[]"; }

    std::string visit_map_expr(std::shared_ptr<Expressions::Map> expr) override {
      std::string blah {"["};
      for (size_t i {0}; i < expr->keys.size(); ++i) {
        blah += expr->keys[i] + " -> ...";
        if (i + 1 < expr->keys.size())
          blah += ", ";
      }
      return blah + "]";
    }

    std::string visit_number_expr(std::shared_ptr<Expressions::Number> expr) override { return std::to_string(expr->value); }
    std::string visit_boolean_expr(std::shared_ptr<Expressions::Boolean> expr) override { return expr->value ? "true" : "false"; }
    std::string visit_nil_expr(std::shared_ptr<Expressions::Nil> expr) override { return "nil"; }
    std::string visit_char_expr(std::shared_ptr<Expressions::Char> expr) override { return std::string {expr->value}; }
    std::string visit_string_expr(std::shared_ptr<Expressions::String> expr) override { return "\\\"" + expr->value + "\\\""; }

    std::string visit_variable_expr(std::shared_ptr<Expressions::Variable> expr) override { return std::string {expr->identifier->src_string}; }

    std::string visit_this_expr(std::shared_ptr<Expressions::This> expr) override { return "this"; }
    std::string visit_super_expr(std::shared_ptr<Expressions::Super> expr) override { return "super"; }

    std::string visit_print_expr(std::shared_ptr<Expressions::Print> expr) override { return std::string {expr->fn_name}; }
  };

  StmtChildrenVisitor stmt_children_visitor_ {*this};
  ExprChildrenVisitor expr_children_visitor_ {*this};
  StmtNameVisitor stmt_name_visitor_ {*this};
  ExprNameVisitor expr_name_visitor_ {*this};

  void walk(const ExprNode& node, int parent_id);
  void walk(const StmtNode& node, int parent_id);
  void walk(const TypePtr& type, int parent_id);

  public:
  std::string render(const std::vector<StmtNode>& tree);
};

/**
 * Exports a  parse tree to GraphViz DOT format.
 * @param tree Parse tree to export
 * @return A string containing the DOT representation of the tree
 */
std::string to_dot(const std::vector<StmtNode>& tree);
