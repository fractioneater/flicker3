#include "lexer.h"

#include <iostream>

class Lexer {
  const std::string& src_ {};

public:
  explicit Lexer(const std::string& src) : src_ {src} {}

  ~Lexer() {
    std::cout << src_;
  }

  [[nodiscard]] Token next_token() const {
    return Token {TOKEN_IDENTIFIER, static_cast<int>(std::size(src_))};
  }
};
