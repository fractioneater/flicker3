/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "analyzer.h"

#include <iostream>

#define VISIT accept(*this)

// Statements --------------------------------------------------

void Analyzer::visit_block_stmt(const Statements::Block& stmt) {
  begin_scope();
  // TODO: Scan declarations to allow recursion.
  for (const auto& s : stmt.statements) {
    s->VISIT;
  }
  end_scope();
}

void Analyzer::visit_expression_stmt(const Statements::Expression& stmt) {
  stmt.expression->VISIT;
}

void Analyzer::visit_variable_stmt(const Statements::Variable& stmt) {
  if (stmt.initializer)
    stmt.initializer->VISIT;
  const TypeId type = stmt.type ? resolve_syntactic_type(stmt.type) : infer_type(stmt.initializer);

  add_object_safe(stmt.identifier, {stmt.is_mutable, type});
}

void Analyzer::visit_function_stmt(const Statements::Function& stmt) {
  // Step 1: Define type params
  begin_scope();
  for (auto param_iter {std::begin(stmt.type_params)}; param_iter != std::end(stmt.type_params); ++param_iter) {
    add_type_safe(
      *param_iter,
      TypeParam {static_cast<int>(param_iter - std::begin(stmt.type_params))}
    );
  }
  // Step 2: Store return type as state
  // TODO.
  // Step 3: Function body
  stmt.body->VISIT;
  // Step 4: Define name with overload set type
  // TODO.
  // Step 5: Leave type params scope
  end_scope();
}

void Analyzer::visit_initializer_stmt(const Statements::Initializer& stmt) {} // NOT IMPLEMENTED
void Analyzer::visit_method_stmt(const Statements::Method& stmt) {}           // NOT IMPLEMENTED
void Analyzer::visit_class_stmt(const Statements::Class& stmt) {}             // NOT IMPLEMENTED
void Analyzer::visit_namespace_stmt(const Statements::Namespace& stmt) {}     // NOT IMPLEMENTED
void Analyzer::visit_import_stmt(const Statements::Import& stmt) {}           // NOT IMPLEMENTED
void Analyzer::visit_typealias_stmt(const Statements::Typealias& stmt) {}     // NOT IMPLEMENTED
void Analyzer::visit_if_stmt(const Statements::If& stmt) {}                   // NOT IMPLEMENTED

void Analyzer::visit_while_stmt(const Statements::While& stmt) {
  stmt.condition->VISIT;
  // Create a loop frame to store the label for scopes inside.
  if (stmt.label && loop_id_with_label(stmt.label))
    diagnostics_.emplace_back("A loop with this label already exists", stmt.label, Diagnostic::WARNING);
  loops_.emplace_back(stmt.label);
  stmt.loop_body->VISIT;
  stmt.around_body->VISIT;

  loops_.pop_back(); // Because the else clause shouldn't have access to the label for break or continue.
  stmt.else_body->VISIT;
}

void Analyzer::visit_each_stmt(const Statements::Each& stmt) {} // NOT IMPLEMENTED

void Analyzer::visit_for_stmt(const Statements::For& stmt) {
  stmt.begin->VISIT; // Adds any initialization variables to the scope.

  // These two could happen at the same time as far as I care.
  stmt.condition->VISIT;
  stmt.end->VISIT;

  // Create a loop frame to store the label for scopes inside.
  if (stmt.label && loop_id_with_label(stmt.label))
    diagnostics_.emplace_back("A loop with this label already exists", stmt.label, Diagnostic::WARNING);
  loops_.emplace_back(stmt.label);

  stmt.loop_body->VISIT;
  stmt.around_body->VISIT;

  loops_.pop_back(); // Because the else clause shouldn't have access to the label for break or continue.
  stmt.else_body->VISIT;
}

void Analyzer::visit_break_stmt(const Statements::Break& stmt) { break_or_continue("Break", stmt.label); }
void Analyzer::visit_continue_stmt(const Statements::Continue& stmt) { break_or_continue("Continue", stmt.label); }

