/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "parser.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <utility>

#include "util.h"

// Declarations --------------------------------------------------

std::optional<StmtNode> Parser::declaration() {
  if (match(TOKEN_VAL)) return val_declaration();
  if (match(TOKEN_VAR)) return var_declaration();
  if (check(TOKEN_FUN)) return function_declaration();
  // if (match(TOKEN_CLASS)) return class_declaration();
  if (match(TOKEN_NAMESPACE)) return namespace_declaration();
  // if (match(TOKEN_USING)) return using_declaration();

  // Each of the places that use this handle the "there is no declaration" case differently.
  return {};
}

StmtNode Parser::declaration_or_statement() {
  if (const auto decl {declaration()}) return *decl;
  return statement();
}

StmtNode Parser::declaration_in_namespace() {
  if (const auto decl {declaration()}) return *decl;

  errors_.emplace_back(current_, "Expected a declaration");
  return std::make_shared<Statements::Pass>();
}

StmtNode Parser::val_declaration() {
  expect(TOKEN_IDENTIFIER, "Expecting a variable name after 'val'");
  const Token* identifier {previous_};

  const TypePtr type {match(TOKEN_COLON) ? broad_type() : nullptr};

  ParserError context {nullptr, "You probably don't want an immutable variable just to hold 'nil'"};
  if (type && type->kind() != TypeKind::OPTIONAL)
    context.add_context({nullptr, "Your type isn't even able to hold 'nil'!"});
  expect(TOKEN_EQ, "Val declarations must have an initializer", context);
  return std::make_shared<Statements::Variable>(false, identifier, type, parse_expression());
}

StmtNode Parser::var_declaration() {
  expect(TOKEN_IDENTIFIER, "Expecting a variable name after 'var'");
  const Token* identifier {previous_};
  TypePtr type {};
  ExprNode initializer {std::make_shared<Expressions::Nil>()};

  if (match(TOKEN_COLON)) {
    type = broad_type();
    if (match(TOKEN_EQ)) initializer = parse_expression();
    else if (type && type->kind() != TypeKind::OPTIONAL)
      errors_.emplace_back(current_, "Non-optional variable must have an initializer; the default value of 'nil' is not allowed");
  } else {
    expect(TOKEN_EQ, "Var declaration with no type must have an initializer");
    initializer = parse_expression();
  }
  return std::make_shared<Statements::Variable>(true, identifier, type, initializer);
}

std::optional<StmtNode> Parser::function_declaration() {
  // After 'fun' we can either have a name or a parameter list which is part of a lambda, not a declaration.
  const auto has_next {current_ < tokens_.data() + tokens_.size() - 1};
  if (has_next && current_[1].type == TOKEN_LEFT_PAREN) return std::nullopt;
  // Consume TOKEN_FUN.
  advance();

  // Property 1: Function name
  expect(TOKEN_IDENTIFIER, "Expecting either a function name for a function declaration or '(' for a lambda");
  const Token* identifier {previous_};

  // Property 2: Type parameters
  std::vector<Token*> type_params {};
  if (match_generic()) {
    if (!check(TOKEN_IDENTIFIER)) errors_.emplace_back(current_, "Expecting a type parameter");
    while (match(TOKEN_IDENTIFIER))
      type_params.emplace_back(previous_);
  }

  // Property 3: Parameters
  expect(TOKEN_LEFT_PAREN, "Expecting '(' to start a parameter list");
  const std::vector params {param_list()};

  // Property 4: Body
  StmtNode body {
    match(TOKEN_EQ)
    ? std::make_shared<Statements::Return>(parse_expression())
    : block_or_statement()
  };

  return std::make_shared<Statements::Function>(identifier, type_params, params, body);
}

// StmtNode Parser::class_declaration() {
//
// }

