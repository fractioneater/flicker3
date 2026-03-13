#include "lexer.h"

#include <fstream>
#include <sstream>
#include <gtest/gtest.h>

#include "lexer-adapter.h"
#include "parser.h"

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

static bool has_error(const std::string& src) {
  Lexer lexer {src};
  while (lexer.next_token().type != TOKEN_EOF) {}
  return !lexer.get_errors().empty();
}

static bool has_warning(const std::string& src) {
  Lexer lexer {src};
  while (lexer.next_token().type != TOKEN_EOF) {}
  return !lexer.get_warnings().empty();
}

// REAL TESTS (written for a very specific reason):
// Comment
TEST(Comment, BlockCommentMaxNest) {
  std::string src = "#-";
  for (int i = 0; i < MAX_COMMENT_NEST; ++i) src += " #-";
  for (int i = 0; i <= MAX_COMMENT_NEST; ++i) src += " -#";
  EXPECT_TRUE(has_error(src));
}

TEST(Comment, BlockCommentUnclosed) {
  EXPECT_TRUE(has_error("#- unclosed"));
}

TEST(Comment, FileTest) {
  std::ifstream file("../test/lexer/comment.fl");
  if (!file.is_open()) {
    FAIL() << "Could not open test/lexer/comment.fl";
  }
  std::stringstream buffer;
  buffer << file.rdbuf();
  std::string source = buffer.str();
  Lexer lexer {source};

  antlr::LexerAdapter adapter {lexer, "comment-test"};
  antlr4::CommonTokenStream token_stream {&adapter};
  Parser parser {&token_stream};

  token_stream.fill();
  EXPECT_TRUE(lexer.get_errors().empty());

  const bool parse_success {parser.parse()};
  EXPECT_TRUE(parse_success);
}

// Identifier
TEST(Identifier, BacktickIdentifierUnclosed) {
  EXPECT_TRUE(has_error("`unclosed"));
}

TEST(Identifier, BacktickIdentifierEmpty) {
  EXPECT_TRUE(has_error("``"));
}

TEST(Identifier, BacktickIdentifierLength) {
  const Token token {scan_single("`four`")};
  EXPECT_EQ(token.length, 4);
}

TEST(Identifier, FileTest) {
  std::ifstream file("../test/lexer/identifier.fl");
  if (!file.is_open()) {
    FAIL() << "Could not open test/lexer/identifier.fl";
  }
  std::stringstream buffer;
  buffer << file.rdbuf();
  std::string source = buffer.str();
  Lexer lexer {source};

  antlr::LexerAdapter adapter {lexer, "identifier-test"};
  antlr4::CommonTokenStream token_stream {&adapter};
  Parser parser {&token_stream};

  token_stream.fill();
  EXPECT_TRUE(lexer.get_errors().empty());

  const bool parse_success {parser.parse()};
  EXPECT_TRUE(parse_success);
}

// Number
TEST(Number, UnderscoreInvalid) {
  EXPECT_TRUE(has_error("32_"));
  EXPECT_TRUE(has_error("32_x"));
  EXPECT_FALSE(has_error("0x32_f"));
}

TEST(Number, UnderscoreBeforeExponent) {
  EXPECT_TRUE(has_error("32_E+20"));
}

TEST(Number, EmptyExponent) {
  EXPECT_TRUE(has_error("2.1E"));
}

TEST(Number, LonelyBasePrefix) {
  EXPECT_TRUE(has_error("0x"));
  EXPECT_TRUE(has_error("0b"));
}

TEST(Number, LowercaseE) {
  EXPECT_TRUE(has_warning("1.6e2"));
}

TEST(Number, SuspiciousChar) {
  EXPECT_TRUE(has_warning("0xabcdefg"));
  EXPECT_TRUE(has_warning("0b102"));
  EXPECT_TRUE(has_warning("882i"));
}

TEST(Number, FileTest) {
  std::ifstream file("../test/lexer/number.fl");
  if (!file.is_open()) {
    FAIL() << "Could not open test/lexer/number.fl";
  }
  std::stringstream buffer;
  buffer << file.rdbuf();
  std::string source = buffer.str();
  Lexer lexer {source};

  antlr::LexerAdapter adapter {lexer, "number-test"};
  antlr4::CommonTokenStream token_stream {&adapter};
  Parser parser {&token_stream};

  token_stream.fill();
  EXPECT_TRUE(lexer.get_errors().empty());

  const bool parse_success {parser.parse()};
  EXPECT_TRUE(parse_success);
}

// Strings + Chars
TEST(String, FileTest) {
  std::ifstream file("../test/lexer/string.fl");
  if (!file.is_open()) {
    FAIL() << "Could not open test/lexer/string.fl";
  }
  std::stringstream buffer;
  buffer << file.rdbuf();
  std::string source = buffer.str();
  Lexer lexer {source};

  antlr::LexerAdapter adapter {lexer, "string-test"};
  antlr4::CommonTokenStream token_stream {&adapter};
  Parser parser {&token_stream};

  token_stream.fill();
  EXPECT_TRUE(lexer.get_errors().empty());

  const bool parse_success {parser.parse()};
  EXPECT_TRUE(parse_success);
}

// BELOW THIS POINT, TESTS ARE NOT SPECIFIC AND TARGETED. A lot of them are not useful, and there are many missing, but I'll fix that.
// TODO: Finish curating (errors)

// Error cases
TEST(LexerTest, UnterminatedString) {
  EXPECT_TRUE(has_error(R"("hello)"));
}

TEST(LexerTest, UnterminatedCharacter) {
  EXPECT_TRUE(has_error(R"('h)"));
}

TEST(LexerTest, EmptyCharacter) {
  EXPECT_TRUE(has_error(R"('')"));
}

TEST(LexerTest, InvalidEscapeInString) {
  EXPECT_TRUE(has_error(R"("\q")"));
}

TEST(LexerTest, UnexpectedCharacter) {
  EXPECT_TRUE(has_error("@"));
}

TEST(LexerTest, InvalidIndentation) {
  EXPECT_TRUE(has_error("if true\n  foo\n bar"));
}
