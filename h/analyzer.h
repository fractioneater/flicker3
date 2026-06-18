/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#pragma once

#include <format>
#include <unordered_map>
#include <vector>

#include "analyzer-host.h"
#include "ast.h"

import diagnostic;

struct ScopeFrame {
  std::unordered_map<std::string, ObjectSymbol> objects {};
  std::unordered_map<std::string, TypeId> types {};

  std::unordered_map<std::string, ObjectSymbol> object_imports {};
  std::unordered_map<std::string, TypeId> type_imports {};
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

class Analyzer : public StmtVisitorVoid, public ExprVisitorVoid {
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

  void visit_program_stmt(const Statements::Program& stmt) override;
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
  void visit_assignment_expr(const Expressions::Assignment& expr) override;
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

  /**
   * Scans loop frames looking for one with a specific label, traversing backward through loops_.
   * @param match_label Label token to match against the name of
   * @return nullopt if the label isn't found, otherwise the number of loops from the innermost out until it was matched
   */
  std::optional<int> loop_id_with_label(const Token* match_label);
  void break_or_continue(const char* name, const Token* label);

  TypeId resolve_syntactic_type(const SyntacticTypePtr& type);

  // Functions that look nicer when you write them like this:
  void begin_scope() {
    scopes_.emplace_back();
  }

  void end_scope() {
    scopes_.pop_back();
  }

  /**
   * Makes sure a name isn't already declared.
   * @param is_type Which symbol table to scan (true for type, false for object)
   * @param name Name of the symbol in question
   */
  void check_duplicate_name(bool is_type, const std::string& name) {
    for (auto iter {std::begin(scopes_)}; iter != std::end(scopes_); ++iter) {
      if (is_type ? (iter->types.contains(name) || iter->type_imports.contains(name)) : (iter->objects.contains(name) || iter->object_imports.contains(name))) {
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
      check_duplicate_name(false, name);
      scopes_.back().objects.emplace(name, symbol);
    } catch (AnalyzerException& e) {
      if (e.kind == ExceptionKind::REDECLARED_NAME)
        report_error("Name has already been declared in this scope", token, Diagnostic::ERROR);
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
      check_duplicate_name(true, name);
      scopes_.back().types.emplace(name, t);
    } catch (AnalyzerException& e) {
      if (e.kind == ExceptionKind::REDECLARED_NAME)
        report_error("Type name has already been declared in this scope", token, Diagnostic::ERROR);
      else if (e.kind == ExceptionKind::SHADOWED_NAME)
        report_error("Type name shadows a declaration from another scope", token, Diagnostic::WARNING);
    }
  }

  /**
   * Adds an object to the scope's import list and reports duplicate names.
   * @param where Identifier token for error positioning (could be '.' or '*')
   * @param name String for symbol's name
   * @param symbol Symbol to add to the scope's object table
   */
  void import_object_safe(const Token* where, const std::string& name, ObjectSymbol symbol) {
    try {
      check_duplicate_name(false, name);
      scopes_.back().object_imports.emplace(name, symbol);
    } catch (AnalyzerException& e) {
      Diagnostic tip {"Use '->' to create an import alias: using \"...\" for a -> b", Diagnostic::NOTE};
      if (e.kind == ExceptionKind::REDECLARED_NAME)
        report_error(std::format("Import '{}' conflicts with a declaration in this scope", name), where, Diagnostic::ERROR, &tip);
      else if (e.kind == ExceptionKind::SHADOWED_NAME)
        report_error(std::format("Import '{}' shadows a declaration from another scope", name), where, Diagnostic::WARNING, &tip);
    }
  }

  /**
   * Adds a type to the scope's import list and reports duplicate names.
   * @param where Identifier token for error positioning (could be '.' or '*')
   * @param name String for the type's name
   * @param t TypeId to add to the scope's type table
   */
  void import_type_safe(const Token* where, const std::string& name, TypeId t) {
    try {
      check_duplicate_name(true, name);
      scopes_.back().type_imports.emplace(name, t);
    } catch (AnalyzerException& e) {
      Diagnostic tip {"Use '->' to create an import alias: using \"...\" for a -> b", Diagnostic::NOTE};
      if (e.kind == ExceptionKind::REDECLARED_NAME)
        report_error(std::format("Import '{}' conflicts with a declaration in this scope", name), where, Diagnostic::ERROR, &tip);
      else if (e.kind == ExceptionKind::SHADOWED_NAME)
        report_error(std::format("Import '{}' shadows a declaration from another scope", name), where, Diagnostic::WARNING, &tip);
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
    const auto& [o , t , o_i, t_i] {parent.global_scope()};
    // Copy all of parent's top-level declarations into this analyzer's imports.
    scopes_.back().object_imports = o;
    scopes_.back().type_imports   = t;
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