void Analyzer::break_or_continue(const char* name, const Token* label) {
  if (loops_.empty()) {
    diagnostics_.emplace_back(std::string(name) + " statement outside of loop", Diagnostic::ERROR); // TODO: Position.
    return;
  }
  if (label && loop_id_with_label(label)) {
    diagnostics_.emplace_back("Label does not match any loop", label, Diagnostic::ERROR);
    return;
  }
  // TODO: I feel like I should give back some helpful context from this. loop_id_with_label() returns  how many loops to break from, but that info is ignored.
}

void Analyzer::visit_return_stmt(const Statements::Return& stmt) {} // NOT IMPLEMENTED
void Analyzer::visit_pass_stmt(const Statements::Pass& stmt) {}     // Nothing to check.

// Expressions --------------------------------------------------

void Analyzer::visit_binary_expr(const Expressions::Binary& expr) {}                    // NOT IMPLEMENTED
void Analyzer::visit_comparison_expr(const Expressions::Comparison& expr) {}            // NOT IMPLEMENTED
void Analyzer::visit_if_expr(const Expressions::If& expr) {}                            // NOT IMPLEMENTED
void Analyzer::visit_call_expr(const Expressions::Call& expr) {}                        // NOT IMPLEMENTED
void Analyzer::visit_subscript_expr(const Expressions::Subscript& expr) {}              // NOT IMPLEMENTED
void Analyzer::visit_member_expr(const Expressions::Member& expr) {}                    // NOT IMPLEMENTED
void Analyzer::visit_namespace_member_expr(const Expressions::NamespaceMember& expr) {} // NOT IMPLEMENTED
void Analyzer::visit_unary_expr(const Expressions::Unary& expr) {}                      // NOT IMPLEMENTED
void Analyzer::visit_interpolation_expr(const Expressions::Interpolation& expr) {}      // NOT IMPLEMENTED
void Analyzer::visit_lambda_expr(const Expressions::Lambda& expr) {}                    // NOT IMPLEMENTED
void Analyzer::visit_grouping_expr(const Expressions::Grouping& expr) {}                // NOT IMPLEMENTED
void Analyzer::visit_list_expr(const Expressions::List& expr) {}                        // NOT IMPLEMENTED
void Analyzer::visit_map_expr(const Expressions::Map& expr) {}                          // NOT IMPLEMENTED
void Analyzer::visit_number_expr(const Expressions::Number& expr) {}                    // NOT IMPLEMENTED
void Analyzer::visit_boolean_expr(const Expressions::Boolean& expr) {}                  // NOT IMPLEMENTED
void Analyzer::visit_nil_expr(const Expressions::Nil& expr) {}                          // NOT IMPLEMENTED
void Analyzer::visit_char_expr(const Expressions::Char& expr) {}                        // NOT IMPLEMENTED
void Analyzer::visit_string_expr(const Expressions::String& expr) {}                    // NOT IMPLEMENTED
void Analyzer::visit_variable_expr(const Expressions::Variable& expr) {}                // NOT IMPLEMENTED
void Analyzer::visit_this_expr(const Expressions::This& expr) {}                        // NOT IMPLEMENTED
void Analyzer::visit_super_expr(const Expressions::Super& expr) {}                      // NOT IMPLEMENTED
void Analyzer::visit_print_expr(const Expressions::Print& expr) {}                      // NOT IMPLEMENTED

std::optional<int> Analyzer::loop_id_with_label(const Token* match_label) {
  for (auto riter = loops_.rbegin(); riter != loops_.rend(); ++riter) {
    if (riter->labeled && riter->label == match_label->src_string)
      // Distance from the end of loops_, not the beginning.
      return std::distance(loops_.rbegin(), riter);
  }

  return std::nullopt;
}

TypeId Analyzer::infer_type(const ExprNode& expr) {
  // TODO. This is going to be tricky.
  throw AnalyzerException {ExceptionKind::INDETERMINABLE_TYPE};
}

TypeId Analyzer::resolve_syntactic_type(SyntacticTypePtr type) {
  // TODO: Turn from parser type into analyzer type.
  return TypeId {}; // Invalid (temporary).
};
