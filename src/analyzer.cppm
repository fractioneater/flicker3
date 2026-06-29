/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

export module analyzer;

import analyzer_host;
import ast;
import diagnostic;
import lexer;
import param;
import type;

import std;

#define VISIT accept(*this)

struct ScopeFrame {
  SymbolTable locals {};
  SymbolTable imports {};
};

struct LoopFrame {
  bool labeled {};
  std::string_view label {};

  explicit LoopFrame(const Token* token) : labeled {token != nullptr}, label {token ? token->src_string : ""} {}
};

struct FunctionFrame {
  /**
   * Used to check return statements against the function's return type and infer the return type from returns.
   * Token* points to the keyword "return," so if the value isn't core_types().unit_t, the token plus one should be the start of the value expr.
   * It is possible for the type to be invalid, only in the case where a return value is not inferrable.
   */
  std::vector<std::pair<TypeId, const Token*>> returns {};
};

struct ClassFrame {
  /**
   * The class's type. This should never be invalid.
   */
  TypeId id;

  explicit ClassFrame(TypeId this_id) : id {this_id} {}
};

// Tiny interface for some fun exceptions.
enum class ExceptionKind { REDECLARED_NAME, SHADOWED_NAME };

struct AnalyzerException : std::exception {
  ExceptionKind kind;
  explicit AnalyzerException(ExceptionKind k) : kind {k} {}
};

export class Analyzer : public StmtVisitorVoid, public ExprVisitorVoid, Searchable {
  // Interface to connect the Analyzer to the ModuleLoader that created it.
  AnalyzerHost& host_;

  // Errors/warnings/notes.
  std::vector<Diagnostic> diagnostics_ {};

  // CONTEXT --------------------------------------------------
  // Scopes for symbol tables. Workaround to avoid 2 global scopes: program block node is parsed as its statements.
  std::vector<ScopeFrame> scopes_ {{}};
  // Loop contexts (for labels).
  std::vector<LoopFrame> loops_ {};
  // Function contexts (for return types).
  std::vector<FunctionFrame> functions_ {};
  // Class contexts (for superclass).
  std::vector<ClassFrame> classes_ {};
  // TODO: Consider one stack for all contexts (for variable resolution in class scope).

  void report_error(
    const std::string& message, const Token* error_token, Diagnostic::Severity severity = Diagnostic::ERROR, const Diagnostic* context = nullptr
  ) {
    if (error_token)
      diagnostics_.emplace_back(message, error_token->start_offset, severity, context);
    else
      diagnostics_.emplace_back(message, severity, context);
  }

  // Statements --------------------------------------------------

  void visit_program_stmt(const Statements::Program& stmt) override {
    // Scope is already created!
    // TODO: Scan declarations to allow recursion.
    for (const auto& s : stmt.items) s->VISIT;
  }

  void visit_block_stmt(const Statements::Block& stmt) override {
    begin_scope();
    // TODO: Scan declarations to allow recursion.
    for (const auto& s : stmt.statements) s->VISIT;
    end_scope();
  }

  void visit_expression_stmt(const Statements::Expression& stmt) override {
    stmt.expression->VISIT;
  }

  void visit_variable_stmt(const Statements::Variable& stmt) override {
    const std::optional declared_type {stmt.type ? resolve_syntactic_type(stmt.type) : std::optional<TypeId> {}};
    if (stmt.initializer) {
      stmt.initializer->VISIT;
      if (stmt.initializer->type && declared_type.has_value()) {
        if (stmt.initializer->type != *declared_type)
          report_error("Value type does not match annotation", stmt.identifier + 2);
        else
          report_error("Unnecessary type annotation", stmt.identifier + 2, Diagnostic::NOTE);
      } else if (!(stmt.initializer->type || declared_type.has_value())) {
        report_error("Not enough type information to declare variable", stmt.identifier);
      }
    }

    if (const TypeId type {declared_type.value_or(stmt.initializer->type)})
      add_object_safe(stmt.identifier, {stmt.is_mutable, type});
  }

  struct OverloadResult {
    enum class Kind { CREATE, UPDATE, ALREADY_HANDLED } kind {Kind::ALREADY_HANDLED};

    TypeId new_type {};
  };

  OverloadResult overload(const Token* identifier, TypeId sig_id, const std::string& name, std::optional<TypeId> existing_type) {
    // Lots of work just for a little overloading.
    if (existing_type) {                        // If there's an object with this name...
      if (const TypeId type {*existing_type}) { // And its type is valid...
        const SemanticType& it {host_.type_arena().at(type)};
        if (std::holds_alternative<OverloadSet>(it)) {
          // Symbol found and is an overload.
          const OverloadSet& current {std::get<OverloadSet>(it)};
          if (current.has(sig_id)) {
            report_error("A function with this signature has already been declared in this scope", identifier);
          } else {
            OverloadSet updated {current};
            updated.add(sig_id);
            const TypeId new_set {host_.type_arena().add(std::move(updated))};
            return {OverloadResult::Kind::UPDATE, new_set};
          }
        } else {
          // If it's defined as something other than an overload, give an error just like add_object_safe would.
          try {
            check_duplicate_name(SymbolKind::OBJECT, name);
          } catch (AnalyzerException& e) {
            if (e.kind == ExceptionKind::REDECLARED_NAME)
              report_error("Name has already been declared in this scope", identifier, Diagnostic::ERROR);
            else if (e.kind == ExceptionKind::SHADOWED_NAME)
              report_error("Name shadows a declaration from another scope", identifier, Diagnostic::WARNING);
          }
        }
        return {OverloadResult::Kind::ALREADY_HANDLED, {}};
      }
    }
    return {OverloadResult::Kind::CREATE};
  }

