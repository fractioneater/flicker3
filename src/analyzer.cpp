/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "analyzer.h"

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
  const std::optional declared_type {stmt.type ? resolve_syntactic_type(stmt.type) : std::optional<TypeId> {}};
  if (stmt.initializer) {
    stmt.initializer->VISIT;
    if (stmt.initializer->type && declared_type.has_value()) {
      if (stmt.initializer->type != *declared_type)
        diagnostics_.emplace_back("Value type does not match annotation", stmt.identifier + 2, Diagnostic::ERROR);
      else
        diagnostics_.emplace_back("Unnecessary type annotation", stmt.identifier + 2, Diagnostic::NOTE);
    } else if (!(stmt.initializer->type || declared_type.has_value())) {
      diagnostics_.emplace_back("Not enough type information to declare variable", stmt.identifier, Diagnostic::ERROR);
    }
  }

  if (const TypeId type = stmt.type ? resolve_syntactic_type(stmt.type) : stmt.initializer->type)
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
  // In case of a Unit-returning function, this'll be nullopt. It may be invalid if resolve_syntactic_type() encounters an error.
  std::optional return_type {stmt.return_type ? resolve_syntactic_type(stmt.return_type) : std::optional<TypeId> {std::nullopt}};
  // And it no longer can be invalid.
  if (return_type.has_value() && !return_type.value()) return_type = std::nullopt;

  functions_.emplace_back();
  // Function body
  stmt.body->VISIT;
  for (const auto& [ret , where] : functions_.back().returns) {
    if (return_type.has_value() && ret != return_type)
      diagnostics_.emplace_back("Return type mismatch", where + 1, Diagnostic::ERROR);
  }

  // If there's no value given, infer instead of going straight to unit.
  if (!return_type) return_type = host_.core_types().any_t; // TODO: Find supertype for all returns. Show warning if it's Any or Any?.

  // Leave params and function scopes.
  functions_.pop_back();
  end_scope();

  // Define name with its signature.
  const Function signature {param_types, return_type.value_or(host_.core_types().unit_t)};
  const TypeId sig_id {host_.type_arena().add(signature)};

  // Lots of work just for a little overloading.
  const std::string name {stmt.identifier->src_string};
  try {
    const TypeId type {find_object(name)->declared_type};
    if (!type) throw AnalyzerException {ExceptionKind::SYMBOL_NOT_FOUND};
    const SemanticType& it {host_.type_arena().at(type)};
    if (std::holds_alternative<OverloadSet>(it)) {
      // Symbol found and is an overload.
      const OverloadSet& current {std::get<OverloadSet>(it)};
      if (current.has(sig_id)) {
        diagnostics_.emplace_back("A function with this signature has already been declared in this scope", stmt.identifier, Diagnostic::ERROR);
      } else {
        OverloadSet updated {current};
        updated.add(sig_id);
        const TypeId new_set {host_.type_arena().add(std::move(updated))};
        if (!rebind_object(name, new_set))
          diagnostics_.emplace_back("Cannot overload imported function", stmt.identifier, Diagnostic::ERROR);
      }
    } else {
      // If it's defined as something other than an overload, give an error just like add_object_safe would.
      try {
        check_duplicate_name(false, name);
      } catch (AnalyzerException& e) {
        if (e.kind == ExceptionKind::REDECLARED_NAME)
          diagnostics_.emplace_back("Name has already been declared in this scope", stmt.identifier, Diagnostic::ERROR);
        else if (e.kind == ExceptionKind::SHADOWED_NAME)
          diagnostics_.emplace_back("Name shadows a declaration from another scope", stmt.identifier, Diagnostic::WARNING);
      }
    }
  } catch (AnalyzerException& _) {
    // Symbol doesn't exist; create a new overload set.
    add_object_safe(
      stmt.identifier,
      {
        false,
        host_.type_arena().add(
          OverloadSet {name, {sig_id}}
        )
      }
    );
  }
}

void Analyzer::visit_initializer_stmt(const Statements::Initializer& stmt) {} // NOT IMPLEMENTED
void Analyzer::visit_method_stmt(const Statements::Method& stmt) {}           // NOT IMPLEMENTED

