/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "analyzer.h"

#include <cassert>
#include <iostream>

#define VISIT accept(*this)

// Statements --------------------------------------------------

void Analyzer::visit_program_stmt(const Statements::Program& stmt) {
  // Scope is already created!
  // TODO: Scan declarations to allow recursion.
  for (const auto& s : stmt.items) s->VISIT;
}

void Analyzer::visit_block_stmt(const Statements::Block& stmt) {
  begin_scope();
  // TODO: Scan declarations to allow recursion.
  for (const auto& s : stmt.statements) s->VISIT;
  end_scope();
}

void Analyzer::visit_expression_stmt(const Statements::Expression& stmt) {
  stmt.expression->VISIT;
}

void Analyzer::visit_variable_stmt(const Statements::Variable& stmt) {
  if (stmt.initializer) stmt.initializer->VISIT;

  if (const TypeId type = stmt.type ? resolve_syntactic_type(stmt.type) : find_expr_type(stmt.initializer))
    add_object_safe(stmt.identifier, {stmt.is_mutable, type});
}

void Analyzer::visit_function_stmt(const Statements::Function& stmt) {
  // Define type params.
  begin_scope();
  for (auto param_iter {std::begin(stmt.type_params)}; param_iter != std::end(stmt.type_params); ++param_iter) {
    add_type_safe(
      *param_iter,
      host_.type_arena().add(TypeParam {static_cast<int>(param_iter - std::begin(stmt.type_params)), std::string {stmt.identifier->src_string}})
    );
  }
  // Define regular params.
  std::vector<TypeId> param_types {};
  param_types.reserve(stmt.params.size());
  for (const auto& [identifier, param_type, modifier] : stmt.params) {
    const TypeId t {resolve_syntactic_type(param_type)};
    param_types.emplace_back(t);
    add_object_safe(identifier, {modifier != Param::Modifier::VAL, t});
  }
  // Store return type as state.
  const TypeId return_type {stmt.return_type ? resolve_syntactic_type(stmt.return_type) : TypeId {}};
  functions_.emplace_back(return_type); // TODO: infer return type from body, maybe.
  // Function body
  stmt.body->VISIT;
  // Leave params and function scopes.
  functions_.pop_back();
  end_scope();
  // Define name with its signature.
  const Function signature {param_types, return_type};                          // TODO: Unit type???
  add_object_safe(stmt.identifier, {false, host_.type_arena().add(signature)}); // TODO: Overloading?
}

void Analyzer::visit_initializer_stmt(const Statements::Initializer& stmt) {} // NOT IMPLEMENTED
void Analyzer::visit_method_stmt(const Statements::Method& stmt) {}           // NOT IMPLEMENTED

void Analyzer::visit_class_stmt(const Statements::Class& stmt) {
  // Define type params
  begin_scope();
  for (auto param_iter {std::begin(stmt.type_params)}; param_iter != std::end(stmt.type_params); ++param_iter) {
    add_type_safe(
      *param_iter,
      host_.type_arena().add(TypeParam {static_cast<int>(param_iter - std::begin(stmt.type_params)), std::string {stmt.identifier->src_string}})
    );
  }
  // Find superclass.
  const auto super {stmt.superclass ? find_type(std::string {stmt.superclass->src_string}) : TypeId {}};
  if (stmt.superclass && !super)
    diagnostics_.emplace_back(
      std::format("Unresolved reference to type '{}'", stmt.superclass->src_string), stmt.superclass, Diagnostic::ERROR
    );
  // Define class early so we can use it inside itself.
  const TypeId t {host_.type_arena().add(Named {std::string {stmt.identifier->src_string}, static_cast<int>(stmt.type_params.size())})};
  add_type_safe(stmt.identifier, t);
  classes_.emplace_back(t, super);
  // Visit namespace items.
  begin_scope();
  for (const auto& it : stmt.namespace_items) it->VISIT;
  // TODO: Before everything goes away, store it in the class somewhere.
  end_scope();
  // Visit initializers.
  for (const auto& it : stmt.initializers) it->VISIT;
  // TODO: Everything with scoping is going wrong.
  // Visit declarations.
  // TODO.
  // Leave scopes.
  classes_.pop_back();
  end_scope();
}