  void visit_function_stmt(const Statements::Function& stmt) override {
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
    for (const auto& [identifier, param_type, _] : stmt.params) {
      const TypeId t {resolve_syntactic_type(param_type)};
      param_types.emplace_back(t);
      add_object_safe(identifier, {true, t});
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
        report_error("Return type mismatch", where + 1);
    }

    // If there's no value given, infer instead of going straight to unit.
    if (!return_type) return_type = host_.core_types().any_t; // TODO: Find supertype for all returns. Show warning if it's Any or Any?.
    // TODO: Error if there's a control path that doesn't return a value.

    // Leave params and function scopes.
    functions_.pop_back();
    end_scope();

    // Define the function signature and attempt to overload it.
    const Function signature {param_types, return_type.value_or(host_.core_types().unit_t)};
    const TypeId sig_id {host_.type_arena().add(signature)};
    const std::string name {stmt.identifier->src_string};
    const auto found {find_object(name)};
    const auto [result, new_type] {overload(stmt.identifier, sig_id, name, found ? found->declared_type : std::optional<TypeId> {})};
    if (result == OverloadResult::Kind::UPDATE) {
      if (!edit_object_type(name, new_type))
        report_error("Cannot overload imported function", stmt.identifier);
    } else if (result == OverloadResult::Kind::CREATE) {
      // Symbol does not exist; create a new overload set.
      add_object_safe(
        stmt.identifier,
        {false, host_.type_arena().add(OverloadSet {name, {sig_id}})}
      );
    }
  }

  void visit_initializer_stmt(const Statements::Initializer& stmt) override {} // TODO: Not implemented

  void visit_method_stmt(const Statements::Method& stmt) override {
    // See visit_function_stmt() for more explanation of what's going on here.
    begin_scope();

    std::vector<TypeId> param_types {};
    for (const auto& [identifier, param_type, _] : stmt.params) {
      const TypeId t {resolve_syntactic_type(param_type)};
      param_types.emplace_back(t);
      add_object_safe(identifier, {true, t});
    }

    std::optional return_type {stmt.return_type ? resolve_syntactic_type(stmt.return_type) : std::optional<TypeId> {std::nullopt}};
    if (return_type.has_value() && !return_type.value()) return_type = std::nullopt;

    functions_.emplace_back();
    stmt.body->VISIT;
    for (const auto& [ret , where] : functions_.back().returns) {
      if (return_type.has_value() && ret != return_type)
        report_error("Return type mismatch", where + 1);
    }
    if (!return_type) return_type = host_.core_types().any_t; // TODO + TODO (see function).

    functions_.pop_back();
    end_scope();

    const Function sig {param_types, return_type.value_or(host_.core_types().unit_t)};

    // Just a little checking to make sure this method is allowed.
    const auto [is_method, rule_param_count, rule_return_type, rule_name] {METHOD_RULES[stmt.identifier->type]};
    if (is_method) {
      // Param checking
      if (rule_param_count == MethodRule::ParamCount::NONE && !sig.params.empty())
        report_error("Method cannot take any parameters", stmt.params.front().identifier);
      else if (rule_param_count == MethodRule::ParamCount::ONE && sig.params.size() != 1)
        report_error("Method must take exactly one parameter", stmt.identifier);
      else if (rule_param_count == MethodRule::ParamCount::COULD_BE_NONE_OR_ONE && sig.params.size() > 1)
        report_error("Method cannot take more than one parameter", stmt.identifier);
      // Return checking
      if (rule_return_type == MethodRule::ReturnRestriction::BOOL && sig.return_type != host_.core_types().bool_t)
        report_error("Method must return a Bool", stmt.identifier);
      else if (rule_return_type == MethodRule::ReturnRestriction::THIS && sig.return_type != classes_.back().id)
        report_error(std::format("Method must return the current class type ('{}')", host_.type_arena().to_string(classes_.back().id)), stmt.identifier);
    } else return;

    const TypeId sig_id {host_.type_arena().add(sig)};
    const auto [result, new_type] {overload(stmt.identifier, sig_id, rule_name, host_.type_arena().member_type(classes_.back().id, rule_name))};

    if (result == OverloadResult::Kind::UPDATE) {
      host_.type_arena().edit_member_type(classes_.back().id, rule_name, new_type);
    } else if (result == OverloadResult::Kind::CREATE) {
      // Doesn't exist yet. Create a temporary scope then put it into the class.
      begin_scope();
      add_object_safe(stmt.identifier, {false, host_.type_arena().add(OverloadSet {rule_name, {sig_id}})});
      store_scope_as_members(classes_.back().id);
    }
  }

  void visit_class_stmt(const Statements::Class& stmt) override {
    // Define class early so we can use it inside itself.
    const TypeId t {host_.type_arena().new_named(std::string {stmt.identifier->src_string}, static_cast<int>(stmt.type_params.size()))};
    add_type_safe(stmt.identifier, t);

    // Find supertypes.
    std::vector<TypeId> supertypes {};
    for (const auto super : stmt.superclasses) {
      if (const auto type {find_type(std::string {super->src_string})})
        supertypes.emplace_back(*type);
      else report_error(std::format("Unresolved reference to type '{}'", super->src_string), super);
    }
    // And if it doesn't have something else to link it to Any, we'll fix that.
    if (supertypes.empty() && t != host_.core_types().any_t) supertypes.emplace_back(host_.core_types().any_t);
    host_.type_arena().define_supertypes(t, std::move(supertypes));

    // Define type params.
    begin_scope();
    for (auto param_iter {std::begin(stmt.type_params)}; param_iter != std::end(stmt.type_params); ++param_iter) {
      add_type_safe(
        *param_iter,
        host_.type_arena().add(TypeParam {static_cast<int>(param_iter - std::begin(stmt.type_params)), std::string {stmt.identifier->src_string}})
      );
    }

    classes_.emplace_back(t); // This marks the start of the region where 'this' is allowed.

    // Visit namespace items.
    if (!stmt.namespace_items.empty()) {
      begin_scope();
      for (const auto& it : stmt.namespace_items) it->VISIT;
      store_scope_as_namespace(stmt.identifier);
      // TODO: Also put the items in the outer scope for in-class access.
    }

    // Visit declarations before initializers to avoid "this" prefix.
    for (const auto& it : stmt.declarations) it->VISIT;

    // Visit initializers.
    if (!stmt.initializers.empty()) {
      begin_scope();
      for (const auto& it : stmt.initializers) it->VISIT;
      end_scope(); // But store in class... TODO.
    }

    // Leave scopes.
    classes_.pop_back();
    store_scope_as_members(t);
  }

