#include "lexer.h"
#include "common.h"

#include <iostream>
#include <utility>

#define ERROR(str) throw str // TODO: Handle errors better, hopefully remove TOKEN_ERROR. Store all error strings in one file for easy access.

namespace Keywords {
  // The string on the left represents how these keywords should show up in USER CODE.
  // So, for example, if I wanted the "nil" keyword to become "NIL" or "Nil", I'd change it here.
  // I believe keywords should be lowercase because that's what most programmers are used to.
  // Constants (nil, true, false) are usually lowercase, and because they aren't classes, I don't believe they should be Capitalized,
  //   although CAPITALIZED would be okay.
  const std::unordered_map<std::string_view, TokenType> map {
    {"alias", TOKEN_ALIAS},
    // TODO MAYBE: Merge "alias" and "use" into "using"
    {"and", TOKEN_AND},
    {"attribute", TOKEN_ATTRIBUTE},
    {"break", TOKEN_BREAK},
    {"class", TOKEN_CLASS},
    {"continue", TOKEN_CONTINUE},
    {"do", TOKEN_DO},
    {"each", TOKEN_EACH},
    {"elif", TOKEN_ELIF},
    {"else", TOKEN_ELSE},
    {"false", TOKEN_FALSE},
    {"for", TOKEN_FOR},
    {"fun", TOKEN_FUN},
    {"if", TOKEN_IF},
    {"in", TOKEN_IN},
    {"is", TOKEN_IS},
    {"nil", TOKEN_NIL},
    {"not", TOKEN_NOT},
    {"of", TOKEN_OF},
    {"or", TOKEN_OR},
    {"pass", TOKEN_PASS},
    {"print", TOKEN_PRINT},
    {"error", TOKEN_PRINT_ERROR},
    {"return", TOKEN_RETURN},
    {"shl", TOKEN_SHL},
    {"shr", TOKEN_SHR},
    {"static", TOKEN_STATIC},
    {"super", TOKEN_SUPER},
    {"this", TOKEN_THIS},
    {"true", TOKEN_TRUE},
    {"use", TOKEN_USE},
    {"val", TOKEN_VAL},
    {"var", TOKEN_VAR},
    {"when", TOKEN_WHEN},
    {"while", TOKEN_WHILE},
  };
}

Lexer::Lexer(std::string src) : src_ {std::move(src)}, src_length_ {std::ssize(src_)} {
  indents_.emplace_back(0);
  std::cout << "Lexer created\n"; //- TEMP
}

Lexer::~Lexer() {
  std::cerr << src_; //- TEMP
}

// PRIVATE -------------------------------------------------------------------------------
// TODO MAYBE: Use only basic methods as part of the lexer class, turn others into public functions that use the lexer's basic functionality.

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
  advance();
  return true;
}

[[nodiscard]] Token Lexer::make_token(TokenType type) {
  prev_type_       = type;
  const int line   = type == TOKEN_LINE ? line_ - 1 : line_;
  const int length = static_cast<int>(current_char_ - start_char_);
  return Token {type, line, start_char_, start_col_, length};
}

