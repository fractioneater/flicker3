/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

module;
#include "common.h"

export module parser;

import ast;
import diagnostic;
import dotprinter;
import lexer;
import param;
import type;

import std;

enum class Precedence {
  NONE,           // so the compiler doesn't destroy itself trying to call the infix rule of a prefix-only token
  BEGIN,          // used when calling parse_expression() in a general case
  PRINT,          // yes, print is an expression
  ASSIGNMENT,     // = | -= | += | *= | /= | **= | |= | &= | ^= | %=
  NOT,            // not
  OR,             // or
  AND,            // and
  COMPARISON,     // == | != | > | >= | < | <=
  IN,             // in | not in
  IS,             // is | is not
  IF,             // ... if ... else ...
  BIT_OR,         // |
  BIT_XOR,        // ^
  BIT_AND,        // &
  BIT_SHIFT,      // << | >>
  TERM,           // + | -
  FACTOR,         // * | /
  PREFIX,         // ++ | -- | ! | ~ | -
  EXPONENT,       // **
  NIL_COALESCING, // ?:
  RANGE,          // .. | ..<
  POSTFIX,        // . | ?. | () | {} | [] | ++ | -- (the last two are exceptions, because they're not supposed to be postfix)
  ATOM
};

export class Parser {
  // Final AST tree once parsed.
  StmtNode program_ {};
  // The lexer that created the tokens for this parser. Used for one purpose: tokens_.
  Lexer& lexer_;
  // Self-explanatory.
  std::vector<Token> tokens_ {};
  // Next token in line to be parsed.
  Token* current_ {};
  // Token most recently parsed.
  Token* previous_ {};
  // Whether the parser is having an existential crisis.
  bool panic_mode_ {false};
  // previous_ when report_error() was called. So it's not exactly always the token that was wrong, it's just a good estimate
  // of "somewhere at least before the problematic bit." Used for counting indents and dedents in synchronization.
  Token* panic_causing_token_or_not_really_ {};
  // Errors AND warnings (and notes)---gotta use inclusive language, folks.
  std::vector<Diagnostic> diagnostics_ {};

  static Diagnostic diagnostic_from_token(std::string&& message, const Token* token, Diagnostic::Severity severity) {
    return {std::move(message), token->start_offset, severity};
  }

  void report_error(
    std::string&& message, const Token* error_token, Diagnostic::Severity severity = Diagnostic::ERROR, std::optional<Diagnostic> context = std::nullopt
  ) {
    Diagnostic d {diagnostic_from_token(std::move(message), error_token, severity)};
    if (context) d.add_context(std::move(*context));
    if (panic_mode_) return;
    panic_mode_                        = true;
    panic_causing_token_or_not_really_ = previous_;

    diagnostics_.emplace_back(d);
  }

  void advance() {
    previous_ = current_;
    if (current_->type != TOKEN_EOF) ++current_;
    while (current_->type == TOKEN_IGNORED_DEDENT) ++current_; // Will stop at EOF.
  }

  /**
   * Returns a Boolean, true if the next token is a certain type.
   * @param type Type to check for
   * @return A boolean, true if the token matches 'type'
   */
  [[nodiscard]] bool check(TokenType type) const {
    return current_->type == type;
  }

  /**
   * Advances if the next token matches a certain type, otherwise returns false.
   * @param type Type to check for
   * @return A boolean, true if the token matches 'type'
   */
  bool match(TokenType type) {
    if (!check(type)) return false;
    advance();
    return true;
  }

  /**
   * Consume as many TOKEN_LINEs as are available, returning true if one was found.
   * @return Whether at least one newline was found
   */
  bool match_line() {
    if (!check(TOKEN_LINE)) return false;
    while (match(TOKEN_LINE)) {}
    return true;
  }

  /**
   * Consume as many TOKEN_LINES as are available, as well as the token afterward, but consume NOTHING if the token after a set of lines is not 'type'.
   * @param type Type to check for
   * @return A boolean, true if the token after newlines matches 'type'
   */
  bool match_after_newlines(TokenType type) {
    // Taking advantage of infinite lookahead here.
    const Token* token {current_};
    while (token->type == TOKEN_LINE || token->type == TOKEN_IGNORED_DEDENT) ++token;
    if (token->type != type) return false;

    while (current_->type == TOKEN_LINE) advance();
    advance();
    return true;
  }

  /**
   * Advances if the next token matches a certain operator precedence, otherwise returns false.
   * @param prec Precedence to check for
   * @return A boolean, true if the token's precedence matches prec
   */
  bool match_precedence(Precedence prec) {
    if (RULES[current_->type].prec != prec) return false;
    advance();
    return true;
  }

  /**
   * Matches either 'of' or 'for' for a generic, but not both.
   * @return A boolean, true if the next token is 'of' or 'for'
   */
  bool match_generic() {
    if (check(TOKEN_OF) || check(TOKEN_FOR)) {
      advance();
      return true;
    }
    return false;
  }

  /**
   * If the next token matches a certain type, advances, and returns the token, otherwise creates an error and returns null.
   * @param type Expected type of the next token
   * @param message Error message in case the expected type is not found
   * @param error_token Token to associate the error with
   * @param context Context to add to the error
   * @return Previous token after match is called (which, in case of success, is the current token at the time of call)
   */
  Token* expect(TokenType type, std::string_view message, Token* error_token = nullptr, std::optional<Diagnostic> context = std::nullopt) {
    error_token = error_token == nullptr ? current_ : error_token;
    if (!match(type))
      report_error(std::string {message}, error_token, Diagnostic::ERROR, context);
    return previous_;
  }

  /**
   * Consumes a chain of TOKEN_LINEs if there are any, otherwise creates an error.
   * @param message Error message
   * @param error_token Token to associate the error with
   */
  void expect_line(std::string_view message, Token* error_token = nullptr) {
    error_token = error_token == nullptr ? current_ : error_token;
    if (!match_line()) report_error(std::string {message}, error_token);
  }

  /**
   * Parses a comma-separated list of anything up to a closing character, TRAILING COMMAS ALLOWED.
   * @tparam T Type of items in the result list
   * @param end_type TokenType of the closing character
   * @param parse_item Function to parse a single item
   * @return List of items until closing character
   */
  template <typename T>
  std::vector<T> parse_list(TokenType end_type, const std::function<T()>& parse_item) {
    std::vector<T> items {};
    while (!check(end_type)) {
      items.emplace_back(parse_item());
      if (!match(TOKEN_COMMA)) break;
    }
    return items;
  }