  void visit_namespace_stmt(const Statements::Namespace& stmt) override {
    begin_scope();
    for (const auto& it : stmt.declarations) it->VISIT;
    store_scope_as_namespace(stmt.identifier);
  }

  void visit_import_stmt(const Statements::Import& stmt) override {
    const std::string pathname {std::any_cast<std::string>(stmt.path->value)};
    // Calling exports() will load the file, analyze it, and return its exports. It does all the work.
    const auto module {host_.exports(std::string {pathname})};
    if (!module) {
      const Diagnostic context {"Ensure module is not trying to import itself", Diagnostic::NOTE};
      report_error(std::format("Failed to load '{}'", pathname), stmt.path, Diagnostic::ERROR, &context);
      return;
    }

    const auto& [name, exports] {*module};

    if (stmt.imports.empty()) {
      // Import all as a namespace.
      const auto& [objects, types, namespaces] {exports};
      begin_scope();
      for (const auto& [name, symbol] : objects)
        import_object_safe(stmt.path, name, symbol);
      for (const auto& [name, type] : types)
        import_type_safe(stmt.path, name, type);
      for (const auto& [name, ns] : namespaces)
        import_namespace_safe(stmt.path, name, ns);
      store_scope_as_namespace(stmt.path, name);
    } else if (stmt.import_all) {
      // Import all by name.
      // The first (and only) token in stmt.imports is the '.' or '*' character.
      const auto& [objects, types, namespaces] {exports};
      for (const auto& [name, symbol] : objects)
        import_object_safe(stmt.imports.front(), name, symbol);
      for (const auto& [name, type] : types)
        import_type_safe(stmt.imports.front(), name, type);
      for (const auto& [name, ns] : namespaces)
        import_namespace_safe(stmt.imports.front(), name, ns);
    } else {
      // Use the explicit imports list.
      for (const Token* identifier : stmt.imports) {
        const std::string import_name {identifier->src_string};

        const auto o {exports.find_object(import_name)};
        const auto t {exports.find_type(import_name)};
        const auto n {exports.find_namespace(import_name)};

        if (o) import_object_safe(identifier, import_name, *o);
        if (t) import_type_safe(identifier, import_name, *t);
        if (n) import_namespace_safe(identifier, import_name, *n);

        if (!(o || t || n)) report_error(std::format("Module '{}' does not export '{}'", name, import_name), identifier);
      }
    }
  }

  void visit_typealias_stmt(const Statements::Typealias& stmt) override {
    add_type_safe(stmt.identifier, resolve_syntactic_type(stmt.type));
  }

  void visit_if_stmt(const Statements::If& stmt) override {
    stmt.condition->VISIT;
    stmt.then_body->VISIT;
    stmt.else_body->VISIT;
  }

  void visit_while_stmt(const Statements::While& stmt) override {
    stmt.condition->VISIT;
    // Create a loop frame to store the label for scopes inside.
    if (stmt.label && loop_id_with_label(stmt.label))
      report_error("A loop with this label already exists", stmt.label, Diagnostic::WARNING);
    loops_.emplace_back(stmt.label);

    stmt.loop_body->VISIT;
    stmt.around_body->VISIT;

    loops_.pop_back(); // Because the else clause shouldn't have access to the label for break or continue.
    stmt.else_body->VISIT;
  }

  void visit_each_stmt(const Statements::Each& stmt) override {
    // Create a loop frame to store the label for scopes inside.
    if (stmt.label && loop_id_with_label(stmt.label))
      report_error("A loop with this label already exists", stmt.label, Diagnostic::WARNING);
    loops_.emplace_back(stmt.label);

    stmt.iterator->VISIT;
    if (stmt.iterator->type && !host_.type_arena().is_supertype(stmt.iterator->type, host_.core_types().sequence_t))
      report_error(std::format("'{}' is not iterable (is not a subtype of Sequence)", host_.type_arena().to_string(stmt.iterator->type)), stmt.iter_var);
    else return;

    add_object_safe(stmt.iter_var, {false, TypeId {}}); // TODO: Type of the iter var is the type param of iterator.
    if (stmt.index_var) add_object_safe(stmt.index_var, {false, host_.core_types().number_t});

    stmt.loop_body->VISIT;
    stmt.around_body->VISIT;

    loops_.pop_back();
    stmt.else_body->VISIT;
  }

  void visit_for_stmt(const Statements::For& stmt) override {
    stmt.begin->VISIT; // Adds any initialization variables to the scope.

    // These two could happen at the same time as far as I care.
    stmt.condition->VISIT;
    stmt.end->VISIT;

    // Create a loop frame to store the label for scopes inside.
    if (stmt.label && loop_id_with_label(stmt.label))
      report_error("A loop with this label already exists", stmt.label, Diagnostic::WARNING);
    loops_.emplace_back(stmt.label);

    stmt.loop_body->VISIT;
    stmt.around_body->VISIT;

    loops_.pop_back(); // Because the else clause shouldn't have access to the label for break or continue.
    stmt.else_body->VISIT;
  }

  void visit_break_stmt(const Statements::Break& stmt) override { break_or_continue("Break", stmt.label); }
  void visit_continue_stmt(const Statements::Continue& stmt) override { break_or_continue("Continue", stmt.label); }

  void visit_return_stmt(const Statements::Return& stmt) override {
    // Better to show this error first (before any errors inside the value).
    if (functions_.empty())
      report_error("Return statement outside of function", stmt.where);

    if (stmt.value) stmt.value->VISIT;
    if (!functions_.empty())
      functions_.back().returns.emplace_back(stmt.value ? stmt.value->type : host_.core_types().unit_t, stmt.where);
  }

  void visit_pass_stmt(const Statements::Pass& stmt) override {} // Nothing to check.

  // Expressions --------------------------------------------------

  void visit_binary_expr(const Expressions::Binary& expr) override {
    expr.left->VISIT;
    expr.right->VISIT;
    if (expr.left->type) {
      const TypeId return_type {host_.type_arena().method_return_type(expr.left->type, expr.fn_name, {expr.right->type})};
      expr.type = return_type;
      if (!return_type)
        report_error(
          std::format("'{}' does not implement '{}'", host_.type_arena().to_string(expr.left->type), expr.fn_name), expr.op
        );
    }
  }

