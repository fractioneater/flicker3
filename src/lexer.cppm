/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

module;
#include "common.h"

export module lexer;

import diagnostic;

import std;

export enum TokenType {
  // Single-character tokens (0 - 8)
  TOKEN_LEFT_PAREN, TOKEN_RIGHT_PAREN, TOKEN_LEFT_BRACKET, TOKEN_RIGHT_BRACKET, TOKEN_LEFT_BRACE, TOKEN_RIGHT_BRACE, TOKEN_SEMICOLON, TOKEN_COMMA, TOKEN_TILDE,
  // Single or multi-character tokens (9 - 47)
  TOKEN_STAR, TOKEN_STAR_STAR, TOKEN_STAR_EQ, TOKEN_STAR_STAR_EQ,
  TOKEN_MINUS, TOKEN_MINUS_MINUS, TOKEN_RIGHT_ARROW, TOKEN_MINUS_EQ,
  TOKEN_PLUS, TOKEN_PLUS_PLUS, TOKEN_PLUS_EQ,
  TOKEN_DOT, TOKEN_DOT_DOT, TOKEN_DOT_DOT_LT,
  TOKEN_QUEST, TOKEN_QUEST_COLON, TOKEN_QUEST_DOT,
  TOKEN_GT, TOKEN_GT_GT, TOKEN_GT_EQ,
  TOKEN_LT, TOKEN_LT_LT, TOKEN_LT_EQ,
  TOKEN_COLON, TOKEN_COLON_COLON,
  TOKEN_SLASH, TOKEN_SLASH_EQ,
  TOKEN_PERCENT, TOKEN_PERCENT_EQ,
  TOKEN_PIPE, TOKEN_PIPE_EQ,
  TOKEN_CARET, TOKEN_CARET_EQ,
  TOKEN_AMPERSAND, TOKEN_AMPERSAND_EQ,
  TOKEN_BANG, TOKEN_BANG_EQ,
  TOKEN_EQ, TOKEN_EQ_EQ,
  // Literals (48 - 52)
  TOKEN_IDENTIFIER, TOKEN_STRING, TOKEN_INTERPOLATION, TOKEN_CHAR, TOKEN_NUMBER,
  // Keywords (53 - 86)
  TOKEN_AND, TOKEN_AROUND, TOKEN_BREAK, TOKEN_CLASS, TOKEN_CONTINUE, TOKEN_DO, TOKEN_EACH, TOKEN_ELIF, TOKEN_ELSE, TOKEN_FALSE, TOKEN_FOR, TOKEN_FUN, TOKEN_IF,
  TOKEN_IN, TOKEN_IS, TOKEN_NAMESPACE, TOKEN_NIL, TOKEN_NOT, TOKEN_OF, TOKEN_OR, TOKEN_OVERRIDE, TOKEN_PASS, TOKEN_PRINT, TOKEN_PRINT_ERROR, TOKEN_PRIVATE,
  TOKEN_RETURN, TOKEN_STATIC, TOKEN_SUPER, TOKEN_THIS, TOKEN_TRUE, TOKEN_USING, TOKEN_VAL, TOKEN_VAR, TOKEN_WHILE,
  // Whitespace (87 - 89)
  TOKEN_INDENT, TOKEN_DEDENT, TOKEN_LINE,
  // EOF (90)
  TOKEN_EOF,
  // Ignored dedents (91), only created during parsing, and only used to minimize unnecessary errors. There should be a better way, but I can't find it.
  TOKEN_IGNORED_DEDENT,
};

namespace Helpers {
  // The string on the left represents how these keywords should show up in USER CODE.
  // So, for example, if I wanted the "nil" keyword to become "NIL" or "Nil", I'd change it here.
  // I believe keywords should be lowercase because that's what most programmers are used to.
  // Constants (nil, true, false) are usually lowercase, and because they aren't classes, I don't believe they should be Capitalized,
  //   although CAPITALIZED would be okay.
  const std::unordered_map<std::string_view, TokenType> KEYWORDS {
    {"and", TOKEN_AND},
    {"around", TOKEN_AROUND},
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
    {"namespace", TOKEN_NAMESPACE},
    {"nil", TOKEN_NIL},
    {"not", TOKEN_NOT},
    {"of", TOKEN_OF},
    {"or", TOKEN_OR},
    {"override", TOKEN_OVERRIDE},
    {"pass", TOKEN_PASS},
    {"print", TOKEN_PRINT},
    {"error", TOKEN_PRINT_ERROR},
    {"private", TOKEN_PRIVATE},
    {"return", TOKEN_RETURN},
    {"static", TOKEN_STATIC},
    {"super", TOKEN_SUPER},
    {"this", TOKEN_THIS},
    {"true", TOKEN_TRUE},
    {"using", TOKEN_USING},
    {"val", TOKEN_VAL},
    {"var", TOKEN_VAR},
    {"while", TOKEN_WHILE},
  };

