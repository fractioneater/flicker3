/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "parser.h"

#include <fstream>
#include <iomanip>
#include <iostream>

#include "util.h"

// Declarations --------------------------------------------------

StmtNode Parser::declaration() {
  if (match(TOKEN_VAL)) return val_declaration();
  if (match(TOKEN_VAR)) return var_declaration();
  return statement();
}

StmtNode Parser::val_declaration() {
  expect(TOKEN_IDENTIFIER, "Expecting a variable name after 'val'");
  const Token* identifier {previous_};

  const TypePtr type {match(TOKEN_COLON) ? parse_type() : nullptr};

  ParserError context {nullptr, "You probably don't want an immutable variable just to hold 'nil'"};
  if (type && type->kind() != TypeKind::OPTIONAL)
    context.add_context({nullptr, "Your type isn't even able to hold 'nil'!"});
  expect(TOKEN_EQ, "Val declarations must have an initializer", context);
  return std::make_shared<Statements::Variable>(false, identifier, type, parse_expression(Precedence::BEGIN));
}

StmtNode Parser::var_declaration() {
  expect(TOKEN_IDENTIFIER, "Expecting a variable name after 'var'");
  const Token* identifier {previous_};
  TypePtr type {};
  ExprNode initializer {std::make_shared<Expressions::Nil>()};

  if (match(TOKEN_COLON)) {
    type = parse_type();
    if (match(TOKEN_EQ)) initializer = parse_expression(Precedence::BEGIN);
    else if (type && type->kind() != TypeKind::OPTIONAL)
      errors_.emplace_back(current_, "Non-optional variable must have an initializer; the default value of 'nil' is not allowed");
  } else {
    expect(TOKEN_EQ, "Var declaration with no type must have an initializer");
    initializer = parse_expression(Precedence::BEGIN);
  }
  return std::make_shared<Statements::Variable>(true, identifier, type, initializer);
}

TypePtr Parser::parse_type() {
  // Check for function type first.
  if (match(TOKEN_LEFT_PAREN)) return function_type();

  if (match(TOKEN_RIGHT_ARROW)) {
    errors_.emplace_back(previous_, "Place empty parentheses for a function type with no parameters");
    return nullptr;
  }

  expect(TOKEN_IDENTIFIER, "Expecting either a type name or '(' for a function type");
  const std::string name {lexer_.token_to_string(*previous_)};
  const bool is_optional {match(TOKEN_QUEST)};
  TypePtr type {std::make_shared<NamedType>(name)};

  if (match(TOKEN_FOR) || match(TOKEN_OF)) {
    std::vector<TypePtr> args {};
    do {
      args.emplace_back(basic_type("a type parameter (a type name)"));
    } while (match(TOKEN_COMMA));
    type = std::make_shared<AppliedType>(type, std::move(args));
  }

  if (is_optional) type = std::make_shared<OptionalType>(type);

  return type;
}

TypePtr Parser::function_type() {
  std::vector<TypePtr> param_types {};
  do {
    if (check(TOKEN_RIGHT_PAREN)) break;
    param_types.emplace_back(basic_type("a parameter type"));
  } while (match(TOKEN_COMMA));

  expect(TOKEN_RIGHT_PAREN, "Expecting ')' after parameter list in function type");

  if (match(TOKEN_RIGHT_ARROW)) {
    return std::make_shared<FunctionType>(std::move(param_types), basic_type("a return type"));
  }
  // Non-returning function.
  return std::make_shared<FunctionType>(std::move(param_types), std::make_shared<NamedType>("Unit"));
}

TypePtr Parser::basic_type(const std::string& thing_to_look_for) {
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
  const std::string name {lexer_.token_to_string(*previous_)};
  TypePtr type {std::make_shared<NamedType>(name)};

  if (match(TOKEN_QUEST)) return std::make_shared<OptionalType>(type);

  if (match(TOKEN_OF) || match(TOKEN_FOR))
    errors_.emplace_back(
      ParserError {
        previous_,
        "For readability's sake, inside a complex type, you must define other complex types with an alias",
        {nullptr, "How to create an alias: 'using YourAliasName = ... for/of ...'"}
      }
    );

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
  return std::make_shared<Statements::Expression>(parse_expression(Precedence::BEGIN));
}