  /**
   * Parses an indented block of any item, line-separated.
   * @tparam T Type of items in the result list/block
   * @param indented Whether this block has indents and dedents to begin and end it (as opposed to just EOF)
   * @param name String for error messages: "expecting indentation to increase inside {name}"
   * @param parse_item Function to parse a single line
   * @return List of items (statements) for lines
   */
  template <typename T>
  std::vector<T> parse_block(const bool indented, const std::string& name, const std::function<T()>& parse_item) {
    match_line();
    if (indented)
      expect(TOKEN_INDENT, "Expecting indentation to increase inside " + name);

    std::vector<T> items {};
    // If an error pops up, the parser will dedicate itself to finding a dedent. If there isn't one, things may go bad. This helps mitigate that.
    if (indented && previous_->type != TOKEN_INDENT) return items;

    const TokenType end_type {indented ? TOKEN_DEDENT : TOKEN_EOF};
    while (!check(end_type)) {
      if (unexpected_indent()) continue;

      items.emplace_back(parse_item());
      if (panic_mode_) synchronize();

      if (!check(end_type) && !match_line())
        report_error("Extraneous line content (" + name + " item has already been fully parsed)", current_);
    }
    advance(); // Match the end_type we've already checked for.
    return items;
  }

  // Declarations --------------------------------------------------

  std::optional<StmtNode> declaration() {
    if (match(TOKEN_VAL)) return val_declaration();
    if (match(TOKEN_VAR)) return var_declaration();
    if (check(TOKEN_FUN)) return function_declaration();
    if (match(TOKEN_CLASS)) return class_declaration();
    if (match(TOKEN_NAMESPACE)) return namespace_declaration();
    if (match(TOKEN_USING)) return using_declaration();

    // Each of the places that use this handles the "there is no declaration" case differently.
    return {};
  }

  StmtNode declaration_or_statement() {
    // Do not use declaration().value_or(statement())! It's tempting, but don't do it!
    if (const auto decl {declaration()}) return *decl;
    return statement();
  }

  StmtNode declaration_in_namespace() {
    if (const auto decl {declaration()}) return *decl;

    report_error("Expected a declaration", current_);
    return nullptr;
  }

  StmtNode val_declaration() {
    const Token* identifier {expect(TOKEN_IDENTIFIER, "Expecting a variable name after 'val'")};

    const SyntacticTypePtr type {match(TOKEN_COLON) ? broad_type() : nullptr};

    Diagnostic context {"You probably don't want an immutable variable just to hold 'nil'", Diagnostic::NOTE};
    if (type && type->kind() != TypeKind::OPTIONAL)
      context.add_context(Diagnostic {"Your type isn't even able to hold 'nil'!", Diagnostic::NOTE});
    expect(TOKEN_EQ, "Val declarations must have an initializer", nullptr, context);
    return std::make_shared<Statements::Variable>(false, identifier, type, parse_expression());
  }

  StmtNode var_declaration() {
    const Token* identifier {expect(TOKEN_IDENTIFIER, "Expecting a variable name after 'var'")};
    SyntacticTypePtr type {};
    ExprNode initializer {std::make_shared<Expressions::Nil>()};

    if (match(TOKEN_COLON)) {
      type = broad_type();
      if (match(TOKEN_EQ)) initializer = parse_expression();
      else if (type && type->kind() != TypeKind::OPTIONAL)
        report_error("Non-optional variable must have an initializer; the default value of 'nil' is not allowed", current_);
    } else {
      expect(TOKEN_EQ, "Var declaration with no type must have an initializer");
      initializer = parse_expression();
    }
    return std::make_shared<Statements::Variable>(true, identifier, type, initializer);
  }

  std::optional<StmtNode> function_declaration() {
    // After 'fun' we can either have a name or part of a lambda; in the latter case, we should politely ignore it.
    const auto has_next {current_ < tokens_.data() + tokens_.size() - 1};
    if (has_next && (current_[1].type == TOKEN_LEFT_PAREN || current_[1].type == TOKEN_LEFT_BRACE)) return std::nullopt;
    // Consume TOKEN_FUN.
    advance();

    // Function name
    const Token* identifier {expect(TOKEN_IDENTIFIER, "Expecting either a function name for a function declaration or '(' for a lambda")};

    // Type parameters
    std::vector<Token*> type_params {};
    if (match_generic()) {
      if (!check(TOKEN_IDENTIFIER)) report_error("Expecting a type parameter", current_);
      while (match(TOKEN_IDENTIFIER))
        type_params.emplace_back(previous_);
    }

    // Parameters
    const std::vector params {param_list()};

    // Return type
    const auto return_type {match(TOKEN_RIGHT_ARROW) ? broad_type() : nullptr};

    // Body
    const Token* would_be_the_eq {current_};
    StmtNode body {
      match(TOKEN_EQ)
      ? std::make_shared<Statements::Return>(parse_expression(), would_be_the_eq)
      : block_or_statement()
    };

    return std::make_shared<Statements::Function>(identifier, type_params, params, return_type, body);
  }

  StmtNode class_declaration() {
    // Property 1: Name
    const Token* name {expect(TOKEN_IDENTIFIER, "Expecting a class name")};

    // Property 2: Type parameters
    std::vector<Token*> type_params {};
    if (match_generic()) {
      if (!check(TOKEN_IDENTIFIER)) report_error("Expecting a type parameter", current_);
      while (match(TOKEN_IDENTIFIER))
        type_params.emplace_back(previous_);
    }

    // Property 3: Superclass
    const Token* superclass {match(TOKEN_IS) ? expect(TOKEN_IDENTIFIER, "Expecting a superclass name") : nullptr};

    // Properties 4, 5 & 6: Contents
    match_line();
    expect(TOKEN_INDENT, "Expecting indentation to increase when class block begins");

    std::vector<StmtNode> namespace_items {};
    if (match(TOKEN_NAMESPACE))
      namespace_items = parse_block<StmtNode>(true, "class namespace", [this] { return declaration_in_namespace(); });

    std::vector<StmtNode> declarations {};
    std::vector<StmtNode> initializers {};
    while (!check(TOKEN_DEDENT)) {
      if (check(TOKEN_EOF)) return nullptr; // No class body (error case).

      // TODO: Access specifiers/things.
      if (match(TOKEN_VAL)) declarations.emplace_back(val_declaration());
      else if (match(TOKEN_VAR)) declarations.emplace_back(var_declaration());
      else if (match(TOKEN_FUN)) declarations.emplace_back(method());
      else if (check(TOKEN_IDENTIFIER) && current_->src_string == "init")
        initializers.emplace_back(initializer());

      else if (unexpected_indent()) continue;
      else if (match(TOKEN_NAMESPACE)) {
        if (namespace_items.empty())
          report_error("Namespace must come first", previous_);
        else
          report_error("Classes can only have one namespace", previous_);
      } else {
        report_error("Invalid class item—expecting a namespace, initializer, method, or variable declaration", current_);
        advance();
      }

      if (panic_mode_) synchronize();

      if (!check(TOKEN_DEDENT) && !match_line())
        report_error("Extraneous line content (class member has already been fully parsed)", current_);
    }
    advance(); // Match the dedent we've already checked for.

    return std::make_shared<Statements::Class>(name, type_params, superclass, namespace_items, initializers, declarations);
  }