  TokenType word_type(std::string_view word) {
    // This namespace that holds the map is in lexer.cppm.
    const auto found {KEYWORDS.find(word)};
    if (found != KEYWORDS.end())
      return found->second; // Return the associated TokenType.

    // Then return IDENTIFIER if it's not a reserved word.
    return TOKEN_IDENTIFIER;
  }

  bool is_alphanumeric(char c) {
    // Apparently it's good to cast it to unsigned char because isalnum() assumes it can go up to 255.
    return std::isalnum(static_cast<unsigned char>(c)) != 0 || c == '_';
  }

  int hex_value(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    return -1;
  }
}

export struct Token {
  TokenType type {TOKEN_EOF};
  std::size_t start_offset {};
  std::size_t length {};             // Number of chars that belong to this token.
  const std::string_view src_string; // String viewing the lexer's source at this token's position.

  std::any value {};

  Token(TokenType type, std::size_t start, std::size_t length, const std::string_view src) : type {type}, start_offset {start}, length {length},
    src_string {length == 0 ? "" : src.substr(start, length)} {}
};

export class Lexer {
  const std::string src_ {};
  const std::string_view src_view_ {};
  const long src_length_ {};

  std::size_t start_offset_ {};               // Current token's start position — char index in src.
  std::size_t offset_ {};                     // Current position — char index in src.
  std::vector<std::size_t> line_offsets_ {0}; // Positions of the first character in each line.

  TokenType prev_type_ {TOKEN_EOF}; // I feel like this may come in handy. EDIT: And when I needed to emit newlines after dedents, it did!

  int brace_nesting_ {}; // Because no whitespace is significant when we're inside a lambda.

  int interpolation_nesting_ {};
  std::array<int, MAX_INTERPOLATION_NEST> parens_ {};

  bool check_indent_ {true};
  int dedents_queued_ {};       // The number of dedents waiting to be scanned.
  std::vector<int> indents_ {}; // A list of past indentation levels, to determine how many dedents are created.

  std::vector<Diagnostic> diagnostics_ {};

  [[nodiscard]] inline bool at_eof() const { return offset_ >= src_length_; }

  [[nodiscard]] char peek() const {
    if (at_eof()) return '\0';
    return src_[offset_];
  }

  [[nodiscard]] char peek_next() const {
    if (offset_ + 1 >= src_length_) return '\0';
    return src_[offset_ + 1];
  }

  /**
   * Advance to the next char, handling newlines.
   * @return The current (now previous) character
   */
  char advance() {
    ++offset_;
    const char c {src_[offset_ - 1]};
    if (c == '\n')
      // Hopefully, when this is called, we shouldn't be at the point where we need to check for indentation again.
      line_offsets_.emplace_back(offset_);

    return c;
  }

  /**
   * Checks if the expected char is present, and if so, advances to the next.
   * @param expected Char to check for
   * @return Whether the expected char was found
   */
  bool match(char expected) {
    if (at_eof()) return false;
    if (src_[offset_] != expected) return false;
    advance();
    return true;
  }

  /**
   * Creates a token of a specified type, initializing it with lexer state info.
   * @param type The type of token to create
   * @return A token with type, offset, and length data
   */
  [[nodiscard]] Token make_token(TokenType type) {
    prev_type_ = type;
    const auto length {offset_ - start_offset_};
    return Token {type, start_offset_, length, src_view_};
  }

  /**
   * Creates a token of a specified type, initializing it with lexer state info and a value.
   * Relies on make_token(type).
   * @param type Type of token to create
   * @param value Token's value (number, string, char)
   * @return A token with type, offset, length, and value data
   */
  [[nodiscard]] Token make_token(TokenType type, std::any value) {
    Token t {make_token(type)};
    t.value = std::move(value);
    return t;
  }

