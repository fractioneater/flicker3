/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "vm.h"

#include <filesystem>
#include <fstream>
#include <iostream>

#include "lexer-adapter.h"
#include "lexer.h"
#include "parser.h"
#include "util.h"

enum InterpretResult {
  INTERPRET_OK, INTERPRET_COMPILE_ERROR, INTERPRET_RUNTIME_ERROR
};

std::string read_entire_file(const char* path) {
  std::ifstream in {path, std::ios::binary};

  if (!in) {
    std::cerr << "Could not open file '" << path << "'\n";
    throw std::system_error(74, std::iostream_category()); // Exit code 74: generic i/o failure.
  }

  in.seekg(0, std::ios::end);
  const std::streampos end_pos = in.tellg();

  if (end_pos >= 0) {
    std::string contents {};
    const auto size = static_cast<std::streamsize>(end_pos);
    if (size == static_cast<std::streamsize>(-1)) {
      std::cerr << "File '" << path << "' is too large\n";
      throw std::system_error(74, std::iostream_category());
    }
    contents.resize(size);

    in.seekg(0, std::ios::beg);
    in.read(contents.data(), size);
    if (!in) {
      std::cerr << "Could not read file '" << path << "'\n";
      throw std::system_error(74, std::iostream_category());
    }

    in.close();
    return contents;
  }

  // Fallback in case seek and tell aren't supported.
  in.clear();
  in.seekg(0, std::ios::beg);
  return std::string {std::istreambuf_iterator(in), std::istreambuf_iterator<char>()};
}

InterpretResult interpret(const std::string& source, std::string_view module) {
  Lexer lexer {source};

  antlr::LexerAdapter adapter {lexer, std::string(module)};
  antlr4::CommonTokenStream token_stream {&adapter};
  Parser parser {&token_stream};

  token_stream.fill();

  #if DEBUG_PRINT_TOKENS
  for (const auto token : token_stream.getTokens()) {
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

  for (const auto& err : lexer.get_errors())
    print_error(lexer, err, module, 0);
  for (const auto& warning : lexer.get_warnings())
    print_error(lexer, warning, module, 1);

  if (!lexer.get_errors().empty()) {
    std::cout << "Lexer error, compiling halted\n";
    return INTERPRET_COMPILE_ERROR;
  }

  const bool parse_success {parser.parse()};

  if (!parse_success) {
    std::cout << "Parser error, compiling halted\n";
    return INTERPRET_COMPILE_ERROR;
  }

  #if DEBUG_PRINT_DOT
  parser.output_dot();
  #endif

  #if DEBUG_PRINT_CODE
  #endif

  #if DEBUG_TRACE_EXECUTION
  #endif

  return INTERPRET_OK;
}

InterpretResult interpret_and_print(const std::string& source, std::string_view module) {
  const InterpretResult result = interpret(source, module);

  if (result == INTERPRET_OK)
    std::cout << "\033[38;5;" << RESULT_COLOR << 'm' << "= > \n" << "\033[0m";

  return result;
}

void repl() {
  constexpr std::string_view prompt {"~ > "};
  std::string line {};
  // Not the cleanest syntax, but this comma expression works to print the "~ >" prompt and then get input.
  while (std::cout << "\033[38;5;" << PROMPT_COLOR << 'm' << prompt << "\033[0m", std::getline(std::cin >> std::ws, line)) {
    interpret_and_print(line, "input");
  }

  // Clear the prompt characters from the last line by printing \b as many times as necessary.
  std::cout << std::string(std::ssize(prompt), '\b');
}

void run_file(const char* path) {
  // Module name
  const std::filesystem::path p {path};
  const std::string module_name {p.stem().string()};
  // Source
  const std::string source {read_entire_file(path)};
  // Blastoff!
  const InterpretResult result {interpret(source, module_name)};

  if (result == INTERPRET_COMPILE_ERROR) throw std::system_error(65, std::generic_category()); // Exit code 65: data format error (compile error).
  if (result == INTERPRET_RUNTIME_ERROR) throw std::system_error(70, std::generic_category()); // Exit code 70: internal software error (runtime error).
}

int main(int argc, const char* argv[]) {
  if (argc == 1) {
    repl();
  } else if (argc == 2) {
    try {
      run_file(argv[1]);
    } catch (const std::system_error& err) {
      return err.code().value();
    }
  } else {
    std::cout << "Usage: flicker [path]\n";
    return 64; // Exit code 64: command-line usage error.
  }

  return 0;
}