  void visit_logical_expr(const Expressions::Logical& expr) override {
    expr.left->VISIT;
    expr.right->VISIT;
    expr.type = host_.core_types().bool_t;
  }

  void visit_comparison_expr(const Expressions::Comparison& expr) override {
    for (const auto& term : expr.expressions) term->VISIT;

    for (int i {0}; i < expr.fn_names.size(); ++i) {
      const ExprNode left {expr.expressions[i]};
      const ExprNode right {expr.expressions[i + 1]};
      const auto& [where, fn] {expr.fn_names[i]};
      if (left->type) {
        if (const TypeId return_type {host_.type_arena().method_return_type(left->type, fn, {right->type})}; !return_type) {
          // All comparison methods must return a bool. We only use method_return_type to make sure it exists. ^^^ Important part.
          report_error(
            std::format("'{}' does not implement '{}'", host_.type_arena().to_string(left->type), fn), where
          );
        }
      }
    }

    expr.type = host_.core_types().bool_t;
  }

  void visit_if_expr(const Expressions::If& expr) override {
    // They're in this order (___ if ___ else ___).
    expr.then->VISIT;
    expr.condition->VISIT;
    expr.else_expr->VISIT;
    // Condition doesn't need to be a bool. Flicker's truthy checking is very simple: only false and nil are falsy.
    if (expr.then->type && expr.else_expr->type) {
      if (expr.then->type != expr.else_expr->type)
        report_error("Mismatched types between branches", nullptr); // TODO: Where?
      else
        expr.type = expr.then->type;
    }
  }

  void visit_assignment_expr(const Expressions::Assignment& expr) override {} // TODO: Not implemented
  void visit_call_expr(const Expressions::Call& expr) override {}             // TODO: Not implemented
  void visit_subscript_expr(const Expressions::Subscript& expr) override {}   // TODO: Not implemented

  void visit_member_expr(const Expressions::Member& expr) override {
    expr.object->VISIT;
    const std::string member_name {expr.member->src_string};
    if (!expr.object->type) return;
    const std::optional type {host_.type_arena().member_type(expr.object->type, member_name)};
    if (!type)
      report_error(
        std::format("'{}' does not have member '{}'", host_.type_arena().to_string(expr.object->type), member_name), expr.member
      );
    expr.type = type.value_or(TypeId {});
  }

  void visit_namespace_member_expr(const Expressions::NamespaceMember& expr) override {
    const Searchable* search_scope {this};
    std::string outer_name {"Scope"};
    for (const auto& ns : expr.namespace_ids) {
      const std::string ns_name {ns->src_string};
      const std::optional found {search_scope->find_namespace(ns_name)};
      if (!found) {
        report_error(std::format("{} does not contain namespace '{}'", outer_name, ns_name), ns);
        return;
      }
      search_scope = found.value().get(); // Looks better than &**found.
      outer_name   = "Namespace '" + ns_name + "'";
    }

    const std::string member_name {expr.member->src_string};
    const auto found {search_scope->find_object(member_name)};
    if (!found) {
      report_error(std::format("{} does not contain member '{}'", outer_name, member_name), expr.member);
      return;
    }
    expr.type = found->declared_type;
  }

  void visit_unary_expr(const Expressions::Unary& expr) override {
    expr.expr->VISIT;
    if (expr.expr->type) {
      const TypeId return_type {host_.type_arena().method_return_type(expr.expr->type, expr.fn_name, {})};
      expr.type = return_type;
      if (!return_type)
        report_error(
          std::format("'{}' does not implement '{}'", host_.type_arena().to_string(expr.expr->type), expr.fn_name), expr.op
        );
    }
  }

  void visit_interpolation_expr(const Expressions::Interpolation& expr) override {
    for (const auto& e : expr.expressions) e->VISIT;
    expr.type = host_.core_types().string_t;
  }

  void visit_lambda_expr(const Expressions::Lambda& expr) override {
    begin_scope();

    // Define params.
    std::vector<TypeId> param_types {};
    for (const auto& [identifier, param_type, _] : expr.params) {
      const TypeId t {resolve_syntactic_type(param_type)};
      param_types.emplace_back(t);
      add_object_safe(identifier, {true, t});
    }

    functions_.emplace_back();

    // Lambda body.
    expr.body->VISIT;

    TypeId return_type {};
    for (const auto& [ret , where] : functions_.back().returns) {
      if (!return_type && ret) return_type = ret;
      else if (ret && return_type != ret)
        report_error("Return type mismatch", where + 1);
    }

    // TODO: Do what functions do: find the common supertype.
    // TODO: Error if there's a control path that doesn't return a value.

    functions_.pop_back();
    end_scope();

    expr.type = host_.type_arena().add(Function {param_types, return_type});
  }

  void visit_grouping_expr(const Expressions::Grouping& expr) override {
    expr.expr->VISIT;
    expr.type = expr.expr->type;
    // Expr doesn't look like a word anymore...
    // wait, it never was.
  }

  void visit_list_expr(const Expressions::List& expr) override {
    for (const auto& item : expr.items) item->VISIT;
    // Find superclass for all item types. TODO. (and warn if it's Any or Any?). Don't forget to pass it below.
    expr.type = host_.type_arena().add(Applied {host_.core_types().list_t, {host_.core_types().any_t}});
  }

  void visit_map_expr(const Expressions::Map& expr) override {
    // Keys are always strings, which makes this easier for us. Instead of Map of A B, we just have Map of A.
    for (const auto& item : expr.values) item->VISIT;
    // Find superclass for all item types. TODO. (and warn if it's Any or Any?). Don't forget to pass it below.
    expr.type = host_.type_arena().add(Applied {host_.core_types().map_t, {host_.core_types().any_t}});
  }