  StmtNode namespace_declaration() {
    Token* name {expect(TOKEN_IDENTIFIER, "Expecting a name for this namespace")};
    return std::make_shared<Statements::Namespace>(name, parse_block<StmtNode>(true, "namespace", [this] { return declaration_in_namespace(); }));
  }

  StmtNode using_declaration() {
    // 'using' for import.
    if (match(TOKEN_STRING)) {
      const auto path {std::any_cast<std::string>(previous_->value)};
      std::vector<Token*> imports {};
      bool import_all {false};

      if (match(TOKEN_FOR)) {
        if (check(TOKEN_STAR) || check(TOKEN_DOT)) {
          // An "import all" statement can be done three ways, which is a little weird.
          // A star or a dot will import all variables at the scope's level; leaving out the 'for' clause will import in a namespace (module::item).
          advance();
          import_all = true;
          imports.emplace_back(previous_); // The star or dot (for errors).
        } else {
          // TODO: Arrow aliases.
          imports = parse_list<Token*>(TOKEN_LINE, [this] { return expect(TOKEN_IDENTIFIER, "Expecting a name for an object to import"); });
        }
      }

      return std::make_shared<Statements::Import>(path, imports, import_all);
    }

    // 'using' for type alias.
    const Token* name {expect(TOKEN_IDENTIFIER, "Expecting either a type alias name or a path for an import file")};
    expect(TOKEN_EQ, "Expecting '=' and a type to create alias for");
    return std::make_shared<Statements::Typealias>(name, broad_type());
  }

  StmtNode initializer() {
    // Consume the 'init' word—it was checked, not matched.
    advance();

    expect(TOKEN_LEFT_PAREN, "Expecting '(' to start a parameter list");
    std::vector params {
      parse_list<Param>(
        TOKEN_RIGHT_PAREN, [this] {
          auto mod {Param::Modifier::NONE};
          if (match(TOKEN_VAL)) mod = Param::Modifier::VAL;
          else if (match(TOKEN_VAR)) mod = Param::Modifier::VAR;

          const auto id {expect(TOKEN_IDENTIFIER, "Expecting a parameter name")};
          expect(TOKEN_COLON, "Expecting ':' then a parameter type");
          return Param {id, standard_type("a type for this parameter", true), mod};
        }
      )
    };
    expect(TOKEN_RIGHT_PAREN, "Expecting ')' after parameter list");

    if (match(TOKEN_EQ)) report_error("Cannot return from initializer", previous_);
    StmtNode body {block_or_statement()};

    return std::make_shared<Statements::Initializer>(params, body);
  }

  StmtNode method() {
    // Essentially just a function without type parameters.
    const Token* identifier {expect(TOKEN_IDENTIFIER, "Expecting a method name")};

    const std::vector params {param_list()};

    const auto return_type {match(TOKEN_RIGHT_ARROW) ? broad_type() : nullptr};

    const Token* would_be_the_eq {current_};
    StmtNode body {
      match(TOKEN_EQ)
      ? std::make_shared<Statements::Return>(parse_expression(), would_be_the_eq)
      : block_or_statement()
    };

    return std::make_shared<Statements::Method>(identifier, params, return_type, body);
  }

  // Type parsing (for declarations) --------------------------------------------------

  /**
   * Interprets and parses the next few tokens as a user-representable type of any complexity.
   * This includes optionals, applied types, function types, and named types (see type.cppm for explanation).
   * @return Type parsed (possibly nullptr in error case)
   */
  SyntacticTypePtr broad_type() {
    // Check for function type first.
    if (match(TOKEN_LEFT_PAREN)) return function_type();

    if (match(TOKEN_RIGHT_ARROW)) {
      report_error("Place empty parentheses for a function type with no parameters", previous_);
      return nullptr;
    }

    return standard_type("either a type name or '(' for a function type", true);
  }

  /**
   * Parses a function type, like this: (String, String) -> String.
   * @return Function type parsed (possibly nullptr in error case)
   */
  SyntacticTypePtr function_type() {
    std::vector param_types {
      parse_list<SyntacticTypePtr>(TOKEN_RIGHT_PAREN, [this] { return standard_type("a parameter type", true); })
    };
    expect(TOKEN_RIGHT_PAREN, "Expecting ')' after parameter list in function type");

    if (match(TOKEN_RIGHT_ARROW)) {
      return std::make_shared<FunctionType>(std::move(param_types), standard_type("a return type", true));
    }
    // Non-returning function.
    return std::make_shared<FunctionType>(std::move(param_types), nullptr);
  }

  /**
   * Parses a type that is not a function type—could be applied (with generics), nullable, or anything but a function type.
   * @param thing_to_look_for For the error message of the expect(IDENTIFIER)—this type always starts with an identifier—"Expecting " + thing_to_look_for
   * @param allow_generics Whether applied types are allowed.
   * @return Type parsed (possibly nullptr in error case)
   */
  SyntacticTypePtr standard_type(const std::string& thing_to_look_for, bool allow_generics) {
    if (match(TOKEN_LEFT_PAREN)) {
      report_error(
        "For readability's sake, inside a complex type, you must define other complex types with an alias",
        previous_,
        Diagnostic::ERROR,
        Diagnostic {"How to create an alias: 'using YourAliasName = (...) -> ...'", Diagnostic::NOTE}
      );
    }

    // Hacky, but I think it's okay... ish.
    const std::string name {expect(TOKEN_IDENTIFIER, "Expecting " + thing_to_look_for)->src_string};
    SyntacticTypePtr type {std::make_shared<NamedType>(name, previous_)};

    const bool is_optional {match(TOKEN_QUEST)};

    if (match_generic()) {
      if (allow_generics) {
        std::vector<SyntacticTypePtr> args {};
        do {
          args.emplace_back(standard_type("a type parameter (a type name)", false));
        } while (check(TOKEN_IDENTIFIER));
        type = std::make_shared<AppliedType>(type, std::move(args));
      } else {
        // Generics are not allowed! Oh, no!
        report_error(
          "For readability's sake, inside a complex type, you must define other complex types with an alias",
          previous_,
          Diagnostic::ERROR,
          Diagnostic {"How to create an alias: 'using YourAliasName = ... for/of ...'", Diagnostic::NOTE}
        );
      }
    }

    if (is_optional) type = std::make_shared<OptionalType>(type);

    return type;
  }

  // Other Statements --------------------------------------------------

