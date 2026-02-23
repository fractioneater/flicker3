#include "lexer.h"
#include <gtest/gtest.h>

static Token scan_single(const std::string& src) {
  Lexer lexer {src};
  return lexer.next_token();
}

static std::vector<Token> scan_all(const std::string& src) {
  Lexer lexer {src};
  std::vector<Token> tokens;
  Token token;
  do {
    token = lexer.next_token();
    tokens.push_back(token);
  } while (token.type != TOKEN_EOF);
  return tokens;
}

static TokenType token_type(const std::string& src) {
  return scan_single(src).type;
}

// Single-character tokens
TEST(LexerTest, LeftParen) {
  EXPECT_EQ(token_type("("), TOKEN_LEFT_PAREN);
}

TEST(LexerTest, RightParen) {
  EXPECT_EQ(token_type(")"), TOKEN_RIGHT_PAREN);
}

TEST(LexerTest, LeftBracket) {
  EXPECT_EQ(token_type("["), TOKEN_LEFT_BRACKET);
}

TEST(LexerTest, RightBracket) {
  EXPECT_EQ(token_type("]"), TOKEN_RIGHT_BRACKET);
}

TEST(LexerTest, LeftBrace) {
  EXPECT_EQ(token_type("{"), TOKEN_LEFT_BRACE);
}

TEST(LexerTest, RightBrace) {
  EXPECT_EQ(token_type("}"), TOKEN_RIGHT_BRACE);
}

TEST(LexerTest, Semicolon) {
  EXPECT_EQ(token_type(";"), TOKEN_SEMICOLON);
}

TEST(LexerTest, Comma) {
  EXPECT_EQ(token_type(","), TOKEN_COMMA);
}

TEST(LexerTest, Plus) {
  EXPECT_EQ(token_type("+"), TOKEN_PLUS);
}

TEST(LexerTest, Slash) {
  EXPECT_EQ(token_type("/"), TOKEN_SLASH);
}

TEST(LexerTest, Percent) {
  EXPECT_EQ(token_type("%"), TOKEN_PERCENT);
}

TEST(LexerTest, Pipe) {
  EXPECT_EQ(token_type("|"), TOKEN_PIPE);
}

TEST(LexerTest, Caret) {
  EXPECT_EQ(token_type("^"), TOKEN_CARET);
}

TEST(LexerTest, Ampersand) {
  EXPECT_EQ(token_type("&"), TOKEN_AMPERSAND);
}

TEST(LexerTest, Tilde) {
  EXPECT_EQ(token_type("~"), TOKEN_TILDE);
}

// Multi-character tokens
TEST(LexerTest, Dot) {
  EXPECT_EQ(token_type("."), TOKEN_DOT);
}

TEST(LexerTest, DotDot) {
  EXPECT_EQ(token_type(".."), TOKEN_DOT_DOT);
}

TEST(LexerTest, DotDotLt) {
  EXPECT_EQ(token_type("..<"), TOKEN_DOT_DOT_LT);
}

TEST(LexerTest, Colon) {
  EXPECT_EQ(token_type(":"), TOKEN_COLON);
}

TEST(LexerTest, ColonColon) {
  EXPECT_EQ(token_type("::"), TOKEN_COLON_COLON);
}

TEST(LexerTest, Star) {
  EXPECT_EQ(token_type("*"), TOKEN_STAR);
}

TEST(LexerTest, StarStar) {
  EXPECT_EQ(token_type("**"), TOKEN_STAR_STAR);
}

TEST(LexerTest, Minus) {
  EXPECT_EQ(token_type("-"), TOKEN_MINUS);
}

TEST(LexerTest, RightArrow) {
  EXPECT_EQ(token_type("->"), TOKEN_RIGHT_ARROW);
}

TEST(LexerTest, Bang) {
  EXPECT_EQ(token_type("!"), TOKEN_BANG);
}

TEST(LexerTest, BangEq) {
  EXPECT_EQ(token_type("!="), TOKEN_BANG_EQ);
}

TEST(LexerTest, Eq) {
  EXPECT_EQ(token_type("="), TOKEN_EQ);
}

