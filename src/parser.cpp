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

// Statements --------------------------------------------------

StmtNode Parser::declaration() {
  return statement();
}

StmtNode Parser::statement() {
  if (match(TOKEN_IF)) return if_statement();
  if (match(TOKEN_WHILE)) return while_statement();
  if (match(TOKEN_PASS)) return std::make_shared<Statements::Pass>();
  // Otherwise, expect an expression statement.
  //   TODO: This creates a weird situation with errors if there's nothing valid here ("Expected an expression" when a statement or expression would be okay)
  return std::make_shared<Statements::Expression>(parse_expression(Precedence::BEGIN));
}

StmtNode Parser::if_statement() {
  const ExprNode condition {parse_expression(Precedence::BEGIN)};
  const StmtNode then_body {block_or_statement()};
  StmtNode else_body {std::make_shared<Statements::Pass>()};

  match_line();
  if (match(TOKEN_ELSE))
    else_body = block_or_statement();
  return std::make_shared<Statements::If>(condition, then_body, else_body);
}

StmtNode Parser::while_statement() {
  const ExprNode condition {parse_expression(Precedence::BEGIN)};
  const StmtNode loop_body {block_or_statement()};
  StmtNode else_body {std::make_shared<Statements::Pass>()};

  match_line();
  if (match(TOKEN_ELSE)) // The while loop's else clause is a weird thing, but it's wonderful. It should be a standard in all languages.
    else_body = block_or_statement();
  return std::make_shared<Statements::While>(condition, loop_body, else_body);
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

// ReSharper disable once CppMemberFunctionMayBeConst
ExprNode Parser::literal() {
  switch (previous_->type) {
    case TOKEN_TRUE: return std::make_shared<Expressions::Literal>(true);
    case TOKEN_FALSE: return std::make_shared<Expressions::Literal>(false);
    case TOKEN_NIL: return std::make_shared<Expressions::Literal>(nullptr);
    case TOKEN_NUMBER:
    case TOKEN_STRING:
    case TOKEN_CHAR: return std::make_shared<Expressions::Literal>(previous_->value);
    default: throw std::logic_error {"unreachable"};
  }
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
    out << to_dot(program_) << '\n';
    out.close();
    std::cout << "Parse tree exported to " << DEBUG_DOT_FILENAME << '\n';
  } else {
    std::cerr << "Could not open " << DEBUG_DOT_FILENAME << " to export parse tree\n";
  }
}