  void visit_number_expr(const Expressions::Number& expr) override { expr.type = host_.core_types().number_t; }
  void visit_boolean_expr(const Expressions::Boolean& expr) override { expr.type = host_.core_types().bool_t; }
  void visit_nil_expr(const Expressions::Nil& expr) override { expr.type = host_.type_arena().add(Optional {host_.core_types().nothing_t}); }
  void visit_char_expr(const Expressions::Char& expr) override { expr.type = host_.core_types().char_t; }
  void visit_string_expr(const Expressions::String& expr) override { expr.type = host_.core_types().string_t; }

  void visit_variable_expr(const Expressions::Variable& expr) override {
    const std::string name {expr.identifier->src_string};
    const std::optional symbol {find_object(name)};
    if (!symbol) {
      report_error(std::format("Undefined variable '{}'", name), expr.identifier);
      return;
    }

    expr.type = symbol->declared_type;
  }

  void visit_this_expr(const Expressions::This& expr) override {
    if (classes_.empty()) {
      report_error("'this' expression outside of class", expr.identifier);
      return;
    }
    expr.type = classes_.back().id;
  }

  void visit_super_expr(const Expressions::Super& expr) override {} // TODO: Not implemented

  void visit_print_expr(const Expressions::Print& expr) override {
    expr.expr->VISIT;
    expr.type = expr.expr->type;
  }

  /**
   * Scans loop frames looking for one with a specific label, traversing backward through loops_.
   * @param match_label Label token to match against the name of
   * @return nullopt if the label isn't found, otherwise the number of loops from the innermost out until it was matched
   */
  std::optional<int> loop_id_with_label(const Token* match_label) {
    for (auto riter {loops_.rbegin()}; riter != loops_.rend(); ++riter) {
      if (riter->labeled && riter->label == match_label->src_string)
        // Distance from the end of loops_, not the beginning.
        return std::distance(loops_.rbegin(), riter);
    }

    return std::nullopt;
  }

  void break_or_continue(const char* name, const Token* label) {
    if (loops_.empty()) {
      report_error(std::string {name} + " statement outside of loop", nullptr); // TODO: Where?
      return;
    }
    if (label && loop_id_with_label(label)) {
      report_error("Label does not match any loop", label);
      return;
    }
    // TODO: I feel like I should give back some helpful context from this. loop_id_with_label() returns how many loops to break from, but that info is ignored.
  }

  TypeId resolve_syntactic_type(const SyntacticTypePtr& type) {
    switch (type->kind()) {
      case TypeKind::NAMED: {
        const auto named {std::dynamic_pointer_cast<NamedType>(type)};
        // If the type being used already exists, this should never add a type to the arena. We get it instead from the scopes.
        if (const auto found {find_type(named->name)}) return *found;
        report_error(std::format("Unresolved reference to type '{}'", named->name), named->identifier);
        return TypeId {};
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
        return host_.type_arena().add(Function {params, resolve_syntactic_type(function->return_type)});
      }
      case TypeKind::NAMESPACED: {
        const auto namespaced {std::dynamic_pointer_cast<NamespacedType>(type)};
        std::string outer_name {"Scope"};
        const Searchable* search_scope {this};
        for (auto iter {std::begin(namespaced->namespace_path)}; iter != std::end(namespaced->namespace_path); ++iter) {
          std::optional found {search_scope->find_namespace(*iter)};
          if (!found) {
            // Error for when an inner namespace doesn't exist.
            report_error(std::format("{} does not contain namespace '{}'", outer_name, *iter), namespaced->where);
            return TypeId {};
          }
          search_scope = found.value().get();
          outer_name   = "Namespace '" + *iter + "'";
        }
        if (const auto found {search_scope->find_type(namespaced->name)}) return *found;
        // Error for when the type doesn't exist in the final namespace.
        report_error(std::format("Namespace '{}' does not contain type '{}'", namespaced->namespace_path.back(), namespaced->name), namespaced->where);
        return TypeId {};
      }
      default:
        throw std::runtime_error("Unhandled type kind");
    }
  }

  void begin_scope() {
    scopes_.emplace_back();
  }

  void end_scope() {
    scopes_.pop_back();
  }

  /**
   * Moves the current scope's objects and types to the member table of a class, and ends the scope.
   * @param t Named class TypeId to add object symbol table to
   */
  void store_scope_as_members(TypeId t) {
    host_.type_arena().add_members(t, std::move(scopes_.back().locals.objects), std::move(scopes_.back().locals.types));
    end_scope();
  }

  /**
   * Moves the current scope's objects to a namespace, and ends the scope.
   * @param token Identifier token for error reporting
   * @param name Optional name if different from error reporting token
   */
  void store_scope_as_namespace(const Token* const token, const std::optional<std::string>& name = std::nullopt) {
    const auto temp {std::make_shared<SymbolTable>(scopes_.back().locals)};
    end_scope();
    add_namespace_safe(token, temp, name);
  }

  enum class SymbolKind { OBJECT, TYPE, NAMESPACE };

  /**
   * Makes sure a name isn't already declared.
   * @param location Which symbol table to scan (type, object, or namespace)
   * @param name Name of the symbol in question
   */
  void check_duplicate_name(SymbolKind location, const std::string& name) {
    std::function<bool(std::vector<ScopeFrame>::iterator)> contains {};
    switch (location) {
      case SymbolKind::OBJECT:
        contains = [&name](std::vector<ScopeFrame>::iterator it) {
          return it->locals.objects.contains(name) || it->imports.objects.contains(name);
        };
        break;
      case SymbolKind::TYPE:
        contains = [&name](std::vector<ScopeFrame>::iterator it) {
          return it->locals.types.contains(name) || it->imports.types.contains(name);
        };
        break;
      case SymbolKind::NAMESPACE:
        contains = [&name](std::vector<ScopeFrame>::iterator it) {
          return it->locals.namespaces.contains(name) || it->imports.namespaces.contains(name);
        };
        break;
    }

    for (auto iter {std::begin(scopes_)}; iter != std::end(scopes_); ++iter) {
      if (contains(iter)) {
        if (std::next(iter) == scopes_.end())
          throw AnalyzerException {ExceptionKind::REDECLARED_NAME};
        throw AnalyzerException {ExceptionKind::SHADOWED_NAME};
      }
    }
  }

