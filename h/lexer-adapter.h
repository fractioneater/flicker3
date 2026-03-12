// This file is not licensed because it was...
// - written by AI
// - not intended to work
// - probably not good code
// And it is going to be deleted as soon as possible.

#pragma once

#include <memory>

#include "antlr4-runtime.h"
#include "lexer.h"

namespace antlr {
  /**
   * A LexerAdapter that connects the handwritten Lexer with ANTLR4-generated parser.
   * It implements antlr4::TokenSource by wrapping a Lexer instance.
   */
  class LexerAdapter : public antlr4::TokenSource {
  public:
    explicit LexerAdapter(Lexer& lexer, std::string source_name = "<inline>")
      : lexer_(lexer), source_name_(std::move(source_name)), factory_(antlr4::CommonTokenFactory::DEFAULT.get()) {}

    std::unique_ptr<antlr4::Token> nextToken() override {
      try {
        const Token flicker_token = lexer_.next_token();

        size_t type {};
        if (flicker_token.type == TOKEN_EOF) {
          type = antlr4::Token::EOF;
        } else {
          // Mapping: TOKEN_LEFT_PAREN (0) -> flicker::LEFT_PAREN (1)
          // The order in lexer.h matches flicker.g4, and flicker.h confirms the IDs.
          type = static_cast<size_t>(flicker_token.type) + 1;
        }

        // We need to create an antlr4::Token.
        // The factory takes (source, type, text, channel, start, stop, line, charPositionInLine)
        // Note: start and stop are absolute character indices.
        // flickerToken.start_char is the start. flickerToken.length is the length.
        // stop index in ANTLR is inclusive.

        const auto start = static_cast<size_t>(flicker_token.start_offset);
        size_t stop;
        if (type == antlr4::Token::EOF) {
          stop = start;
        } else {
          stop = start + static_cast<size_t>(flicker_token.length) - 1;
        }

        // Extract text from the lexer source
        std::string text;
        if (type != antlr4::Token::EOF) {
          text = lexer_.get_src().substr(start, flicker_token.length);
        }

        auto [line, col] {lexer_.offset_to_line_col(start)};

        auto token = factory_->create(
          {this, nullptr},
          type,
          text,
          antlr4::Token::DEFAULT_CHANNEL,
          start,
          stop,
          line, col
        );

        return token;
      } catch (const LexerError&) {
        // LexerError doesn't inherit from std::exception, but we can still catch it.
        // We can wrap it or just let it propagate if the caller expects it.
        throw;
      }
    }

    std::string getSourceName() override {
      return source_name_;
    }

    size_t getLine() const override {
      // Return the line of the last token emitted, if any.
      return last_line_;
    }

    size_t getCharPositionInLine() override {
      return last_col_;
    }

    antlr4::TokenFactory<antlr4::CommonToken>* getTokenFactory() override {
      return factory_;
    }

    void setTokenFactory(antlr4::TokenFactory<antlr4::CommonToken>* factory) {
      factory_ = factory;
    }

    antlr4::CharStream* getInputStream() override {
      return nullptr; // Our Lexer doesn't use antlr4::CharStream
    }

  private:
    Lexer& lexer_;
    std::string source_name_;
    antlr4::TokenFactory<antlr4::CommonToken>* factory_;
    size_t last_line_ {1};
    size_t last_col_ {0};
  };
} // namespace antlr