TEST(LexerTest, EqEq) {
  EXPECT_EQ(token_type("=="), TOKEN_EQ_EQ);
}

TEST(LexerTest, Gt) {
  EXPECT_EQ(token_type(">"), TOKEN_GT);
}

TEST(LexerTest, GtEq) {
  EXPECT_EQ(token_type(">="), TOKEN_GT_EQ);
}

TEST(LexerTest, Lt) {
  EXPECT_EQ(token_type("<"), TOKEN_LT);
}

TEST(LexerTest, LtEq) {
  EXPECT_EQ(token_type("<="), TOKEN_LT_EQ);
}

// Keywords
TEST(LexerTest, KeywordAlias) {
  EXPECT_EQ(token_type("alias"), TOKEN_ALIAS);
}

TEST(LexerTest, KeywordAnd) {
  EXPECT_EQ(token_type("and"), TOKEN_AND);
}

TEST(LexerTest, KeywordBreak) {
  EXPECT_EQ(token_type("break"), TOKEN_BREAK);
}

TEST(LexerTest, KeywordClass) {
  EXPECT_EQ(token_type("class"), TOKEN_CLASS);
}

TEST(LexerTest, KeywordContinue) {
  EXPECT_EQ(token_type("continue"), TOKEN_CONTINUE);
}

TEST(LexerTest, KeywordDo) {
  EXPECT_EQ(token_type("do"), TOKEN_DO);
}

TEST(LexerTest, KeywordEach) {
  EXPECT_EQ(token_type("each"), TOKEN_EACH);
}

TEST(LexerTest, KeywordElif) {
  EXPECT_EQ(token_type("elif"), TOKEN_ELIF);
}

TEST(LexerTest, KeywordElse) {
  EXPECT_EQ(token_type("else"), TOKEN_ELSE);
}

TEST(LexerTest, KeywordFalse) {
  EXPECT_EQ(token_type("false"), TOKEN_FALSE);
}

TEST(LexerTest, KeywordFor) {
  EXPECT_EQ(token_type("for"), TOKEN_FOR);
}

TEST(LexerTest, KeywordFun) {
  EXPECT_EQ(token_type("fun"), TOKEN_FUN);
}

TEST(LexerTest, KeywordIf) {
  EXPECT_EQ(token_type("if"), TOKEN_IF);
}

TEST(LexerTest, KeywordIn) {
  EXPECT_EQ(token_type("in"), TOKEN_IN);
}

TEST(LexerTest, KeywordIs) {
  EXPECT_EQ(token_type("is"), TOKEN_IS);
}

TEST(LexerTest, KeywordNil) {
  EXPECT_EQ(token_type("nil"), TOKEN_NIL);
}

TEST(LexerTest, KeywordNot) {
  EXPECT_EQ(token_type("not"), TOKEN_NOT);
}

TEST(LexerTest, KeywordOf) {
  EXPECT_EQ(token_type("of"), TOKEN_OF);
}

TEST(LexerTest, KeywordOr) {
  EXPECT_EQ(token_type("or"), TOKEN_OR);
}

TEST(LexerTest, KeywordPass) {
  EXPECT_EQ(token_type("pass"), TOKEN_PASS);
}

TEST(LexerTest, KeywordPrint) {
  EXPECT_EQ(token_type("print"), TOKEN_PRINT);
}

TEST(LexerTest, KeywordError) {
  EXPECT_EQ(token_type("error"), TOKEN_PRINT_ERROR);
}

TEST(LexerTest, KeywordReturn) {
  EXPECT_EQ(token_type("return"), TOKEN_RETURN);
}

TEST(LexerTest, KeywordShl) {
  EXPECT_EQ(token_type("shl"), TOKEN_SHL);
}

TEST(LexerTest, KeywordShr) {
  EXPECT_EQ(token_type("shr"), TOKEN_SHR);
}

TEST(LexerTest, KeywordStatic) {
  EXPECT_EQ(token_type("static"), TOKEN_STATIC);
}

TEST(LexerTest, KeywordSuper) {
  EXPECT_EQ(token_type("super"), TOKEN_SUPER);
}

