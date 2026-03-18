/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "parser.h"

#include <iomanip>
#include <iostream>

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

void Parser::output_dot() {
  if (!tree_) {
    std::cerr << "output_dot() couldn't run. There's no tree. Make sure you're parsing with ANTLR.\n";
    return;
  }

  if (std::ofstream out {DEBUG_DOT_FILENAME}) {
    out << flicker::to_dot(tree_, &antlr_parser_) << '\n';
    out.close();
    std::cout << "Parse tree exported to " << DEBUG_DOT_FILENAME << '\n';
  } else {
    std::cerr << "Could not open " << DEBUG_DOT_FILENAME << " to export parse tree\n";
  }
}

bool Parser::parse_antlr() {
  FlickerErrorListener error_listener {};
  antlr_parser_.removeErrorListeners();
  antlr_parser_.addErrorListener(&error_listener);

  // Run the thing!
  tree_ = antlr_parser_.program();

  return antlr_parser_.getNumberOfSyntaxErrors() == 0;
}

// Non-ANTLR --------------------------------------------------

std::shared_ptr<Expr> Parser::binary() {
  const auto left {parse_expression(Precedence::NONE)};
  const auto right {parse_expression(Precedence::NONE)};
  return std::make_shared<Binary>(previous_, left, right);
}

std::shared_ptr<Expr> Parser::unary() {
  return std::make_shared<Unary>(previous_, parse_expression(Precedence::NONE));
}

std::shared_ptr<Expr> Parser::literal() {
  return std::make_shared<Literal>(320.424);
}

std::shared_ptr<Expr> Parser::grouping() {
  const auto grouping {std::make_shared<Grouping>(parse_expression(Precedence::NONE))};
  expect(TOKEN_RIGHT_PAREN, "Expecting a closing parenthesis");
  return grouping;
}

std::shared_ptr<Expr> Parser::parse_expression(Precedence precedence) {
  advance();
  const ParseFn prefix_rule {rules[previous_.type].prefix};
  if (prefix_rule == nullptr) {
    errors_.emplace_back(previous_, "Expecting an expression");
    return nullptr;
  }

  const auto expr {(this->*prefix_rule)()};

  while (precedence <= rules[current_.type].prec) {
    advance();
    const ParseFn infix_rule {rules[previous_.type].infix};
    (this->*infix_rule)();
  }

  return expr;
}

bool Parser::parse() {
  advance();
  ast_ = parse_expression(Precedence::NONE);
  return true;
}
