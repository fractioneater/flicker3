/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "parser.h"

#include <iomanip>
#include <iostream>

#include "util.h"

class FlickerErrorListener : public antlr4::BaseErrorListener {
public:
  void syntaxError(
    antlr4::Recognizer* recognizer, antlr4::Token* offending_symbol, size_t line, size_t char_position_in_line, const std::string& msg, std::exception_ptr e
  ) override {
    std::cout << "Error at " << line << ":" << char_position_in_line << ". " << msg << '\n';
  }
};

Parser::Parser(antlr4::CommonTokenStream* token_stream) : antlr_parser_ {token_stream} {}

bool Parser::parse() {
  FlickerErrorListener error_listener {};
  antlr_parser_.removeErrorListeners();
  antlr_parser_.addErrorListener(&error_listener);

  // Run the thing!
  tree_ = antlr_parser_.program();

  return antlr_parser_.getNumberOfSyntaxErrors() == 0;
}

void Parser::output_dot() {
  if (std::ofstream out {DEBUG_DOT_FILENAME}) {
    out << flicker::to_dot(tree_, &antlr_parser_) << '\n';
    out.close();
    std::cout << "Parse tree exported to " << DEBUG_DOT_FILENAME << '\n';
  } else {
    std::cerr << "Could not open " << DEBUG_DOT_FILENAME << " to export parse tree\n";
  }
}
