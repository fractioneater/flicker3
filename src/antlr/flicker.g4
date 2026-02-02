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
	// Keywords (37 - 70)
	AND, ATTRIBUTE, BREAK, CLASS, CONTINUE, DO, EACH, ELIF, ELSE,
	FALSE, FOR, FUN, IF, IN, IS, NIL, NOT, OF, OR, PASS, PRINT,
	PRINT_ERROR, RETURN, SHL, SHR, STATIC, SUPER, THIS, TRUE, USING,
	VAL, VAR, WHEN, WHILE,
	// Whitespace (71 - 73)
	INDENT, DEDENT, LINE
}

program : newline* (topLevel statementEnd)* EOF ;

newline : LINE+ ; // This one is just a plain newline.
statementEnd      // This one is a statement end check.
	: newline EOF?
	| EOF
	;

topLevel : statement | expression ;

type : IDENTIFIER /* QUEST? */ ((OF | FOR) IDENTIFIER /* QUEST? */)? ;
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

functionDecl : FUN IDENTIFIER LEFT_PAREN (paramList)? RIGHT_PAREN (funcReturnType)? functionContents;

funcReturnType : (COLON | RIGHT_ARROW) IDENTIFIER; // TODO: Decide on a symbol.
functionContents : blockOrStatement | (EQ expression);

paramList : param (COMMA param)* ;
param : IDENTIFIER COLON type ;

block : (DO)? newline INDENT blockBody DEDENT ;
blockBody : (topLevel statementEnd)* ;

classDecl : CLASS IDENTIFIER (LT IDENTIFIER)? classBody ;

classBody : NUMBER ; // TODO!

usingStatement
	: USING STRING (FOR (DOT | STAR | importList))? // Import
	| USING IDENTIFIER EQ type // Type alias
	;

importList : importItem (COMMA importItem)* ;
importItem : IDENTIFIER | IDENTIFIER RIGHT_ARROW IDENTIFIER ;

loopLabel : COLON IDENTIFIER ;

doStatement : DO topLevel ;
blockOrStatement : block | doStatement ;

ifStmt : IF expression blockOrStatement (ELIF expression blockOrStatement)* (ELSE blockOrStatement)? ;
whileStmt : WHILE loopLabel? expression blockOrStatement ;
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
whenContents : (whenCase statementEnd)+ (elseCase statementEnd)? ;
whenCase : expression blockOrStatement ;
elseCase : ELSE blockOrStatement ;

// Expression ------------------------------

expression
	: IDENTIFIER                                                            #exprIdentifier
	| constantExpr                                                          #exprConstant
	| interpolationExpr                                                     #exprInterpolation
	| listOrMapLiteral                                                      #exprListOrMap
	| lambdaLiteral                                                         #exprLambda
	| LEFT_PAREN expression RIGHT_PAREN                                     #exprParen
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

// There's no reason to have empty interpolation, but it's still allowed.
// Question: what happens if it tries to consume the next string as its expression?
interpolationExpr : INTERPOLATION expression? STRING ;

constantExpr : NUMBER | TRUE | FALSE | NIL | STRING ;

listOrMapLiteral : listLiteral | mapLiteral ;
listLiteral : LEFT_BRACKET (listItems)? RIGHT_BRACKET ;

listItems : expression (COMMA expression)* (COMMA)? ; // Trailing commas allowed on lists and maps only.

mapLiteral : LEFT_BRACKET (RIGHT_ARROW | mapItems) RIGHT_BRACKET ;

mapItems : mapItem (COMMA mapItem)* (COMMA)? ; // See above.
mapItem : expression RIGHT_ARROW expression ;

lambdaLiteral : FUN lambdaParams ((RIGHT_ARROW lambdaBody) | (EQ expression)) ;

lambdaParams : paramList | parenthesizedOptionalParamList | /* No params at all */ ;
parenthesizedOptionalParamList : (LEFT_PAREN (paramList)? RIGHT_PAREN) ;

lambdaBody : braceBody | block ;

braceBody : LEFT_BRACE (statement terminator+)* statement? terminator* RIGHT_BRACE ;
terminator : (SEMICOLON | newline) ;
