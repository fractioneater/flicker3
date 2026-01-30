#include "lexer.h"
#include "common.h"

#include <iostream>
#include <utility>

// TODO: Store all error strings in one file for easy access.

namespace Keywords {
  // The string on the left represents how these keywords should show up in USER CODE.
  // So, for example, if I wanted the "nil" keyword to become "NIL" or "Nil", I'd change it here.
  // I believe keywords should be lowercase because that's what most programmers are used to.
  // Constants (nil, true, false) are usually lowercase, and because they aren't classes, I don't believe they should be Capitalized,
  //   although CAPITALIZED would be okay.
  const std::unordered_map<std::string_view, TokenType> map {
    {"alias", TOKEN_ALIAS},
    // CONSIDER! Merge "alias" and "use" into "using"
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
}

Lexer::~Lexer() = default;

// PRIVATE -------------------------------------------------------------------------------

// CONSIDER! Use only basic methods as part of the lexer class, turn others into public functions that use the lexer's basic functionality.

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
    // Hopefully, when this is called, we shouldn't be at the point where we need to check for indentation again.
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
      throw LexerError {"Unclosed block comment"};

    if (peek() == '#') {
      if (peek_next() == ':') {
        advance();
        if (nest_depth++ == MAX_COMMENT_NEST)
          throw LexerError {line_, col_, current_char_, "Too many nested comments"};
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
      throw LexerError {line_, col_, current_char_, "Unclosed identifier—even these can't have newlines"};
    advance();
  }

  if (at_eof())
    throw LexerError {"Unclosed identifier"};

  advance(); // The closing backtick.
  auto token = make_token(TOKEN_IDENTIFIER);
  // Only the stuff within backticks is needed.
  token.start_char++;
  token.length -= 2;

  if (token.length == 0)
    throw LexerError {line_, col_, current_char_, "Empty identifier"};

  return token;
}

int hex_value(char c) {
  if (c >= '0' && c <= '9') return c - '0';
  if (c >= 'a' && c <= 'f') return c - 'a' + 10;
  if (c >= 'A' && c <= 'F') return c - 'A' + 10;
  return -1;
}

[[nodiscard]] std::uint32_t Lexer::read_hex(int length) {
  std::uint32_t value = 0;
  for (int i = 0; i < length; ++i) {
    if (at_eof())
      throw LexerError {"Unterminated escape sequence"};

    const char c {advance()};
    const int digit = hex_value(c);
    if (digit == -1)
      throw LexerError {line_, col_, current_char_, "Unterminated escape sequence"};

    value = (value << 4) | static_cast<std::uint32_t>(digit);
  }
  return value;
}

void Lexer::append_utf8(std::string& buffer, std::uint32_t code_point) const {
  if (code_point > 0x10FFFFu)
    throw LexerError {line_, col_, current_char_, "Invalid Unicode code point"};
  if (code_point >= 0xD800u && code_point <= 0xDFFFu)
    throw LexerError {line_, col_, current_char_, "Invalid Unicode surrogate"};

  if (code_point <= 0x7Fu) {
    // One byte.
    buffer.push_back(static_cast<char>(code_point));
  } else if (code_point <= 0x7FFu) {
    // Two bytes: 110xxxxx 10xxxxxx.
    buffer.push_back(static_cast<char>(0xC0u | (code_point >> 6)));
    buffer.push_back(static_cast<char>(0x80u | (code_point & 0x3Fu)));
  } else if (code_point <= 0xFFFFu) {
    // Three bytes: 1110xxxx 10xxxxxx 10xxxxxx.
    buffer.push_back(static_cast<char>(0xE0u | (code_point >> 12)));
    buffer.push_back(static_cast<char>(0x80u | ((code_point >> 6) & 0x3Fu)));
    buffer.push_back(static_cast<char>(0x80u | (code_point & 0x3Fu)));
  } else {
    // Four bytes: 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx.
    buffer.push_back(static_cast<char>(0xF0u | (code_point >> 18)));
    buffer.push_back(static_cast<char>(0x80u | ((code_point >> 12) & 0x3Fu)));
    buffer.push_back(static_cast<char>(0x80u | ((code_point >> 6) & 0x3Fu)));
    buffer.push_back(static_cast<char>(0x80u | (code_point & 0x3Fu)));
  }
}

[[nodiscard]] Token Lexer::string() {
  // An interpolation token means the start of interpolation; it will have values in between and then a TOKEN_STRING to close it.
  // The type is a string unless interpolation is found.
  TokenType type {TOKEN_STRING};
  std::string buffer {};
  // This estimate will usually create one more than the estimate value, but that's okay.
  const auto found_index {src_.find('"', current_char_)};
  if (found_index == std::string::npos)
    throw LexerError {"Unterminated string"};
  buffer.reserve(found_index - start_char_);

  while (true) {
    const char c {advance()};
    if (c == '"') break;
    if (c == '\r') continue; // TODO: Why am I removing these?
    if (at_eof())
      throw LexerError {"Unterminated string"};

    // String interpolation, which looks like this: "abc =(thing)"
    if (c == '=' && peek() == '(') {
      if (interpolation_nesting_ < MAX_INTERPOLATION_NEST) {
        advance(); // The parenthesis.
        type = TOKEN_INTERPOLATION;
        // When we find a closing parenthesis, we need to know it's THE closing parenthesis.
        // This list stores the current parenthesis nesting for each level of interpolation to handle things like this:
        //   "hello, world with a population of =(20 * (i + 3))!"
        parens_[interpolation_nesting_++] = 1;
        break;
      }

      throw LexerError {line_, col_, current_char_, "Too many nested strings"};
    }

    // @formatter:off because it doesn't like two statements on one line.
    if (c == '\\') {
      switch (advance()) {
        case '\\': buffer.push_back('\\'); break;
        case '"': buffer.push_back('"'); break;
        case '=': buffer.push_back('='); break;
        case '0': buffer.push_back('\0'); break;
        case 'a': buffer.push_back('\a'); break;
        case 'b': buffer.push_back('\b'); break;
        case 'e': buffer.push_back('\033'); break;
        case 'f': buffer.push_back('\f'); break;
        case 'n': buffer.push_back('\n'); break;
        case 'r': buffer.push_back('\r'); break;
        case 't': buffer.push_back('\t'); break;
        case 'u': {
          const std::uint32_t code_point {read_hex(4)};
          append_utf8(buffer, code_point);
          break;
        }
        case 'U': {
          const std::uint32_t code_point {read_hex(8)};
          append_utf8(buffer, code_point);
          break;
        }
        case 'v': buffer.push_back('\v'); break;
        case 'x': {
          const std::uint32_t byte {read_hex(2)};
          buffer.push_back(static_cast<char>(byte));
          break;
        }
        default: throw LexerError {line_, col_ - 1, current_char_ - 1, "Invalid escape character"};
      }
    } else {
      buffer.push_back(c);
    }
  }
  // @formatter:on again

  return make_token(type);
}

[[nodiscard]] Token Lexer::character() {
  [[maybe_unused]] char value {}; //- TEMP (maybe_unused for -Werror)
  const char c {advance()};

  if (c == '\'')
    throw LexerError {line_, col_, current_char_, "Empty characters are not allowed"};

  // @formatter:off
  if (c == '\\') {
    switch (advance()) {
      case '\\': value = '\\'; break;
      case '\'': value = '\''; break;
      case '0': value = '\0'; break;
      case 'a': value = '\a'; break;
      case 'b': value = '\b'; break;
      case 'e': value = '\033'; break;
      case 'f': value = '\f'; break;
      case 'n': value = '\n'; break;
      case 'r': value = '\r'; break;
      case 't': value = '\t'; break;
      case 'v': value = '\v'; break;
      // CONSIDER! Store a character as a char32_t, allowing longer Unicode code points.
      case 'x': value = static_cast<char>(read_hex(2)); break;
      default: throw LexerError {line_, col_ - 1, current_char_ - 1, "Invalid escape character"};
    }
  } else value = c;
  // @formatter:on

  if (!match('\''))
    throw LexerError {line_, col_, current_char_, "Character is unterminated or more than one char"};

  return make_token(TOKEN_CHAR);
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
        throw LexerError {line_, col_, current_char_, "Underscores must be followed by digits"};
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
    throw LexerError {line_, col_, current_char_, "Expected a hex digit after 0x"};
  consume_digit_chunk(is_hex_digit);

  if (!is_hex_digit(peek()) && std::isalpha(static_cast<unsigned char>(peek())) != 0) {
    const LexerWarning warning {line_, col_, current_char_, "Character appears to be part of the number, but is actually not"};
    warnings_.emplace_back(warning);
  }

  return make_token(TOKEN_NUMBER);
}

[[nodiscard]] Token Lexer::binary_number() {
  const auto is_binary_digit = [](char c) { return c == '0' || c == '1'; };

  if (!is_binary_digit(peek()))
    throw LexerError {line_, col_, current_char_, "Expected a binary digit after 0b"};
  consume_digit_chunk(is_binary_digit);

  if (!is_binary_digit(peek()) && std::isalnum(static_cast<unsigned char>(peek())) != 0) {
    const LexerWarning warning {line_, col_, current_char_, "Character appears to be part of the number, but is actually not"};
    warnings_.emplace_back(warning);
  }

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
      throw LexerError {line_, col_, current_char_, "Exponent requires a digit"};

    consume_digit_chunk(is_digit);
  }

