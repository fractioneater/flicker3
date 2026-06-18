#include "parser.h"

#include <fstream>
#include <gtest/gtest.h>

#include "vm.h"

import lexer;

TEST(GeneralParsing, BasicVariableDeclaration) {
  const std::string src {"var x = 42\n"};
  Lexer lexer {src};
  Parser parser {lexer};
  parser.parse();
  EXPECT_TRUE(parser.get_diagnostics().empty());
}

TEST(GeneralParsing, MultipleStatements) {
  const std::string src {"var x = 42\nprint x\n"};
  Lexer lexer {src};
  Parser parser {lexer};
  parser.parse();
  EXPECT_TRUE(parser.get_diagnostics().empty());
}

TEST(GeneralParsing, BlockWithIndentation) {
  const std::string src {"if x\n  pass\n"};
  Lexer lexer {src};
  Parser parser {lexer};
  parser.parse();
  EXPECT_TRUE(parser.get_diagnostics().empty());
}

TEST(GeneralParsing, ComplexFunction) {
  const std::string src {
    "fun add(a: Int, b: Int) -> Int\n"
    "  return a + b\n"
  };
  Lexer lexer {src};
  Parser parser {lexer};
  parser.parse();
  EXPECT_TRUE(parser.get_diagnostics().empty());
}

// Error recovery!

TEST(ErrorRecovery, SyncEndAtDedent) {
  const std::string src {
    "if true 3\n"
    "  print \"a\"\n"
    "else\n"
    "  print \"b\"\n"
  };
  Lexer lexer {src};
  Parser parser {lexer};
  parser.parse();
  EXPECT_EQ(parser.get_diagnostics().size(), 1);
}

TEST(ErrorRecovery, RandomIndent) {
  const std::string src {
    "if true do 3\n"
    "  print \"a\"\n"
    "else\n"
    "  print \"b\"\n"
  };
  Lexer lexer {src};
  Parser parser {lexer};
  parser.parse();
  EXPECT_EQ(parser.get_diagnostics().size(), 1);
}

TEST(ErrorRecovery, MissingIndent) {
  const std::string src {
    "if true or false\n"
    "print \"a\"\n"
    "  print \"b\"\n"
  };
  Lexer lexer {src};
  Parser parser {lexer};
  parser.parse();
  EXPECT_EQ(parser.get_diagnostics().size(), 1);
}

TEST(ErrorRecovery, Weird) {
  const std::string src {
    "if true or false\n"
    "  print \"a\" \"b\"\n"
  };
  Lexer lexer {src};
  Parser parser {lexer};
  parser.parse();
  EXPECT_EQ(parser.get_diagnostics().size(), 1);
}

TEST(ErrorRecovery, RandomBlock) {
  const std::string src {
    "var a = 3\n"
    "  print a\n"
    "  print \"a\"\n"
  };
  Lexer lexer {src};
  Parser parser {lexer};
  parser.parse();
  EXPECT_EQ(parser.get_diagnostics().size(), 1);
}

TEST(ErrorRecovery, ErrorInsideRandomBlock) {
  const std::string src {
    "var a = 3\n"
    "  var b = 3\n"
    "  if true\n"
    "    print \"exactly\"\n"
    "    print 3::3\n"
    "  var c = 3\n"
    "var d = 32\n"
  };
  Lexer lexer {src};
  Parser parser {lexer};
  parser.parse();
  EXPECT_EQ(parser.get_diagnostics().size(), 2);
}

TEST(ErrorRecovery, RandomBlockInNamespaceBeforeEOF) {
  const std::string src {
    "namespace Hmmm\n"
    "  var a = 1\n"
    "  val b = 1\n"
    "    var x = 3\n"
  };
  Lexer lexer {src};
  Parser parser {lexer};
  parser.parse();
  EXPECT_EQ(parser.get_diagnostics().size(), 1);
}