void Analyzer::visit_class_stmt(const Statements::Class& stmt) {
  // Define class early so we can use it inside itself.
  const TypeId t {host_.type_arena().new_named(static_cast<std::string>(stmt.identifier->src_string), static_cast<int>(stmt.type_params.size()))};
  add_type_safe(stmt.identifier, t);

  // Define type params
  begin_scope();
  for (auto param_iter {std::begin(stmt.type_params)}; param_iter != std::end(stmt.type_params); ++param_iter) {
    add_type_safe(
      *param_iter,
      host_.type_arena().add(TypeParam {static_cast<int>(param_iter - std::begin(stmt.type_params)), std::string {stmt.identifier->src_string}})
    );
  }

  // Find superclass.
  std::optional<TypeId> super {};
  if (stmt.superclass) {
    try {
      super = find_type(std::string {stmt.superclass->src_string});
    } catch (AnalyzerException& _) {
      diagnostics_.emplace_back(std::format("Unresolved reference to type '{}'", stmt.superclass->src_string), stmt.superclass, Diagnostic::ERROR);
    }
  }
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
    // Calling exports() will load the file, analyze it, and return its exports. It does all the work.
    const auto& [objects, types] {host_.exports(stmt.path)};
    object_exports = objects;
    type_exports   = types;
  } catch (std::runtime_error& _) {
    diagnostics_.emplace_back(std::format("Failed to load '{}'", stmt.path), Diagnostic::ERROR); // TODO: Where?
    return;
  }

  if (stmt.imports.empty()) {
    // Import all as a namespace.
    // TODO.
    // ReSharper disable once CppDFAConstantConditions :(
  } else if (stmt.import_all) {
    // Import all by name.
    // The first (and only) token in stmt.imports is the '.' or '*' character.
    // ReSharper disable once CppDFAUnreachableCode :(
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
  // Better to show this error first (before any errors inside the value).
  if (functions_.empty())
    diagnostics_.emplace_back("Return statement outside of function", stmt.where, Diagnostic::ERROR);

  if (stmt.value) stmt.value->VISIT;
  if (!functions_.empty())
    functions_.back().returns.emplace_back(stmt.value ? stmt.value->type : host_.core_types().unit_t, stmt.where);
}

void Analyzer::visit_pass_stmt(const Statements::Pass& stmt) {} // Nothing to check.

// Expressions --------------------------------------------------

void Analyzer::visit_binary_expr(const Expressions::Binary& expr) {
  expr.left->VISIT;
  expr.right->VISIT;
  if (expr.left->type) {
    const TypeId return_type {host_.type_arena().method_return_type(expr.left->type, expr.fn_name, {expr.right->type})};
    expr.type = return_type;
    if (!return_type)
      diagnostics_.emplace_back(
        std::format("'{}' does not implement '{}'", host_.type_arena().to_string(expr.left->type), expr.fn_name), Diagnostic::ERROR
      ); // TODO: Where?
  }
}

void Analyzer::visit_comparison_expr(const Expressions::Comparison& expr) {} // NOT IMPLEMENTED

void Analyzer::visit_if_expr(const Expressions::If& expr) {
  // They're in this order (___ if ___ else ___).
  expr.then->VISIT;
  expr.condition->VISIT;
  expr.else_expr->VISIT;
  // Condition doesn't need to be a bool. Flicker's truthy checking is very simple: only false and nil are falsy.
  if (expr.then->type && expr.else_expr->type) {
    if (expr.then->type != expr.else_expr->type)
      diagnostics_.emplace_back("Mismatched types between branches", Diagnostic::ERROR); // TODO: Where?
    else
      expr.type = expr.then->type;
  }
}

void Analyzer::visit_assignment_expr(const Expressions::Assignment& expr) {}            // NOT IMPLEMENTED
void Analyzer::visit_call_expr(const Expressions::Call& expr) {}                        // NOT IMPLEMENTED
void Analyzer::visit_subscript_expr(const Expressions::Subscript& expr) {}              // NOT IMPLEMENTED
void Analyzer::visit_member_expr(const Expressions::Member& expr) {}                    // NOT IMPLEMENTED
void Analyzer::visit_namespace_member_expr(const Expressions::NamespaceMember& expr) {} // NOT IMPLEMENTED

