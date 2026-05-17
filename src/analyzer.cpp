/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "analyzer.h"

#include <iostream>

// Statements --------------------------------------------------

void Analyzer::visit_block_stmt(const Statements::Block& stmt) {
  // TODO: Create scope.
  for (const auto& s : stmt.statements) {
    s->accept(*this);
  }
}

void Analyzer::visit_expression_stmt(const Statements::Expression& stmt) {} // NOT IMPLEMENTED
void Analyzer::visit_variable_stmt(const Statements::Variable& stmt) {} // NOT IMPLEMENTED
void Analyzer::visit_function_stmt(const Statements::Function& stmt) {} // NOT IMPLEMENTED
void Analyzer::visit_initializer_stmt(const Statements::Initializer& stmt) {} // NOT IMPLEMENTED
void Analyzer::visit_method_stmt(const Statements::Method& stmt) {} // NOT IMPLEMENTED
void Analyzer::visit_class_stmt(const Statements::Class& stmt) {} // NOT IMPLEMENTED
void Analyzer::visit_namespace_stmt(const Statements::Namespace& stmt) {} // NOT IMPLEMENTED
void Analyzer::visit_import_stmt(const Statements::Import& stmt) {} // NOT IMPLEMENTED
void Analyzer::visit_typealias_stmt(const Statements::Typealias& stmt) {} // NOT IMPLEMENTED
void Analyzer::visit_if_stmt(const Statements::If& stmt) {} // NOT IMPLEMENTED

void Analyzer::visit_while_stmt(const Statements::While& stmt) {
  stmt.condition->accept(*this);
  // Create a loop frame to store the label for scopes inside.
  if (stmt.label && std::ranges::any_of(loops_, [&stmt](const LoopFrame& loop) { return loop.label == stmt.label->src_string; }))
    diagnostics_.emplace_back("A loop with this label already exists", Diagnostic::WARNING);
  loops_.emplace_back(stmt.label);
  stmt.loop_body->accept(*this);
  stmt.around_body->accept(*this);

  loops_.pop_back(); // Because the else clause shouldn't have access to the label for break or continue.
  stmt.else_body->accept(*this);
}

void Analyzer::visit_each_stmt(const Statements::Each& stmt) {} // NOT IMPLEMENTED

void Analyzer::visit_for_stmt(const Statements::For& stmt) {
  stmt.begin->accept(*this); // Adds any initialization variables to the scope.

  // These two could happen at the same time as far as I care.
  stmt.condition->accept(*this);
  stmt.end->accept(*this);

  // Create a loop frame to store the label for scopes inside.
  if (stmt.label && std::ranges::any_of(loops_, [&stmt](const LoopFrame& loop) { return loop.label == stmt.label->src_string; }))
    diagnostics_.emplace_back("A loop with this label already exists", Diagnostic::WARNING);
  loops_.emplace_back(stmt.label);

  stmt.loop_body->accept(*this);
  stmt.around_body->accept(*this);

  loops_.pop_back(); // Because the else clause shouldn't have access to the label for break or continue.
  stmt.else_body->accept(*this);
}

void Analyzer::visit_break_stmt(const Statements::Break& stmt) { break_or_continue("Break", stmt.label); }
void Analyzer::visit_continue_stmt(const Statements::Continue& stmt) { break_or_continue("Continue", stmt.label); }

void Analyzer::break_or_continue(const char* name, const Token* label) {
  if (loops_.empty()) {
    diagnostics_.emplace_back(std::string(name) + " statement outside of loop", Diagnostic::ERROR); // TODO: Position.
    return;
  }
  if (label && !std::ranges::any_of(loops_, [&label](const LoopFrame& loop) { return loop.label == label->src_string; })) {
    diagnostics_.emplace_back("Label does not match any loop", Diagnostic::ERROR);
    return;
  }
  // TODO: I feel like I should give back some helpful context from this. We now can find exactly how many loops to break from, but that info is ignored.
}

void Analyzer::visit_return_stmt(const Statements::Return& stmt) {}  // NOT IMPLEMENTED
void Analyzer::visit_pass_stmt(const Statements::Pass& stmt) {} // Nothing to check.

// Expressions --------------------------------------------------

void Analyzer::visit_binary_expr(const Expressions::Binary& expr) {} // NOT IMPLEMENTED
void Analyzer::visit_comparison_expr(const Expressions::Comparison& expr) {} // NOT IMPLEMENTED
void Analyzer::visit_if_expr(const Expressions::If& expr) {} // NOT IMPLEMENTED
void Analyzer::visit_call_expr(const Expressions::Call& expr) {} // NOT IMPLEMENTED
void Analyzer::visit_subscript_expr(const Expressions::Subscript& expr) {} // NOT IMPLEMENTED
void Analyzer::visit_member_expr(const Expressions::Member& expr) {} // NOT IMPLEMENTED
void Analyzer::visit_namespace_member_expr(const Expressions::NamespaceMember& expr) {} // NOT IMPLEMENTED
void Analyzer::visit_unary_expr(const Expressions::Unary& expr) {} // NOT IMPLEMENTED
void Analyzer::visit_interpolation_expr(const Expressions::Interpolation& expr) {} // NOT IMPLEMENTED
void Analyzer::visit_lambda_expr(const Expressions::Lambda& expr) {} // NOT IMPLEMENTED
void Analyzer::visit_grouping_expr(const Expressions::Grouping& expr) {} // NOT IMPLEMENTED
void Analyzer::visit_list_expr(const Expressions::List& expr) {} // NOT IMPLEMENTED
void Analyzer::visit_map_expr(const Expressions::Map& expr) {} // NOT IMPLEMENTED
void Analyzer::visit_number_expr(const Expressions::Number& expr) {} // NOT IMPLEMENTED
void Analyzer::visit_boolean_expr(const Expressions::Boolean& expr) {} // NOT IMPLEMENTED
void Analyzer::visit_nil_expr(const Expressions::Nil& expr) {} // NOT IMPLEMENTED
void Analyzer::visit_char_expr(const Expressions::Char& expr) {} // NOT IMPLEMENTED
void Analyzer::visit_string_expr(const Expressions::String& expr) {} // NOT IMPLEMENTED
void Analyzer::visit_variable_expr(const Expressions::Variable& expr) {} // NOT IMPLEMENTED
void Analyzer::visit_this_expr(const Expressions::This& expr) {} // NOT IMPLEMENTED
void Analyzer::visit_super_expr(const Expressions::Super& expr) {} // NOT IMPLEMENTED
void Analyzer::visit_print_expr(const Expressions::Print& expr) {} // NOT IMPLEMENTED

void Analyzer::run() {
  // TODO: Should the program be a block? I've tried it and reverted it because it was messy, but there may be another way to clean it up.
  Statements::Block {program_}.accept(*this);
}