StmtNode Parser::namespace_declaration() {
  expect(TOKEN_IDENTIFIER, "Expecting a name for this namespace");
  Token* name {previous_};
  match_line();
  expect(TOKEN_INDENT, "Expecting indentation to increase when namespace block begins");

  std::vector<StmtNode> contents {};
  while (!check(TOKEN_DEDENT)) {
    contents.emplace_back(declaration_in_namespace());
    if (!match_line()) break;
  }
  // TODO: This error will be shown if there are two statements on one line. Same issue in block().
  expect(TOKEN_DEDENT, "Expecting indentation to decrease after namespace block ends");

  return std::make_shared<Statements::Namespace>(name, std::move(contents));
}

// StmtNode Parser::using_declaration() {
//
// }

// Type parsing (for declarations) --------------------------------------------------

TypePtr Parser::broad_type() {
  // Check for function type first.
  if (match(TOKEN_LEFT_PAREN)) return function_type();

  if (match(TOKEN_RIGHT_ARROW)) {
    errors_.emplace_back(previous_, "Place empty parentheses for a function type with no parameters");
    return nullptr;
  }

  return standard_type("either a type name or '(' for a function type", true);
}

TypePtr Parser::function_type() {
  std::vector<TypePtr> param_types {};
  do {
    if (check(TOKEN_RIGHT_PAREN)) break;
    param_types.emplace_back(standard_type("a parameter type", true));
  } while (match(TOKEN_COMMA));

  expect(TOKEN_RIGHT_PAREN, "Expecting ')' after parameter list in function type");

  if (match(TOKEN_RIGHT_ARROW)) {
    return std::make_shared<FunctionType>(std::move(param_types), standard_type("a return type", true));
  }
  // Non-returning function.
  return std::make_shared<FunctionType>(std::move(param_types), std::make_shared<NamedType>("Unit"));
}

TypePtr Parser::standard_type(const std::string& thing_to_look_for, bool allow_generics) {
  if (match(TOKEN_LEFT_PAREN)) {
    errors_.emplace_back(
      ParserError {
        previous_,
        "For readability's sake, inside a complex type, you must define other complex types with an alias",
        {nullptr, "How to create an alias: 'using YourAliasName = (...) -> ...'"}
      }
    );
  }

  expect(TOKEN_IDENTIFIER, "Expecting " + thing_to_look_for);
  const std::string name {previous_->src_string};
  TypePtr type {std::make_shared<NamedType>(name)};

  const bool is_optional {match(TOKEN_QUEST)};

  if (match_generic()) {
    if (allow_generics) {
      std::vector<TypePtr> args {};
      do {
        args.emplace_back(standard_type("a type parameter (a type name)", false));
      } while (check(TOKEN_IDENTIFIER));
      type = std::make_shared<AppliedType>(type, std::move(args));
    } else {
      // Generics are not allowed! Oh, no!
      errors_.emplace_back(
        ParserError {
          previous_,
          "For readability's sake, inside a complex type, you must define other complex types with an alias",
          {nullptr, "How to create an alias: 'using YourAliasName = ... for/of ...'"}
        }
      );
    }
  }

  if (is_optional) type = std::make_shared<OptionalType>(type);

  return type;
}

// Other Statements --------------------------------------------------

