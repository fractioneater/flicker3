parser grammar flicker;

tokens {
  // Single-character tokens
  LEFT_PAREN, RIGHT_PAREN, LEFT_BRACKET, RIGHT_BRACKET, LEFT_BRACE, RIGHT_BRACE, SEMICOLON, COMMA,
  PLUS, SLASH, PERCENT, PIPE, CARET, AMPERSAND, TILDE,
  // 1-3 character tokens
  DOT, DOT_DOT, DOT_DOT_LT,
  QUEST, QUEST_COLON, QUEST_DOT,
  COLON, COLON_COLON,
  STAR, STAR_STAR,
  MINUS, RIGHT_ARROW,
  BANG, BANG_EQ,
  EQ, EQ_EQ,
  GT, GT_GT, GT_EQ,
  LT, LT_LT, LT_EQ,
  // Literals
  IDENTIFIER, STRING, INTERPOLATION, CHAR, NUMBER,
  // Keywords
  AND, BREAK, CLASS, CONTINUE, CN, DO, EACH, ELIF, ELSE, FALSE, FOR, FUN, IF,
  IN, IS, NIL, NOT, OF, OR, OVERRIDE, PASS, PRINT, PRINT_ERROR, PRIVATE, RETURN,
  STATIC, SUPER, THIS, TRUE, USING, VAL, VAR, WHEN, WHILE,
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

// Statement ------------------------------

statement
	: variableDecl
	| functionDecl
	| classDecl
	| usingStatement
	| ifStmt
	| whileStmt
	| eachStmt
	| forStmt
	| breakStmt
	| continueStmt
	| whenStmt
	| returnStmt
	| printStmt
	| consoleErrorStmt
	| passStmt
	;

variableDecl : (VAR | VAL) IDENTIFIER (COLON type)? (EQ expression)?;

typeParam : (OF | FOR) IDENTIFIER ;
functionDecl : FUN IDENTIFIER typeParam? LEFT_PAREN (paramList)? RIGHT_PAREN (funcReturnType)? functionContents;

funcReturnType : (COLON | RIGHT_ARROW) IDENTIFIER; // TODO: Decide on a symbol.
functionContents : blockOrStatement | (EQ expression);

paramList : param (COMMA param)* ;
param : IDENTIFIER COLON type ;

block : (DO)? newline INDENT blockBody DEDENT ;
blockBody : (codeItem newline)* codeItem? ;

accessSpecifier : PRIVATE ; // There may be more.

classDecl : CLASS IDENTIFIER typeParam? (IS type)? newline INDENT classBody DEDENT ;
classBody : (companionNamespace newline)? (classItem newline)* classItem? ;
companionNamespace : CN newline INDENT (classItem newline)* classItem? DEDENT ;
classItem : accessSpecifier* (variableDecl | method) ;
method: OVERRIDE? functionDecl ;

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
printStmt : PRINT expression ;
consoleErrorStmt : PRINT_ERROR expression ;
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
	| expression QUEST_COLON expression                                     #nilCoalescingOp
	| <assoc=right> expression STAR_STAR expression                         #powerExpr
	| (MINUS | BANG | TILDE) expression                                     #prefixExpr
	| expression (SLASH | STAR) expression                                  #factorExpr
	| expression (PLUS | MINUS) expression                                  #termExpr
	| expression (LT_LT | GT_GT) expression                                 #bitShiftExpr
	| expression (PIPE | AMPERSAND | CARET) expression                      #bitwisExpr
	| expression (IS | IS NOT) expression                                   #isExpr
	| expression (IN | NOT IN) expression                                   #inExpr
	| expression comparisonOperator expression                              #comparison
	| expression AND expression                                             #andExpr
	| expression OR expression                                              #orExpr
	| NOT expression                                                        #notExpr
	| expression IF expression ELSE expression                              #ifExpr
	| <assoc=right> expression EQ expression                                #assignment
	;

comparisonOperator : EQ_EQ | BANG_EQ | GT | GT_EQ | LT | LT_EQ ;

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
exprLambdaBody : lambdaParams? EQ expression ;