void Lexer::block_comment() {
  // Keep consuming until the closing comment or EOF.
  for (int nest_depth = 1; nest_depth > 0; advance()) {
    if (at_eof())
      ERROR("Unclosed block comment");

    if (peek() == '#') {
      if (peek_next() == ':') {
        advance();
        if (nest_depth++ == MAX_COMMENT_NEST)
          ERROR("Too many nested comments");
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

[[nodiscard]] Token Lexer::backtick_identifier() {
  while (peek() != '`' && !at_eof()) {
    if (peek() == '\n')
      ERROR("Unclosed identifier—even these can't have newlines");
    advance();
  }

  if (at_eof())
    ERROR("Unclosed identifier");

  advance(); // The closing backtick.
  auto token = make_token(TOKEN_IDENTIFIER);
  // Only the stuff within backticks is needed.
  token.start_char++;
  token.length -= 2;

  if (token.length == 0)
    ERROR("Empty identifier");

  return token;
}

[[nodiscard]] Token Lexer::string() {
  ERROR("Strings are not yet supported"); // TODO
}

[[nodiscard]] Token Lexer::character() {
  ERROR("Characters are not yet supported"); // TODO
}

void Lexer::consume_digit_chunk(bool (*is_digit)(char)) {
  while (true) {
    const char c {peek()};

    if (is_digit(c)) {
      advance();
      continue;
    }

    if (c == '_') {
      if (!is_digit(peek_next()))
        ERROR("Underscores must be followed by digits");
      advance(); // The underscore.
      continue;
    }

    break;
  }
}

[[nodiscard]] Token Lexer::hex_number() {
  const auto is_hex_digit = [](char c) {
    return std::isdigit(static_cast<unsigned char>(c)) != 0 || (c <= 'f' && c >= 'a') || (c <= 'F' && c >= 'A');
  };

  if (!is_hex_digit(peek()))
    ERROR("Expected a hex digit after 0x");
  consume_digit_chunk(is_hex_digit);

  return make_token(TOKEN_NUMBER);
}

[[nodiscard]] Token Lexer::binary_number() {
  const auto is_binary_digit = [](char c) { return c == '0' || c == '1'; };

  if (!is_binary_digit(peek()))
    ERROR("Expected a binary digit after 0b");
  consume_digit_chunk(is_binary_digit);

  return make_token(TOKEN_NUMBER);
}

[[nodiscard]] Token Lexer::number() {
  const auto is_digit = [](char c) { return std::isdigit(static_cast<unsigned char>(c)) != 0; };

  // This, number(), is called after a digit is found, so we can consume the rest of them.
  consume_digit_chunk(is_digit);

  // Fractional part.
  // The second clause prevents confusing property access (62.prop) AND trailing decimal points.
  if (peek() == '.' && is_digit(peek_next())) {
    advance(); // Consume the dot.
    consume_digit_chunk(is_digit);
  }

  // Exponent part.
  if (peek() == 'E') {
    advance(); // Consume the E.

    if (peek() == '+' || peek() == '-') advance();

    if (!is_digit(peek()))
      ERROR("Exponent requires a digit");

    consume_digit_chunk(is_digit);
  }

  // TODO: Parse it inside the lexer for coolness.
  return make_token(TOKEN_NUMBER);
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

  // TODO: Indentation, the best part!

  // The main loop, which will really only need to repeat once in most cases. Comments are the only thing that will fail to produce a token or an error.
  while (!at_eof()) {
    start_char_ = current_char_;
    start_col_  = col_;

    switch (const char c {advance()}) {
      // Handled easily here.
      case '(': return make_token(TOKEN_LEFT_PAREN);
      case ')': return make_token(TOKEN_RIGHT_PAREN);
      case '[': return make_token(TOKEN_LEFT_BRACKET);
      case ']': return make_token(TOKEN_RIGHT_BRACKET);
      case '{': return make_token(TOKEN_LEFT_BRACE);
      case '}': return make_token(TOKEN_RIGHT_BRACE);
      case ';': return make_token(TOKEN_SEMICOLON);
      case ',': return make_token(TOKEN_COMMA);
      case '+': return make_token(TOKEN_PLUS);
      case '/': return make_token(TOKEN_SLASH);
      case '%': return make_token(TOKEN_PERCENT);
      case '|': return make_token(TOKEN_PIPE);
      case '^': return make_token(TOKEN_CARET);
      case '&': return make_token(TOKEN_AMPERSAND);
      case '~': return make_token(TOKEN_TILDE);
      case '.': return make_token(match('.') ? (match('<') ? TOKEN_DOT_DOT_LT : TOKEN_DOT_DOT) : TOKEN_DOT);
      case ':': return make_token(match(':') ? TOKEN_COLON_COLON : TOKEN_COLON);
      case '*': return make_token(match('*') ? TOKEN_STAR_STAR : TOKEN_STAR);
      case '-': return make_token(match('>') ? TOKEN_RIGHT_ARROW : TOKEN_MINUS);
      case '!': return make_token(match('=') ? TOKEN_BANG_EQ : TOKEN_BANG);
      case '=': return make_token(match('=') ? TOKEN_EQ_EQ : TOKEN_EQ);
      case '>': return make_token(match('=') ? TOKEN_GT_EQ : TOKEN_GT);
      case '<': return make_token(match('=') ? TOKEN_LT_EQ : TOKEN_LT);
      // Not handled here.
      case '`': return backtick_identifier();
      case '"': return string();
      case '\'': return character();
      case '#':
        line_comment();
        break;
      // Whitespace cases.
      case '\n':
        check_indent_ = true;
        return make_token(TOKEN_LINE);
      case ' ':
      case '\t':
      case '\r':
        while (peek() == ' ' || peek() == '\t' || peek() == '\r') advance();
        break;
      case '0': // Zero-prefixed numbers (custom base)
        if (match('x')) return hex_number();
        if (match('b')) return binary_number();
        return number();
      default:
        if (std::isalpha(static_cast<unsigned char>(c)) != 0) return word();
        if (std::isdigit(static_cast<unsigned char>(c)) != 0) return number();
        ERROR("Unexpected character");
    }
  }

  // It has to be EOF by this point
  start_char_ = current_char_;
  start_col_  = col_;
  return make_token(TOKEN_EOF);
}
