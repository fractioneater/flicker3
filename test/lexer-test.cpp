#include "lexer.h"

#include <gtest/gtest.h>

TEST(Lexer, SimpleExpression) {
  Lexer lexer {"3 + 2 - 1"};
  int token_count {};
  while (lexer.next_token().type != TOKEN_EOF)
    token_count++;
  EXPECT_EQ(token_count, 5);
}