StmtNode Parser::statement() {
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

StmtNode Parser::if_statement() {
  const ExprNode condition {parse_expression()};
  const StmtNode then_body {block_or_statement()};
  StmtNode else_body {std::make_shared<Statements::Pass>()};
  if (match_after_newlines(TOKEN_ELIF))
    else_body = if_statement();
  else // The final else (if existent) will be handled by the nested/recursed if.
    else_body = optional_else_body();
  return std::make_shared<Statements::If>(condition, then_body, else_body);
}

StmtNode Parser::while_statement() {
  Token* label {loop_label()};
  const ExprNode condition {parse_expression()};
  const StmtNode loop_body {block_or_statement()};
  const StmtNode else_body {optional_else_body()};
  return std::make_shared<Statements::While>(label, condition, loop_body, else_body);
}

StmtNode Parser::each_statement() {
  Token* label {loop_label()};

  expect(TOKEN_IDENTIFIER, "Expecting a loop variable name");
  Token* iter_var {previous_};

  Token* index_var {};
  if (match(TOKEN_LEFT_BRACKET)) {
    expect(TOKEN_IDENTIFIER, "Expecting a loop index variable name");
    index_var = previous_;
    expect(TOKEN_RIGHT_BRACKET, "Expecting ']' after loop index variable");
  }

  expect(TOKEN_IN, "Iterator loops must follow the format: each ___ in ___");

  const ExprNode expr {parse_expression()};
  const StmtNode loop_body {block_or_statement()};
  const StmtNode else_body {optional_else_body()};

  return std::make_shared<Statements::Each>(label, iter_var, index_var, expr, loop_body, else_body);
}

StmtNode Parser::for_statement() {
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

  ParserError context {for_token, "'for' creates a C-style for loop; use 'each' for iteration"};
  expect(TOKEN_SEMICOLON, "Expecting ';' between for loop clauses", context);

  // Only expressions are acceptable for the next two clauses.
  ExprNode condition {std::make_shared<Expressions::Boolean>(true)}; // The default value is true; a "for ;;" loop is an infinite loop.
  if (!check(TOKEN_SEMICOLON)) condition = parse_expression();

  expect(TOKEN_SEMICOLON, "Expecting ';' between for loop clauses");

  ExprNode end {std::make_shared<Expressions::Nil>()};
  if (!check(TOKEN_LINE) && !check(TOKEN_DO)) end = parse_expression();

  const StmtNode loop_body {block_or_statement()};
  const StmtNode else_body {optional_else_body()};

  return std::make_shared<Statements::For>(label, begin, condition, end, loop_body, else_body);
}

StmtNode Parser::break_statement() {
  return std::make_shared<Statements::Break>(loop_label());
}

StmtNode Parser::continue_statement() {
  return std::make_shared<Statements::Continue>(loop_label());
}

StmtNode Parser::return_statement() {
  if (check(TOKEN_LINE) || check(TOKEN_EOF) || check(TOKEN_DEDENT) || check(TOKEN_SEMICOLON))
    return std::make_shared<Statements::Return>(std::make_shared<Expressions::Nil>());
  return std::make_shared<Statements::Return>(parse_expression());
}

StmtNode Parser::block() {
  match_line();
  expect(TOKEN_INDENT, "Expecting indentation to increase when block begins");
  std::vector<StmtNode> contents {};
  while (!check(TOKEN_EOF) && !check(TOKEN_DEDENT)) {
    contents.emplace_back(declaration_or_statement());
    if (!match_line()) break;
  }
  expect(TOKEN_DEDENT, "Expecting indentation to decrease after block ends"); // Users shouldn't see this error if Lexer is doing its job.
  // TODO: The above error will always be paired with the "expecting indentation increase" one, and the EOF check should be unnecessary for the same reason,
  //   so is there anything I can do about that?
  return std::make_shared<Statements::Block>(contents);
}

StmtNode Parser::block_or_statement() {
  if (check(TOKEN_LINE)) return block();
  expect(TOKEN_DO, "Must have either 'do' or newline before statements");
  if (check(TOKEN_LINE)) return block();
  return statement();
}

StmtNode Parser::optional_else_body() {
  if (match_after_newlines(TOKEN_ELSE)) // Won't consume newlines if there isn't an ELSE afterward.
    return block_or_statement();
  return std::make_shared<Statements::Pass>();
}

Token* Parser::loop_label() {
  if (match(TOKEN_COLON)) {
    expect(TOKEN_IDENTIFIER, "Expecting loop label after ':'");
    return previous_;
  }
  return nullptr;
}

std::vector<Param> Parser::param_list() {
  std::vector<Param> params {};
  if (!check(TOKEN_RIGHT_PAREN))
    do {
      if (check(TOKEN_RIGHT_PAREN)) {
        errors_.emplace_back(previous_, "Trailing commas are not allowed");
        break;
      }

      expect(TOKEN_IDENTIFIER, "Expecting a parameter name");
      const auto id {previous_};
      expect(TOKEN_COLON, "Expecting ':' then a parameter type");
      params.emplace_back(id, standard_type("a type for this parameter", true));
    } while (match(TOKEN_COMMA));

  expect(TOKEN_RIGHT_PAREN, "Expecting ')' after parameter list");
  return params;
}

// Expressions --------------------------------------------------

ExprNode Parser::binary_right_assoc(const ExprNode& left) {
  const Precedence prec {static_cast<int>(rules[previous_->type].prec)};
  return std::make_shared<Expressions::Binary>(rules[previous_->type].fn_name, left, parse_expression(prec));
}

ExprNode Parser::binary(const ExprNode& left) {
  const Precedence prec {static_cast<int>(rules[previous_->type].prec) + 1};
  return std::make_shared<Expressions::Binary>(rules[previous_->type].fn_name, left, parse_expression(prec));
}

ExprNode Parser::infix_not(const ExprNode& left) {
  expect(TOKEN_IN, "Cannot use 'not' as an infix operator by itself; try 'not in' or 'is not'", previous_);
  constexpr Precedence prec {static_cast<int>(Precedence::IN) + 1};
  return std::make_shared<Expressions::Binary>("not_in", left, parse_expression(prec));
}

ExprNode Parser::binary_is(const ExprNode& left) {
  constexpr Precedence prec {static_cast<int>(Precedence::IS) + 1};
  if (match(TOKEN_NOT))
    return std::make_shared<Expressions::Binary>("is_not", left, parse_expression(prec));
  return std::make_shared<Expressions::Binary>("is", left, parse_expression(prec));
}

ExprNode Parser::comparison(const ExprNode& left) {
  constexpr Precedence prec {static_cast<int>(Precedence::COMPARISON) + 1};
  std::vector<NamedFunction> comparison_funcs {};
  std::vector operands {left};

  do {
    comparison_funcs.emplace_back(rules[previous_->type].fn_name);
    operands.emplace_back(parse_expression(prec));
  } while (match_precedence(Precedence::COMPARISON));

  return std::make_shared<Expressions::Comparison>(comparison_funcs, operands);
}

ExprNode Parser::if_expr(const ExprNode& left) {
  constexpr Precedence prec {static_cast<int>(Precedence::IF) + 1};
  const ExprNode condition {parse_expression()};
  expect(TOKEN_ELSE, "Expecting else clause in if expression");
  return std::make_shared<Expressions::If>(condition, left, parse_expression(prec));
}

ExprNode Parser::postfix_inc_dec(const ExprNode& expr) {
  warnings_.emplace_back(previous_, "Postfix increment and decrement operators behave as their prefix equivalent; prefer the prefix version");
  return std::make_shared<Expressions::Unary>(rules[previous_->type].fn_name, expr);
}

ExprNode Parser::call(const ExprNode& expr) {
  ParserError start_context {previous_, "To match this one"};
  std::vector<ExprNode> args {};
  // The one error case that comes to mind immediately is an attempted trailing comma.
  if (!check(TOKEN_RIGHT_PAREN))
    do {
      if (check(TOKEN_RIGHT_PAREN)) {
        errors_.emplace_back(previous_, "Trailing commas are not allowed");
        break;
      }
      args.emplace_back(parse_expression());
    } while (match(TOKEN_COMMA));
  expect(TOKEN_RIGHT_PAREN, "Expecting a closing parenthesis", start_context);

  return std::make_shared<Expressions::Call>(expr, args);
}

ExprNode Parser::lambda_call(const ExprNode& expr) {
  return std::make_shared<Expressions::Call>(expr, std::vector {lambda()});
}

ExprNode Parser::subscript(const ExprNode& expr) {
  ParserError start_context {previous_, "To match this one"};
  std::vector<ExprNode> args {};
  if (!check(TOKEN_RIGHT_BRACKET))
    do {
      if (check(TOKEN_RIGHT_BRACKET)) {
        errors_.emplace_back(previous_, "Trailing commas are not allowed");
        break;
      }
      args.emplace_back(parse_expression());
    } while (match(TOKEN_COMMA));
  expect(TOKEN_RIGHT_BRACKET, "Expecting ']' after subscript", start_context);

  return std::make_shared<Expressions::Subscript>(expr, args);
}

ExprNode Parser::member(const ExprNode& expr) {
  const bool safe_access {previous_->type == TOKEN_QUEST_DOT};
  expect(TOKEN_IDENTIFIER, "Expecting a member name");
  return std::make_shared<Expressions::Member>(expr, previous_, safe_access);
}

ExprNode Parser::namespace_member(const ExprNode& expr) {
  if (const auto var_expr {std::dynamic_pointer_cast<Expressions::Variable>(expr)}) {
    expect(TOKEN_IDENTIFIER, "Expecting a namespace member");
    return std::make_shared<Expressions::NamespaceMember>(var_expr->identifier, previous_);
  }
  errors_.emplace_back(previous_, "'::' (namespace access) only works for namespaces");
  return std::make_shared<Expressions::Nil>();
}

ExprNode Parser::unary() {
  return std::make_shared<Expressions::Unary>(rules[previous_->type].fn_name, parse_expression(Precedence::PREFIX));
}

ExprNode Parser::prefix_not() {
  return std::make_shared<Expressions::Unary>("!", parse_expression(Precedence::NOT));
}

ExprNode Parser::print() {
  return std::make_shared<Expressions::Print>(rules[previous_->type].fn_name, parse_expression(Precedence::PRINT));
}

ExprNode Parser::list(ExprNode first_item) {
  std::vector items {std::move(first_item)};

  while (match(TOKEN_COMMA)) {
    if (check(TOKEN_RIGHT_BRACKET)) {
      errors_.emplace_back(previous_, "Trailing commas are not allowed");
      break;
    }
    items.emplace_back(parse_expression());
  }
  expect(TOKEN_RIGHT_BRACKET, "Expecting ']' after list");

  return std::make_shared<Expressions::List>(items);
}

ExprNode Parser::map(const ExprNode& first_item) {
  std::vector<std::string> keys {};
  std::vector<ExprNode> values {};

  // A little helper to handle keys.
  auto validate_key = [&](const ExprNode& key) {
    // A string is valid, but identifiers are the preferred style for readability.
    if (const auto str {std::dynamic_pointer_cast<Expressions::String>(key)}) {
      keys.emplace_back(str->value);
      warnings_.emplace_back(previous_, "It's recommended to use identifiers instead of strings as keys");
      return;
    }

    // String interpolation for keys is not supported yet.
    if (std::dynamic_pointer_cast<Expressions::Interpolation>(key)) {
      errors_.emplace_back(previous_, "String interpolation for keys is not yet supported");
      keys.emplace_back("");
      return;
    }

    if (const auto var {std::dynamic_pointer_cast<Expressions::Variable>(key)}) {
      keys.emplace_back(var->identifier->src_string);
      return;
    }

    errors_.emplace_back(previous_, "Invalid key type", ParserError {"If you're trying to use a reserved word, wrap it in backticks (ex. `class`)"});
  };

  // Step 1: First key (already parsed by collection()) and its value.
  validate_key(first_item);
  match(TOKEN_RIGHT_ARROW); // We already know it exists, just consume it a bit late so validate_key has the right previous_.
  values.emplace_back(parse_expression());

  // Step 2: Parse the rest of the map.
  while (match(TOKEN_COMMA)) {
    if (check(TOKEN_RIGHT_BRACKET)) {
      errors_.emplace_back(previous_, "Trailing commas are not allowed");
      break;
    }

    validate_key(parse_expression());
    expect(TOKEN_RIGHT_ARROW, "Expecting '->' after map key");
    values.emplace_back(parse_expression());
  }

  expect(TOKEN_RIGHT_BRACKET, "Expecting ']' after map");

  return std::make_shared<Expressions::Map>(keys, values);
}

ExprNode Parser::collection() {
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

ExprNode Parser::lambda() {
  // We can reach this point from either a lambda call or a lambda literal.
  // In case of a lambda call, the '{' will already be consumed; in a standard lambda, only 'fun' will be consumed.
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
      match(TOKEN_LEFT_PAREN) ? param_list() : std::vector<Param> {}
    };
    StmtNode body {};

    if (match(TOKEN_EQ)) {
      body = std::make_shared<Statements::Return>(parse_expression());
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
  expect(TOKEN_LEFT_PAREN, "Expecting '(' to start a parameter list");
  std::vector params {param_list()};

  StmtNode body {
    match(TOKEN_EQ)
    ? std::make_shared<Statements::Return>(parse_expression()) // Could be an expression
    : block_or_statement()                                     // or a statement.
  };

  return std::make_shared<Expressions::Lambda>(params, body);
}

ExprNode Parser::string_interpolation() {
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
      errors_.emplace_back("You've found a lexer bug: string interpolation with no ending token—tell this to the developer");
      break;
    }
  } while (match(TOKEN_INTERPOLATION));

  return std::make_shared<Expressions::Interpolation>(start, expressions, end_strings);
}

