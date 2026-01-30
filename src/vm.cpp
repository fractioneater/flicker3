#include "vm.h"

#include "common.h"

#include <iostream>

#include "lexer.h"

void print_error_prefix(const LexerError& err) {
  // module@line:col (and it's all bold)
  std::cout << "\033[1m" << err.module << "@" << err.line << ":" << err.col << "\033[0m ";
}

// Returns a string_view without newlines on either end.
std::string_view get_line_containing_index(std::string_view source, long char_index) {
  // TODO: Keep thinking how to make errors better. Multi-line errors aren't handled well right now.
  //   And I'd like to have info on the span of the error (start to end instead of just one char).
  //   Of course, I also need color!
  const auto line_start {source.find_last_of('\n', char_index - 1)};
  const auto line_end {source.find('\n', char_index)};
  return source.substr(line_start + 1, line_end - line_start - 1);
}

void print_error(std::string_view source, const LexerError& err) {
  if (err.line == -1)
    // CONSIDER! See the thing in lexer.h, in the LexerError class, about this.
    std::cout << "\033[1m" << err.module << "@EOF\033[0m " << err.what() << '\n';
  else {
    print_error_prefix(err);
    std::cout << err.what() << '\n';
    std::cout << " | " << get_line_containing_index(source, err.char_index) << '\n';
    std::cout << " | " << std::string(err.col - 1, ' ') << "^\n";
  }
}

InterpretResult interpret(const std::string& source, std::string_view module) {
  // TODO: Review std::string/string_view, find out which is better for Lexer constructor.
  Lexer lexer {source};

  std::vector<Token> tokens {};

  try {
    do {
      tokens.push_back(lexer.next_token());
    } while (tokens.back().type != TOKEN_EOF);
  } catch (LexerError& err) {
    std::cout << "Lexer error, compiling halted\n";
    err.module = module;
    print_error(source, err);

    return INTERPRET_COMPILE_ERROR;
  }

  #if DEBUG_PRINT_TOKENS
  for (const auto& token : tokens) {
    if (token.type == TOKEN_EOF)
      std::cout << "EOF: col " << token.col << ", length " << token.length << "\n";
    else if (token.type == TOKEN_IDENTIFIER)
      std::cout << "Identifier '" << source.substr(token.start_char, token.length) << "': " << token.line << ':' << token.col << ", length " << token.length
        << "\n";
    else
      std::cout << "Token: type " << token.type << ", " << token.line << ':' << token.col << ", length " << token.length << "\n";
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
