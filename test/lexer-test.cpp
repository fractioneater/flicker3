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

// Each section here will start with a "file test." These are in test/lexer/...
// The file tests should (in theory) cover everything CORRECT about the item being tested.
// The rest of the section ensures INCORRECT code is handled properly (errors, warnings).

// Comment
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

TEST(Comment, BlockCommentMaxNest) {
  std::string src = "#-";
  for (int i = 0; i < MAX_COMMENT_NEST; ++i) src += " #-";
  for (int i = 0; i <= MAX_COMMENT_NEST; ++i) src += " -#";
  EXPECT_TRUE(has_error(src));
}

TEST(Comment, BlockCommentUnclosed) {
  EXPECT_TRUE(has_error("#- unclosed"));
}

// Identifier
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

// Number
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

TEST(String, Unterminated) {
  EXPECT_TRUE(has_error("\"no closing quote"));
  EXPECT_TRUE(has_error("'e"));
  EXPECT_TRUE(has_error("'"));
}

TEST(String, EmptyChar) {
  EXPECT_TRUE(has_error("''"));
}

TEST(String, InvalidEscape) {
  EXPECT_TRUE(has_error("\"\\6\""));
  EXPECT_TRUE(has_error("'\\6'"));
}

// Indentation + Lambdas
TEST(Indentation, FileTest) {
  std::ifstream file("../test/lexer/indent.fl");
  if (!file.is_open()) {
    FAIL() << "Could not open test/lexer/indent.fl";
  }
  std::stringstream buffer;
  buffer << file.rdbuf();
  std::string source = buffer.str();
  Lexer lexer {source};

  antlr::LexerAdapter adapter {lexer, "indent-test"};
  antlr4::CommonTokenStream token_stream {&adapter};
  Parser parser {&token_stream};

  token_stream.fill();
  EXPECT_TRUE(lexer.get_errors().empty());

  const bool parse_success {parser.parse()};
  EXPECT_TRUE(parse_success);
}

TEST(Indentation, NoPrevMatchingIndent) {
  EXPECT_TRUE(has_error("if true\n  foo\n bar"));
}

TEST(Indentation, Tabs) {
  EXPECT_TRUE(has_error("\t"));
}

// It may feel like there are things missing here (for lambdas especially), but they're tests for the parser, not the lexer.

// Other little things
TEST(Misc, UnexpectedCharacter) {
  EXPECT_TRUE(has_error("@$"));
}
