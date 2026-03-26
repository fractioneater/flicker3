/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "parser.h"

#include <iomanip>
#include <iostream>

#include "flicker.h"
#include "util.h"

// ANTLR --------------------------------------------------

class FlickerErrorListener : public antlr4::BaseErrorListener {
public:
  void syntaxError(
    antlr4::Recognizer* recognizer, antlr4::Token* offending_symbol, size_t line, size_t char_position_in_line, const std::string& msg, std::exception_ptr e
  ) override {
    std::cout << "Error at " << line << ":" << char_position_in_line << ". " << msg << '\n';
  }
};

// If you're trying to get output_dot for ANTLR, you'll need to revert the util file back to the previous version (before 3/19/2026).
// void Parser::output_dot(antlr4::tree::ParseTree* tree) {
//   if (std::ofstream out {DEBUG_DOT_FILENAME}) {
//     out << to_dot(tree, &antlr_parser_) << '\n';
//     out.close();
//     std::cout << "Parse tree exported to " << DEBUG_DOT_FILENAME << '\n';
//   } else {
//     std::cerr << "Could not open " << DEBUG_DOT_FILENAME << " to export parse tree\n";
//   }
// }

antlr::flicker::ProgramContext* Parser::parse_antlr() {
  FlickerErrorListener error_listener {};
  antlr_parser_.removeErrorListeners();
  antlr_parser_.addErrorListener(&error_listener);

  // Run the thing!
  return antlr_parser_.program();
}

// Non-ANTLR --------------------------------------------------

ExprNode Parser::binary_right_assoc(const ExprNode& left) {
  const Precedence prec {static_cast<int>(rules[previous_->type].prec)};
  return std::make_shared<Expressions::Binary>(*previous_, rules[previous_->type].fn_name, left, parse_expression(prec));
}

ExprNode Parser::binary(const ExprNode& left) {
  const Precedence prec {static_cast<int>(rules[previous_->type].prec) + 1};
  return std::make_shared<Expressions::Binary>(*previous_, rules[previous_->type].fn_name, left, parse_expression(prec));
}

ExprNode Parser::infix_not(const ExprNode& left) {
  expect(TOKEN_IN, "Cannot use 'not' as an infix operator by itself; try 'not in' or 'is not'", previous_);
  constexpr Precedence prec {static_cast<int>(Precedence::IN) + 1};
  return std::make_shared<Expressions::Binary>(*(previous_ - 1), "not_in", left, parse_expression(prec));
}

ExprNode Parser::binary_is(const ExprNode& left) {
  constexpr Precedence prec {static_cast<int>(Precedence::IS) + 1};
  if (match(TOKEN_NOT))
    return std::make_shared<Expressions::Binary>(*(previous_ - 1), "is_not", left, parse_expression(prec));
  return std::make_shared<Expressions::Binary>(*previous_, "is", left, parse_expression(prec));
}

ExprNode Parser::unary() {
  return std::make_shared<Expressions::Unary>(*previous_, rules[previous_->type].fn_name, parse_expression(Precedence::PREFIX));
}

ExprNode Parser::prefix_not() {
  return std::make_shared<Expressions::Unary>(*previous_, "!", parse_expression(Precedence::NOT));
}

ExprNode Parser::print() {
  return std::make_shared<Expressions::Print>(*previous_, rules[previous_->type].fn_name, parse_expression(Precedence::PRINT));
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
  ast_ = parse_expression(Precedence::BEGIN);
}

void Parser::output_dot() const {
  if (!ast_) {
    std::cerr << "Parser's ast_ is nullptr; run parse() before calling\n";
    return;
  }

  if (std::ofstream out {DEBUG_DOT_FILENAME}) {
    out << to_dot(ast_) << '\n';
    out.close();
    std::cout << "Parse tree exported to " << DEBUG_DOT_FILENAME << '\n';
  } else {
    std::cerr << "Could not open " << DEBUG_DOT_FILENAME << " to export parse tree\n";
  }
}