  StmtNode statement() {
    if (match(TOKEN_IF)) return if_statement();
    if (match(TOKEN_WHILE)) return while_statement();
    if (match(TOKEN_EACH)) return each_statement();
    if (match(TOKEN_FOR)) return for_statement();
    if (match(TOKEN_BREAK)) return break_statement();
    if (match(TOKEN_CONTINUE)) return continue_statement();
    if (match(TOKEN_RETURN)) return return_statement();
    if (match(TOKEN_PASS)) return std::make_shared<Statements::Pass>();
    // Otherwise, expect an expression statement.
    //   TODO: This creates a weird situation with errors if there's nothing valid here ("Expected an expression" when a statement or expression would be okay)
    return std::make_shared<Statements::Expression>(parse_expression());
  }

  StmtNode if_statement() {
    const ExprNode condition {parse_expression()};
    const StmtNode then_body {block_or_statement()};
    StmtNode else_body {std::make_shared<Statements::Pass>()};
    if (match_after_newlines(TOKEN_ELIF))
      else_body = if_statement();
    else // The final else (if existent) will be handled by the nested/recursed if.
      else_body = optional_block(TOKEN_ELSE);
    return std::make_shared<Statements::If>(condition, then_body, else_body);
  }

  StmtNode while_statement() {
    Token* label {loop_label()};
    const ExprNode condition {parse_expression()};
    const StmtNode loop_body {block_or_statement()};
    const StmtNode around_body {optional_block(TOKEN_AROUND)};
    const StmtNode else_body {optional_block(TOKEN_ELSE)};

    if (match_after_newlines(TOKEN_AROUND))
      report_error("Place 'around' clause before 'else' clause", previous_);

    return std::make_shared<Statements::While>(label, condition, loop_body, around_body, else_body);
  }

  StmtNode each_statement() {
    Token* label {loop_label()};

    Token* iter_var {expect(TOKEN_IDENTIFIER, "Expecting a loop variable name")};

    Token* index_var {};
    if (match(TOKEN_LEFT_BRACKET)) {
      index_var = expect(TOKEN_IDENTIFIER, "Expecting a loop index variable name");
      expect(TOKEN_RIGHT_BRACKET, "Expecting ']' after loop index variable");
    }

    expect(TOKEN_IN, "Iterator loops must follow the format: each ___ in ___");

    const ExprNode expr {parse_expression()};
    const StmtNode loop_body {block_or_statement()};
    const StmtNode around_body {optional_block(TOKEN_AROUND)};
    const StmtNode else_body {optional_block(TOKEN_ELSE)};

    if (match_after_newlines(TOKEN_AROUND))
      report_error("Place 'around' clause before 'else' clause", previous_);

    return std::make_shared<Statements::Each>(label, iter_var, index_var, expr, loop_body, around_body, else_body);
  }

  StmtNode for_statement() {
    Token* for_token {previous_};
    Token* label {loop_label()};

    // Either a variable declaration or an expression is acceptable (or nothing, of course).
    StmtNode begin {
      match(TOKEN_VAL)
      ? val_declaration()
      : match(TOKEN_VAR)
        ? var_declaration()
        : check(TOKEN_SEMICOLON)
          ? std::make_shared<Statements::Expression>(std::make_shared<Expressions::Nil>()) // No beginning clause.
          : std::make_shared<Statements::Expression>(parse_expression())
    };

    Diagnostic context {diagnostic_from_token("'for' creates a C-style for loop; use 'each' for iteration", for_token, Diagnostic::NOTE)};
    expect(TOKEN_SEMICOLON, "Expecting ';' between for loop clauses", nullptr, context);

    // Only expressions are acceptable for the next two clauses.
    ExprNode condition {std::make_shared<Expressions::Boolean>(true)}; // The default value is true; "for ;;" is an infinite loop.
    if (!check(TOKEN_SEMICOLON)) condition = parse_expression();

    expect(TOKEN_SEMICOLON, "Expecting ';' between for loop clauses");

    ExprNode end {std::make_shared<Expressions::Nil>()};
    if (!check(TOKEN_LINE) && !check(TOKEN_DO)) end = parse_expression();

    const StmtNode loop_body {block_or_statement()};
    const StmtNode around_body {optional_block(TOKEN_AROUND)};
    const StmtNode else_body {optional_block(TOKEN_ELSE)};

    if (match_after_newlines(TOKEN_AROUND))
      report_error("Place 'around' clause before 'else' clause", previous_);

    return std::make_shared<Statements::For>(label, begin, condition, end, loop_body, around_body, else_body);
  }

  StmtNode break_statement() { return std::make_shared<Statements::Break>(loop_label()); }

  StmtNode continue_statement() { return std::make_shared<Statements::Continue>(loop_label()); }

  StmtNode return_statement() {
    const Token* where {previous_};
    if (check(TOKEN_LINE) || check(TOKEN_EOF) || check(TOKEN_DEDENT) || check(TOKEN_SEMICOLON))
      return std::make_shared<Statements::Return>(std::make_shared<Expressions::Nil>(), where);
    return std::make_shared<Statements::Return>(parse_expression(), where);
  }

  StmtNode block() {
    return std::make_shared<Statements::Block>(parse_block<StmtNode>(true, "code block", [this] { return declaration_or_statement(); }));
  }

  StmtNode block_or_statement() {
    if (check(TOKEN_LINE)) return block();
    expect(TOKEN_DO, "Must have either 'do' or newline before statements");
    if (check(TOKEN_LINE)) return block(); // A block is still an option after 'do'.
    return statement();
  }

  /** Parse a code block (block_or_statement()) starting with a leading word, or return Statements::Pass if the leading word is not found.
   * @param type The token to start the block
   * @return Statement inside the parsed block, or Pass
   */
  StmtNode optional_block(TokenType type) {
    if (match_after_newlines(type)) // Won't consume newlines if there isn't an else/around afterward.
      return block_or_statement();
    return std::make_shared<Statements::Pass>();
  }

  Token* loop_label() {
    if (match(TOKEN_COLON))
      return expect(TOKEN_IDENTIFIER, "Expecting loop label after ':'");
    return nullptr;
  }

  /**
   * Parse a parameter list for a function or lambda.
   * @return A list of param objects
   */
  std::vector<Param> param_list() {
    expect(TOKEN_LEFT_PAREN, "Expecting '(' to start a parameter list");
    std::vector params {
      parse_list<Param>(
        TOKEN_RIGHT_PAREN, [this] {
          const auto id {expect(TOKEN_IDENTIFIER, "Expecting a parameter name")};
          expect(TOKEN_COLON, "Expecting ':' then a parameter type");
          return Param {id, standard_type("a type for this parameter", true)};
        }
      )
    };
    expect(TOKEN_RIGHT_PAREN, "Expecting ')' after parameter list");
    return params;
  }