// ReSharper disable once CppMemberFunctionMayBeConst because it needs to match the PrefixFn signature.
ExprNode Parser::literal() {
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

// ReSharper disable once CppMemberFunctionMayBeConst because it needs to match the PrefixFn signature.
ExprNode Parser::variable() {
  return std::make_shared<Expressions::Variable>(previous_);
}

ExprNode Parser::this_id() {
  return std::make_shared<Expressions::This>(previous_);
}

ExprNode Parser::super_id() {
  return std::make_shared<Expressions::Super>(previous_);
}

ExprNode Parser::grouping() {
  ParserError start_context {previous_, "To match this one"};
  const auto grouping {std::make_shared<Expressions::Grouping>(parse_expression())};
  expect(TOKEN_RIGHT_PAREN, "Expecting a closing parenthesis", start_context);
  return grouping;
}

ExprNode Parser::parse_expression() { return parse_expression(Precedence::BEGIN); }

ExprNode Parser::parse_expression(Precedence precedence) {
  advance();
  const PrefixFn prefix_rule {rules[previous_->type].prefix};
  if (prefix_rule == nullptr) {
    errors_.emplace_back(previous_, "Expecting an expression");
    return nullptr;
  }

  auto expr {(this->*prefix_rule)()};

  while (precedence <= rules[current_->type].prec) {
    advance();
    const InfixFn infix_rule {rules[previous_->type].infix};
    expr = (this->*infix_rule)(expr);
  }

  return expr;
}

// Non-parsing functions --------------------------------------------------

void Parser::populate_token_vec() {
  while (true) {
    const auto next {lexer_.next_token()};
    tokens_.emplace_back(next);
    if (next.type == TOKEN_EOF) break;
  }
  current_ = tokens_.data();
}

void Parser::parse() {
  if (tokens_.empty()) {
    errors_.emplace_back("No tokens to parse");
    return;
  }

  // From the grammar, this is the top level structure:
  // program : newline? (codeItem newline)* codeItem? EOF ;
  match_line();
  while (!check(TOKEN_EOF)) {
    program_.emplace_back(declaration_or_statement());
    if (!match_line()) break;
  }
  expect(TOKEN_EOF, "Expecting newline or EOF after statement");
}

void Parser::output_dot() const {
  if (program_.empty()) {
    std::cerr << "Parser's AST is empty; run parse() before calling\n";
    return;
  }

  if (std::ofstream out {DEBUG_DOT_FILENAME}) {
    out << to_dot(program_) << '\n';
    out.close();
    std::cout << "Parse tree exported to " << DEBUG_DOT_FILENAME << '\n';
  } else {
    std::cerr << "Could not open " << DEBUG_DOT_FILENAME << " to export parse tree\n";
  }
}
