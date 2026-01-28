#pragma once

#include <string>
#include <unordered_map>
#include <vector>

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
  // Literals (32 - 35)
  TOKEN_IDENTIFIER, TOKEN_STRING, TOKEN_INTERPOLATION, TOKEN_NUMBER,
  // Keywords (36 - 68)
  TOKEN_AND, TOKEN_ATTRIBUTE, TOKEN_BREAK, TOKEN_CLASS, TOKEN_CONTINUE, TOKEN_DO, TOKEN_EACH, TOKEN_ELIF, TOKEN_ELSE, TOKEN_FALSE,
  TOKEN_FOR, TOKEN_FUN, TOKEN_IF, TOKEN_IN, TOKEN_IS, TOKEN_NIL, TOKEN_NOT, TOKEN_OF, TOKEN_OR, TOKEN_PASS, TOKEN_PRINT,
  TOKEN_PRINT_ERROR, TOKEN_RETURN, TOKEN_SHL, TOKEN_SHR, TOKEN_STATIC, TOKEN_SUPER, TOKEN_THIS, TOKEN_TRUE, TOKEN_USE,
  TOKEN_VAL, TOKEN_VAR, TOKEN_WHEN, TOKEN_WHILE,
  // Whitespace (69 - 71)
  TOKEN_INDENT, TOKEN_DEDENT, TOKEN_LINE,
  // Misc (72 - 74)
  TOKEN_EOF, TOKEN_ERROR, TOKEN_NULL
};

struct Token {
  TokenType type {TOKEN_NULL};
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

  TokenType prev_type_ {TOKEN_NULL}; // I feel like this may come in handy.

  int dedents_queued_ {};       // The number of dedents waiting to be scanned.
  std::vector<int> indents_ {}; // A list of past indentation levels, to determine how many dedents are created.

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

  void block_comment();
  void line_comment();

  /**
   * Scans a string of alphanumeric or underscore characters (checking for a reserved word).
   * @return An identifier or keyword token
   */
  [[nodiscard]] Token word();

public:
  explicit Lexer(std::string src);
  ~Lexer();

  /**
   * The only function here that NEEDS to be exposed to the public. Retrieves the next token.
   * @return A token, specifically the next one
   */
  [[nodiscard]] Token next_token();
};

namespace Keywords {
  // The string on the left represents how these keywords should show up in USER CODE.
  // So, for example, if I wanted the "nil" keyword to become "NIL" or "Nil", I'd change it here.
  // I believe keywords should be lowercase because that's what most programmers are used to.
  // Constants (nil, true, false) are usually lowercase, and because they aren't classes, I don't believe they should be Capitalized,
  //   although CAPITALIZED would be okay.
  const std::unordered_map<std::string_view, TokenType> map {
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