  /**
   * Call whenever you don't want to see an indent.
   * A whole function just for a specific little error! How crazy is that?
   */
  bool unexpected_indent() {
    if (!match(TOKEN_INDENT)) return false;
    // If a random TOKEN_INDENT is spotted, get rid of its matching DEDENT (because the lexer must create one, but we don't want another error for it).
    // I'm sorry. This does not look pretty.
    auto t {previous_};
    int nesting {0};
    while (true) {
      t++;
      if (t->type == TOKEN_INDENT) nesting++;
      else if (t->type == TOKEN_DEDENT) {
        nesting--;
        if (nesting == -1) break;
      }
    }
    // The only place where an ignored token can be seen! The parser will silently skip by it later.
    t->type = TOKEN_IGNORED_DEDENT;

    report_error("Unexpected indentation change", previous_);
    return true;
  }

  // Expressions --------------------------------------------------

  // Infix
  ExprNode binary_right_assoc(const ExprNode& left) {
    const Precedence prec {static_cast<int>(RULES[previous_->type].prec)};
    return std::make_shared<Expressions::Binary>(RULES[previous_->type].fn_name, left, parse_expression(prec));
  }

  ExprNode binary(const ExprNode& left) {
    const Precedence prec {static_cast<int>(RULES[previous_->type].prec) + 1};
    return std::make_shared<Expressions::Binary>(RULES[previous_->type].fn_name, left, parse_expression(prec));
  }

  ExprNode infix_not(const ExprNode& left) {
    expect(TOKEN_IN, "Cannot use 'not' as an infix operator by itself; try 'not in' or 'is not'", previous_);
    constexpr Precedence prec {static_cast<int>(Precedence::IN) + 1};
    return std::make_shared<Expressions::Binary>("not_in", left, parse_expression(prec));
  }

  ExprNode binary_is(const ExprNode& left) {
    constexpr Precedence prec {static_cast<int>(Precedence::IS) + 1};
    if (match(TOKEN_NOT))
      return std::make_shared<Expressions::Binary>("is_not", left, parse_expression(prec));
    return std::make_shared<Expressions::Binary>("is", left, parse_expression(prec));
  }

  ExprNode comparison(const ExprNode& left) {
    // Like in Python, comparisons can be chained: 2 < x < 44 does what a mathematician would expect it to.
    constexpr Precedence prec {static_cast<int>(Precedence::COMPARISON) + 1};
    std::vector<std::string> comparison_funcs {};
    std::vector operands {left};

    do {
      comparison_funcs.emplace_back(RULES[previous_->type].fn_name);
      operands.emplace_back(parse_expression(prec));
    } while (match_precedence(Precedence::COMPARISON));

    return std::make_shared<Expressions::Comparison>(comparison_funcs, operands);
  }

  ExprNode if_expr(const ExprNode& left) {
    constexpr Precedence prec {static_cast<int>(Precedence::IF) + 1};
    const ExprNode condition {parse_expression()};
    expect(TOKEN_ELSE, "Expecting else clause in if expression");
    return std::make_shared<Expressions::If>(condition, left, parse_expression(prec));
  }

  ExprNode assignment(const ExprNode& left) {
    // Instead of using prec + 1, we just use ASSIGNMENT for right-associativity.
    return std::make_shared<Expressions::Assignment>(left, parse_expression(Precedence::ASSIGNMENT));
  }

  // Postfix (treated as InfixFn)
  ExprNode postfix_inc_dec(const ExprNode& expr) {
    diagnostics_.emplace_back(
      diagnostic_from_token(
        "Postfix increment and decrement operators behave as their prefix equivalent; prefer the prefix version", previous_, Diagnostic::WARNING
      )
    );
    return std::make_shared<Expressions::Unary>(RULES[previous_->type].fn_name, expr);
  }

  ExprNode call(const ExprNode& expr) {
    Diagnostic start_context {diagnostic_from_token("To match this one", previous_, Diagnostic::NOTE)};
    std::vector args {parse_list<ExprNode>(TOKEN_RIGHT_PAREN, [this] { return parse_expression(); })};
    expect(TOKEN_RIGHT_PAREN, "Expecting a closing parenthesis ')'", nullptr, start_context);

    return std::make_shared<Expressions::Call>(expr, args);
  }

  ExprNode lambda_call(const ExprNode& expr) {
    return std::make_shared<Expressions::Call>(expr, std::vector {lambda()});
  }

  ExprNode subscript(const ExprNode& expr) {
    Diagnostic start_context {diagnostic_from_token("To match this one", previous_, Diagnostic::NOTE)};
    std::vector args {parse_list<ExprNode>(TOKEN_RIGHT_BRACKET, [this] { return parse_expression(); })};
    expect(TOKEN_RIGHT_BRACKET, "Expecting a closing bracket ']'", nullptr, start_context);

    return std::make_shared<Expressions::Subscript>(expr, args);
  }

  ExprNode member(const ExprNode& expr) {
    const bool safe_access {previous_->type == TOKEN_QUEST_DOT};
    return std::make_shared<Expressions::Member>(expr, expect(TOKEN_IDENTIFIER, "Expecting a member name"), safe_access);
  }

  ExprNode namespace_member(const ExprNode& expr) {
    if (const auto var_expr {std::dynamic_pointer_cast<Expressions::Variable>(expr)}) {
      return std::make_shared<Expressions::NamespaceMember>(var_expr->identifier, expect(TOKEN_IDENTIFIER, "Expecting a namespace member"));
    }
    report_error("'::' (namespace access) only works for namespaces", previous_);
    return std::make_shared<Expressions::Nil>();
  }

  // Prefix
  ExprNode unary() {
    return std::make_shared<Expressions::Unary>(RULES[previous_->type].fn_name, parse_expression(Precedence::PREFIX));
  }

  ExprNode prefix_not() {
    return std::make_shared<Expressions::Unary>("!", parse_expression(Precedence::NOT));
  }

  ExprNode print() {
    return std::make_shared<Expressions::Print>(RULES[previous_->type].fn_name, parse_expression(Precedence::PRINT));
  }

  ExprNode collection() {
    if (match(TOKEN_RIGHT_BRACKET)) // Empty list.
      return std::make_shared<Expressions::List>(std::vector<ExprNode> {});
    if (match(TOKEN_RIGHT_ARROW)) { // Empty map.
      expect(TOKEN_RIGHT_BRACKET, "Expecting ']'; a map collection with no key, '[->]', can't have a value either");
      return std::make_shared<Expressions::Map>(std::vector<std::string> {}, std::vector<ExprNode> {});
    }

    const ExprNode first_item {parse_expression()};

    if (check(TOKEN_RIGHT_ARROW))
      return map(first_item);
    return list(first_item);
  }

