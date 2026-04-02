/**
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

parser grammar flicker;

tokens {
  // Single-character tokens
  LEFT_PAREN, RIGHT_PAREN, LEFT_BRACKET, RIGHT_BRACKET, LEFT_BRACE, RIGHT_BRACE, SEMICOLON, COMMA, TILDE,
  // Single or multi-character tokens
  STAR, STAR_STAR, STAR_EQ, STAR_STAR_EQ,
  MINUS, MINUS_MINUS, RIGHT_ARROW, MINUS_EQ,
  PLUS, PLUS_PLUS, PLUS_EQ,
  DOT, DOT_DOT, DOT_DOT_LT,
  QUEST, QUEST_COLON, QUEST_DOT,
  GT, GT_GT, GT_EQ,
  LT, LT_LT, LT_EQ,
  COLON, COLON_COLON,
  SLASH, SLASH_EQ,
  PERCENT, PERCENT_EQ,
  PIPE, PIPE_EQ,
  CARET, CARET_EQ,
  AMPERSAND, AMPERSAND_EQ,
  BANG, BANG_EQ,
  EQ, EQ_EQ,
  // Literals
  IDENTIFIER, STRING, INTERPOLATION, CHAR, NUMBER,
  // Keywords
  AND, BREAK, CLASS, CONTINUE, DO, EACH, ELIF, ELSE, FALSE, FOR, FUN, IF,
  IN, IS, NAMESPACE, NIL, NOT, OF, OR, OVERRIDE, PASS, PRINT, PRINT_ERROR, PRIVATE,
  RETURN, STATIC, SUPER, THIS, TRUE, USING, VAL, VAR, WHEN, WHILE,
  // Whitespace
  INDENT, DEDENT, LINE
}

// RULES (important):
// If a grammar rule involves a block, it must work WITH OR WITHOUT a newline before the closing dedent.

program : newline? (codeItem newline)* codeItem? EOF ;

newline : LINE+ ; // This one is just a plain newline.

codeItem : statement | expression ;

type : IDENTIFIER QUEST? ((OF | FOR) IDENTIFIER QUEST?)? ;
// List of Int, Bagel?, List? of Bagel?, FunctionWrapper? for SpecialFunction
// TODO: I need things like "map for A, B"

// Statement ------------------------------

statement
	: declaration
	| ifStmt
	| whileStmt
	| eachStmt
	| forStmt
	| whenStmt
	| breakStmt
	| continueStmt
	| returnStmt
	| passStmt
	;

declaration
  : variableDecl
  | functionDecl
  | classDecl
  | usingStatement
  | namespace
  ;

namespace : NAMESPACE IDENTIFIER newline INDENT (declaration newline)* declaration? DEDENT ;
variableDecl : (VAR | VAL) IDENTIFIER (COLON type)? (EQ expression)?;

typeParam : (OF | FOR) IDENTIFIER ;
functionDecl : FUN IDENTIFIER typeParam? LEFT_PAREN (paramList)? RIGHT_PAREN (funcReturnType)? functionContents;

funcReturnType : (COLON | RIGHT_ARROW) IDENTIFIER; // TODO: Decide on a symbol.
functionContents : blockOrStatement | (EQ expression);

paramList : param (COMMA param)* ;
param : IDENTIFIER COLON type ;

block : (DO)? newline INDENT blockBody DEDENT ;
blockBody : (codeItem newline)* codeItem? ;

accessSpecifier : PRIVATE | OVERRIDE ;

classDecl : CLASS IDENTIFIER typeParam? (IS type)? newline INDENT classBody DEDENT ;
classBody : (companionNamespace newline)? (classItem newline)* classItem? ;
companionNamespace : NAMESPACE newline INDENT (classItem newline)* classItem? DEDENT ;
classItem
  : initializer
  | accessSpecifier* (variableDecl | method)
  ;
// CONSIDER: Identifiers can't have type params this way (no init for T())
//    Wait, what did I mean by that? Of course they can; the type is defined in "Class of T"
initializer : IDENTIFIER LEFT_PAREN initParamList? RIGHT_PAREN superInitParams? blockOrStatement ;
initParamList : initParam (COMMA initParam)* ;
initParam : (VAR | VAL)? IDENTIFIER COLON type ;
superInitParams : LEFT_BRACE (expression (COMMA expression)*)? RIGHT_BRACE ;
method : functionDecl ;

usingStatement
	: USING STRING (FOR (DOT | STAR | importList))? // Import
	| USING IDENTIFIER EQ type // Type alias
	;

importList : importItem (COMMA importItem)* ;
importItem : IDENTIFIER | IDENTIFIER RIGHT_ARROW IDENTIFIER ;

loopLabel : COLON IDENTIFIER ;

doStatement : DO codeItem ;
blockOrStatement : block | doStatement ;

ifStmt : IF expression blockOrStatement (newline ELIF expression blockOrStatement)* (newline ELSE blockOrStatement)? ;
whileStmt : WHILE loopLabel? expression blockOrStatement (newline ELSE blockOrStatement)? ; // While-else, but unlike Python's version.
eachStmt : EACH loopLabel? IDENTIFIER (LEFT_BRACKET IDENTIFIER RIGHT_BRACKET)? IN expression blockOrStatement ;
forStmt : FOR loopLabel? (variableDecl | expression)? SEMICOLON (expression)? SEMICOLON (expression)? blockOrStatement ;
breakStmt : BREAK loopLabel? ;
continueStmt : CONTINUE loopLabel? ;
whenStmt : WHEN expression whenBody ;
returnStmt : RETURN (expression)? ;
passStmt : PASS ;

whenBody : newline INDENT whenContents DEDENT ;
whenContents : (whenCase newline)+ (whenCase | elseCase)? newline? ;
whenCase : expression blockOrStatement ;
elseCase : ELSE blockOrStatement ;

// Expression ------------------------------

expression
	: IDENTIFIER COLON_COLON IDENTIFIER                                     #scopedIdentifier
	| IDENTIFIER                                                            #identifier
	| constantExpr                                                          #constant
	| interpolationExpr                                                     #interpolation
	| listOrMapLiteral                                                      #listOrMap
	| lambdaLiteral                                                         #lambda
	| LEFT_PAREN expression RIGHT_PAREN                                     #parenExpr
	| expression (DOT_DOT | DOT_DOT_LT) expression                          #rangeExpr
	| expression (DOT | QUEST_DOT) IDENTIFIER                               #member
	| expression LEFT_PAREN (expression (COMMA expression)*)? RIGHT_PAREN   #call
	| expression LEFT_BRACKET (expression (COMMA expression)*) RIGHT_BRACKET #arrayAccess
	| expression braceLambda                                                #lambdaCall
	| expression (PLUS_PLUS | MINUS_MINUS)                                  #postfixExpr
	| expression QUEST_COLON expression                                     #nilCoalescingOp
	| <assoc=right> expression STAR_STAR expression                         #powerExpr
	| (MINUS | BANG | TILDE | PLUS_PLUS | MINUS_MINUS) expression           #prefixExpr
	| expression (SLASH | STAR | PERCENT) expression                        #factorExpr
	| expression (PLUS | MINUS) expression                                  #termExpr
	| expression (LT_LT | GT_GT) expression                                 #bitShiftExpr
	| expression (PIPE | AMPERSAND | CARET) expression                      #bitwiseExpr
	| expression IF expression ELSE expression                              #ifExpr
	| expression (IS | IS NOT) expression                                   #isExpr
	| expression (IN | NOT IN) expression                                   #inExpr
	| expression comparisonOperator expression                              #comparison
	| expression AND expression                                             #andExpr
	| expression OR expression                                              #orExpr
	| NOT expression                                                        #notExpr
	| <assoc=right> expression assignOperator expression                    #assignment
	| (PRINT | PRINT_ERROR) expression                                      #printExpr
	;

comparisonOperator : EQ_EQ | BANG_EQ | GT | GT_EQ | LT | LT_EQ ;
assignOperator : EQ | MINUS_EQ | PLUS_EQ | STAR_EQ | SLASH_EQ | STAR_STAR_EQ | PIPE_EQ | AMPERSAND_EQ | CARET_EQ | PERCENT_EQ ;

// There's no reason to have empty interpolation, but it's still allowed.
// Question: what happens if it tries to consume the next string as its expression?
// Answer: it doesn't. Not with ANTLR at least.
interpolationExpr : (INTERPOLATION expression?)+ STRING ;

constantExpr : NUMBER | TRUE | FALSE | NIL | STRING | CHAR ;

listOrMapLiteral : listLiteral | mapLiteral ;
listLiteral : LEFT_BRACKET (listItems)? RIGHT_BRACKET ;

listItems : expression (COMMA expression)* (COMMA)? ; // Trailing commas allowed on lists and maps only.

mapLiteral : LEFT_BRACKET (RIGHT_ARROW | mapItems) RIGHT_BRACKET ;

mapItems : mapItem (COMMA mapItem)* (COMMA)? ; // See above.
mapItem : expression RIGHT_ARROW expression ;

lambdaLiteral : FUN (braceLambda | blockLambda) ;

lambdaParams : paramList | parenthesizedOptionalParamList ;
parenthesizedOptionalParamList : (LEFT_PAREN paramList? RIGHT_PAREN) ;

blockLambda : lambdaParams (blockOrStatement | EQ expression) ;
braceLambda : LEFT_BRACE (statementLambdaBody | exprLambdaBody) RIGHT_BRACE ;

statementLambdaBody : (lambdaParams RIGHT_ARROW)? (codeItem SEMICOLON)* ; // All must end in semicolon.
exprLambdaBody : lambdaParams? EQ expression SEMICOLON? ;
