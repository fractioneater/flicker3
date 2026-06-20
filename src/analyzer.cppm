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
  std::unordered_map<std::string, ObjectSymbol> objects {};
  std::unordered_map<std::string, TypeId> types {};
  std::unordered_map<std::string, Namespace> namespaces {};

  std::unordered_map<std::string, ObjectSymbol> object_imports {};
  std::unordered_map<std::string, TypeId> type_imports {};
  std::unordered_map<std::string, Namespace> namespace_imports {};
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

  /**
   * Superclass type ID. Will be nullopt if the class doesn't give a superclass, and invalid if a nonexistent type name is provided.
   */
  std::optional<TypeId> superclass;

  explicit ClassFrame(TypeId this_id, std::optional<TypeId> super_id) : id {this_id}, superclass {super_id} {}
};

// Tiny interface for some fun exceptions.
enum class ExceptionKind { REDECLARED_NAME, SHADOWED_NAME, SYMBOL_NOT_FOUND };

struct AnalyzerException : std::exception {
  ExceptionKind kind;
  explicit AnalyzerException(ExceptionKind k) : kind {k} {}
};

export class Analyzer : public StmtVisitorVoid, public ExprVisitorVoid {
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

    if (const TypeId type = stmt.type ? resolve_syntactic_type(stmt.type) : stmt.initializer->type)
      add_object_safe(stmt.identifier, {stmt.is_mutable, type});
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
        report_error("Return type mismatch", where + 1);
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
          report_error("A function with this signature has already been declared in this scope", stmt.identifier);
        } else {
          OverloadSet updated {current};
          updated.add(sig_id);
          const TypeId new_set {host_.type_arena().add(std::move(updated))};
          if (!rebind_object(name, new_set))
            report_error("Cannot overload imported function", stmt.identifier);
        }
      } else {
        // If it's defined as something other than an overload, give an error just like add_object_safe would.
        try {
          check_duplicate_name(SymbolKind::OBJECT, name);
        } catch (AnalyzerException& e) {
          if (e.kind == ExceptionKind::REDECLARED_NAME)
            report_error("Name has already been declared in this scope", stmt.identifier, Diagnostic::ERROR);
          else if (e.kind == ExceptionKind::SHADOWED_NAME)
            report_error("Name shadows a declaration from another scope", stmt.identifier, Diagnostic::WARNING);
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

  void visit_initializer_stmt(const Statements::Initializer& stmt) override {} // NOT IMPLEMENTED
  void visit_method_stmt(const Statements::Method& stmt) override {}           // NOT IMPLEMENTED
  void visit_class_stmt(const Statements::Class& stmt) override {
    // Define class early so we can use it inside itself.
    const TypeId t {host_.type_arena().new_named(std::string {stmt.identifier->src_string}, static_cast<int>(stmt.type_params.size()))};
    add_type_safe(stmt.identifier, t);

    // Define type params.
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
        report_error(std::format("Unresolved reference to type '{}'", stmt.superclass->src_string), stmt.superclass);
      }
    }
    classes_.emplace_back(t, super);

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

  void visit_namespace_stmt(const Statements::Namespace& stmt) override {} // NOT IMPLEMENTED

  void visit_import_stmt(const Statements::Import& stmt) override {
    std::unordered_map<std::string, ObjectSymbol> object_exports {};
    std::unordered_map<std::string, TypeId> type_exports {};
    std::unordered_map<std::string, Namespace> namespace_exports {};
    try {
      // Calling exports() will load the file, analyze it, and return its exports. It does all the work.
      const auto& [objects, types, namespaces] {host_.exports(stmt.path)};
      object_exports    = objects;
      type_exports      = types;
      namespace_exports = namespaces;
    } catch (std::runtime_error& _) {
      report_error(std::format("Failed to load '{}'", stmt.path), nullptr); // TODO: Where?
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
      for (const auto& [name, ns] : namespace_exports)
        import_namespace_safe(stmt.imports.front(), name, ns);
    } else {
      // Use the explicit imports list.
      for (const Token* identifier : stmt.imports) {
        const std::string name {identifier->src_string};
        const auto o {object_exports.find(name)};
        const auto t {type_exports.find(name)};
        const auto n {namespace_exports.find(name)};

        bool success {false};
        if (o != std::end(object_exports)) {
          import_object_safe(identifier, name, o->second);
          success = true;
        }
        if (t != std::end(type_exports)) {
          import_type_safe(identifier, name, t->second);
          success = true;
        }
        if (n != std::end(namespace_exports)) {
          import_namespace_safe(identifier, name, n->second);
          success = true;
        }

        if (!success)
          report_error(std::format("Module '{}' does not export '{}'", stmt.path, name), identifier);
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

    // TODO: Check for Sequence
    stmt.iterator->VISIT;

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
          std::format("'{}' does not implement '{}'", host_.type_arena().to_string(expr.left->type), expr.fn_name), nullptr
        ); // TODO: Where?
    }
  }

  void visit_comparison_expr(const Expressions::Comparison& expr) override {} // NOT IMPLEMENTED

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

  void visit_assignment_expr(const Expressions::Assignment& expr) override {} // NOT IMPLEMENTED
  void visit_call_expr(const Expressions::Call& expr) override {}             // NOT IMPLEMENTED
  void visit_subscript_expr(const Expressions::Subscript& expr) override {}   // NOT IMPLEMENTED

  void visit_member_expr(const Expressions::Member& expr) override {
    expr.object->VISIT;
    const std::string member_name {expr.member->src_string};
    if (!expr.object->type) return;
    const std::optional type {host_.type_arena().member_type(expr.object->type, member_name)};
    if (!type)
      report_error(
        std::format("'{}' does not have member '{}'", host_.type_arena().to_string(expr.object->type), member_name), nullptr
      ); // TODO: Where?
    expr.type = type.value_or(TypeId {});
  }

  void visit_namespace_member_expr(const Expressions::NamespaceMember& expr) override {
    const std::string namespace_name {expr.namespace_id->src_string};
    const std::string member_name {expr.member->src_string};
    // TODO:
    // First, check with find_type() for a class with the namespace.
    // Second, find a way to store namespaces created not inside a class. Check there too.

    // const std::optional type {host_.type_arena().namespace_member_type(find_type(namespace_name), member_name)};
  }

  void visit_unary_expr(const Expressions::Unary& expr) override {
    expr.expr->VISIT;
    if (expr.expr->type) {
      const TypeId return_type {host_.type_arena().method_return_type(expr.expr->type, expr.fn_name, {})};
      expr.type = return_type;
      if (!return_type)
        report_error(
          std::format("'{}' does not implement '{}'", host_.type_arena().to_string(expr.expr->type), expr.fn_name), nullptr
        ); // TODO: Where?
    }
  }

  void visit_interpolation_expr(const Expressions::Interpolation& expr) override {
    for (const auto& e : expr.expressions) e->VISIT;
    expr.type = host_.core_types().string_t;
  }

  void visit_lambda_expr(const Expressions::Lambda& expr) override {} // NOT IMPLEMENTED

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
    std::optional<ObjectSymbol> symbol {};
    try {
      symbol = find_object(name);
    } catch (AnalyzerException& _) {
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

  void visit_super_expr(const Expressions::Super& expr) override {} // NOT IMPLEMENTED

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
        try {
          return find_type(named->name);
        } catch (AnalyzerException& _) {
          report_error(std::format("Unresolved reference to type '{}'", named->name), named->identifier); // TODO: Where?
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

  void begin_scope() {
    scopes_.emplace_back();
  }

  void end_scope() {
    scopes_.pop_back();
  }

  /**
   * Move the current scope's objects to the member table of a class, and end the scope.
   * @param t Named class TypeId to add object symbol table to
   */
  void store_scope_as_members(TypeId t) {
    host_.type_arena().add_members(t, std::move(scopes_.back().objects));
    end_scope();
  }

  /**
   * Move the current scope's objects to a namespace, and end the scope.
   * @param name Namespace identifier token
   */
  void store_scope_as_namespace(const Token* const name) {
    auto&& temp {std::move(scopes_.back().objects)};
    end_scope();
    add_namespace_safe(name, std::move(temp));
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
          return it->objects.contains(name) || it->object_imports.contains(name);
        };
        break;
      case SymbolKind::TYPE:
        contains = [&name](std::vector<ScopeFrame>::iterator it) {
          return it->types.contains(name) || it->type_imports.contains(name);
        };
        break;
      case SymbolKind::NAMESPACE:
        contains = [&name](std::vector<ScopeFrame>::iterator it) {
          return it->namespaces.contains(name) || it->namespace_imports.contains(name);
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
      scopes_.back().objects.emplace(name, symbol);
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
      scopes_.back().types.emplace(name, t);
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
   */
  void add_namespace_safe(const Token* const token, const Namespace& ns) noexcept {
    const std::string name {token->src_string};
    try {
      check_duplicate_name(SymbolKind::NAMESPACE, name);
      scopes_.back().namespaces.emplace(name, ns);
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
      scopes_.back().object_imports.emplace(name, symbol);
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
      scopes_.back().type_imports.emplace(name, t);
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
  void import_namespace_safe(const Token* where, const std::string& name, const Namespace& ns) noexcept {
    try {
      check_duplicate_name(SymbolKind::NAMESPACE, name);
      scopes_.back().namespaces.emplace(name, ns);
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
   */
  bool rebind_object(const std::string& name, TypeId t) {
    for (auto scope {scopes_.rbegin()}; scope != scopes_.rend(); ++scope) {
      if (auto e {scope->objects.find(name)}; e != scope->objects.end()) {
        e->second.declared_type = t; // Keep is_mutable.
        return true;
      }
    }
    return false;
  }

  public:
  explicit Analyzer(AnalyzerHost& host) : host_ {host} {}

  explicit Analyzer(AnalyzerHost& host, Analyzer& parent) : host_ {host} {
    const auto& [o, t, n, o_i, t_i, n_i] {parent.global_scope()};
    // Copy all of parent's top-level declarations into this analyzer's imports.
    scopes_.back().object_imports    = o;
    scopes_.back().type_imports      = t;
    scopes_.back().namespace_imports = n;
  }

  [[nodiscard]] const std::vector<Diagnostic>& get_diagnostics() const { return diagnostics_; }

  void clear_diagnostics() { diagnostics_.clear(); }

  ScopeFrame& global_scope() { return scopes_.front(); }

  /**
   * IMPORTANT: Can throw AnalyzerException {SYMBOL_NOT_FOUND}; use in try block.
   * @param name Symbol name
   * @return Imported or declared-in-module type with the specified name
   */
  TypeId find_type(const std::string& name) {
    for (auto scope {scopes_.rbegin()}; scope != scopes_.rend(); ++scope) {
      if (scope->types.contains(name))
        return scope->types.at(name);
      if (scope->type_imports.contains(name))
        return scope->type_imports.at(name);
    }
    throw AnalyzerException {ExceptionKind::SYMBOL_NOT_FOUND};
  }

  /**
   * IMPORTANT: Can throw AnalyzerException {SYMBOL_NOT_FOUND}; use in try block.
   * @param name Symbol name
   * @return Imported or declared-in-module object with the specified name
   */
  std::optional<ObjectSymbol> find_object(const std::string& name) {
    for (auto scope {scopes_.rbegin()}; scope != scopes_.rend(); ++scope) {
      if (scope->objects.contains(name))
        return scope->objects.at(name);
      if (scope->object_imports.contains(name))
        return scope->object_imports.at(name);
    }
    throw AnalyzerException {ExceptionKind::SYMBOL_NOT_FOUND};
  }

  [[nodiscard]] bool encountered_halt() const {
    return std::ranges::any_of(diagnostics_, [](const Diagnostic& d) { return d.is_halting(); });
  }
};
