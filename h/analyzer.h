/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#pragma once

#include <vector>

#include "ast.h"

struct LoopFrame {
  bool labeled;
  std::string_view label;

  explicit LoopFrame(const Token* token) : labeled {token != nullptr}, label {token ? token->src_string : ""} {}
};

class Analyzer : public StmtVisitorVoid, public ExprVisitorVoid {
  // AST from the parser.
  const std::vector<StmtNode>& program_ {};
  // Errors/warnings/notes.
  std::vector<Diagnostic> diagnostics_ {};

  // CONTEXT --------------------------------------------------
  std::vector<LoopFrame> loops_ {};

  void visit_block_stmt(const Statements::Block& stmt) override;
  void visit_expression_stmt(const Statements::Expression& stmt) override;
  void visit_variable_stmt(const Statements::Variable& stmt) override;
  void visit_function_stmt(const Statements::Function& stmt) override;
  void visit_initializer_stmt(const Statements::Initializer& stmt) override;
  void visit_method_stmt(const Statements::Method& stmt) override;
  void visit_class_stmt(const Statements::Class& stmt) override;
  void visit_namespace_stmt(const Statements::Namespace& stmt) override;
  void visit_import_stmt(const Statements::Import& stmt) override;
  void visit_typealias_stmt(const Statements::Typealias& stmt) override;
  void visit_if_stmt(const Statements::If& stmt) override;
  void visit_while_stmt(const Statements::While& stmt) override;
  void visit_each_stmt(const Statements::Each& stmt) override;
  void visit_for_stmt(const Statements::For& stmt) override;
  void visit_break_stmt(const Statements::Break& stmt) override;
  void visit_continue_stmt(const Statements::Continue& stmt) override;
  void visit_return_stmt(const Statements::Return& stmt) override;
  void visit_pass_stmt(const Statements::Pass& stmt) override;

  void visit_binary_expr(const Expressions::Binary& expr) override;
  void visit_comparison_expr(const Expressions::Comparison& expr) override;
  void visit_if_expr(const Expressions::If& expr) override;
  void visit_call_expr(const Expressions::Call& expr) override;
  void visit_subscript_expr(const Expressions::Subscript& expr) override;
  void visit_member_expr(const Expressions::Member& expr) override;
  void visit_namespace_member_expr(const Expressions::NamespaceMember& expr) override;
  void visit_unary_expr(const Expressions::Unary& expr) override;
  void visit_interpolation_expr(const Expressions::Interpolation& expr) override;
  void visit_lambda_expr(const Expressions::Lambda& expr) override;
  void visit_grouping_expr(const Expressions::Grouping& expr) override;
  void visit_list_expr(const Expressions::List& expr) override;
  void visit_map_expr(const Expressions::Map& expr) override;
  void visit_number_expr(const Expressions::Number& expr) override;
  void visit_boolean_expr(const Expressions::Boolean& expr) override;
  void visit_nil_expr(const Expressions::Nil& expr) override;
  void visit_char_expr(const Expressions::Char& expr) override;
  void visit_string_expr(const Expressions::String& expr) override;
  void visit_variable_expr(const Expressions::Variable& expr) override;
  void visit_this_expr(const Expressions::This& expr) override;
  void visit_super_expr(const Expressions::Super& expr) override;
  void visit_print_expr(const Expressions::Print& expr) override;

  void break_or_continue(const char* name, const Token* label);

  public:
  explicit Analyzer(const std::vector<StmtNode>& program) : program_ {program} {}

  /**
   * Checks the parsed AST to make sure all names and types are correct.
   */
  void run();

  [[nodiscard]] const std::vector<Diagnostic>& get_diagnostics() const { return diagnostics_; }

  [[nodiscard]] bool encountered_halt() const {
    return std::ranges::any_of(diagnostics_, [](const Diagnostic& d) { return d.is_halting(); });
  }
};
