#include "parser.h"

#include <gtest/gtest.h>

#include "lexer.h"
#include "vm.h"

TEST(ParserTest, BasicVariableDeclaration) {
  const std::string src {"var x = 42\n"};
  Lexer lexer {src};
  Parser parser {lexer};
  parser.populate_token_vec();
  parser.parse();
  EXPECT_TRUE(parser.get_errors().empty());
}

TEST(ParserTest, MultipleStatements) {
  const std::string src {"var x = 42\nprint x\n"};
  Lexer lexer {src};
  Parser parser {lexer};
  parser.populate_token_vec();
  parser.parse();
  EXPECT_TRUE(parser.get_errors().empty());
}

TEST(ParserTest, BlockWithIndentation) {
  const std::string src {"if x\n  pass\n"};
  Lexer lexer {src};
  Parser parser {lexer};
  parser.populate_token_vec();
  parser.parse();
  EXPECT_TRUE(parser.get_errors().empty());
}

TEST(ParserTest, ComplexFunction) {
  const std::string src {
    "fun add(a: Int, b: Int) -> Int\n"
    "  return a + b\n"
    "\n"
  };
  Lexer lexer {src};
  Parser parser {lexer};
  parser.populate_token_vec();
  parser.parse();
  EXPECT_TRUE(parser.get_errors().empty());
}
