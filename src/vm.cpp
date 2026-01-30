#include "vm.h"

#include "common.h"

#include <iostream>

#include "lexer.h"

InterpretResult interpret(const std::string& source, std::string_view module) {
  // TODO: Review std::string/string_view, find out which is better for Lexer constructor.
  Lexer lexer {source};

  std::vector<Token> tokens {};

  try {
    do {
      tokens.push_back(lexer.next_token());
    } while (tokens.back().type != TOKEN_EOF);
  } catch (const LexerError& err) {
    std::cout << "Lexer error, compiling halted\n";
    if (err.line == -1)
      // CONSIDER! See the thing in lexer.h, in the LexerError class, about this.
      std::cout << "\033[1m" << module << "@EOF\033[0m " << err.what() << '\n';
    else
      std::cout << "\033[1m" << module << "@" << err.line << ":" << err.col << "\033[0m " << err.what() << '\n';

    return INTERPRET_COMPILE_ERROR;
  }

  #if DEBUG_PRINT_TOKENS
  for (const auto& token : tokens) {
    if (token.type == TOKEN_EOF)
      std::cout << "EOF: col " << token.col << ", length " << token.length << "\n";
    else if (token.type == TOKEN_IDENTIFIER)
      std::cout << "Identifier '" << source.substr(token.start_char, token.length) << "': col " << token.col << ", length " << token.length << "\n";
    else
      std::cout << "Token: type " << token.type << ", col " << token.col << ", length " << token.length << "\n";
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
