/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#pragma once

#include <algorithm>
#include <functional>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include <bits/stdint-uintn.h>

#include "common.h"

class LexerError {
public:
  size_t offset {};
  std::string message {};
  std::unique_ptr<LexerError> context {};

  LexerError(size_t offset, std::string&& message) : offset {offset}, message {std::move(message)} {}
  LexerError(size_t offset, std::string&& message, LexerError&& context) : offset {offset}, message {std::move(message)},
    context {std::make_unique<LexerError>(std::move(context))} {}

  void add_context(LexerError&& c) {
    this->context = std::make_unique<LexerError>(std::move(c));
  }

  [[nodiscard]] const char* what() const noexcept { return message.c_str(); }
};

enum TokenType {
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
  TOKEN_AND, TOKEN_BREAK, TOKEN_CLASS, TOKEN_CONTINUE, TOKEN_DO, TOKEN_EACH, TOKEN_ELIF, TOKEN_ELSE, TOKEN_FALSE, TOKEN_FOR, TOKEN_FUN, TOKEN_IF,
  TOKEN_IN, TOKEN_IS, TOKEN_NAMESPACE, TOKEN_NIL, TOKEN_NOT, TOKEN_OF, TOKEN_OR, TOKEN_OVERRIDE, TOKEN_PASS, TOKEN_PRINT, TOKEN_PRINT_ERROR, TOKEN_PRIVATE,
  TOKEN_RETURN, TOKEN_STATIC, TOKEN_SUPER, TOKEN_THIS, TOKEN_TRUE, TOKEN_USING, TOKEN_VAL, TOKEN_VAR, TOKEN_WHEN, TOKEN_WHILE,
  // Whitespace (87 - 89)
  TOKEN_INDENT, TOKEN_DEDENT, TOKEN_LINE,
  // EOF (90)
  TOKEN_EOF,
};

struct Token {
  TokenType type {TOKEN_EOF};
  size_t start_offset {};
  size_t length {}; // Number of chars that belong to this token.
  // End column can be computed with (col + length). End char can be computed with (start_char + length)
};

class Lexer {
  const std::string src_ {};
  const long src_length_ {};

  size_t start_offset_ {};               // Current token's start position — char index in src.
  size_t offset_ {};                     // Current position — char index in src.
  std::vector<size_t> line_offsets_ {0}; // Positions of the first character in each line.

  TokenType prev_type_ {TOKEN_EOF}; // I feel like this may come in handy. EDIT: And when I needed to emit newlines after dedents, it did!

  int brace_nesting_ {}; // Because no whitespace is significant when we're inside a lambda.

  int interpolation_nesting_ {};
  std::array<int, MAX_INTERPOLATION_NEST> parens_ {};

  bool check_indent_ {true};
  int dedents_queued_ {};       // The number of dedents waiting to be scanned.
  std::vector<int> indents_ {}; // A list of past indentation levels, to determine how many dedents are created.

  std::vector<LexerError> errors_ {};
  std::vector<LexerError> warnings_ {};

  [[nodiscard]] bool at_eof() const;
  [[nodiscard]] char peek() const;
  [[nodiscard]] char peek_next() const;

  /**
   * Advance to the next char, handling newlines.
   * @return The current (now previous) character
   */
  char advance();

  /**
   * Checks if the expected char is present, and if so, advances to the next.
   * @param expected The char to check for
   * @return Whether the expected char was found
   */
  bool match(char expected);

  /**
   * Creates a token of a specified type, initializing it with lexer state info.
   * @param type The type of token to create
   * @return A token with line, char, and col data
   */
  [[nodiscard]] Token make_token(TokenType type); // To set prev_type_ automatically.

  /**
   * Scans a block comment until the closing #. Allows, and tracks, nesting.
   */
  void block_comment();

  /**
   * Assumes a line comment is being parsed, but will call block_comment() if it sees the next character is a colon.
   */
  void line_comment();

  /**
   * Scans a string of alphanumeric or underscore characters (checking for a reserved word).
   * @return An identifier or keyword token
   */
  [[nodiscard]] Token word();

  /**
   * Scans backtick-enclosed identifiers.
   * @return An identifier token with start and length values EXCLUDING the delineating backticks
   */
  [[nodiscard]] Token backtick_identifier();

  /**
   * Reads a sequence of hexadecimal digits, advancing the lexer state.
   * @param length The number of hexadecimal digits to read
   * @return A 32-bit unsigned integer computed from the hexadecimal digits
   */
  [[nodiscard]] uint32_t read_hex(int length);

  /**
   * Appends the UTF-8 encoded representation of a Unicode code point to a buffer. Also checks
   * the code point to ensure it is within the valid Unicode range and not a surrogate.
   * @param buffer The string to which the UTF-8 encoded bytes will be appended
   * @param code_point The Unicode code point to be encoded and added to the buffer
   *                   Must be a valid code point in the Unicode range (0x0 to 0x10FFFF) and not a surrogate (0xD800 to 0xDFFF)
   */
  void append_utf8(std::string& buffer, uint32_t code_point);

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
  [[nodiscard]] Token string();

  /**
   * Scans a single character, delineated with single-quotes. Allows most of the same escape sequences that string() allows.
   * @return A TOKEN_CHARACTER, not to be confused with one of Tolkien's characters (ex. Sam or Treebeard)
   */
  [[nodiscard]] Token character();

  /**
   * Scans a hexadecimal number. No support for floating point or exponents.
   * @return A TOKEN_NUMBER
   */
  [[nodiscard]] Token hex_number();

  /**
   * Scans a binary number. No support for floating point or exponents.
   * @return A TOKEN_NUMBER
   */
  [[nodiscard]] Token binary_number();

  /**
   * Consumes a sequence of characters classified as digits, handling underscores between them.
   * Underscores must be followed by valid digit characters.
   * @param is_digit A pointer to a function that takes a character as input and returns true if the character is considered a digit
   */
  void consume_digit_chunk(bool (*is_digit)(char));

  /**
   * Scans a decimal number, including optional fractional and exponent part.
   * @return A token for the scanned number
   */
  [[nodiscard]] Token number();

  /**
   * Check for indents or dedents. Should only be called at the start of a line.
   * @return An indent or dedent token if applicable, otherwise std::nullopt
   */
  std::optional<Token> indentation();

  /**
   * @return A dedent if necessary, otherwise EOF token
   */
  [[nodiscard]] Token eof();

public:
  explicit Lexer(std::string src);
  ~Lexer();

  /**
   * The only function here that NEEDS to be exposed to the public. Retrieves the next token.
   * @return A token, specifically the next one
   */
  [[nodiscard]] Token next_token();

  [[nodiscard]] const std::string& get_src() const { return src_; }

  /**
   * @return A vector of the starting char indices of each line in the source file
   */
  [[nodiscard]] const std::vector<size_t>& get_line_offsets() const { return line_offsets_; }
  /**
   * Returns the human-readable position in code of a character index in the source file.
   * @param offset The char index to convert to line and column
   * @return A pair of [line, col], 1-based indexing, from the offset given
   */
  [[nodiscard]] std::pair<size_t, size_t> offset_to_line_col(size_t offset) const;
  /**
   * Returns a string of the whole line that contains a given offset.
   * @param offset The beginning of the range, as a char index in the source file
   * @return A string_view WITHOUT a trailing newline, viewing the source
   */
  [[nodiscard]] std::string_view offset_to_line_string(size_t offset) const;

  [[nodiscard]] const std::vector<LexerError>& get_errors() const { return errors_; }
  [[nodiscard]] const std::vector<LexerError>& get_warnings() const { return warnings_; }
};
