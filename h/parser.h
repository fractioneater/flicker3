/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#pragma once

#include "ast.h"
#include "type.h"

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
  NONE,           // so the compiler doesn't destroy itself trying to call the infix rule of a prefix-only token
  BEGIN,          // used when calling parse_expression() in a general case
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
  RANGE,          // .. | ..<
  POSTFIX,        // . | ?. | () | {} | [] | ++ | -- (the last two are exceptions, because they're not supposed to be postfix)
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
   * Returns a Boolean, true if the next token is a certain type.
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
   * Consume as many TOKEN_LINEs as are available, returning true if one was found.
   * @return Whether at least one newline was found
   */
  bool match_line() {
    if (!check(TOKEN_LINE)) return false;
    while (match(TOKEN_LINE)) {}
    return true;
  }

  /**
   * Consume as many TOKEN_LINES as are available, as well as the token afterward, BUT CONSUME NOTHING IF THE TOKEN AFTER A SET OF LINES IS NOT 'type'.
   * @param type Type to check for
   * @return A boolean, true if the token after newlines matches 'type'
   */
  bool match_after_newlines(TokenType type) {
    // Taking advantage of infinite lookahead here.
    const Token* token = current_;
    while (token->type == TOKEN_LINE) ++token;
    if (token->type != type) return false;

    while (current_->type == TOKEN_LINE) advance();
    advance();
    return true;
  }

  /**
   * Advances if the next token matches a certain operator precedence, otherwise returns false.
   * @param prec Precedence to check for
   * @return A boolean, true if the token's precedence matches prec
   */
  bool match_precedence(Precedence prec) {
    if (rules[current_->type].prec != prec) return false;
    advance();
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

  std::optional<StmtNode> declaration();
  StmtNode declaration_or_statement();
  StmtNode declaration_in_namespace();
  StmtNode val_declaration();
  StmtNode var_declaration();
  // StmtNode function_declaration();
  // StmtNode class_declaration();
  StmtNode namespace_declaration();
  // StmtNode using_declaration();

  /**
   * Interprets and parses the next few tokens as a user-representable type of any complexity.
   * This includes optionals, applied types, function types, and named types (see h/type.h for explanation).
   * @return Type parsed (possibly nullptr in error case)
   */
  TypePtr parse_type();
  /**
   * Parses a function type, like this: (String, String) -> String.
   * Does not allow applied types or function types nested inside (only basic_type calls).
   * @return Function type parsed (possibly nullptr in error case)
   */
  TypePtr function_type();
  /**
   * Parses a basic type only, no applied types (no 'for' or 'of') and no function types allowed.
   * Will show helpful errors if an applied or function type is found.
   * @param thing_to_look_for For the error message of the expect(IDENTIFIER)—this type always starts with an identifier—which are "Expecting " + thing_to_look_for
   * @return Basic type parsed (possibly nullptr in error case)
   */
  TypePtr basic_type(const std::string& thing_to_look_for);

  StmtNode statement();
  StmtNode if_statement();
  StmtNode while_statement();
  StmtNode each_statement();
  StmtNode for_statement();
  StmtNode break_statement();
  StmtNode continue_statement();
  StmtNode return_statement();

  StmtNode block();
  StmtNode block_or_statement();
  StmtNode optional_else_body();
  Token* loop_label();

  // Infix
  ExprNode binary_right_assoc(const ExprNode& left);
  ExprNode binary(const ExprNode& left);
  ExprNode infix_not(const ExprNode& left);
  ExprNode binary_is(const ExprNode& left);
  ExprNode comparison(const ExprNode& left);
  ExprNode if_expr(const ExprNode& left);
  // Postfix (treated as InfixFn)
  ExprNode postfix_inc_dec(const ExprNode& expr);
  ExprNode call(const ExprNode& expr);
  ExprNode subscript(const ExprNode& expr);
  ExprNode member(const ExprNode& expr);
  ExprNode namespace_member(const ExprNode& expr);
  // Prefix
  ExprNode unary();
  ExprNode prefix_not();
  ExprNode print();
  ExprNode list(ExprNode first_item);
  ExprNode map(const ExprNode& first_item);
  ExprNode collection();
  ExprNode string_interpolation();
  // Primary/atom
  ExprNode literal();
  ExprNode variable();
  ExprNode this_id();
  ExprNode super_id();
  ExprNode grouping();

  ExprNode parse_expression();
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

  #define UNUSED                     ParseRule {nullptr, nullptr, "", Precedence::NONE}
  #define INFIX_RULE(fn, name, prec) ParseRule {nullptr, &Parser::fn, name, Precedence::prec}
  #define PREFIX_RULE(fn, name)      ParseRule {&Parser::fn, nullptr, name, Precedence::NONE}
  #define BOTH(pre, in, name, prec)  ParseRule {&Parser::pre, &Parser::in, name, Precedence::prec}

  // @formatter:off; it will separate the comments from the rest of their lines, which is horrifying.
  // IMPORTANT: Prefix rules always have a precedence of none! Their precedence is decided by the parse_expression(prec) call inside them, not the parse rule table!
  // This means that for "BOTH" rules, the precedence only applies to the infix rule.
  std::array<ParseRule, 90> rules {{
    /* TOKEN_LEFT_PAREN    */ BOTH(grouping, call, "", POSTFIX),
    /* TOKEN_RIGHT_PAREN   */ UNUSED,
    /* TOKEN_LEFT_BRACKET  */ BOTH(collection, subscript, "", POSTFIX),
    /* TOKEN_RIGHT_BRACKET */ UNUSED,
    /* TOKEN_LEFT_BRACE    *//* INFIX_RULE(lambda_call, "", POSTFIX),*/ UNUSED,
    /* TOKEN_RIGHT_BRACE   */ UNUSED,
    /* TOKEN_SEMICOLON     */ UNUSED,
    /* TOKEN_COMMA         */ UNUSED,
    /* TOKEN_TILDE         */ PREFIX_RULE(unary, "~"),
    /* TOKEN_STAR          */ INFIX_RULE(binary, "*", FACTOR),
    /* TOKEN_STAR_STAR     */ INFIX_RULE(binary_right_assoc, "**", EXPONENT),
    /* TOKEN_STAR_EQ       */ UNUSED,
    /* TOKEN_STAR_STAR_EQ  */ UNUSED,
    /* TOKEN_MINUS         */ BOTH(unary, binary, "-", TERM),
    /* TOKEN_MINUS_MINUS   */ BOTH(unary, postfix_inc_dec, "--", POSTFIX),
    /* TOKEN_RIGHT_ARROW   */ UNUSED,
    /* TOKEN_MINUS_EQ      */ UNUSED,
    /* TOKEN_PLUS          */ INFIX_RULE(binary, "+", TERM),
    /* TOKEN_PLUS_PLUS     */ BOTH(unary, postfix_inc_dec, "++", POSTFIX),
    /* TOKEN_PLUS_EQ       */ UNUSED,
    /* TOKEN_DOT           */ INFIX_RULE(member, "", POSTFIX),
    /* TOKEN_DOT_DOT       */ INFIX_RULE(binary, "..", RANGE),
    /* TOKEN_DOT_DOT_LT    */ INFIX_RULE(binary, "..<", RANGE),
    /* TOKEN_QUEST         */ UNUSED,
    /* TOKEN_QUEST_COLON   */ INFIX_RULE(binary, "?:", NIL_COALESCING),
    /* TOKEN_QUEST_DOT     */ INFIX_RULE(member, "", POSTFIX),
    /* TOKEN_GT            */ INFIX_RULE(comparison, ">", COMPARISON),
    /* TOKEN_GT_GT         */ INFIX_RULE(binary, ">>", BIT_SHIFT),
    /* TOKEN_GT_EQ         */ INFIX_RULE(comparison, ">=", COMPARISON),
    /* TOKEN_LT            */ INFIX_RULE(comparison, "<", COMPARISON),
    /* TOKEN_LT_LT         */ INFIX_RULE(binary, "<<", BIT_SHIFT),
    /* TOKEN_LT_EQ         */ INFIX_RULE(comparison, "<=", COMPARISON),
    /* TOKEN_COLON         */ UNUSED,
    /* TOKEN_COLON_COLON   */ INFIX_RULE(namespace_member, "", ATOM),
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
    /* TOKEN_BANG          */ PREFIX_RULE(unary, "!"),
    /* TOKEN_BANG_EQ       */ INFIX_RULE(comparison, "!=", COMPARISON),
    /* TOKEN_EQ            */ UNUSED,
    /* TOKEN_EQ_EQ         */ INFIX_RULE(comparison, "==", COMPARISON),
    /* TOKEN_IDENTIFIER    */ PREFIX_RULE(variable, ""),
    /* TOKEN_STRING        */ PREFIX_RULE(literal, ""),
    /* TOKEN_INTERPOLATION */ PREFIX_RULE(string_interpolation, ""),
    /* TOKEN_CHAR          */ PREFIX_RULE(literal, ""),
    /* TOKEN_NUMBER        */ PREFIX_RULE(literal, ""),
    /* TOKEN_AND           */ INFIX_RULE(binary, "and", AND),
    /* TOKEN_BREAK         */ UNUSED,
    /* TOKEN_CLASS         */ UNUSED,
    /* TOKEN_CONTINUE      */ UNUSED,
    /* TOKEN_DO            */ UNUSED,
    /* TOKEN_EACH          */ UNUSED,
    /* TOKEN_ELIF          */ UNUSED,
    /* TOKEN_ELSE          */ UNUSED,
    /* TOKEN_FALSE         */ PREFIX_RULE(literal, ""),
    /* TOKEN_FOR           */ UNUSED, // TODO: Does this ever show up as an operator? How to handle it?
    /* TOKEN_FUN           *//* PREFIX_RULE(lambda, ""),*/ UNUSED,
    /* TOKEN_IF            */ INFIX_RULE(if_expr, "", IF),
    /* TOKEN_IN            */ INFIX_RULE(binary, "in", IN),
    /* TOKEN_IS            */ INFIX_RULE(binary_is, "", IS),
    /* TOKEN_NAMESPACE     */ UNUSED,
    /* TOKEN_NIL           */ PREFIX_RULE(literal, ""),
    /* TOKEN_NOT           */ BOTH(prefix_not, infix_not, "", IN),
    /* TOKEN_OF            */ UNUSED, // TODO: Does this ever show up as an operator? How to handle it?
    /* TOKEN_OR            */ INFIX_RULE(binary, "or", OR),
    /* TOKEN_OVERRIDE      */ UNUSED,
    /* TOKEN_PASS          */ UNUSED,
    /* TOKEN_PRINT         */ PREFIX_RULE(print, "print"),
    /* TOKEN_PRINT_ERROR   */ PREFIX_RULE(print, "print_err"),
    /* TOKEN_PRIVATE       */ UNUSED,
    /* TOKEN_RETURN        */ UNUSED,
    /* TOKEN_STATIC        */ UNUSED,
    /* TOKEN_SUPER         */ PREFIX_RULE(super_id, ""),
    /* TOKEN_THIS          */ PREFIX_RULE(this_id, ""),
    /* TOKEN_TRUE          */ PREFIX_RULE(literal, ""),
    /* TOKEN_USING         */ UNUSED,
    /* TOKEN_VAL           */ UNUSED,
    /* TOKEN_VAR           */ UNUSED,
    /* TOKEN_WHILE         */ UNUSED,
    /* TOKEN_INDENT        */ UNUSED,
    /* TOKEN_DEDENT        */ UNUSED,
    /* TOKEN_LINE          */ UNUSED,
    /* TOKEN_EOF           */ UNUSED,
  }};
  // @formatter:on
};
