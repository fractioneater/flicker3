#include "lexer.h"
#include "common.h"

#include <iostream>
#include <utility>

#define ERROR(str) throw str // TODO: Handle errors better, hopefully remove TOKEN_ERROR. Store all error strings in one file for easy access.

Lexer::Lexer(std::string src) : src_ {std::move(src)}, src_length_ {std::ssize(src_)} {
  indents_.emplace_back(0);
  std::cout << "Lexer created\n"; //- TEMP
}

Lexer::~Lexer() {
  std::cerr << src_; //- TEMP
}

// PRIVATE -------------------------------------------------------------------------------

[[nodiscard]] bool Lexer::at_eof() const { return current_char_ >= src_length_; }

[[nodiscard]] char Lexer::peek() const {
  if (at_eof()) return '\0';
  return src_[current_char_];
}

[[nodiscard]] char Lexer::peek_next() const {
  if (current_char_ + 1 >= src_length_) return '\0';
  return src_[current_char_ + 1];
}

char Lexer::advance() {
  ++current_char_;
  ++col_;
  if (src_[current_char_ - 1] == '\n') {
    ++line_;
    col_ = 1;
  }
  return src_[current_char_ - 1];
}

bool Lexer::match(char expected) {
  if (at_eof()) return false;
  if (src_[current_char_] != expected) return false;
  ++current_char_;
  return true;
}

[[nodiscard]] Token Lexer::make_token(TokenType type) {
  prev_type_       = type;
  const int line   = type == TOKEN_LINE ? line_ - 1 : line_;
  const int length = current_char_ - start_char_;
  return Token {type, line, start_char_, start_col_, length};
}

void Lexer::block_comment() {
  // Keep consuming until the closing comment or EOF.
  for (int nest_depth = 1; nest_depth > 0; advance()) {
    if (at_eof())
      ERROR("Unclosed block comment.");

    if (peek() == '#') {
      if (peek_next() == ':') {
        advance();
        if (nest_depth++ == MAX_COMMENT_NEST)
          ERROR("Too many nested comments.");
      } else --nest_depth;
    }
  }
}

void Lexer::line_comment() {
  if (peek() == ':') block_comment();
  else {
    while (peek() != '\n' && !at_eof()) advance();
  }
}

bool is_alphanumeric(char c) {
  // Apparently it's good to cast it to unsigned char because isalnum() assumes it can go up to 255.
  return std::isalnum(static_cast<unsigned char>(c)) != 0 || c == '_';
}

TokenType word_type(std::string_view word) {
  // This namespace that holds the map is in lexer.h.
  const auto found {Keywords::map.find(word)};
  if (found != Keywords::map.end())
    return found->second; // Return the associated TokenType.

  // Then return IDENTIFIER if it's not a reserved word.
  return TOKEN_IDENTIFIER;
}

[[nodiscard]] Token Lexer::word() {
  while (is_alphanumeric(peek())) advance();
  const std::string_view word {static_cast<std::string_view>(src_).substr(start_char_, current_char_ - start_char_)};
  return make_token(word_type(word));
}

// PUBLIC --------------------------------------------------------------------------------

[[nodiscard]] Token Lexer::next_token() {
  // Top priority is to return dedents if more are called for.
  if (dedents_queued_ > 0) {
    --dedents_queued_;
    return make_token(TOKEN_DEDENT);
  }

  // Keep returning EOFs once we reach the end of the source.
  if (at_eof()) return make_token(TOKEN_EOF);

  const TokenType type = TOKEN_IDENTIFIER;
  prev_type_           = type;
  return make_token(type);
}