  if (!is_digit(peek()) && std::isalpha(static_cast<unsigned char>(peek())) != 0) {
    const LexerWarning warning {line_, col_, current_char_, "Character appears to be part of the number, but is actually not"};
    warnings_.emplace_back(warning);
  }

  // TODO: Parse it inside the lexer for coolness.
  return make_token(TOKEN_NUMBER);
}

// This function will only be called at the start of a line.
std::optional<Token> Lexer::indentation() {
  // Loop through characters until something significant (not whitespace or comment) is found.
  while (true) {
    switch (peek()) {
      case '\0': return std::nullopt; // EOF, no need to report this indentation.

      case ' ': // Whitespace character
      case '\r': // Whitespace character
      case '\n': // This line was whitespace or comments only. Try again on the next line.
        advance();
        continue;

      case '\t': throw LexerError {line_, col_, current_char_, "Tabs are not allowed in indentation"};

      case '#': {
        advance();
        if (peek() == ':') {
          const LexerWarning warning {line_, col_ - 1, current_char_ - 1, "Consider moving this comment to the end of the line"};
          warnings_.emplace_back(warning);
          block_comment(); // May cross lines; the ending column is what matters.
        } else {
          while (peek() != '\n' && !at_eof()) advance();
        }
        continue; // Keep processing stuff after a block comment.
      }

      default: ; // Break from here, which in turn breaks from the loop.
    }
    break;
  }

  const int indent {col_ - 1};

  if (indent > indents_.back()) { // If it's an indentation...
    // We'll return an indent token, so we don't need to keep looking.
    check_indent_ = false;

    indents_.push_back(indent);
    return make_token(TOKEN_INDENT);
  }

  bool had_a_dedent {false};
  while (indent < indents_.back()) { // If there are dedents...
    had_a_dedent = true;

    ++dedents_queued_;
    indents_.pop_back(); // Check again with a new, more shallow indent.

    // So, um, this really shouldn't be happening. Because, you know, it would mean... it would mean the indentation level was less than zero.
    if (indents_.empty())
      throw LexerError {line_, col_, current_char_, "AAAAH"};
  }

  if (had_a_dedent) {
    if (indent != indents_.back()) {
      dedents_queued_ = 0;
      throw LexerError {line_, col_, current_char_, "Indentation does not match any previous line"};
    }
    --dedents_queued_;
    return make_token(TOKEN_DEDENT);
  }

  // We're not at the start of a line anymore.
  check_indent_ = false;
  return std::nullopt;
}

