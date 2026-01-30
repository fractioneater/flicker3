#pragma once

#include <functional>
#include <optional>
#include <string>
#include <vector>
#include <bits/stdint-uintn.h>

#include "common.h"

class LexerError {
public:
  // If the line number is -1, it's an error at EOF.
  int line {-1};
  int col {-1};
  long char_index {};
  std::string message {};
  // This is set in interpret() because the lexer doesn't have module information.
  std::string module {};

  // CONSIDER! Removing EOF errors, modifying string buffer reserve() to not complain if closing quote isn't found and let the error be reported at the
  //   correct column

  // For EOF errors that don't need a line.
  explicit LexerError(std::string&& message) : message {std::move(message)} {}
  LexerError(int line, int col, long char_index, std::string&& message) : line {line}, col {col}, char_index {char_index}, message {std::move(message)} {}

  [[nodiscard]] const char* what() const noexcept { return message.c_str(); }
};

class LexerWarning : public LexerError {
public:
  LexerWarning(int line, int col, long char_index, std::string&& message) : LexerError {line, col, char_index, std::move(message)} {}
};

enum TokenType {
  // Single-character tokens (0 - 14)
  TOKEN_LEFT_PAREN, TOKEN_RIGHT_PAREN, TOKEN_LEFT_BRACKET, TOKEN_RIGHT_BRACKET, TOKEN_LEFT_BRACE, TOKEN_RIGHT_BRACE,
  TOKEN_SEMICOLON, TOKEN_COMMA, TOKEN_PLUS, TOKEN_SLASH, TOKEN_PERCENT, TOKEN_PIPE, TOKEN_CARET, TOKEN_AMPERSAND, TOKEN_TILDE,
  // 1-3 character tokens (15 - 31)
  TOKEN_DOT, TOKEN_DOT_DOT, TOKEN_DOT_DOT_LT,
  TOKEN_COLON, TOKEN_COLON_COLON,
  TOKEN_STAR, TOKEN_STAR_STAR,
  TOKEN_MINUS, TOKEN_RIGHT_ARROW,
  TOKEN_BANG, TOKEN_BANG_EQ,
  TOKEN_EQ, TOKEN_EQ_EQ,
  TOKEN_GT, TOKEN_GT_EQ,
  TOKEN_LT, TOKEN_LT_EQ,
  // Literals (32 - 36)
  TOKEN_IDENTIFIER, TOKEN_STRING, TOKEN_INTERPOLATION, TOKEN_CHAR, TOKEN_NUMBER,
  // Keywords (37 - 71)
  TOKEN_ALIAS, TOKEN_AND, TOKEN_ATTRIBUTE, TOKEN_BREAK, TOKEN_CLASS, TOKEN_CONTINUE, TOKEN_DO, TOKEN_EACH, TOKEN_ELIF, TOKEN_ELSE,
  TOKEN_FALSE, TOKEN_FOR, TOKEN_FUN, TOKEN_IF, TOKEN_IN, TOKEN_IS, TOKEN_NIL, TOKEN_NOT, TOKEN_OF, TOKEN_OR, TOKEN_PASS, TOKEN_PRINT,
  TOKEN_PRINT_ERROR, TOKEN_RETURN, TOKEN_SHL, TOKEN_SHR, TOKEN_STATIC, TOKEN_SUPER, TOKEN_THIS, TOKEN_TRUE, TOKEN_USE,
  TOKEN_VAL, TOKEN_VAR, TOKEN_WHEN, TOKEN_WHILE,
  // Whitespace (72 - 74)
  TOKEN_INDENT, TOKEN_DEDENT, TOKEN_LINE,
  // Misc (75)
  TOKEN_EOF,
};

struct Token {
  TokenType type {TOKEN_EOF};
  int line {};
  long start_char {};
  int col {};    // Start column.
  int length {}; // Number of chars that belong to this token.
  // End column can be computed with (col + length). End char can be computed with (start_char + length)
};

class Lexer {
  const std::string src_ {};
  const long src_length_ {};

  int line_ {1};
  int col_ {1};
  int start_col_ {1};
  long start_char_ {}; // Current token's starting index.
  long current_char_ {};

  TokenType prev_type_ {TOKEN_EOF}; // I feel like this may come in handy.

  int interpolation_nesting_ {};
  std::array<int, MAX_INTERPOLATION_NEST> parens_ {};

  bool check_indent_ {true};
  int dedents_queued_ {};       // The number of dedents waiting to be scanned.
  std::vector<int> indents_ {}; // A list of past indentation levels, to determine how many dedents are created.

  std::vector<LexerError> errors_ {};
  std::vector<LexerWarning> warnings_ {};

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
  void append_utf8(std::string& buffer, uint32_t code_point) const;

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

  const std::vector<LexerWarning>& get_warnings() { return warnings_; }
};
