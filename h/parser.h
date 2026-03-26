/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#pragma once

#include "ast.h"

class ParserError {
public:
  Token* token {};
  std::string message {};
  std::unique_ptr<ParserError> context {};

  explicit ParserError(std::string&& message) : message {std::move(message)} {}

  ParserError(Token* token, std::string&& message) : token {token}, message {std::move(message)} {}

  ParserError(Token* token, std::string&& message, ParserError&& context) : token {token}, message {std::move(message)},
    context {std::make_unique<ParserError>(std::move(context))} {}

  void add_context(ParserError&& c) {
    this->context = std::make_unique<ParserError>(std::move(c));
  }

  [[nodiscard]] const char* what() const noexcept { return message.c_str(); }
};

enum class Precedence {
  NONE,
  BEGIN,          // used when calling parse_expression() at top level, or in parentheses
  PRINT,          // yes, print is an expression
  ASSIGNMENT,     // = | -= | += | *= | /= | **= | |= | &= | ^= | %=
  NOT,            // not
  OR,             // or
  AND,            // and
  COMPARISON,     // == | != | > | >= | < | <=
  IN,             // in | not in
  IS,             // is | is not
  IF,             // ... if ... else ...
  BIT_OR,         // |
  BIT_XOR,        // ^
  BIT_AND,        // &
  BIT_SHIFT,      // << | >>
  TERM,           // + | -
  FACTOR,         // * | /
  PREFIX,         // ++ | -- | ! | ~ | -
  EXPONENT,       // **
  NIL_COALESCING, // ?:
  POSTFIX,        // ++ | -- | . | ?. | () | {} | []
  RANGE,          // .. | ..<
  ATOM
};

class Parser {
  Lexer& lexer_;
  std::vector<StmtNode> program_ {};

  std::vector<Token> tokens_ {};
  Token* current_ {};
  Token* previous_ {};

  std::vector<ParserError> errors_ {};
  std::vector<ParserError> warnings_ {};

public:
  explicit Parser(Lexer& lexer) : lexer_ {lexer} {}

  void advance() {
    previous_ = current_;
    if (current_->type != TOKEN_EOF) ++current_;
  }

  /**
   * Returns a boolean of whether the next token is a certain type.
   * @param type Type to check for
   * @return A boolean, true if the token matches 'type'
   */
  [[nodiscard]] bool check(TokenType type) const {
    return current_->type == type;
  }

  /**
   * Advances if the next token matches a certain type, otherwise returns false.
   * @param type Type to check for
   * @return A boolean, true if the token matches 'type'
   */
  bool match(TokenType type) {
    if (!check(type)) return false;
    advance();
    return true;
  }

  /**
   * Match as many TOKEN_LINEs as are available, returning true if one was found.
   * @return Whether at least one newline was found
   */
  bool match_line() {
    if (!check(TOKEN_LINE)) return false;
    while (match(TOKEN_LINE)) {}
    return true;
  }

  /**
   * If the next token matches a certain type, advances, otherwise creates an error.
   * @param type Expected type of the next token
   * @param message Error message in case the expected type is not found
   * @param error_token Token to associate the error with
   */
  void expect(TokenType type, std::string_view message, Token* error_token = nullptr) {
    error_token = (error_token == nullptr) ? current_ : error_token;
    if (!match(type))
      errors_.emplace_back(error_token, std::string(message));
  }

  /**
   * Consumes a chain of TOKEN_LINEs if there are any, otherwise creates an error.
   * @param message Error message
   * @param error_token Token to associate the error with
   */
  void expect_line(std::string_view message, Token* error_token = nullptr) {
    error_token = (error_token == nullptr) ? current_ : error_token;
    if (!match_line()) errors_.emplace_back(error_token, std::string(message));
  }

  /**
   * If the next token matches a certain type, advances, otherwise creates an error.
   * @param type Expected type of the next token
   * @param message Error message in case the expected type is not found
   * @param context Context to add to the error
   * @param error_token Token to associate the error with
   */
  void expect(TokenType type, std::string_view message, ParserError& context, Token* error_token = nullptr) {
    error_token = (error_token == nullptr) ? current_ : error_token;
    if (!match(type))
      errors_.emplace_back(error_token, std::string(message), std::move(context));
  }

  StmtNode declaration();
  StmtNode statement();
  StmtNode block();

  ExprNode binary_right_assoc(const ExprNode& left);
  ExprNode binary(const ExprNode& left);
  ExprNode infix_not(const ExprNode& left);
  ExprNode binary_is(const ExprNode& left);
  ExprNode unary();
  ExprNode prefix_not();
  ExprNode print();
  ExprNode literal();
  ExprNode grouping();

  ExprNode parse_expression(Precedence precedence);