void Analyzer::visit_namespace_stmt(const Statements::Namespace& stmt) {} // NOT IMPLEMENTED

void Analyzer::visit_import_stmt(const Statements::Import& stmt) {
  std::unordered_map<std::string, ObjectSymbol> object_exports {};
  std::unordered_map<std::string, TypeId> type_exports {};
  try {
    const auto& [objects, types] {host_.exports(stmt.path)};
    object_exports = objects;
    type_exports   = types;
  } catch (std::runtime_error& e) {
    diagnostics_.emplace_back(std::format("Failed to load '{}'", stmt.path), Diagnostic::ERROR); // TODO: Where?
    return;
  }

  if (stmt.imports.empty()) {
    // Import all as a namespace.
    // TODO.
  } else if (stmt.import_all) {
    // Import all by name.
    // The first (and only) token in stmt.imports is the '.' or '*' character.
    for (const auto& [name, symbol] : object_exports)
      import_object_safe(stmt.imports.front(), name, symbol);
    for (const auto& [name, type] : type_exports)
      import_type_safe(stmt.imports.front(), name, type);
  } else {
    // Use the explicit imports list.
    for (const Token* identifier : stmt.imports) {
      const std::string name {identifier->src_string};
      const auto o {object_exports.find(name)};
      const auto t {type_exports.find(name)};

      if (o != std::end(object_exports))
        import_object_safe(identifier, name, o->second);
      if (t != std::end(type_exports))
        import_type_safe(identifier, name, t->second);
    }
  }
}

void Analyzer::visit_typealias_stmt(const Statements::Typealias& stmt) {
  add_type_safe(stmt.identifier, resolve_syntactic_type(stmt.type));
}

void Analyzer::visit_if_stmt(const Statements::If& stmt) {
  stmt.condition->VISIT;
  stmt.then_body->VISIT;
  stmt.else_body->VISIT;
}

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

void Analyzer::visit_each_stmt(const Statements::Each& stmt) {
  // Create a loop frame to store the label for scopes inside.
  if (stmt.label && loop_id_with_label(stmt.label))
    diagnostics_.emplace_back("A loop with this label already exists", stmt.label, Diagnostic::WARNING);
  loops_.emplace_back(stmt.label);

  // TODO: Check for Sequence
  stmt.iterator->VISIT;

  add_object_safe(stmt.iter_var, {false, TypeId {}}); // TODO: Type of the iter var is the type param of iterator.
  if (stmt.index_var) add_object_safe(stmt.index_var, {false, host_.core_types().number_t});

  stmt.loop_body->VISIT;
  stmt.around_body->VISIT;

  loops_.pop_back();
  stmt.else_body->VISIT;
}

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
    diagnostics_.emplace_back(std::string {name} + " statement outside of loop", Diagnostic::ERROR); // TODO: Where?
    return;
  }
  if (label && loop_id_with_label(label)) {
    diagnostics_.emplace_back("Label does not match any loop", label, Diagnostic::ERROR);
    return;
  }
  // TODO: I feel like I should give back some helpful context from this. loop_id_with_label() returns how many loops to break from, but that info is ignored.
}

void Analyzer::visit_return_stmt(const Statements::Return& stmt) {
  if (stmt.value) stmt.value->VISIT;
  if (functions_.empty()) {
    diagnostics_.emplace_back("Return statement outside of function", stmt.where, Diagnostic::ERROR);
    return;
  }
  if (stmt.value) {
    if (find_expr_type(stmt.value) != functions_.back().return_type)
      diagnostics_.emplace_back("Incorrect return value type", stmt.where + 1, Diagnostic::ERROR);
  } else {
    if (functions_.back().returns)
      diagnostics_.emplace_back("Must return a value", stmt.where, Diagnostic::ERROR);
  }
}