TEST(LexerTest, KeywordThis) {
  EXPECT_EQ(token_type("this"), TOKEN_THIS);
}

TEST(LexerTest, KeywordTrue) {
  EXPECT_EQ(token_type("true"), TOKEN_TRUE);
}

TEST(LexerTest, KeywordUse) {
  EXPECT_EQ(token_type("use"), TOKEN_USE);
}

TEST(LexerTest, KeywordVal) {
  EXPECT_EQ(token_type("val"), TOKEN_VAL);
}

TEST(LexerTest, KeywordVar) {
  EXPECT_EQ(token_type("var"), TOKEN_VAR);
}

TEST(LexerTest, KeywordWhen) {
  EXPECT_EQ(token_type("when"), TOKEN_WHEN);
}

TEST(LexerTest, KeywordWhile) {
  EXPECT_EQ(token_type("while"), TOKEN_WHILE);
}

// Identifiers
TEST(LexerTest, SimpleIdentifier) {
  EXPECT_EQ(token_type("myVar"), TOKEN_IDENTIFIER);
}

TEST(LexerTest, IdentifierWithUnderscore) {
  EXPECT_EQ(token_type("my_var"), TOKEN_IDENTIFIER);
}

TEST(LexerTest, IdentifierWithNumbers) {
  EXPECT_EQ(token_type("var123"), TOKEN_IDENTIFIER);
}

TEST(LexerTest, BacktickIdentifier) {
  EXPECT_EQ(token_type("`my-var`"), TOKEN_IDENTIFIER);
}

TEST(LexerTest, BacktickIdentifierLength) {
  Token token = scan_single("`hello`");
  EXPECT_EQ(token.length, 5);
}

// Numbers
TEST(LexerTest, SimpleNumber) {
  EXPECT_EQ(token_type("123"), TOKEN_NUMBER);
}

TEST(LexerTest, NumberWithUnderscore) {
  EXPECT_EQ(token_type("1_000_000"), TOKEN_NUMBER);
}

TEST(LexerTest, DecimalNumber) {
  EXPECT_EQ(token_type("123.456"), TOKEN_NUMBER);
}

TEST(LexerTest, DecimalNotFollowedByDigit) {
  const auto tokens {scan_all("1.property")};
  EXPECT_EQ(tokens[0].type, TOKEN_NUMBER);
  EXPECT_EQ(tokens[1].type, TOKEN_DOT);
  EXPECT_EQ(tokens[2].type, TOKEN_IDENTIFIER);
}

TEST(LexerTest, NumberWithExponent) {
  EXPECT_EQ(token_type("1.5E10"), TOKEN_NUMBER);
}

TEST(LexerTest, NumberWithPlusExponent) {
  EXPECT_EQ(token_type("1.5E+10"), TOKEN_NUMBER);
}

TEST(LexerTest, NumberWithNegativeExponent) {
  EXPECT_EQ(token_type("1.5E-10"), TOKEN_NUMBER);
}

TEST(LexerTest, HexNumber) {
  EXPECT_EQ(token_type("0x1F"), TOKEN_NUMBER);
}

TEST(LexerTest, BinaryNumber) {
  EXPECT_EQ(token_type("0b1010"), TOKEN_NUMBER);
}

// Strings
TEST(LexerTest, SimpleString) {
  EXPECT_EQ(token_type("\"hello\""), TOKEN_STRING);
}

TEST(LexerTest, StringWithEscapeSequence) {
  EXPECT_EQ(token_type("\"hello\\nworld\""), TOKEN_STRING);
}

TEST(LexerTest, StringWithBackslash) {
  EXPECT_EQ(token_type("\"path\\\\to\\\\file\""), TOKEN_STRING);
}

TEST(LexerTest, StringWithQuote) {
  EXPECT_EQ(token_type("\"say \\\"hello\\\"\""), TOKEN_STRING);
}

TEST(LexerTest, StringWithUnicodeEscape) {
  EXPECT_EQ(token_type("\"\\u0041\""), TOKEN_STRING);
}

TEST(LexerTest, StringWithHexEscape) {
  EXPECT_EQ(token_type("\"\\x41\""), TOKEN_STRING);
}