  /**
   * Adds an object to the symbol table and reports duplicate names.
   * @param token Identifier token for symbol name and error positioning
   * @param symbol Symbol to add to the scope's object table
   */
  void add_object_safe(const Token* const token, ObjectSymbol symbol) noexcept {
    const std::string name {token->src_string};
    try {
      check_duplicate_name(SymbolKind::OBJECT, name);
      scopes_.back().locals.objects.try_emplace(name, symbol);
    } catch (AnalyzerException& e) {
      if (e.kind == ExceptionKind::REDECLARED_NAME)
        report_error("An object with this name has already been declared in this scope", token, Diagnostic::ERROR);
      else if (e.kind == ExceptionKind::SHADOWED_NAME)
        report_error("Name shadows a declaration from another scope", token, Diagnostic::WARNING);
    }
  }

  /**
   * Adds an already-existing type to the symbol table and reports duplicate names.
   * @param token Identifier token for symbol name and error positioning
   * @param t TypeId to add to the scope's type table
   */
  void add_type_safe(const Token* const token, TypeId t) noexcept {
    const std::string name {token->src_string};
    try {
      check_duplicate_name(SymbolKind::TYPE, name);
      scopes_.back().locals.types.try_emplace(name, t);
    } catch (AnalyzerException& e) {
      if (e.kind == ExceptionKind::REDECLARED_NAME)
        report_error("A type with this name has already been declared in this scope", token, Diagnostic::ERROR);
      else if (e.kind == ExceptionKind::SHADOWED_NAME)
        report_error("Type name shadows a declaration from another scope", token, Diagnostic::WARNING);
    }
  }

  /**
   * Adds a namespace to the symbol table and reports duplicate names.
   * @param token Identifier token for symbol name and error positioning
   * @param ns Namespace object to add to symbol table
   * @param real_name In case the token's src_string isn't the correct name
   */
  void add_namespace_safe(const Token* const token, Namespace ns, const std::optional<std::string>& real_name = std::nullopt) noexcept {
    const std::string name {real_name.value_or(std::string {token->src_string})};
    try {
      check_duplicate_name(SymbolKind::NAMESPACE, name);
      scopes_.back().locals.namespaces.try_emplace(name, std::move(ns));
    } catch (AnalyzerException& e) {
      if (e.kind == ExceptionKind::REDECLARED_NAME)
        report_error("A namespace with this name has already been declared in this scope", token, Diagnostic::ERROR);
      else if (e.kind == ExceptionKind::SHADOWED_NAME)
        report_error("Namespace shadows a declaration from another scope", token, Diagnostic::WARNING);
    }
  }

  /**
   * Adds an object to the scope's import list and reports duplicate names.
   * @param where Identifier token for error positioning (could be '.' or '*')
   * @param name String for symbol's name
   * @param symbol Symbol to add to the scope's object table
   */
  void import_object_safe(const Token* where, const std::string& name, ObjectSymbol symbol) noexcept {
    try {
      check_duplicate_name(SymbolKind::OBJECT, name);
      scopes_.back().imports.objects.try_emplace(name, symbol);
    } catch (AnalyzerException& e) {
      const Diagnostic tip {"Use '->' to create an import alias: using \"...\" for a -> b", Diagnostic::NOTE};
      if (e.kind == ExceptionKind::REDECLARED_NAME)
        report_error(std::format("Import '{}' conflicts with an object declaration in this scope", name), where, Diagnostic::ERROR, &tip);
      else if (e.kind == ExceptionKind::SHADOWED_NAME)
        report_error(std::format("Import '{}' shadows an object declaration from another scope", name), where, Diagnostic::WARNING, &tip);
    }
  }

  /**
   * Adds a type to the scope's import list and reports duplicate names.
   * @param where Identifier token for error positioning (could be '.' or '*')
   * @param name String for the type's name
   * @param t TypeId to add to the scope's type table
   */
  void import_type_safe(const Token* where, const std::string& name, TypeId t) noexcept {
    try {
      check_duplicate_name(SymbolKind::TYPE, name);
      scopes_.back().imports.types.try_emplace(name, t);
    } catch (AnalyzerException& e) {
      const Diagnostic tip {"Use '->' to create an import alias: using \"...\" for a -> b", Diagnostic::NOTE};
      if (e.kind == ExceptionKind::REDECLARED_NAME)
        report_error(std::format("Import '{}' conflicts with a type declaration in this scope", name), where, Diagnostic::ERROR, &tip);
      else if (e.kind == ExceptionKind::SHADOWED_NAME)
        report_error(std::format("Import '{}' shadows a type declaration from another scope", name), where, Diagnostic::WARNING, &tip);
    }
  }

  /**
   * Adds a namespace to the scope's import list and reports duplicate names.
   * @param where Identifier token for error positioning (could be '.' or '*')
   * @param name String for the namespace's name
   * @param ns Namespace object
   */
  void import_namespace_safe(const Token* where, const std::string& name, Namespace ns) noexcept {
    try {
      check_duplicate_name(SymbolKind::NAMESPACE, name);
      scopes_.back().locals.namespaces.try_emplace(name, std::move(ns));
    } catch (AnalyzerException& e) {
      const Diagnostic tip {"Use '->' to create an import alias: using \"...\" for a -> b", Diagnostic::NOTE};
      if (e.kind == ExceptionKind::REDECLARED_NAME)
        report_error(std::format("Import '{}' conflicts with a namespace declaration in this scope", name), where, Diagnostic::ERROR, &tip);
      else if (e.kind == ExceptionKind::SHADOWED_NAME)
        report_error(std::format("Import '{}' shadows a namespace declaration from another scope", name), where, Diagnostic::WARNING, &tip);
    }
  }

  /**
   * Rebinds an object symbol to a new type. Used for overload sets (when a new overload is added).
   * @param name Object name to rebind
   * @param t The symbol's new type
   * @return If the object was found in the local scope—an imported object will not be rebound, and this will return false
   */
  bool edit_object_type(const std::string& name, TypeId t) {
    for (auto scope {scopes_.rbegin()}; scope != scopes_.rend(); ++scope) {
      if (auto e {scope->locals.objects.find(name)}; e != scope->locals.objects.end()) {
        e->second.declared_type = t; // Keep is_mutable.
        return true;
      }
    }
    return false;
  }