[[nodiscard]] Token Lexer::eof() {
  start_char_ = current_char_;
  start_col_  = col_;
  // Create dedents at EOF: emit one now and queue the rest.
  // The indents list should still hold the original 0.
  const int open_blocks {static_cast<int>(indents_.size()) - 1};
  if (open_blocks > 0) {
    indents_.resize(1);
    // Minus one for the one we're creating right now.
    dedents_queued_ += open_blocks - 1;
    return make_token(TOKEN_DEDENT);
  }
  return make_token(TOKEN_EOF);
}

// PUBLIC --------------------------------------------------------------------------------

[[nodiscard]] Token Lexer::next_token() {
  start_char_ = current_char_;
  start_col_  = col_;

  // Top priority is to return dedents if more are called for.
  if (dedents_queued_ > 0) {
    --dedents_queued_;
    return make_token(TOKEN_DEDENT);
  }

  if (check_indent_) {
    if (const auto token {indentation()})
      return *token;
    check_indent_ = false;
  }

  // Keep returning EOFs once we reach the end of the source.
  if (at_eof()) return eof();

  // The main loop, which will really only need to repeat once in most cases. Whitespace (including comments) is the only thing that will fail to produce a
  // token or an error.
  do {
    start_char_ = current_char_;
    start_col_  = col_;

    switch (const char c {advance()}) {
      // Special rules because of string interpolation.
      case '(': {
        // Increment the number of open parentheses inside the innermost nested interpolation.
        if (interpolation_nesting_ > 0) parens_[interpolation_nesting_ - 1]++;
        return make_token(TOKEN_LEFT_PAREN);
      }
      case ')': {
        // Close the most recently opened parenthesis, and if we're out of the interpolation, continue the string.
        if (interpolation_nesting_ > 0 && --parens_[interpolation_nesting_ - 1] == 0) {
          --interpolation_nesting_;
          return string();
        }
        return make_token(TOKEN_RIGHT_PAREN);
      }
      // Handled easily here.
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
        throw LexerError {line_, col_ - 1, current_char_ - 1, "Unexpected character"};
    }
  } while (!at_eof());

  // It has to be EOF by this point
  return eof();
}