  /**
   * Fill the tokens_ vector with tokens from the lexer, up to ONE end-of-file token.
   * This allows the lexer to display all of its errors and warnings before the parser begins.
   * Also initializes current_ and previous_ (IMPORTANT! Must be called for this purpose).
   */
  void populate_token_vec();

  /**
   * Parses the input token stream and generates an AST which is stored in program_ if there are no errors.
   * @return True if parsing completes without syntax errors; otherwise false
   */
  void parse();

  /**
   * Output in GraphViz DOT format, to a file specified by DEBUG_DOT_FILENAME, from the tree stored in program_.
   * There must be a tree already—parse() must have been called.
   */
  void output_dot() const;

  const std::vector<ParserError>& get_errors() { return errors_; }
  const std::vector<ParserError>& get_warnings() { return warnings_; }

  // Helper data structures and parse rules
  using PrefixFn = ExprNode(Parser::*)();
  using InfixFn  = ExprNode(Parser::*)(const ExprNode&);

  struct ParseRule {
    PrefixFn prefix {};
    InfixFn infix {};
    NamedFunction fn_name {};
    Precedence prec {};
  };

  #define UNUSED                      ParseRule {nullptr, nullptr, "", Precedence::NONE}
  #define INFIX_RULE(fn, name, prec)  ParseRule {nullptr, &Parser::fn, name, Precedence::prec}
  #define PREFIX_RULE(fn, name, prec) ParseRule {&Parser::fn, nullptr, name, Precedence::prec}
  #define BOTH(pre, in, name, prec)   ParseRule {&Parser::pre, &Parser::in, name, Precedence::prec}