TEST(LexerTest, StringMultiline) {
  EXPECT_EQ(token_type("\"hello\nworld\""), TOKEN_STRING);
}

TEST(LexerTest, StringWithInterpolation) {
  EXPECT_EQ(token_type("\"hello =(name)\""), TOKEN_INTERPOLATION);
}

// Characters
TEST(LexerTest, SimpleCharacter) {
  EXPECT_EQ(token_type("'a'"), TOKEN_CHAR);
}

TEST(LexerTest, CharacterBackslash) {
  EXPECT_EQ(token_type("'\\\\'"), TOKEN_CHAR);
}

TEST(LexerTest, CharacterQuote) {
  EXPECT_EQ(token_type("'\\''"), TOKEN_CHAR);
}

TEST(LexerTest, CharacterTab) {
  EXPECT_EQ(token_type("'\\t'"), TOKEN_CHAR);
}

// Comments
TEST(LexerTest, LineComment) {
  auto tokens = scan_all("123 # comment");
  EXPECT_EQ(tokens[0].type, TOKEN_NUMBER);
  EXPECT_EQ(tokens[1].type, TOKEN_EOF);
}

TEST(LexerTest, BlockComment) {
  auto tokens = scan_all("123 #: comment # 456");
  EXPECT_EQ(tokens[0].type, TOKEN_NUMBER);
  EXPECT_EQ(tokens[1].type, TOKEN_NUMBER);
  EXPECT_EQ(tokens[2].type, TOKEN_EOF);
}

TEST(LexerTest, NestedBlockComment) {
  auto tokens = scan_all("123 #: outer #: inner # end # 456");
  EXPECT_EQ(tokens[0].type, TOKEN_NUMBER);
  EXPECT_EQ(tokens[1].type, TOKEN_NUMBER);
  EXPECT_EQ(tokens[2].type, TOKEN_EOF);
}

// Whitespace and line handling
TEST(LexerTest, SkipWhitespace) {
  auto tokens = scan_all("123   456");
  EXPECT_EQ(tokens[0].type, TOKEN_NUMBER);
  EXPECT_EQ(tokens[1].type, TOKEN_NUMBER);
  EXPECT_EQ(tokens[2].type, TOKEN_EOF);
}

TEST(LexerTest, NewlineToken) {
  auto tokens = scan_all("123\n456");
  EXPECT_EQ(tokens[0].type, TOKEN_NUMBER);
  EXPECT_EQ(tokens[1].type, TOKEN_LINE);
  EXPECT_EQ(tokens[2].type, TOKEN_NUMBER);
  EXPECT_EQ(tokens[3].type, TOKEN_EOF);
}

TEST(LexerTest, Indentation) {
  const auto tokens = scan_all("fun foo\n  bar");
  EXPECT_EQ(tokens[0].type, TOKEN_FUN);
  EXPECT_EQ(tokens[1].type, TOKEN_IDENTIFIER);
  EXPECT_EQ(tokens[2].type, TOKEN_LINE);
  EXPECT_EQ(tokens[3].type, TOKEN_INDENT);
  EXPECT_EQ(tokens[4].type, TOKEN_IDENTIFIER);
}

TEST(LexerTest, Dedentation) {
  const auto tokens = scan_all("if true\n  foo\nbar");
  bool found_dedent = false;
  for (const auto& token : tokens) {
    if (token.type == TOKEN_DEDENT) {
      found_dedent = true;
      break;
    }
  }
  EXPECT_TRUE(found_dedent);
}

TEST(LexerTest, DedentsAtEOFNoFinalNewline) {
  const auto tokens = scan_all("if true\n  if truer\n    foo");
  EXPECT_EQ(tokens[0].type, TOKEN_IF);
  EXPECT_EQ(tokens[1].type, TOKEN_TRUE);
  EXPECT_EQ(tokens[2].type, TOKEN_LINE);
  EXPECT_EQ(tokens[3].type, TOKEN_INDENT);
  EXPECT_EQ(tokens[4].type, TOKEN_IF);
  EXPECT_EQ(tokens[5].type, TOKEN_IDENTIFIER);
  EXPECT_EQ(tokens[6].type, TOKEN_LINE);
  EXPECT_EQ(tokens[7].type, TOKEN_INDENT);
  EXPECT_EQ(tokens[8].type, TOKEN_IDENTIFIER);
  EXPECT_EQ(tokens[9].type, TOKEN_DEDENT);
  EXPECT_EQ(tokens[10].type, TOKEN_DEDENT);
  EXPECT_EQ(tokens[11].type, TOKEN_EOF);
}

