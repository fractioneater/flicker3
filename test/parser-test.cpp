#include <gtest/gtest.h>

#include "antlr4-runtime.h"
#include "flicker.h"
#include "lexer-adapter.h"
#include "vm.h"

TEST(ParserTest, BasicVariableDeclaration) {
  std::string src = "var x = 42\n";
  Lexer flicker_lexer(src);
  antlr::LexerAdapter adapter(flicker_lexer, "test.fl");

  antlr4::CommonTokenStream tokens(&adapter);
  antlr::flicker parser(&tokens);

  auto tree = parser.program();

  EXPECT_EQ(parser.getNumberOfSyntaxErrors(), 0);
  EXPECT_NE(tree, nullptr);
}

TEST(ParserTest, MultipleStatements) {
  std::string src = "var x = 42\nprint x\n";
  Lexer flicker_lexer(src);
  antlr::LexerAdapter adapter(flicker_lexer, "test.fl");

  antlr4::CommonTokenStream tokens(&adapter);
  antlr::flicker parser(&tokens);

  auto tree = parser.program();

  EXPECT_EQ(parser.getNumberOfSyntaxErrors(), 0);
}

TEST(ParserTest, BlockWithIndentation) {
  std::string src = "if x\n  pass\n";
  Lexer flicker_lexer(src);
  antlr::LexerAdapter adapter(flicker_lexer, "test.fl");

  antlr4::CommonTokenStream tokens(&adapter);
  antlr::flicker parser(&tokens);

  auto tree = parser.program();

  EXPECT_EQ(parser.getNumberOfSyntaxErrors(), 0);
}

TEST(ParserTest, ComplexFunction) {
  std::string src =
    "fun add(a: Int, b: Int) -> Int\n"
    "  return a + b\n"
    "\n";
  Lexer flicker_lexer(src);
  antlr::LexerAdapter adapter(flicker_lexer, "test.fl");

  antlr4::CommonTokenStream tokens(&adapter);
  antlr::flicker parser(&tokens);

  auto tree = parser.program();

  EXPECT_EQ(parser.getNumberOfSyntaxErrors(), 0);
}