  struct MethodRule {
    // Because non-methods technically have a method rule.
    bool is_method {};

    enum class ParamCount { NONE, ONE, COULD_BE_NONE_OR_ONE, UNRESTRICTED } param_count {ParamCount::UNRESTRICTED};

    enum class ReturnRestriction { UNRESTRICTED, BOOL, THIS } return_type {ReturnRestriction::UNRESTRICTED};

    std::string name {};
  };

  #define NOT_A_METHOD                  {false, MethodRule::ParamCount::UNRESTRICTED, MethodRule::ReturnRestriction::UNRESTRICTED, ""}
  #define UNARY_METHOD(name)            {true, MethodRule::ParamCount::NONE, MethodRule::ReturnRestriction::UNRESTRICTED, name}
  #define BINARY_METHOD(name)           {true, MethodRule::ParamCount::ONE, MethodRule::ReturnRestriction::UNRESTRICTED, name}
  #define EITHER(name)                  {true, MethodRule::ParamCount::COULD_BE_NONE_OR_ONE, MethodRule::ReturnRestriction::UNRESTRICTED, name}
  #define UNARY_MODIFYING_METHOD(name)  {true, MethodRule::ParamCount::NONE, MethodRule::ReturnRestriction::THIS, name}
  #define BINARY_MODIFYING_METHOD(name) {true, MethodRule::ParamCount::ONE, MethodRule::ReturnRestriction::THIS, name}

  // @formatter:off
  static constexpr std::array<MethodRule, 93> METHOD_RULES {{
    // MAKE SURE THE NAMES OF THE FUNCTIONS IN HERE MATCH THE ONES IN THE PARSER RULE TABLE EXACTLY!
    /* TOKEN_LEFT_PAREN     */ NOT_A_METHOD,
    /* TOKEN_RIGHT_PAREN    */ NOT_A_METHOD,
    /* TOKEN_LEFT_BRACKET   */ NOT_A_METHOD,
    /* TOKEN_RIGHT_BRACKET  */ NOT_A_METHOD,
    /* TOKEN_LEFT_BRACE     */ NOT_A_METHOD,
    /* TOKEN_RIGHT_BRACE    */ NOT_A_METHOD,
    /* TOKEN_SEMICOLON      */ NOT_A_METHOD,
    /* TOKEN_COMMA          */ NOT_A_METHOD,
    /* TOKEN_STAR           */ BINARY_METHOD("*"),
    /* TOKEN_STAR_STAR      */ BINARY_METHOD("**"),
    /* TOKEN_STAR_EQ        */ BINARY_MODIFYING_METHOD("*="),
    /* TOKEN_STAR_STAR_EQ   */ BINARY_MODIFYING_METHOD("**="),
    /* TOKEN_MINUS          */ EITHER("-"),
    /* TOKEN_MINUS_MINUS    */ UNARY_MODIFYING_METHOD("--"),
    /* TOKEN_RIGHT_ARROW    */ NOT_A_METHOD,
    /* TOKEN_MINUS_EQ       */ BINARY_MODIFYING_METHOD("-="),
    /* TOKEN_PLUS           */ BINARY_METHOD("+"),
    /* TOKEN_PLUS_PLUS      */ UNARY_MODIFYING_METHOD("++"),
    /* TOKEN_PLUS_EQ        */ BINARY_MODIFYING_METHOD("+="),
    /* TOKEN_DOT            */ NOT_A_METHOD,
    /* TOKEN_DOT_DOT        */ BINARY_METHOD(".."),
    /* TOKEN_DOT_DOT_LT     */ BINARY_METHOD("..<"),
    /* TOKEN_QUEST          */ NOT_A_METHOD,
    /* TOKEN_QUEST_COLON    */ NOT_A_METHOD,
    /* TOKEN_QUEST_DOT      */ NOT_A_METHOD,
    /* TOKEN_GT             */ { true, MethodRule::ParamCount::ONE, MethodRule::ReturnRestriction::BOOL, ">",},
    /* TOKEN_GT_GT          */ BINARY_METHOD(">>"),
    /* TOKEN_GT_EQ          */ { true, MethodRule::ParamCount::ONE, MethodRule::ReturnRestriction::BOOL, ">="},
    /* TOKEN_LT             */ { true, MethodRule::ParamCount::ONE, MethodRule::ReturnRestriction::BOOL, "<"},
    /* TOKEN_LT_LT          */ BINARY_METHOD("<<"),
    /* TOKEN_LT_EQ          */ { true, MethodRule::ParamCount::ONE, MethodRule::ReturnRestriction::BOOL, "<="},
    /* TOKEN_COLON          */ NOT_A_METHOD,
    /* TOKEN_COLON_COLON    */ NOT_A_METHOD,
    /* TOKEN_SLASH          */ BINARY_METHOD("/"),
    /* TOKEN_SLASH_EQ       */ BINARY_MODIFYING_METHOD("/="),
    /* TOKEN_PERCENT        */ BINARY_METHOD("%"),
    /* TOKEN_PERCENT_EQ     */ BINARY_MODIFYING_METHOD("%="),
    /* TOKEN_PIPE           */ BINARY_METHOD("|"),
    /* TOKEN_PIPE_EQ        */ BINARY_MODIFYING_METHOD("|="),
    /* TOKEN_CARET          */ BINARY_METHOD("^"),
    /* TOKEN_CARET_EQ       */ BINARY_MODIFYING_METHOD("^="),
    /* TOKEN_AMPERSAND      */ BINARY_METHOD("&"),
    /* TOKEN_AMPERSAND_EQ   */ BINARY_MODIFYING_METHOD("&="),
    /* TOKEN_TILDE          */ UNARY_METHOD("~"),
    /* TOKEN_TILDE_TILDE    */ UNARY_MODIFYING_METHOD("~~"),
    /* TOKEN_BANG           */ UNARY_METHOD("!"),
    /* TOKEN_BANG_EQ        */ { true, MethodRule::ParamCount::ONE, MethodRule::ReturnRestriction::BOOL, "!="},
    /* TOKEN_EQ             */ NOT_A_METHOD,
    /* TOKEN_EQ_EQ          */ { true, MethodRule::ParamCount::ONE, MethodRule::ReturnRestriction::BOOL, "=="},
    /* TOKEN_IDENTIFIER     */ { true, MethodRule::ParamCount::UNRESTRICTED, MethodRule::ReturnRestriction::UNRESTRICTED, ""},
    /* TOKEN_STRING         */ NOT_A_METHOD,
    /* TOKEN_INTERPOLATION  */ NOT_A_METHOD,
    /* TOKEN_CHAR           */ NOT_A_METHOD,
    /* TOKEN_NUMBER         */ NOT_A_METHOD,
    /* TOKEN_AND            */ NOT_A_METHOD,
    /* TOKEN_AROUND         */ NOT_A_METHOD,
    /* TOKEN_BREAK          */ NOT_A_METHOD,
    /* TOKEN_CLASS          */ NOT_A_METHOD,
    /* TOKEN_CONTINUE       */ NOT_A_METHOD,
    /* TOKEN_DO             */ NOT_A_METHOD,
    /* TOKEN_EACH           */ NOT_A_METHOD,
    /* TOKEN_ELIF           */ NOT_A_METHOD,
    /* TOKEN_ELSE           */ NOT_A_METHOD,
    /* TOKEN_FALSE          */ NOT_A_METHOD,
    /* TOKEN_FOR            */ NOT_A_METHOD,
    /* TOKEN_FUN            */ NOT_A_METHOD,
    /* TOKEN_IF             */ NOT_A_METHOD,
    /* TOKEN_IN             */ BINARY_METHOD("in"),
    /* TOKEN_IS             */ NOT_A_METHOD,
    /* TOKEN_NAMESPACE      */ NOT_A_METHOD,
    /* TOKEN_NIL            */ NOT_A_METHOD,
    /* TOKEN_NOT            */ NOT_A_METHOD, // I don't mean "Not, a method." Not is not a method. It's really not.
    /* TOKEN_OF             */ NOT_A_METHOD,
    /* TOKEN_OR             */ NOT_A_METHOD,
    /* TOKEN_OVERRIDE       */ NOT_A_METHOD,
    /* TOKEN_PASS           */ NOT_A_METHOD,
    /* TOKEN_PRINT          */ NOT_A_METHOD,
    /* TOKEN_PRINT_ERROR    */ NOT_A_METHOD,
    /* TOKEN_PRIVATE        */ NOT_A_METHOD,
    /* TOKEN_RETURN         */ NOT_A_METHOD,
    /* TOKEN_STATIC         */ NOT_A_METHOD,
    /* TOKEN_SUPER          */ NOT_A_METHOD,
    /* TOKEN_THIS           */ NOT_A_METHOD,
    /* TOKEN_TRUE           */ NOT_A_METHOD,
    /* TOKEN_USING          */ NOT_A_METHOD,
    /* TOKEN_VAL            */ NOT_A_METHOD,
    /* TOKEN_VAR            */ NOT_A_METHOD,
    /* TOKEN_WHILE          */ NOT_A_METHOD,
    /* TOKEN_INDENT         */ NOT_A_METHOD,
    /* TOKEN_DEDENT         */ NOT_A_METHOD,
    /* TOKEN_LINE           */ NOT_A_METHOD,
    /* TOKEN_EOF            */ NOT_A_METHOD,
    /* TOKEN_IGNORED_DEDENT */ NOT_A_METHOD,
  }};
  // @formatter:on