TEST(LexerTest, DedentsAtEOFWithCommentLine) {
  const auto tokens = scan_all("if true\n  if truer\n    foo\n# comment");
  EXPECT_EQ(tokens[0].type, TOKEN_IF);
  EXPECT_EQ(tokens[1].type, TOKEN_TRUE);
  EXPECT_EQ(tokens[2].type, TOKEN_LINE);
  EXPECT_EQ(tokens[3].type, TOKEN_INDENT);
  EXPECT_EQ(tokens[4].type, TOKEN_IF);
  EXPECT_EQ(tokens[5].type, TOKEN_IDENTIFIER);
  EXPECT_EQ(tokens[6].type, TOKEN_LINE);
  EXPECT_EQ(tokens[7].type, TOKEN_INDENT);
  EXPECT_EQ(tokens[8].type, TOKEN_IDENTIFIER);
  EXPECT_EQ(tokens[9].type, TOKEN_LINE);
  EXPECT_EQ(tokens[10].type, TOKEN_DEDENT);
  EXPECT_EQ(tokens[11].type, TOKEN_DEDENT);
  EXPECT_EQ(tokens[12].type, TOKEN_EOF);
}

// Token position tracking
TEST(LexerTest, TokenLine) {
  Token token = scan_single("hello");
  EXPECT_EQ(token.line, 1);
}

TEST(LexerTest, TokenLineMultiple) {
  Lexer lexer {"\nhello"};
  lexer.next_token();
  Token token = lexer.next_token();
  EXPECT_EQ(token.line, 2);
}

TEST(LexerTest, TokenColumn) {
  const auto tokens { scan_all("hello\n  hello again")};
  EXPECT_EQ(tokens[0].col, 1);
  EXPECT_EQ(tokens[1].col, 6); // Line
  EXPECT_EQ(tokens[2].col, 1); // Indent
  EXPECT_EQ(tokens[3].col, 3);
  EXPECT_EQ(tokens[4].col, 9);
}

TEST(LexerTest, TokenLength) {
  const auto tokens { scan_all("hello\n  hello again")};
  EXPECT_EQ(tokens[0].length, 5);
  EXPECT_EQ(tokens[1].length, 1); // Line
  EXPECT_EQ(tokens[2].length, 2); // Indent
  EXPECT_EQ(tokens[3].length, 5);
  EXPECT_EQ(tokens[4].length, 5);
}

TEST(LexerTest, TokenStartChar) {
  Token token = scan_single("hello");
  EXPECT_EQ(token.start_offset, 0);
}

// Complex expressions
TEST(LexerTest, ArithmeticExpression) {
  auto tokens = scan_all("1 + 2 * 3");
  EXPECT_EQ(tokens[0].type, TOKEN_NUMBER);
  EXPECT_EQ(tokens[1].type, TOKEN_PLUS);
  EXPECT_EQ(tokens[2].type, TOKEN_NUMBER);
  EXPECT_EQ(tokens[3].type, TOKEN_STAR);
  EXPECT_EQ(tokens[4].type, TOKEN_NUMBER);
  EXPECT_EQ(tokens[5].type, TOKEN_EOF);
}

// Error cases
TEST(LexerTest, UnterminatedString) {
  Lexer lexer {R"("hello)"};
  EXPECT_THROW(lexer.next_token(), LexerError);
}

TEST(LexerTest, UnterminatedCharacter) {
  Lexer lexer {R"('h)"};
  EXPECT_THROW(lexer.next_token(), LexerError);
}

TEST(LexerTest, EmptyCharacter) {
  Lexer lexer {R"('')"};
  EXPECT_THROW(lexer.next_token(), LexerError);
}