StmtNode Parser::if_statement() {
  const ExprNode condition {parse_expression(Precedence::BEGIN)};
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
  const ExprNode condition {parse_expression(Precedence::BEGIN)};
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

  const ExprNode expr {parse_expression(Precedence::BEGIN)};
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
        : std::make_shared<Statements::Expression>(parse_expression(Precedence::BEGIN))
  };

  ParserError context {for_token, "'for' creates a C-style for loop; use 'each' for iteration"};
  expect(TOKEN_SEMICOLON, "Expecting ';' between for loop clauses", context);

  // Only expressions are acceptable for the next two clauses.
  ExprNode condition {std::make_shared<Expressions::Boolean>(true)}; // The default value is true; a "for ;;" loop is an infinite loop.
  if (!check(TOKEN_SEMICOLON)) condition = parse_expression(Precedence::BEGIN);

  expect(TOKEN_SEMICOLON, "Expecting ';' between for loop clauses");

  ExprNode end {std::make_shared<Expressions::Nil>()};
  if (!check(TOKEN_LINE) && !check(TOKEN_DO)) end = parse_expression(Precedence::BEGIN);

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
  if (check(TOKEN_LINE) || check(TOKEN_EOF) || check(TOKEN_DEDENT))
    return std::make_shared<Statements::Return>(std::make_shared<Expressions::Nil>());
  return std::make_shared<Statements::Return>(parse_expression(Precedence::BEGIN));
}

StmtNode Parser::block() {
  expect_line("Place a newline before beginning a block");
  expect(TOKEN_INDENT, "Expecting indentation to increase when block begins");
  std::vector<StmtNode> contents {};
  while (!check(TOKEN_EOF) && !check(TOKEN_DEDENT)) {
    contents.emplace_back(declaration());
    if (!match_line()) break;
  }
  expect(TOKEN_DEDENT, "Expecting indentation to decrease after block ends"); // Users shouldn't see this error if Lexer is doing its job.
  // TODO: The above error will always be paired with the "expecting indentation increase" one, and the EOF check should be unnecessary for the same reason,
  //   so is there anything I can do about that?
  return std::make_shared<Statements::Block>(contents);
}

StmtNode Parser::block_or_statement() {
  if (check(TOKEN_LINE)) return block();
  expect(TOKEN_DO, "Must have either 'do' or newline between condition and statement");
  if (check(TOKEN_LINE)) return block();
  return statement();
}

StmtNode Parser::optional_else_body() {
  if (match_after_newlines(TOKEN_ELSE)) // Won't consume newlines if there isn't an ELSE afterward
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

ExprNode Parser::unary() {
  return std::make_shared<Expressions::Unary>(rules[previous_->type].fn_name, parse_expression(Precedence::PREFIX));
}

ExprNode Parser::prefix_not() {
  return std::make_shared<Expressions::Unary>("!", parse_expression(Precedence::NOT));
}

ExprNode Parser::print() {
  return std::make_shared<Expressions::Print>(rules[previous_->type].fn_name, parse_expression(Precedence::PRINT));
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

ExprNode Parser::grouping() {
  ParserError start_context {previous_, "To match this one"};
  const auto grouping {std::make_shared<Expressions::Grouping>(parse_expression(Precedence::BEGIN))};
  expect(TOKEN_RIGHT_PAREN, "Expecting a closing parenthesis", start_context);
  return grouping;
}

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
    program_.emplace_back(declaration());
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
    out << to_dot(program_, lexer_) << '\n';
    out.close();
    std::cout << "Parse tree exported to " << DEBUG_DOT_FILENAME << '\n';
  } else {
    std::cerr << "Could not open " << DEBUG_DOT_FILENAME << " to export parse tree\n";
  }
}