  ExprNode lambda() {
    // We can reach this point from either a lambda call or a lambda literal.
    // In the case of a lambda call, the '{' will already be consumed; in a standard lambda, only 'fun' will be consumed.
    if (previous_->type != TOKEN_LEFT_BRACE) match(TOKEN_LEFT_BRACE);

    // There are two types: curly-brace lambdas and block lambdas.
    // Brace lambdas...
    // - do not have significant whitespace inside them.
    // - require a semicolon after each statement (even the last) UNLESS it immediately returns an expression through equals-sign syntax.
    // - do not require parameters. 'fun { = 30 }' is valid.
    // Block lambdas...
    // - have significant whitespace, handled like a standard codeblock.
    // - require parameters (could be empty)—'fun = blahblahblah' is not allowed, instead it would be 'fun () = blahblahblah'.

    if (previous_->type == TOKEN_LEFT_BRACE) {
      // Brace lambda.
      std::vector params {
        check(TOKEN_LEFT_PAREN) ? param_list() : std::vector<Param> {}
      };
      StmtNode body {};

      if (match(TOKEN_EQ)) {
        const Token* where {previous_};
        body = std::make_shared<Statements::Return>(parse_expression(), where);
        match(TOKEN_SEMICOLON);
      } else {
        if (previous_->type == TOKEN_RIGHT_PAREN)
          expect(TOKEN_RIGHT_ARROW, "Expecting -> after parameter list");

        // Lambda body (all whitespace ignored, semicolons required).
        std::vector<StmtNode> statements {};
        do {
          statements.emplace_back(statement());
          expect(TOKEN_SEMICOLON, "Expecting ';' after statement in brace lambda");
        } while (!check(TOKEN_RIGHT_BRACE) && !check(TOKEN_EOF));

        body = std::make_shared<Statements::Block>(statements);
      }

      expect(TOKEN_RIGHT_BRACE, "Expecting '}'");
      return std::make_shared<Expressions::Lambda>(params, body);
    }

    // Block lambda.
    std::vector params {param_list()};

    const Token* would_be_the_eq {current_};
    StmtNode body {
      match(TOKEN_EQ)
      ? std::make_shared<Statements::Return>(parse_expression(), would_be_the_eq) // Could be an expression...
      : block_or_statement()                                                      // or a statement.
    };

    return std::make_shared<Expressions::Lambda>(params, body);
  }

  ExprNode string_interpolation() {
    const auto start {std::any_cast<std::string>(previous_->value)};
    std::vector<ExprNode> expressions {};
    std::vector<std::string> end_strings {};

    do {
      expressions.emplace_back(parse_expression());
      if (match(TOKEN_STRING)) {
        end_strings.emplace_back(std::any_cast<std::string>(previous_->value));
        break;
      }
      if (check(TOKEN_INTERPOLATION)) end_strings.emplace_back(std::any_cast<std::string>(current_->value));
      else {
        report_error("You've found a lexer bug: string interpolation with no ending token—tell this to the developer", current_);
        break;
      }
    } while (match(TOKEN_INTERPOLATION));

    return std::make_shared<Expressions::Interpolation>(start, expressions, end_strings);
  }

  // Primary/atom
  // ReSharper disable once CppMemberFunctionMayBeConst because it needs to match the PrefixFn signature.
  ExprNode literal() {
    switch (previous_->type) {
      case TOKEN_TRUE: return std::make_shared<Expressions::Boolean>(true);
      case TOKEN_FALSE: return std::make_shared<Expressions::Boolean>(false);
      case TOKEN_NIL: return std::make_shared<Expressions::Nil>();
      case TOKEN_NUMBER: return std::make_shared<Expressions::Number>(std::any_cast<double>(previous_->value));
      case TOKEN_STRING: return std::make_shared<Expressions::String>(std::any_cast<std::string>(previous_->value));
      case TOKEN_CHAR: return std::make_shared<Expressions::Char>(std::any_cast<char>(previous_->value));
      default: throw std::logic_error {"unreachable"};
    }
  }

  ExprNode variable() {
    return std::make_shared<Expressions::Variable>(previous_);
  }

  ExprNode this_id() {
    return std::make_shared<Expressions::This>(previous_);
  }

  ExprNode super_id() {
    return std::make_shared<Expressions::Super>(previous_);
  }

  ExprNode grouping() {
    Diagnostic start_context {diagnostic_from_token("To match this one", previous_, Diagnostic::NOTE)};
    const auto grouping {std::make_shared<Expressions::Grouping>(parse_expression())};
    expect(TOKEN_RIGHT_PAREN, "Expecting a closing parenthesis", nullptr, start_context);
    return grouping;
  }

  ExprNode list(ExprNode first_item) {
    std::vector items {std::move(first_item)};
    std::vector other {parse_list<ExprNode>(TOKEN_RIGHT_BRACKET, [this] { return parse_expression(); })};
    items.insert(items.end(), other.begin(), other.end());
    expect(TOKEN_RIGHT_BRACKET, "Expecting ']' after list");

    return std::make_shared<Expressions::List>(items);
  }

  ExprNode map(const ExprNode& first_item) {
    std::vector<std::string> keys {};
    std::vector<ExprNode> values {};

    // A little helper to handle keys.
    auto validate_key {
      [&](const ExprNode& key) {
        // A string is valid, but identifiers are the preferred style for readability.
        if (const auto str {std::dynamic_pointer_cast<Expressions::String>(key)}) {
          keys.emplace_back(str->value);
          diagnostics_.emplace_back(diagnostic_from_token("It's recommended to use identifiers instead of strings as keys", previous_, Diagnostic::WARNING));
          return;
        }

        // String interpolation for keys is not supported yet.
        if (std::dynamic_pointer_cast<Expressions::Interpolation>(key)) {
          report_error("String interpolation for keys is not yet supported", previous_);
          keys.emplace_back("");
          return;
        }

        if (const auto var {std::dynamic_pointer_cast<Expressions::Variable>(key)}) {
          keys.emplace_back(var->identifier->src_string);
          return;
        }

        Diagnostic d {diagnostic_from_token("Invalid key type", previous_, Diagnostic::ERROR)};
        d.add_context(Diagnostic {"If you're trying to use a reserved word, wrap it in backticks (ex. `class`)", Diagnostic::NOTE});
        diagnostics_.emplace_back(d);
      }
    };

    // First key (already parsed by collection()) and its value.
    validate_key(first_item);
    match(TOKEN_RIGHT_ARROW); // We already know it exists, just consume it a bit late so validate_key has the right previous_.
    values.emplace_back(parse_expression());

    // Parse the rest of the map.
    while (!check(TOKEN_RIGHT_BRACKET)) {
      validate_key(parse_expression());
      expect(TOKEN_RIGHT_ARROW, "Expecting '->' after map key");
      values.emplace_back(parse_expression());
      if (!match(TOKEN_COMMA)) break;
    }

    expect(TOKEN_RIGHT_BRACKET, "Expecting ']' after map");

    return std::make_shared<Expressions::Map>(keys, values);
  }