  public:
  explicit Analyzer(AnalyzerHost& host) : host_ {host} {}

  explicit Analyzer(AnalyzerHost& host, Analyzer& parent) : host_ {host} {
    const auto& [o, t, n] {parent.global_scope().locals};
    // Copy all of parent's top-level declarations into this analyzer's imports.
    scopes_.back().imports.objects    = o;
    scopes_.back().imports.types      = t;
    scopes_.back().imports.namespaces = n;
  }

  [[nodiscard]] const std::vector<Diagnostic>& get_diagnostics() const { return diagnostics_; }

  void clear_diagnostics() { diagnostics_.clear(); }

  ScopeFrame& global_scope() { return scopes_.front(); }

  void define_core_class(const std::string& name, TypeId t) {
    scopes_.front().locals.types.try_emplace(name, t);
  }

  /**
   * @param name Symbol name
   * @return Imported or declared-in-module type with the specified name
   */
  [[nodiscard]] std::optional<TypeId> find_type(const std::string& name) const override {
    for (auto scope {scopes_.rbegin()}; scope != scopes_.rend(); ++scope) {
      if (scope->locals.types.contains(name))
        return scope->locals.types.at(name);
      if (scope->imports.types.contains(name))
        return scope->imports.types.at(name);
    }
    return std::nullopt;
  }

  /**
   * @param name Symbol name
   * @return Imported or declared-in-module object with the specified name
   */
  [[nodiscard]] std::optional<ObjectSymbol> find_object(const std::string& name) const override {
    for (auto scope {scopes_.rbegin()}; scope != scopes_.rend(); ++scope) {
      if (scope->locals.objects.contains(name))
        return scope->locals.objects.at(name);
      if (scope->imports.objects.contains(name))
        return scope->imports.objects.at(name);
    }
    return std::nullopt;
  }

  /**
   * @param name Symbol name
   * @return Imported or declared-in-module namespace with the specified name
   */
  [[nodiscard]] std::optional<Namespace> find_namespace(const std::string& name) const override {
    for (auto scope {scopes_.rbegin()}; scope != scopes_.rend(); ++scope) {
      if (scope->locals.namespaces.contains(name))
        return scope->locals.namespaces.at(name);
      if (scope->imports.namespaces.contains(name))
        return scope->imports.namespaces.at(name);
    }
    return std::nullopt;
  }

  [[nodiscard]] bool encountered_halt() const {
    return std::ranges::any_of(diagnostics_, [](const Diagnostic& d) { return d.is_halting(); });
  }
};
