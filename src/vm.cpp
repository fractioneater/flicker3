#include "vm.h"

#include "common.h"

#include <fstream>
#include <iostream>

#include "flicker.h"
#include "lexer-adapter.h"
#include "lexer.h"
#include "tree-export.h"

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

class FlickerErrorListener : public antlr4::BaseErrorListener {
  std::string_view source_ {};
  std::string module_ {};

public:
  FlickerErrorListener(std::string_view source, std::string module) : source_ {source}, module_ {std::move(module)} {}

  void syntaxError(
    antlr4::Recognizer* recognizer, antlr4::Token* offending_symbol, size_t line, size_t char_position_in_line, const std::string& msg, std::exception_ptr e
  ) override {
    LexerError err {
      static_cast<int>(line),
      static_cast<int>(char_position_in_line),
      offending_symbol ? static_cast<long>(offending_symbol->getStartIndex()) : -1L,
      std::string(msg)
    };
    err.module = module_;
    print_error(source_, err);
  }
};

InterpretResult interpret(const std::string& source, std::string_view module) {
  Lexer lexer {source};

  try {
    antlr::LexerAdapter adapter {lexer, std::string(module)};
    antlr4::CommonTokenStream token_stream {&adapter};
    antlr::flicker parser {&token_stream};

    FlickerErrorListener error_listener {source, std::string(module)};
    parser.removeErrorListeners();
    parser.addErrorListener(&error_listener);

    auto tree {parser.program()};

    #if DEBUG_PRINT_TOKENS
    token_stream.fill();
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
  } catch (LexerError& err) {
    err.module = module;
    print_error(source, err);
    std::cout << "Lexer error, compiling halted\n";

    return INTERPRET_COMPILE_ERROR;
  }

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
