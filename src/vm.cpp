/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "vm.h"

#include "common.h"

#include <fstream>
#include <iostream>

#include "flicker.h"
#include "lexer-adapter.h"
#include "lexer.h"
#include "tree-export.h"

#define COLOR_ERROR 211
#define COLOR_WARNING 221

void print_error(const Lexer& lexer, const LexerError& err, const std::string_view module, bool is_error) {
  const auto [line, col] {lexer.offset_to_line_col(err.offset)};

  std::cout << "\033[38;5;" << (is_error ? COLOR_ERROR : COLOR_WARNING) << "m\033[1m" << module << "@";
  if (line == -1)
    std::cout << "EOF\033[0m " << err.what() << '\n';
  else {
    std::cout << line << ":" << col << "\033[0m " << err.what() << '\n';
    size_t counter {line};
    for (const std::string_view line_str : lexer.offset_range_to_line_strings(err.offset, err.offset + 1)) {
      std::cout << " │ " << line_str << '\n';
      if (counter == line) std::cout << " \u00B7 " << std::string(col - 1, ' ') << "^\n";
      ++counter;
    }
  }
}

class FlickerErrorListener : public antlr4::BaseErrorListener {
  const Lexer& lexer_;
  std::string_view source_ {};
  std::string module_ {};

public:
  FlickerErrorListener(const Lexer& lexer, std::string_view source, std::string module) : lexer_ {lexer}, source_ {source}, module_ {std::move(module)} {}

  void syntaxError(
    antlr4::Recognizer* recognizer, antlr4::Token* offending_symbol, size_t line, size_t char_position_in_line, const std::string& msg, std::exception_ptr e
  ) override {
    const LexerError err {offending_symbol->getStartIndex(), std::string(msg)};
    print_error(lexer_, err, module_, true);
  }
};

InterpretResult interpret(const std::string& source, std::string_view module) {
  Lexer lexer {source};

  antlr::LexerAdapter adapter {lexer, std::string(module)};
  antlr4::CommonTokenStream token_stream {&adapter};
  antlr::flicker parser {&token_stream};

  FlickerErrorListener error_listener {lexer, source, std::string(module)};
  parser.removeErrorListeners();
  parser.addErrorListener(&error_listener);

  token_stream.fill();
  for (const auto& err : lexer.get_errors())
    print_error(lexer, err, module, true);
  for (const auto& err : lexer.get_warnings())
    print_error(lexer, err, module, false);

  if (!lexer.get_errors().empty()) {
    std::cout << "Lexer error, compiling halted\n";
    return INTERPRET_COMPILE_ERROR;
  }

  [[maybe_unused]] auto tree {parser.program()};

  #if DEBUG_PRINT_TOKENS
  for (auto token : token_stream.getTokens()) {
    if (token->getType() == antlr4::Token::EOF) { // EOF:
      std::cout << "EOF: col " << token->getCharPositionInLine() << "\n";
      continue;
    }

    const auto type = token->getType() - 1;
    if (type == TOKEN_IDENTIFIER) { // Identifier:
      std::cout << "Identifier '" << token->getText() << "': " << token->getLine() << ':' << token->getCharPositionInLine() << ", length "
        << token->getText().length() << "\n";
    } else if (type == TOKEN_INDENT) {
      std::cout << "Indent\n";
    } else if (type == TOKEN_DEDENT) {
      std::cout << "Dedent\n";
    } else if (type == TOKEN_LINE) {
      std::cout << "Newline\n";
    } else { // Other:
      std::cout << "Token: type " << type << ", " << token->getLine() << ":" << token->getCharPositionInLine() << ", length "
        << token->getText().length() << "\n";
    }
  }
  #endif

  if (parser.getNumberOfSyntaxErrors() > 0) {
    std::cout << "Parser error, compiling halted\n";
    return INTERPRET_COMPILE_ERROR;
  }

  // Temporarily print things out in a Lisp-like tree.
  // std::cout << tree->toStringTree(&parser) << '\n';

  #if DEBUG_PRINT_DOT
  std::ofstream out {DEBUG_DOT_FILENAME};
  if (out) {
    out << flicker::to_dot(tree, &parser) << '\n';
    out.close();
    std::cout << "Parse tree exported to " << DEBUG_DOT_FILENAME << '\n';
  } else {
    std::cerr << "Could not open " << DEBUG_DOT_FILENAME << " for writing\n";
  }
  #endif

  #if DEBUG_PRINT_CODE
  std::cout << "I'm supposed to print your code after compiling.\n";
  #endif

  #if DEBUG_TRACE_EXECUTION
  std::cout << "I'm supposed to trace execution.\n";
  #endif

  return INTERPRET_OK;
}

InterpretResult interpret_and_print(const std::string& source, std::string_view module) {
  const InterpretResult result = interpret(source, module);

  if (result == INTERPRET_OK)
    std::cout << "= > \n";

  return result;
}