  /**
   * Adds a diagnostic to the lexer's diagnostics vector, computing some necessary information from the offset.
   * @param message Error message
   * @param error_offset Char pos (offset) of the error
   * @param severity Diagnostic severity (NOTE, WARN, or ERROR)
   */
  void report_error(std::string&& message, std::size_t error_offset, Diagnostic::Severity severity = Diagnostic::ERROR) {
    diagnostics_.emplace_back(std::move(message), error_offset, severity);
  }

  /**
   * Scans a block comment until the closing #. Allows, and tracks, nesting.
   * @return A newline if there is one somewhere in the comment, otherwise nothing
   */
  std::optional<Token> block_comment() {
    const std::size_t start_offset {offset_ - 1};
    // Keep consuming until the closing comment or EOF.
    char prev {};
    for (int nest_depth {1}; nest_depth > 0; prev = advance()) {
      if (at_eof()) {
        report_error("Block comment missing closing '-#'", start_offset);
        return std::nullopt;
      }

      if (peek() == '#') {
        // This may seem weird, but comments can be chained like this, just for the sake of not being counterintuitive:
        // #-     stuff     -#-     more stuff (still at depth 1)     -#
        if (prev == '-') --nest_depth;
        if (peek_next() == '-') {
          advance();
          if (nest_depth++ == MAX_COMMENT_NEST) {
            report_error("Too many nested comments", offset_ - 1);
            return std::nullopt;
          }
        }
      }
    }

    if (line_offsets_.back() > start_offset) {
      check_indent_ = true; // Because indentation is column-based, it'll be fine to check indent after the end of a block comment.
      return make_token(TOKEN_LINE);
    }
    return std::nullopt;
  }

  /**
   * Assumes a line comment is being parsed, but will call block_comment() if it sees the next character is a hyphen.
   * Can scan past the end of the line if followed by another #.
   * @return Either a newline from block_comment() or nothing
   */
  std::optional<Token> line_comment() {
    if (peek() == '-') return block_comment();
    if (peek() == '#') {
      // A double-hashtag comment consumes past the end of the line (to allow manual wrapping).
      while (advance() != '\n' && !at_eof()) {}
    } else {
      while (peek() != '\n' && !at_eof()) advance();
    }
    return std::nullopt;
  }

  /**
   * Scans a string of alphanumeric or underscore characters (checking for a reserved word).
   * @return An identifier or keyword token
   */
  [[nodiscard]] Token word() {
    while (Helpers::is_alphanumeric(peek())) advance();
    const std::string_view word {static_cast<std::string_view>(src_).substr(start_offset_, offset_ - start_offset_)};
    return make_token(Helpers::word_type(word));
  }

  /**
   * Scans backtick-enclosed identifiers.
   * @return An identifier token with start and length values EXCLUDING the delineating backticks
   */
  [[nodiscard]] Token backtick_identifier() {
    while (peek() != '`' && !at_eof()) {
      if (peek() == '\n') {
        report_error("Identifier is missing closing backtick; even these can't have newlines", start_offset_);
        return make_token(TOKEN_IDENTIFIER);
      }
      advance();
    }

    if (at_eof()) {
      report_error("Identifier is missing closing backtick", start_offset_);
      return make_token(TOKEN_IDENTIFIER);
    }

    advance(); // The closing backtick.
    auto token {make_token(TOKEN_IDENTIFIER)};
    // Only the stuff within backticks is needed.
    token.start_offset++;
    token.length -= 2;

    if (token.length == 0) {
      report_error("Empty identifier", start_offset_);
      return make_token(TOKEN_IDENTIFIER); // Instead of returning the var 'token', let's just do this.
    }

    return token;
  }

  /**
   * Reads a sequence of hexadecimal digits, advancing the lexer state.
   * @param length The number of hexadecimal digits to read
   * @return A 32-bit unsigned integer computed from the hexadecimal digits
   */
  [[nodiscard]] std::uint32_t read_hex(int length) {
    std::uint32_t value {0};
    for (int i {0}; i < length; ++i) {
      if (at_eof()) {
        report_error(std::format("Escape sequence cut short by EOF (should be {} digits)", length), offset_);
        return 0;
      }

      const int digit {Helpers::hex_value(peek())};
      if (digit == -1) {
        report_error(std::format("Invalid hex character; sequence should be {} digits", length), offset_);
        return 0;
      }
      advance(); // The char that was just peeked at.

      value = (value << 4) | static_cast<std::uint32_t>(digit);
    }
    return value;
  }