void Analyzer::visit_unary_expr(const Expressions::Unary& expr) {
  expr.expr->VISIT;
  if (expr.expr->type) {
    const TypeId return_type {host_.type_arena().method_return_type(expr.expr->type, expr.fn_name, {})};
    expr.type = return_type;
    if (!return_type)
      diagnostics_.emplace_back(
        std::format("'{}' does not implement '{}'", host_.type_arena().to_string(expr.expr->type), expr.fn_name), Diagnostic::ERROR
      ); // TODO: Where?
  }
}

void Analyzer::visit_interpolation_expr(const Expressions::Interpolation& expr) {
  for (const auto& e : expr.expressions) e->VISIT;
  expr.type = host_.core_types().string_t;
}

void Analyzer::visit_lambda_expr(const Expressions::Lambda& expr) {} // NOT IMPLEMENTED

void Analyzer::visit_grouping_expr(const Expressions::Grouping& expr) {
  expr.expr->VISIT;
  expr.type = expr.expr->type;
  // Expr doesn't look like a word anymore...
  // wait, it never was.
}

void Analyzer::visit_list_expr(const Expressions::List& expr) {
  for (const auto& item : expr.items) item->VISIT;
  // Find superclass for all item types. TODO. (and warn if it's Any or Any?). Don't forget to pass it below.
  expr.type = host_.type_arena().add(Applied {host_.core_types().list_t, {host_.core_types().any_t}});
}

void Analyzer::visit_map_expr(const Expressions::Map& expr) {
  // Keys are always strings, which makes this easier for us. Instead of Map of A B, we just have Map of A.
  for (const auto& item : expr.values) item->VISIT;
  // Find superclass for all item types. TODO. (and warn if it's Any or Any?). Don't forget to pass it below.
  expr.type = host_.type_arena().add(Applied {host_.core_types().map_t, {host_.core_types().any_t}});
}

void Analyzer::visit_number_expr(const Expressions::Number& expr) { expr.type = host_.core_types().number_t; }
void Analyzer::visit_boolean_expr(const Expressions::Boolean& expr) { expr.type = host_.core_types().bool_t; }
void Analyzer::visit_nil_expr(const Expressions::Nil& expr) { expr.type = host_.type_arena().add(Optional {host_.core_types().nothing_t}); }
void Analyzer::visit_char_expr(const Expressions::Char& expr) { expr.type = host_.core_types().char_t; }
void Analyzer::visit_string_expr(const Expressions::String& expr) { expr.type = host_.core_types().string_t; }

void Analyzer::visit_variable_expr(const Expressions::Variable& expr) {
  const std::string name {expr.identifier->src_string};
  std::optional<ObjectSymbol> symbol {};
  try {
    symbol = find_object(name);
  } catch (AnalyzerException& _) {
    return;
  }

  expr.type = symbol->declared_type;
}

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

TypeId Analyzer::resolve_syntactic_type(const SyntacticTypePtr& type) {
  switch (type->kind()) {
    case TypeKind::NAMED: {
      const auto named {std::dynamic_pointer_cast<NamedType>(type)};
      // If the type being used already exists, this should never add a type to the arena. We get it instead from the scopes.
      try {
        return find_type(named->name);
      } catch (AnalyzerException& _) {
        diagnostics_.emplace_back(std::format("Unresolved reference to type '{}'", named->name), named->identifier, Diagnostic::ERROR); // TODO: Where?
        return TypeId {};
      }
    }
    case TypeKind::APPLIED: {
      const auto applied {std::dynamic_pointer_cast<AppliedType>(type)};
      const TypeId base {resolve_syntactic_type(applied->constructor)};
      std::vector<TypeId> args {};
      for (const auto& arg : applied->args) args.emplace_back(resolve_syntactic_type(arg));
      return host_.type_arena().add(Applied {base, args});
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
      throw std::runtime_error("Unhandled type kind");
  }
}