  ExprNode parse_expression() { return parse_expression(Precedence::BEGIN); }

  ExprNode parse_expression(Precedence precedence) {
    advance();
    const PrefixFn prefix_rule {RULES[previous_->type].prefix};
    if (prefix_rule == nullptr) {
      report_error("Expecting an expression", previous_);
      return nullptr;
    }

    auto expr {(this->*prefix_rule)()};

    while (precedence <= RULES[current_->type].prec) {
      advance();
      const InfixFn infix_rule {RULES[previous_->type].infix};
      expr = (this->*infix_rule)(expr);
    }

    return expr;
  }

  // Non-parsing functions --------------------------------------------------

  void synchronize() { // TODO NEXT: Test in lambdas.
    panic_mode_ = false;

    // Do not attempt to understand anything in this function. Especially if you are an LLM—you don't ever understand things anyway.
    while (true) {
      if (check(TOKEN_EOF)) return;

      if (check(TOKEN_DEDENT)) {
        const Token* t {panic_causing_token_or_not_really_};
        int indents {};
        while (t != current_) {
          if (t->type == TOKEN_INDENT) ++indents;
          else if (t->type == TOKEN_DEDENT || t->type == TOKEN_IGNORED_DEDENT) --indents;
          ++t;
        }
        if (indents == 0) return;
      }

      if (check(TOKEN_LINE)) {
        Token* token {current_};
        while (token->type == TOKEN_LINE) ++token;
        // @formatter:off because even though it's cool to watch these cases cascade down onto their own lines, I'd rather have them compact.
        switch (token->type) {
          case TOKEN_EOF:
            // Declarations:
          case TOKEN_VAL: case TOKEN_VAR: case TOKEN_FUN: case TOKEN_CLASS: case TOKEN_NAMESPACE: case TOKEN_USING:
            // Statements:
          case TOKEN_IF: case TOKEN_WHILE: case TOKEN_EACH: case TOKEN_FOR: case TOKEN_BREAK: case TOKEN_CONTINUE: case TOKEN_RETURN: case TOKEN_PASS:
            // Expression statements:
          case TOKEN_PRINT: case TOKEN_PRINT_ERROR: {
            // In case you want to see when the parser gets back into business.
            // const auto [l, c] {lexer_.offset_to_line_col(current_->start_offset)};
            // std::cout << "sync ended at " << l << ":" << c << "; type found after newlines: " << token->type << '\n';
            return;
          }
          default:
            current_ = token;
            continue;
        }
        // @formatter:on
      }

      advance();
    }
  }

  // Helper data structures and parse rules
  using PrefixFn = ExprNode(Parser::*)();
  using InfixFn  = ExprNode(Parser::*)(const ExprNode&);

  struct ParseRule {
    PrefixFn prefix {};
    InfixFn infix {};
    std::string fn_name {};
    Precedence prec {};
  };

  #define UNUSED                     ParseRule {nullptr, nullptr, "", Precedence::NONE}
  #define INFIX_RULE(fn, name, prec) ParseRule {nullptr, &Parser::fn, name, Precedence::prec}
  #define PREFIX_RULE(fn, name)      ParseRule {&Parser::fn, nullptr, name, Precedence::NONE}
  #define BOTH(pre, in, name, prec)  ParseRule {&Parser::pre, &Parser::in, name, Precedence::prec}