  /**
   * Appends the UTF-8 encoded representation of a Unicode code point to a buffer. Also checks
   * the code point to ensure it is within the valid Unicode range and not a surrogate.
   * @param buffer String to which the UTF-8 encoded bytes will be appended
   * @param code_point Unicode code point to be encoded and added to the buffer
   *                   Must be a valid code point in the Unicode range (0x0 to 0x10FFFF) and not a surrogate (0xD800 to 0xDFFF)
   * @param sequence_start_offset Char index in the source file where the sequence starts, for error reporting
   */
  void append_utf8(std::string& buffer, std::uint32_t code_point, std::size_t sequence_start_offset) {
    if (code_point > 0x10FFFFu) {
      report_error("Invalid Unicode code point", sequence_start_offset);
      return;
    }
    if (code_point >= 0xD800u && code_point <= 0xDFFFu) {
      report_error("Invalid Unicode surrogate", sequence_start_offset);
      return;
    }

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

  /**
   * Scans a double-quote delineated string, allowing newlines and the following escape codes:
   * - \\\\ backslash
   * - \" double quote
   * - \\= non-interpolating equals sign
   * - \\0 null character
   * - \\a alert/bell
   * - \\b backspace
   * - \\e escape (\\033)
   * - \\f form feed
   * - \\n newline
   * - \\r carriage return
   * - \\t horizontal tab
   * - \\u.... four-digit Unicode escape
   * - \\U........ eight-digit Unicode escape
   * - \\v vertical tab
   * - \\x.. two-digit hex byte
   * @return Either a TOKEN_STRING or a TOKEN_INTERPOLATION depending on the string's content
   */
  [[nodiscard]] Token string() {
    // An interpolation token means the start of interpolation; it will have values in between and then a TOKEN_STRING to close it.
    // The type is a string unless interpolation is found.
    TokenType type {TOKEN_STRING};
    std::string buffer {};
    buffer.reserve(12); // CONSIDER! Is this a good default?

    while (true) {
      const char c {advance()};
      if (c == '"') break;
      if (c == '\r') continue; // To stay platform-independent.
      if (c == '\n') {
        report_error("String is missing closing quotation mark; newlines aren't allowed in strings", start_offset_);
        return make_token(TOKEN_STRING);
      }
      if (at_eof()) {
        report_error("String is missing closing quotation mark", start_offset_);
        return make_token(TOKEN_STRING);
      }

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

        report_error("Too many nested string-interpolations", offset_ + 1);
        return make_token(TOKEN_STRING);
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
          const std::size_t sequence_start_offset {offset_};
          const std::uint32_t code_point {read_hex(4)};
          append_utf8(buffer, code_point, sequence_start_offset);
          break;
        }
        case 'U': {
          const std::size_t sequence_start_offset {offset_};
          const std::uint32_t code_point {read_hex(8)};
          append_utf8(buffer, code_point, sequence_start_offset);
          break;
        }
        case 'v': buffer.push_back('\v'); break;
        case 'x': {
          const std::uint32_t byte {read_hex(2)};
          buffer.push_back(static_cast<char>(byte));
          break;
        }
        default:
          report_error("Invalid escape character", offset_ - 1);
      }
    } else {
      buffer.push_back(c);
    }
  }
    // @formatter:on again

    return make_token(type, buffer);
  }

  /**
   * Scans a single character, delineated with single-quotes. Allows most of the same escape sequences that string() allows.
   * @return A TOKEN_CHARACTER, not to be confused with one of Tolkien's characters (ex. Sam or Treebeard)
   */
  [[nodiscard]] Token character() {
    char value {};
    const char c {advance()};

    if (c == '\'') {
      report_error("Empty characters are not allowed", start_offset_);
      return make_token(TOKEN_CHAR);
    }

    if (c == '\n') {
      report_error("Character literal is missing closing quotation mark", start_offset_);
      return make_token(TOKEN_CHAR);
    }

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
      default:
        report_error("Invalid escape character", offset_ - 1);
    }
  } else value = c;
    // @formatter:on

    if (!match('\'')) {
      const std::size_t possible_end_offset {offset_ - 1}; // To check if a backslash was accidentally escaped.

      while (!at_eof() && peek() != '\'' && peek() != '\n') { advance(); }
      if (at_eof() || peek() == '\n') {
        report_error("Character literal is missing closing quotation mark", start_offset_);
      } else if (peek() == '\'') {
        report_error("Use double-quotes for strings; single-quotes are for single characters", start_offset_);
        advance(); // Closing quote.
      }

      if (src_[possible_end_offset] == '\'') {
        diagnostics_.back().add_context(
          Diagnostic {
            "Backslashes should be escaped ('\\\\') to allow this quote to close the char",
            Diagnostic::NOTE
          }
        );
      }

      return make_token(TOKEN_CHAR);
    }

    return make_token(TOKEN_CHAR, value);
  }

  /**
   * Scans a hexadecimal number. No support for floating point or exponents.
   * @return A TOKEN_NUMBER
   */
  [[nodiscard]] Token hex_number() {
    const auto is_hex_digit {
      [](char c) {
        return std::isdigit(static_cast<unsigned char>(c)) != 0 || (c <= 'f' && c >= 'a') || (c <= 'F' && c >= 'A');
      }
    };

    if (!is_hex_digit(peek())) {
      report_error("Expected a hex digit after 0x", offset_);
      return make_token(TOKEN_NUMBER);
    }
    consume_digit_chunk(is_hex_digit);

    if (!is_hex_digit(peek()) && std::isalpha(static_cast<unsigned char>(peek())) != 0) {
      report_error("Character appears to be part of the number, but is actually not", offset_, Diagnostic::WARNING);
    }

    auto raw_hex {std::string {src_.substr(start_offset_, offset_ - start_offset_)}};
    std::erase(raw_hex, '_');
    auto hex {static_cast<double>(std::stoll(raw_hex, nullptr, 16))};
    return make_token(TOKEN_NUMBER, hex);
  }

  /**
   * Scans a binary number. No support for floating point or exponents.
   * @return A TOKEN_NUMBER
   */
  [[nodiscard]] Token binary_number() {
    const auto is_binary_digit {[](char c) { return c == '0' || c == '1'; }};

    if (!is_binary_digit(peek())) {
      report_error("Expected a binary digit after 0b", offset_);
      return make_token(TOKEN_NUMBER);
    }
    consume_digit_chunk(is_binary_digit);

    if (!is_binary_digit(peek()) && std::isalnum(static_cast<unsigned char>(peek())) != 0) {
      report_error("Character appears to be part of the number, but is actually not", offset_, Diagnostic::WARNING);
    }

    auto raw_binary {std::string {src_.substr(start_offset_, offset_ - start_offset_)}};
    std::erase(raw_binary, '_');
    auto binary {static_cast<double>(std::stoll(raw_binary, nullptr, 2))};
    return make_token(TOKEN_NUMBER, binary);
  }

  /**
   * Consumes a sequence of characters classified as digits, handling underscores between them.
   * Underscores must be followed by valid digit characters.
   * @param is_digit A pointer to a function that takes a character as input and returns true if the character is considered a digit
   */
  void consume_digit_chunk(bool (*is_digit)(char)) {
    while (true) {
      const char c {peek()};

      if (is_digit(c)) {
        advance();
        continue;
      }

      if (c == '_') {
        if (!is_digit(peek_next()))
          report_error("Underscores must be followed by digits", offset_);
        advance(); // The underscore.
        continue;
      }

      break;
    }
  }

  /**
   * Scans a decimal number, including optional fractional and exponent part.
   * @return A token for the scanned number
   */
  [[nodiscard]] Token number() {
    const auto is_digit {[](char c) { return std::isdigit(static_cast<unsigned char>(c)) != 0; }};

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

      if (!is_digit(peek())) {
        report_error("Exponent requires a digit", offset_);
        return make_token(TOKEN_NUMBER);
      }

      consume_digit_chunk(is_digit);
    }

    if (!is_digit(peek()) && std::isalpha(static_cast<unsigned char>(peek())) != 0) {
      if (peek() == 'e')
        report_error("Use uppercase E for an exponent part", offset_, Diagnostic::WARNING);
      else
        report_error("Character appears to be part of the number, but is actually not", offset_, Diagnostic::WARNING);
    }

    auto raw_decimal {std::string {src_.substr(start_offset_, offset_ - start_offset_)}};
    std::erase(raw_decimal, '_');
    auto decimal {std::stod(raw_decimal)};
    return make_token(TOKEN_NUMBER, decimal);
  }

  /**
   * Check for indents or dedents. Should only be called at the start of a line.
   * @return An indent or dedent token if applicable, otherwise std::nullopt
   */
  std::optional<Token> indentation() {
    // Loop through characters until something significant (not whitespace or comment) is found.
    while (true) {
      switch (peek()) {
        case '\0': return std::nullopt; // EOF, no need to report this indentation.

        case ' ':  // Whitespace character
        case '\r': // Whitespace character
        case '\n': // This line was whitespace or comments only. Try again on the next line.
          advance();
          continue;

        case '\t': report_error("Tabs are not allowed in indentation", offset_);

        case '#': {
          advance();
          // Because the function is only called at the start of a line, we can ignore the return value; it can only be another newline.
          line_comment();
          continue; // Keep processing stuff after a block comment.
        }

        default: ; // Break from here, which in turn breaks from the loop.
      }
      break;
    }

    const auto col {static_cast<int>(offset_ - line_offsets_.back() + 1)}; // 1-based indexing.
    const int indent {col - 1};

    if (indent > indents_.back()) { // If it's an indentation...
      // We'll return an indent token, so we don't need to keep looking.
      check_indent_ = false;

      indents_.push_back(indent);
      return make_token(TOKEN_INDENT);
    }

    bool had_a_dedent {false};
    // ReSharper disable once CppDFALoopConditionNotUpdated because it IS updated clearly with pop_back().
    while (indent < indents_.back()) { // If there are dedents...
      had_a_dedent = true;

      ++dedents_queued_;
      indents_.pop_back(); // Check again with a new, more shallow indent.

      // So, um, this really shouldn't be happening. Because, you know, it would mean... it would mean the indentation level was less than zero.
      if (indents_.empty())
        report_error("AAAAH", offset_);
    }

    if (had_a_dedent) {
      if (indent != indents_.back()) {
        dedents_queued_ = 0;
        report_error("Indentation does not match any previous line", offset_);
        return std::nullopt; // CONSIDER! What is best to return here?
      }
      --dedents_queued_;
      return make_token(TOKEN_DEDENT);
    }

    // We're not at the start of a line anymore.
    check_indent_ = false;
    return std::nullopt;
  }

  /**
   * @return A dedent if necessary, otherwise EOF token
   */
  [[nodiscard]] Token eof() {
    start_offset_ = offset_;

    // Create dedents at EOF: emit one now and queue the rest.
    // The indents list should still hold the original 0.
    const int open_blocks {static_cast<int>(indents_.size()) - 1};
    if (open_blocks > 0) {
      indents_.resize(1);
      dedents_queued_ += open_blocks;

      --dedents_queued_;
      return make_token(TOKEN_DEDENT);
    }
    return make_token(TOKEN_EOF);
  }

  public:
  explicit Lexer(std::string src) : src_ {std::move(src)}, src_view_ {src_}, src_length_ {std::ssize(src_)} {
    indents_.emplace_back(0);
  }

  ~Lexer() = default;

  /**
   * The only function here that NEEDS to be exposed to the public. Retrieves the next token.
   * @return A token, specifically the next one
   */
  [[nodiscard]] Token next_token() {
    start_offset_ = offset_;

    if (prev_type_ == TOKEN_DEDENT) return make_token(TOKEN_LINE);

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
      start_offset_ = offset_;

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
        case '{':
          ++brace_nesting_;
          return make_token(TOKEN_LEFT_BRACE);
        case '}':
          if (--brace_nesting_ < 0)
            report_error("Extra closing brace", offset_);
          return make_token(TOKEN_RIGHT_BRACE);
        case ';': return make_token(TOKEN_SEMICOLON);
        case ',': return make_token(TOKEN_COMMA);
        case '~': return make_token(TOKEN_TILDE);
        case '.': return make_token(match('.') ? (match('<') ? TOKEN_DOT_DOT_LT : TOKEN_DOT_DOT) : TOKEN_DOT);
        case '?': return make_token(match('.') ? TOKEN_QUEST_DOT : match(':') ? TOKEN_QUEST_COLON : TOKEN_QUEST);
        case ':': return make_token(match(':') ? TOKEN_COLON_COLON : TOKEN_COLON);
        case '*': return make_token(match('*') ? (match('=') ? TOKEN_STAR_STAR_EQ : TOKEN_STAR_STAR) : match('=') ? TOKEN_STAR_EQ : TOKEN_STAR);
        case '+': return make_token(match('=') ? TOKEN_PLUS_EQ : match('+') ? TOKEN_PLUS_PLUS : TOKEN_PLUS);
        case '/': return make_token(match('=') ? TOKEN_SLASH_EQ : TOKEN_SLASH);
        case '-': return make_token(match('>') ? TOKEN_RIGHT_ARROW : match('=') ? TOKEN_MINUS_EQ : match('-') ? TOKEN_MINUS_MINUS : TOKEN_MINUS);
        case '%': return make_token(match('=') ? TOKEN_PERCENT_EQ : TOKEN_PERCENT);
        case '|': return make_token(match('=') ? TOKEN_PIPE_EQ : TOKEN_PIPE);
        case '^': return make_token(match('=') ? TOKEN_CARET_EQ : TOKEN_CARET);
        case '&': return make_token(match('=') ? TOKEN_AMPERSAND_EQ : TOKEN_AMPERSAND);
        case '!': return make_token(match('=') ? TOKEN_BANG_EQ : TOKEN_BANG);
        case '=': return make_token(match('=') ? TOKEN_EQ_EQ : TOKEN_EQ);
        case '>': return make_token(match('=') ? TOKEN_GT_EQ : match('>') ? TOKEN_GT_GT : TOKEN_GT);
        case '<': return make_token(match('=') ? TOKEN_LT_EQ : match('<') ? TOKEN_LT_LT : TOKEN_LT);
        // Not handled here.
        case '`': return backtick_identifier();
        case '"': return string();
        case '\'': return character();
        case '#':
          if (const std::optional opt {line_comment()}) return *opt;
          break;
        // Whitespace cases.
        case '\n':
          if (brace_nesting_ > 0) break;
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
          if (c == '_' || std::isalpha(static_cast<unsigned char>(c)) != 0) return word();
          if (std::isdigit(static_cast<unsigned char>(c)) != 0) return number();
          report_error("Unexpected character", offset_ - 1);
      }
    } while (!at_eof());

    // It has to be EOF by this point
    return eof();
  }

  [[nodiscard]] const std::string& get_src() const { return src_; }

  /**
   * @return A vector of the starting char indices of each line in the source file
   */
  [[nodiscard]] const std::vector<std::size_t>& get_line_offsets() const { return line_offsets_; }

  /**
   * Returns the human-readable position in code of a character index in the source file.
   * @param offset Char index to convert to line and column
   * @return A pair of [line, col], 1-based indexing, from the offset given
   */
  [[nodiscard]] std::pair<std::size_t, std::size_t> offset_to_line_col(std::size_t offset) const {
    const auto subrange {std::ranges::find_last_if(line_offsets_, [offset](std::size_t it) { return it <= offset; })};

    if (subrange.begin() == subrange.end())
      return {0, 0};

    const auto before {subrange.begin()};

    // 1-based indexing for both.
    const auto line {before - line_offsets_.begin() + 1};
    const auto col {offset - *before + 1};

    return {line, col};
  }

  /**
   * Returns a string of the whole line that contains a given offset.
   * @param offset Beginning of the range, as a char index in the source file
   * @return A string_view WITHOUT a trailing newline, viewing the source
   */
  [[nodiscard]] std::string_view offset_to_line_string(std::size_t offset) const {
    if (line_offsets_.empty()) return ""; // Shouldn't happen; line_offsets_ is initialized with 0.

    // Find the first line whose start offset is > start, then step back one.
    const auto upper {std::ranges::upper_bound(line_offsets_, offset)};
    const auto line_index {static_cast<int>(std::distance(line_offsets_.begin(), upper)) - 1};

    const std::size_t line_start {line_offsets_[line_index]};
    const std::size_t next_start {
      upper == line_offsets_.end()
      ? src_length_
      : line_offsets_[line_index + 1] - 1
    };

    const std::size_t len {next_start - line_start};
    return src_view_.substr(line_start, len);
  }

  [[nodiscard]] const std::vector<Diagnostic>& get_diagnostics() const { return diagnostics_; }

  [[nodiscard]] bool encountered_halt() const {
    return std::ranges::any_of(diagnostics_, [](const Diagnostic& d) { return d.is_halting(); });
  }
};
