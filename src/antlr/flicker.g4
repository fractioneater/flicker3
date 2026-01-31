parser grammar flicker;

tokens {
	// Single-character tokens (0 - 14)
	LEFT_PAREN, RIGHT_PAREN, LEFT_BRACKET, RIGHT_BRACKET, LEFT_BRACE, RIGHT_BRACE,
	SEMICOLON, COMMA, PLUS, SLASH, PERCENT, PIPE, CARET, AMPERSAND, TILDE,
	// 1-3 character tokens (15 - 31)
	DOT, DOT_DOT, DOT_DOT_LT,
	COLON, COLON_COLON,
	STAR, STAR_STAR,
	MINUS, RIGHT_ARROW,
	BANG, BANG_EQ,
	EQ, EQ_EQ,
	GT, GT_EQ,
	LT, LT_EQ,
	// Literals (32 - 36)
	IDENTIFIER, STRING, INTERPOLATION, CHAR, NUMBER,
	// Keywords (37 - 71)
	ALIAS, AND, ATTRIBUTE, BREAK, CLASS, CONTINUE, DO, EACH, ELIF, ELSE,
	FALSE, FOR, FUN, IF, IN, IS, NIL, NOT, OF, OR, PASS, PRINT,
	PRINT_ERROR, RETURN, SHL, SHR, STATIC, SUPER, THIS, TRUE, USE,
	VAL, VAR, WHEN, WHILE,
	// Whitespace (72 - 74)
	INDENT, DEDENT, LINE
}

program : newline* (topLevel statementEnd)* EOF;

newline : LINE+; // This one is just a plain newline.
statementEnd : newline | EOF; // This one is a statement end check.
topLevel : (statement | expression);

// ------------------------------

statement : declaration | keywordStatement;

declaration : variableDecl | functionDecl | classDecl | use;

variableDecl : (VAR | VAL) IDENTIFIER (COLON IDENTIFIER /*(QUEST)?*/)? (EQ expression)?;

functionDecl : FUN IDENTIFIER LEFT_PAREN (paramList)? RIGHT_PAREN (funcReturnType)? functionContents;

funcReturnType : (COLON | RIGHT_ARROW) IDENTIFIER; // TODO: Decide on a symbol.
functionContents : block | (EQ expression);

paramList : param (COMMA param)* ;
param : IDENTIFIER COLON IDENTIFIER /*(QUEST)?*/ ;

block : (DO)? newline INDENT blockBody DEDENT ;
blockBody : (topLevel statementEnd) * ;

classDecl : CLASS IDENTIFIER (LT IDENTIFIER)? classBody ;

classBody : NUMBER ; // TODO!

use : USE ((DOT | importList) OF)? STRING ;

importList : IDENTIFIER (COMMA IDENTIFIER) * ;

keywordStatement : ifStmt | whileStmt | eachStmt | forStmt | breakStmt | continueStmt | whenStmt | returnStmt | printStmt | consoleErrorStmt | passStmt ;

loopLabel : COLON IDENTIFIER ;

doStatement : DO topLevel ;
blockOrStatement : block | doStatement ;

ifStmt : IF expression blockOrStatement (ELIF expression blockOrStatement)* (ELSE blockOrStatement)? ;
whileStmt : WHILE (loopLabel)? expression blockOrStatement ;
eachStmt : EACH (loopLabel)? IDENTIFIER (LEFT_BRACKET IDENTIFIER RIGHT_BRACKET)? IN expression blockOrStatement ;
forStmt : FOR (loopLabel)? (variableDecl | expression)? SEMICOLON (expression)? SEMICOLON (expression)? blockOrStatement ;
breakStmt : BREAK (loopLabel)? ;
continueStmt : CONTINUE (loopLabel)? ;
whenStmt : WHEN expression whenBody ;
returnStmt : RETURN (expression)? ;
printStmt : PRINT expression ;
consoleErrorStmt : PRINT_ERROR expression ;
passStmt : PASS ;

whenBody : newline INDENT whenContents DEDENT ;
whenContents : (whenCase statementEnd) + (elseCase statementEnd)? ;
whenCase : expression blockOrStatement ;
elseCase : ELSE blockOrStatement ;

// ------------------------------

expression
	: IDENTIFIER                                                            #exprIdentifier
	| constantExpr                                                          #exprConstant
	| interpolationExpr                                                     #exprInterpolation
	| listOrMapLiteral                                                      #exprListOrMap
	| lambdaLiteral                                                         #exprLambda
	| parenthesizedExpr                                                     #exprParen
	| expression DOT IDENTIFIER                                             #exprMember
	| expression COLON_COLON IDENTIFIER                                     #exprStaticMember
	| expression LEFT_PAREN (expression (COMMA expression)*)? RIGHT_PAREN   #exprCall
	| expression LEFT_BRACKET (expression (COMMA expression)*) RIGHT_BRACKET #exprIndex
	| (MINUS | BANG | TILDE) expression                                     #exprPrefix
	| <assoc=right> expression STAR_STAR expression                         #exprPower
	| expression (SLASH | STAR) expression                                  #exprMulDivMod
	| expression (PLUS | MINUS) expression                                  #exprAddSub
	| expression (SHL | SHR) expression                                     #exprShift
	| expression (PIPE | AMPERSAND | CARET) expression                      #exprBitwiseB
	| expression comparisonOperator expression                              #exprCompare
	| expression (DOT_DOT | DOT_DOT_LT) expression                          #exprRange
	| expression AND expression                                             #exprAnd
	| expression OR expression                                              #exprOr
	| expression IF expression ELSE expression                              #exprIf
	| <assoc=right> expression EQ expression                                #exprAssign
	;

comparisonOperator : EQ_EQ | BANG_EQ | GT | GT_EQ | LT | LT_EQ ;

parenthesizedExpr : LEFT_PAREN expression RIGHT_PAREN ;

// There's no reason to have it blank, but it's still allowed.
interpolationExpr : INTERPOLATION expression STRING ;

constantExpr : NUMBER | TRUE | FALSE | NIL | STRING ;

listOrMapLiteral : listLiteral | mapLiteral ;
listLiteral : LEFT_BRACKET (listItems)? RIGHT_BRACKET ;

listItems : expression (COMMA expression)* (COMMA)? ; // Trailing commas allowed on lists and maps only.

mapLiteral : LEFT_BRACKET (RIGHT_ARROW | mapItems) RIGHT_BRACKET ;

mapItems : mapItem (COMMA mapItem)* (COMMA)? ; // See above.
mapItem : expression RIGHT_ARROW expression ;

lambdaLiteral : FUN lambdaParams ((RIGHT_ARROW lambdaBody) | (EQ expression)) ;

// If there are 0 params, there must be ().
lambdaParams : paramList | parenthesizedOptionalParamList ;
parenthesizedOptionalParamList : (LEFT_PAREN (paramList)? RIGHT_PAREN) ;

lambdaBody : braceBody | block ;

braceBody : LEFT_BRACE (statement (SEMICOLON)?)* RIGHT_BRACE ;