  // @formatter:off; it will separate the comments from the rest of their lines, which is horrifying.
  // IMPORTANT: Prefix rules always have a precedence of none! Their precedence is decided by the parse_expression(prec) call inside them, not the parse rule table!
  // This means that for "BOTH" rules, the precedence only applies to the infix rule.
  static constexpr std::array<ParseRule, 92> RULES {{
    /* TOKEN_LEFT_PAREN    */ BOTH(grouping, call, "", POSTFIX),
    /* TOKEN_RIGHT_PAREN   */ UNUSED,
    /* TOKEN_LEFT_BRACKET  */ BOTH(collection, subscript, "", POSTFIX),
    /* TOKEN_RIGHT_BRACKET */ UNUSED,
    /* TOKEN_LEFT_BRACE    */ INFIX_RULE(lambda_call, "", POSTFIX),
    /* TOKEN_RIGHT_BRACE   */ UNUSED,
    /* TOKEN_SEMICOLON     */ UNUSED,
    /* TOKEN_COMMA         */ UNUSED,
    /* TOKEN_TILDE         */ PREFIX_RULE(unary, "~"),
    /* TOKEN_STAR          */ INFIX_RULE(binary, "*", FACTOR),
    /* TOKEN_STAR_STAR     */ INFIX_RULE(binary_right_assoc, "**", EXPONENT),
    /* TOKEN_STAR_EQ       */ UNUSED,
    /* TOKEN_STAR_STAR_EQ  */ UNUSED,
    /* TOKEN_MINUS         */ BOTH(unary, binary, "-", TERM),
    /* TOKEN_MINUS_MINUS   */ BOTH(unary, postfix_inc_dec, "--", POSTFIX),
    /* TOKEN_RIGHT_ARROW   */ UNUSED,
    /* TOKEN_MINUS_EQ      */ UNUSED,
    /* TOKEN_PLUS          */ INFIX_RULE(binary, "+", TERM),
    /* TOKEN_PLUS_PLUS     */ BOTH(unary, postfix_inc_dec, "++", POSTFIX),
    /* TOKEN_PLUS_EQ       */ UNUSED,
    /* TOKEN_DOT           */ INFIX_RULE(member, "", POSTFIX),
    /* TOKEN_DOT_DOT       */ INFIX_RULE(binary, "..", RANGE),
    /* TOKEN_DOT_DOT_LT    */ INFIX_RULE(binary, "..<", RANGE),
    /* TOKEN_QUEST         */ UNUSED,
    /* TOKEN_QUEST_COLON   */ INFIX_RULE(binary, "?:", NIL_COALESCING),
    /* TOKEN_QUEST_DOT     */ INFIX_RULE(member, "", POSTFIX),
    /* TOKEN_GT            */ INFIX_RULE(comparison, ">", COMPARISON),
    /* TOKEN_GT_GT         */ INFIX_RULE(binary, ">>", BIT_SHIFT),
    /* TOKEN_GT_EQ         */ INFIX_RULE(comparison, ">=", COMPARISON),
    /* TOKEN_LT            */ INFIX_RULE(comparison, "<", COMPARISON),
    /* TOKEN_LT_LT         */ INFIX_RULE(binary, "<<", BIT_SHIFT),
    /* TOKEN_LT_EQ         */ INFIX_RULE(comparison, "<=", COMPARISON),
    /* TOKEN_COLON         */ UNUSED,
    /* TOKEN_COLON_COLON   */ INFIX_RULE(namespace_member, "", ATOM),
    /* TOKEN_SLASH         */ INFIX_RULE(binary, "/", FACTOR),
    /* TOKEN_SLASH_EQ      */ UNUSED,
    /* TOKEN_PERCENT       */ INFIX_RULE(binary, "%", FACTOR),
    /* TOKEN_PERCENT_EQ    */ UNUSED,
    /* TOKEN_PIPE          */ INFIX_RULE(binary, "|", BIT_OR),
    /* TOKEN_PIPE_EQ       */ UNUSED,
    /* TOKEN_CARET         */ INFIX_RULE(binary, "^", BIT_XOR),
    /* TOKEN_CARET_EQ      */ UNUSED,
    /* TOKEN_AMPERSAND     */ INFIX_RULE(binary, "&", BIT_AND),
    /* TOKEN_AMPERSAND_EQ  */ UNUSED,
    /* TOKEN_BANG          */ PREFIX_RULE(unary, "!"),
    /* TOKEN_BANG_EQ       */ INFIX_RULE(comparison, "!=", COMPARISON),
    /* TOKEN_EQ            */ INFIX_RULE(assignment, "=", ASSIGNMENT),
    /* TOKEN_EQ_EQ         */ INFIX_RULE(comparison, "==", COMPARISON),
    /* TOKEN_IDENTIFIER    */ PREFIX_RULE(variable, ""),
    /* TOKEN_STRING        */ PREFIX_RULE(literal, ""),
    /* TOKEN_INTERPOLATION */ PREFIX_RULE(string_interpolation, ""),
    /* TOKEN_CHAR          */ PREFIX_RULE(literal, ""),
    /* TOKEN_NUMBER        */ PREFIX_RULE(literal, ""),
    /* TOKEN_AND           */ INFIX_RULE(binary, "and", AND),
    /* TOKEN_AROUND        */ UNUSED,
    /* TOKEN_BREAK         */ UNUSED,
    /* TOKEN_CLASS         */ UNUSED,
    /* TOKEN_CONTINUE      */ UNUSED,
    /* TOKEN_DO            */ UNUSED,
    /* TOKEN_EACH          */ UNUSED,
    /* TOKEN_ELIF          */ UNUSED,
    /* TOKEN_ELSE          */ UNUSED,
    /* TOKEN_FALSE         */ PREFIX_RULE(literal, ""),
    /* TOKEN_FOR           */ UNUSED, // TODO: Does this ever show up as an operator? How to handle it?
    /* TOKEN_FUN           */ PREFIX_RULE(lambda, ""),
    /* TOKEN_IF            */ INFIX_RULE(if_expr, "", IF),
    /* TOKEN_IN            */ INFIX_RULE(binary, "in", IN),
    /* TOKEN_IS            */ INFIX_RULE(binary_is, "", IS),
    /* TOKEN_NAMESPACE     */ UNUSED,
    /* TOKEN_NIL           */ PREFIX_RULE(literal, ""),
    /* TOKEN_NOT           */ BOTH(prefix_not, infix_not, "", IN),
    /* TOKEN_OF            */ UNUSED, // TODO: Does this ever show up as an operator? How to handle it?
    /* TOKEN_OR            */ INFIX_RULE(binary, "or", OR),
    /* TOKEN_OVERRIDE      */ UNUSED,
    /* TOKEN_PASS          */ UNUSED,
    /* TOKEN_PRINT         */ PREFIX_RULE(print, "print"),
    /* TOKEN_PRINT_ERROR   */ PREFIX_RULE(print, "print_err"),
    /* TOKEN_PRIVATE       */ UNUSED,
    /* TOKEN_RETURN        */ UNUSED,
    /* TOKEN_STATIC        */ UNUSED,
    /* TOKEN_SUPER         */ PREFIX_RULE(super_id, ""),
    /* TOKEN_THIS          */ PREFIX_RULE(this_id, ""),
    /* TOKEN_TRUE          */ PREFIX_RULE(literal, ""),
    /* TOKEN_USING         */ UNUSED,
    /* TOKEN_VAL           */ UNUSED,
    /* TOKEN_VAR           */ UNUSED,
    /* TOKEN_WHILE         */ UNUSED,
    /* TOKEN_INDENT        */ UNUSED,
    /* TOKEN_DEDENT        */ UNUSED,
    /* TOKEN_LINE          */ UNUSED,
    /* TOKEN_EOF           */ UNUSED,
    /* TOKEN_IGNORED_DEDENT*/ UNUSED,
  }};
  // @formatter:on

  public:
  explicit Parser(Lexer& lexer) : lexer_ {lexer} {
    while (true) {
      const auto next {lexer_.next_token()};
      tokens_.emplace_back(next);
      if (next.type == TOKEN_EOF) break;
    }
    current_ = tokens_.data();
  }

  /**
   * @return The parser's tokens as a const reference.
   */
  [[nodiscard]] const std::vector<Token>& get_tokens() const { return tokens_; }

  /**
   * Parses the input token stream and generates an AST which is stored in program_ if there are no errors.
   * @return True if parsing completes without syntax errors; otherwise false
   */
  StmtNode parse() {
    if (tokens_.empty()) {
      diagnostics_.emplace_back("No tokens to parse");
      return nullptr;
    }

    program_ = std::make_shared<Statements::Program>(parse_block<StmtNode>(false, "top-level program", [this] { return declaration_or_statement(); }));
    return program_;
  }

  /**
   * Output in GraphViz DOT format, to a file specified by DEBUG_DOT_FILENAME, from the tree stored in program_.
   * There must be a tree already—parse() must have been called.
   */
  void output_dot() const {
    if (program_ == nullptr) {
      std::cerr << "Parser's AST is empty; run parse() before calling\n";
      return;
    }

    if (std::ofstream out {DEBUG_DOT_FILENAME}) {
      out << to_dot(std::dynamic_pointer_cast<Statements::Program>(program_)->items) << '\n';
      out.close();
      #if PRINT_COLORS
      std::cout << DARK_GRAY_COLOR << "Parse tree exported to " << DEBUG_DOT_FILENAME << CLEAR_FORMAT << '\n';
      #else
      std::cout << "Parse tree exported to " << DEBUG_DOT_FILENAME << '\n';
      #endif
    } else {
      std::cerr << "Could not open " << DEBUG_DOT_FILENAME << " to export parse tree\n";
    }
  }

  [[nodiscard]] const std::vector<Diagnostic>& get_diagnostics() const { return diagnostics_; }

  [[nodiscard]] bool encountered_halt() const {
    return std::ranges::any_of(diagnostics_, [](const Diagnostic& d) { return d.is_halting(); });
  }
};