void Analyzer::visit_pass_stmt(const Statements::Pass& stmt) {} // Nothing to check.

// Expressions --------------------------------------------------

void Analyzer::visit_binary_expr(const Expressions::Binary& expr) {}                    // NOT IMPLEMENTED
void Analyzer::visit_comparison_expr(const Expressions::Comparison& expr) {}            // NOT IMPLEMENTED
void Analyzer::visit_if_expr(const Expressions::If& expr) {}                            // NOT IMPLEMENTED
void Analyzer::visit_assignment_expr(const Expressions::Assignment& expr) {}            // NOT IMPLEMENTED
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
void Analyzer::visit_number_expr(const Expressions::Number& expr) { expr.type = host_.core_types().number_t; }
void Analyzer::visit_boolean_expr(const Expressions::Boolean& expr) { expr.type = host_.core_types().bool_t; }
void Analyzer::visit_nil_expr(const Expressions::Nil& expr) { expr.type = host_.core_types().nil_t; }
void Analyzer::visit_char_expr(const Expressions::Char& expr) { expr.type = host_.core_types().char_t; }
void Analyzer::visit_string_expr(const Expressions::String& expr) { expr.type = host_.core_types().string_t; }
void Analyzer::visit_variable_expr(const Expressions::Variable& expr) {} // NOT IMPLEMENTED

void Analyzer::visit_this_expr(const Expressions::This& expr) {
  if (classes_.empty()) {
    diagnostics_.emplace_back("'this' expression outside of class", expr.identifier, Diagnostic::ERROR);
    return;
  }
  expr.type = classes_.back().id;
}

void Analyzer::visit_super_expr(const Expressions::Super& expr) {} // NOT IMPLEMENTED

void Analyzer::visit_print_expr(const Expressions::Print& expr) {
  expr.expr->VISIT;
  expr.type = expr.expr->type;
}

std::optional<int> Analyzer::loop_id_with_label(const Token* match_label) {
  for (auto riter {loops_.rbegin()}; riter != loops_.rend(); ++riter) {
    if (riter->labeled && riter->label == match_label->src_string)
      // Distance from the end of loops_, not the beginning.
      return std::distance(loops_.rbegin(), riter);
  }

  return std::nullopt;
}

TypeId Analyzer::find_expr_type(const ExprNode& expr) {
  // TODO. This is going to be tricky.
  throw AnalyzerException {ExceptionKind::INDETERMINABLE_TYPE};
}

TypeId Analyzer::resolve_syntactic_type(const SyntacticTypePtr& type) {
  switch (type->kind()) {
    case TypeKind::NAMED: {
      const auto named {std::dynamic_pointer_cast<NamedType>(type)};
      // If the type being used already exists, this should never add a type to the arena. We get it instead from the scopes.
      const auto found {find_type(named->name)};

      if (!found) diagnostics_.emplace_back(std::format("Unresolved reference to type '{}'", named->name), Diagnostic::ERROR); // TODO: Where?
      return found;
    }
    case TypeKind::APPLIED: {
      const auto applied {std::dynamic_pointer_cast<AppliedType>(type)};
      std::vector<TypeId> args {};
      for (const auto& arg : applied->args) args.emplace_back(resolve_syntactic_type(arg));
      return host_.type_arena().add(Applied {resolve_syntactic_type(applied->constructor), args});
    }
    case TypeKind::OPTIONAL: {
      const auto optional {std::dynamic_pointer_cast<OptionalType>(type)};
      return host_.type_arena().add(Optional {resolve_syntactic_type(optional->inner)});
    }
    case TypeKind::FUNCTION: {
      const auto function {std::dynamic_pointer_cast<FunctionType>(type)};
      std::vector<TypeId> params {};
      for (const auto& param : function->params) params.emplace_back(resolve_syntactic_type(param));
      return host_.type_arena().add(Function {params, resolve_syntactic_type(function->result)});
    }
    default:
      std::cerr << "Unhandled type kind" << std::endl;
      abort();
  }
}
