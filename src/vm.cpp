#include "vm.h"

#include "common.h"

#include <iostream>

#include "lexer.h"

InterpretResult interpret(const std::string& source, std::string_view module) {
  std::cout << "Your module is named " << module << ".\n";

  // TODO: Review std::string/string_view, find out which is better for Lexer constructor.
  Lexer lexer {source};

  std::vector<Token> tokens {};

  do {
    tokens.push_back(lexer.next_token());
  } while (tokens.back().type != TOKEN_EOF);

  #if DEBUG_PRINT_TOKENS
  for (const auto& token : tokens) {
    if (token.type == TOKEN_EOF)
      std::cout << "EOF: col " << token.col << ", length " << token.length << "\n";
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

  std::cout << "= >\n";

  return result;
}