  // @formatter:off
  std::array<ParseRule, 91> rules {{
    /* TOKEN_LEFT_PAREN    *//* BOTH(grouping, call, POSTFIX),*/ PREFIX_RULE(grouping, "", NONE),
    /* TOKEN_RIGHT_PAREN   */ UNUSED,
    /* TOKEN_LEFT_BRACKET  *//* BOTH(collection, subscript, POSTFIX),*/ UNUSED,
    /* TOKEN_RIGHT_BRACKET */ UNUSED,
    /* TOKEN_LEFT_BRACE    *//* INFIX_RULE(lambda_call, POSTFIX),*/ UNUSED,
    /* TOKEN_RIGHT_BRACE   */ UNUSED,
    /* TOKEN_SEMICOLON     */ UNUSED,
    /* TOKEN_COMMA         */ UNUSED,
    /* TOKEN_TILDE         */ PREFIX_RULE(unary, "~", PREFIX),
    /* TOKEN_STAR          */ INFIX_RULE(binary, "*", FACTOR),
    /* TOKEN_STAR_STAR     */ INFIX_RULE(binary_right_assoc, "**", EXPONENT),
    /* TOKEN_STAR_EQ       */ UNUSED,
    /* TOKEN_STAR_STAR_EQ  */ UNUSED,
    /* TOKEN_MINUS         */ BOTH(unary, binary, "-", TERM),
    /* TOKEN_MINUS_MINUS   *//* BOTH(unary, postfix, POSTFIX),*/ UNUSED,
    /* TOKEN_RIGHT_ARROW   */ UNUSED,
    /* TOKEN_MINUS_EQ      */ UNUSED,
    /* TOKEN_PLUS          */ INFIX_RULE(binary, "+", TERM),
    /* TOKEN_PLUS_PLUS     *//* BOTH(unary, postfix, POSTFIX),*/ UNUSED,
    /* TOKEN_PLUS_EQ       */ UNUSED,
    /* TOKEN_DOT           *//* INFIX_RULE(dot, POSTFIX),*/ UNUSED,
    /* TOKEN_DOT_DOT       */ INFIX_RULE(binary, "..", RANGE),
    /* TOKEN_DOT_DOT_LT    */ INFIX_RULE(binary, "..<", RANGE),
    /* TOKEN_QUEST         */ UNUSED,
    /* TOKEN_QUEST_COLON   */ INFIX_RULE(binary, "?:", NIL_COALESCING),
    /* TOKEN_QUEST_DOT     *//* INFIX_RULE(dot, POSTFIX),*/ UNUSED,
    /* TOKEN_GT            */ INFIX_RULE(binary, ">", COMPARISON),
    /* TOKEN_GT_GT         */ INFIX_RULE(binary, ">>", BIT_SHIFT),
    /* TOKEN_GT_EQ         */ INFIX_RULE(binary, ">=", COMPARISON),
    /* TOKEN_LT            */ INFIX_RULE(binary, "<", COMPARISON),
    /* TOKEN_LT_LT         */ INFIX_RULE(binary, "<<", BIT_SHIFT),
    /* TOKEN_LT_EQ         */ INFIX_RULE(binary, "<=", COMPARISON),
    /* TOKEN_COLON         */ UNUSED,
    /* TOKEN_COLON_COLON   *//* INFIX_RULE(scope_access, ATOM),*/ UNUSED,
    /* TOKEN_SLASH         */ INFIX_RULE(binary, "/", FACTOR),
    /* TOKEN_SLASH_EQ      */ UNUSED,
    /* TOKEN_PERCENT       */ INFIX_RULE(binary, "%", FACTOR),
    /* TOKEN_PERCENT_EQ    */ UNUSED,
    /* TOKEN_PIPE          */ INFIX_RULE(binary, "|", BIT_OR),
    /* TOKEN_PIPE_EQ       */ UNUSED,
    /* TOKEN_CARET         */ INFIX_RULE(binary, "^", BIT_XOR),
    /* TOKEN_CARET_EQ      */ UNUSED,
    /* TOKEN_AMPERSAND     */ INFIX_RULE(binary, "&", BIT_AND),
    /* TOKEN_AMPERSAND_EQ  */ UNUSED,
    /* TOKEN_BANG          */ PREFIX_RULE(unary, "!", PREFIX),
    /* TOKEN_BANG_EQ       */ INFIX_RULE(binary, "!=", COMPARISON),
    /* TOKEN_EQ            */ UNUSED,
    /* TOKEN_EQ_EQ         */ INFIX_RULE(binary, "==", COMPARISON),
    /* TOKEN_IDENTIFIER    *//* PREFIX_RULE(identifier, NONE),*/ UNUSED,
    /* TOKEN_STRING        */ PREFIX_RULE(literal, "", NONE),
    /* TOKEN_INTERPOLATION *//* PREFIX_RULE(string_interpolation, NONE),*/ UNUSED,
    /* TOKEN_CHAR          */ PREFIX_RULE(literal, "", NONE),
    /* TOKEN_NUMBER        */ PREFIX_RULE(literal, "", NONE),
    /* TOKEN_AND           */ INFIX_RULE(binary, "and", AND),
    /* TOKEN_BREAK         */ UNUSED,
    /* TOKEN_CLASS         */ UNUSED,
    /* TOKEN_CONTINUE      */ UNUSED,
    /* TOKEN_DO            */ UNUSED,
    /* TOKEN_EACH          */ UNUSED,
    /* TOKEN_ELIF          */ UNUSED,
    /* TOKEN_ELSE          */ UNUSED,
    /* TOKEN_FALSE         */ PREFIX_RULE(literal, "", NONE),
    /* TOKEN_FOR           */ UNUSED,
    /* TOKEN_FUN           */ UNUSED,
    /* TOKEN_IF            *//* INFIX_RULE(if_expr, IF),*/ UNUSED,
    /* TOKEN_IN            */ INFIX_RULE(binary, "in", IN),
    /* TOKEN_IS            */ INFIX_RULE(binary_is, "", IS),
    /* TOKEN_NAMESPACE     */ UNUSED,
    /* TOKEN_NIL           */ PREFIX_RULE(literal, "", NONE),
    /* TOKEN_NOT           */ BOTH(prefix_not, infix_not, "", IN),
    /* TOKEN_OF            *//* PREFIX_RULE(of, ATOM),*/ UNUSED,
    /* TOKEN_OR            */ INFIX_RULE(binary, "or", OR),
    /* TOKEN_OVERRIDE      */ UNUSED,
    /* TOKEN_PASS          */ UNUSED,
    /* TOKEN_PRINT         */ PREFIX_RULE(print, "print", PRINT),
    /* TOKEN_PRINT_ERROR   */ PREFIX_RULE(print, "print_err", PRINT),
    /* TOKEN_PRIVATE       */ UNUSED,
    /* TOKEN_RETURN        */ UNUSED,
    /* TOKEN_STATIC        */ UNUSED,
    /* TOKEN_SUPER         *//* PREFIX_RULE(super_id, NONE),*/ UNUSED,
    /* TOKEN_THIS          *//* PREFIX_RULE(this_id, NONE),*/ UNUSED,
    /* TOKEN_TRUE          */ PREFIX_RULE(literal, "", NONE),
    /* TOKEN_USING         */ UNUSED,
    /* TOKEN_VAL           */ UNUSED,
    /* TOKEN_VAR           */ UNUSED,
    /* TOKEN_WHEN          */ UNUSED,
    /* TOKEN_WHILE         */ UNUSED,
    /* TOKEN_INDENT        */ UNUSED,
    /* TOKEN_DEDENT        */ UNUSED,
    /* TOKEN_LINE          */ UNUSED,
    /* TOKEN_EOF           */ UNUSED,
  }};
  // @formatter:on
};
