#include <gtest/gtest.h>
#include "lexer-adapter.h"

using namespace antlr;

TEST(LexerAdapterTest, BasicTokens) {
    std::string src = "var x = 42;";
    Lexer flicker_lexer(src);
    LexerAdapter adapter(flicker_lexer, "test.fl");

    // var
    auto token = adapter.nextToken();
    EXPECT_EQ(token->getText(), "var");
    // Lexer TOKEN_VAR is 69 (counting from 0, it's the 70th item)
    // Map: TOKEN_VAR (69) + 1 = 70.
    // In flicker.g4, VAR is indeed at index 69 (0-indexed).
    // tokens { LEFT_PAREN(0) ... VAR(69) ... }
    EXPECT_EQ(token->getType(), 70);
    
    EXPECT_EQ(token->getLine(), 1);
    EXPECT_EQ(token->getCharPositionInLine(), 0);

    // x
    token = adapter.nextToken();
    EXPECT_EQ(token->getText(), "x");
    EXPECT_EQ(token->getCharPositionInLine(), 4);

    // =
    token = adapter.nextToken();
    EXPECT_EQ(token->getText(), "=");

    // 42
    token = adapter.nextToken();
    EXPECT_EQ(token->getText(), "42");

    // ;
    token = adapter.nextToken();
    EXPECT_EQ(token->getText(), ";");

    // EOF
    token = adapter.nextToken();
    EXPECT_EQ(token->getType(), antlr4::Token::EOF);
}

TEST(LexerAdapterTest, Indentation) {
    std::string src = "if x:\n  pass";
    Lexer flicker_lexer(src);
    LexerAdapter adapter(flicker_lexer);

    // if
    auto token = adapter.nextToken();
    EXPECT_EQ(token->getText(), "if");

    // x
    token = adapter.nextToken();
    EXPECT_EQ(token->getText(), "x");

    // :
    token = adapter.nextToken();
    EXPECT_EQ(token->getText(), ":");

    // LINE
    token = adapter.nextToken();
    // Lexer might produce TOKEN_LINE here.
    
    // INDENT
    token = adapter.nextToken();
    // pass
    token = adapter.nextToken();
    EXPECT_EQ(token->getText(), "pass");

    // EOF (and possible DEDENTs)
}