TEST(LexerTest, InvalidEscapeInString) {
  Lexer lexer {R"("\q")"};
  EXPECT_THROW(lexer.next_token(), LexerError);
}

TEST(LexerTest, UnterminatedBlockComment) {
  Lexer lexer {"#: unclosed"};
  EXPECT_THROW(lexer.next_token(), LexerError);
}

TEST(LexerTest, UnterminatedBacktickIdentifier) {
  Lexer lexer {"`hello"};
  EXPECT_THROW(lexer.next_token(), LexerError);
}

TEST(LexerTest, EmptyBacktickIdentifier) {
  Lexer lexer {"``"};
  EXPECT_THROW(lexer.next_token(), LexerError);
}

TEST(LexerTest, HexWithoutDigits) {
  Lexer lexer {"0x"};
  EXPECT_THROW(lexer.next_token(), LexerError);
}

TEST(LexerTest, BinaryWithoutDigits) {
  Lexer lexer {"0b"};
  EXPECT_THROW(lexer.next_token(), LexerError);
}

TEST(LexerTest, UnderscoreNotFollowedByDigit) {
  Lexer lexer {"1_a"};
  EXPECT_THROW(lexer.next_token(), LexerError);
}

TEST(LexerTest, ExponentNotFollowedByDigits) {
  Lexer lexer {"1E"};
  EXPECT_THROW(lexer.next_token(), LexerError);
}

TEST(LexerTest, UnexpectedCharacter) {
  Lexer lexer {"@"};
  EXPECT_THROW(lexer.next_token(), LexerError);
}

TEST(LexerTest, InvalidIndentation) {
  Lexer lexer {"if true\n  foo\n bar"};
  while (true) {
    try {
      Token token = lexer.next_token();
      if (token.type == TOKEN_EOF) break;
    } catch (const LexerError&) {
      return;
    }
  }
  FAIL() << "Expected LexerError for invalid indentation";
}

// Confusion (warnings):
TEST(LexerTest, CommentBeforeCode) {
  Lexer lexer {"fun not_fun\n  #: what's this?#     print 3"};
  std::vector<Token> tokens;
  Token token;
  do {
    token = lexer.next_token();
    tokens.push_back(token);
  } while (token.type != TOKEN_EOF);
  EXPECT_EQ(tokens[0].type, TOKEN_FUN);
  EXPECT_EQ(tokens[1].type, TOKEN_IDENTIFIER);
  EXPECT_EQ(tokens[2].type, TOKEN_LINE);
  EXPECT_EQ(tokens[3].type, TOKEN_INDENT);
  EXPECT_EQ(tokens[3].length, 23);
  EXPECT_EQ(tokens[4].type, TOKEN_PRINT);
  EXPECT_EQ(tokens[4].col, 24);
  EXPECT_EQ(tokens[5].type, TOKEN_NUMBER);
  EXPECT_EQ(tokens[6].type, TOKEN_DEDENT);
  EXPECT_EQ(tokens[7].type, TOKEN_EOF);
  EXPECT_FALSE(lexer.get_warnings().empty());
}

TEST(LexerTest, BinaryWithInvalidDigit) {
  Lexer lexer {"0b102"};
  std::vector<Token> tokens;
  Token token;
  do {
    token = lexer.next_token();
    tokens.push_back(token);
  } while (token.type != TOKEN_EOF);
  EXPECT_FALSE(lexer.get_warnings().empty());
}

TEST(LexerTest, NumberWithInvalidDigit) {
  Lexer lexer {"102C"};
  std::vector<Token> tokens;
  Token token;
  do {
    token = lexer.next_token();
    tokens.push_back(token);
  } while (token.type != TOKEN_EOF);
  EXPECT_FALSE(lexer.get_warnings().empty());
}

TEST(LexerTest, HexWithInvalidDigit) {
  Lexer lexer {"0x10gA"};
  std::vector<Token> tokens;
  Token token;
  do {
    token = lexer.next_token();
    tokens.push_back(token);
  } while (token.type != TOKEN_EOF);
  EXPECT_FALSE(lexer.get_warnings().empty());
}
