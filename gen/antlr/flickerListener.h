
// Generated from /home/fractioneater/stuff/git/flicker-3/src/antlr/flicker.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "flicker.h"


namespace antlr {

/**
 * This interface defines an abstract listener for a parse tree produced by flicker.
 */
class  flickerListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(flicker::ProgramContext *ctx) = 0;
  virtual void exitProgram(flicker::ProgramContext *ctx) = 0;

  virtual void enterNewline(flicker::NewlineContext *ctx) = 0;
  virtual void exitNewline(flicker::NewlineContext *ctx) = 0;

  virtual void enterStatementEnd(flicker::StatementEndContext *ctx) = 0;
  virtual void exitStatementEnd(flicker::StatementEndContext *ctx) = 0;

  virtual void enterTopLevel(flicker::TopLevelContext *ctx) = 0;
  virtual void exitTopLevel(flicker::TopLevelContext *ctx) = 0;

  virtual void enterStatement(flicker::StatementContext *ctx) = 0;
  virtual void exitStatement(flicker::StatementContext *ctx) = 0;

  virtual void enterDeclaration(flicker::DeclarationContext *ctx) = 0;
  virtual void exitDeclaration(flicker::DeclarationContext *ctx) = 0;

  virtual void enterVariableDecl(flicker::VariableDeclContext *ctx) = 0;
  virtual void exitVariableDecl(flicker::VariableDeclContext *ctx) = 0;

  virtual void enterFunctionDecl(flicker::FunctionDeclContext *ctx) = 0;
  virtual void exitFunctionDecl(flicker::FunctionDeclContext *ctx) = 0;

  virtual void enterFuncReturnType(flicker::FuncReturnTypeContext *ctx) = 0;
  virtual void exitFuncReturnType(flicker::FuncReturnTypeContext *ctx) = 0;

  virtual void enterFunctionContents(flicker::FunctionContentsContext *ctx) = 0;
  virtual void exitFunctionContents(flicker::FunctionContentsContext *ctx) = 0;

  virtual void enterParamList(flicker::ParamListContext *ctx) = 0;
  virtual void exitParamList(flicker::ParamListContext *ctx) = 0;

  virtual void enterParam(flicker::ParamContext *ctx) = 0;
  virtual void exitParam(flicker::ParamContext *ctx) = 0;

  virtual void enterBlock(flicker::BlockContext *ctx) = 0;
  virtual void exitBlock(flicker::BlockContext *ctx) = 0;

  virtual void enterBlockBody(flicker::BlockBodyContext *ctx) = 0;
  virtual void exitBlockBody(flicker::BlockBodyContext *ctx) = 0;

  virtual void enterClassDecl(flicker::ClassDeclContext *ctx) = 0;
  virtual void exitClassDecl(flicker::ClassDeclContext *ctx) = 0;

  virtual void enterClassBody(flicker::ClassBodyContext *ctx) = 0;
  virtual void exitClassBody(flicker::ClassBodyContext *ctx) = 0;

  virtual void enterUse(flicker::UseContext *ctx) = 0;
  virtual void exitUse(flicker::UseContext *ctx) = 0;

  virtual void enterImportList(flicker::ImportListContext *ctx) = 0;
  virtual void exitImportList(flicker::ImportListContext *ctx) = 0;

  virtual void enterKeywordStatement(flicker::KeywordStatementContext *ctx) = 0;
  virtual void exitKeywordStatement(flicker::KeywordStatementContext *ctx) = 0;

  virtual void enterLoopLabel(flicker::LoopLabelContext *ctx) = 0;
  virtual void exitLoopLabel(flicker::LoopLabelContext *ctx) = 0;

  virtual void enterDoStatement(flicker::DoStatementContext *ctx) = 0;
  virtual void exitDoStatement(flicker::DoStatementContext *ctx) = 0;

  virtual void enterBlockOrStatement(flicker::BlockOrStatementContext *ctx) = 0;
  virtual void exitBlockOrStatement(flicker::BlockOrStatementContext *ctx) = 0;

  virtual void enterIfStmt(flicker::IfStmtContext *ctx) = 0;
  virtual void exitIfStmt(flicker::IfStmtContext *ctx) = 0;

  virtual void enterWhileStmt(flicker::WhileStmtContext *ctx) = 0;
  virtual void exitWhileStmt(flicker::WhileStmtContext *ctx) = 0;

  virtual void enterEachStmt(flicker::EachStmtContext *ctx) = 0;
  virtual void exitEachStmt(flicker::EachStmtContext *ctx) = 0;

  virtual void enterForStmt(flicker::ForStmtContext *ctx) = 0;
  virtual void exitForStmt(flicker::ForStmtContext *ctx) = 0;

  virtual void enterBreakStmt(flicker::BreakStmtContext *ctx) = 0;
  virtual void exitBreakStmt(flicker::BreakStmtContext *ctx) = 0;

  virtual void enterContinueStmt(flicker::ContinueStmtContext *ctx) = 0;
  virtual void exitContinueStmt(flicker::ContinueStmtContext *ctx) = 0;

  virtual void enterWhenStmt(flicker::WhenStmtContext *ctx) = 0;
  virtual void exitWhenStmt(flicker::WhenStmtContext *ctx) = 0;

  virtual void enterReturnStmt(flicker::ReturnStmtContext *ctx) = 0;
  virtual void exitReturnStmt(flicker::ReturnStmtContext *ctx) = 0;

  virtual void enterPrintStmt(flicker::PrintStmtContext *ctx) = 0;
  virtual void exitPrintStmt(flicker::PrintStmtContext *ctx) = 0;

  virtual void enterConsoleErrorStmt(flicker::ConsoleErrorStmtContext *ctx) = 0;
  virtual void exitConsoleErrorStmt(flicker::ConsoleErrorStmtContext *ctx) = 0;

  virtual void enterPassStmt(flicker::PassStmtContext *ctx) = 0;
  virtual void exitPassStmt(flicker::PassStmtContext *ctx) = 0;

  virtual void enterWhenBody(flicker::WhenBodyContext *ctx) = 0;
  virtual void exitWhenBody(flicker::WhenBodyContext *ctx) = 0;

  virtual void enterWhenContents(flicker::WhenContentsContext *ctx) = 0;
  virtual void exitWhenContents(flicker::WhenContentsContext *ctx) = 0;

  virtual void enterWhenCase(flicker::WhenCaseContext *ctx) = 0;
  virtual void exitWhenCase(flicker::WhenCaseContext *ctx) = 0;

  virtual void enterElseCase(flicker::ElseCaseContext *ctx) = 0;
  virtual void exitElseCase(flicker::ElseCaseContext *ctx) = 0;

  virtual void enterExprMulDivMod(flicker::ExprMulDivModContext *ctx) = 0;
  virtual void exitExprMulDivMod(flicker::ExprMulDivModContext *ctx) = 0;

  virtual void enterExprAddSub(flicker::ExprAddSubContext *ctx) = 0;
  virtual void exitExprAddSub(flicker::ExprAddSubContext *ctx) = 0;

  virtual void enterExprIdentifier(flicker::ExprIdentifierContext *ctx) = 0;
  virtual void exitExprIdentifier(flicker::ExprIdentifierContext *ctx) = 0;

  virtual void enterExprRange(flicker::ExprRangeContext *ctx) = 0;
  virtual void exitExprRange(flicker::ExprRangeContext *ctx) = 0;

  virtual void enterExprAssign(flicker::ExprAssignContext *ctx) = 0;
  virtual void exitExprAssign(flicker::ExprAssignContext *ctx) = 0;

  virtual void enterExprLambda(flicker::ExprLambdaContext *ctx) = 0;
  virtual void exitExprLambda(flicker::ExprLambdaContext *ctx) = 0;

  virtual void enterExprCompare(flicker::ExprCompareContext *ctx) = 0;
  virtual void exitExprCompare(flicker::ExprCompareContext *ctx) = 0;

  virtual void enterExprMember(flicker::ExprMemberContext *ctx) = 0;
  virtual void exitExprMember(flicker::ExprMemberContext *ctx) = 0;

  virtual void enterExprParen(flicker::ExprParenContext *ctx) = 0;
  virtual void exitExprParen(flicker::ExprParenContext *ctx) = 0;

  virtual void enterExprOr(flicker::ExprOrContext *ctx) = 0;
  virtual void exitExprOr(flicker::ExprOrContext *ctx) = 0;

  virtual void enterExprInterpolation(flicker::ExprInterpolationContext *ctx) = 0;
  virtual void exitExprInterpolation(flicker::ExprInterpolationContext *ctx) = 0;

  virtual void enterExprCall(flicker::ExprCallContext *ctx) = 0;
  virtual void exitExprCall(flicker::ExprCallContext *ctx) = 0;

  virtual void enterExprListOrMap(flicker::ExprListOrMapContext *ctx) = 0;
  virtual void exitExprListOrMap(flicker::ExprListOrMapContext *ctx) = 0;

  virtual void enterExprPrefix(flicker::ExprPrefixContext *ctx) = 0;
  virtual void exitExprPrefix(flicker::ExprPrefixContext *ctx) = 0;

  virtual void enterExprBitwiseB(flicker::ExprBitwiseBContext *ctx) = 0;
  virtual void exitExprBitwiseB(flicker::ExprBitwiseBContext *ctx) = 0;

  virtual void enterExprAnd(flicker::ExprAndContext *ctx) = 0;
  virtual void exitExprAnd(flicker::ExprAndContext *ctx) = 0;

  virtual void enterExprPower(flicker::ExprPowerContext *ctx) = 0;
  virtual void exitExprPower(flicker::ExprPowerContext *ctx) = 0;

  virtual void enterExprIndex(flicker::ExprIndexContext *ctx) = 0;
  virtual void exitExprIndex(flicker::ExprIndexContext *ctx) = 0;

  virtual void enterExprIf(flicker::ExprIfContext *ctx) = 0;
  virtual void exitExprIf(flicker::ExprIfContext *ctx) = 0;

  virtual void enterExprShift(flicker::ExprShiftContext *ctx) = 0;
  virtual void exitExprShift(flicker::ExprShiftContext *ctx) = 0;

  virtual void enterExprConstant(flicker::ExprConstantContext *ctx) = 0;
  virtual void exitExprConstant(flicker::ExprConstantContext *ctx) = 0;

  virtual void enterExprStaticMember(flicker::ExprStaticMemberContext *ctx) = 0;
  virtual void exitExprStaticMember(flicker::ExprStaticMemberContext *ctx) = 0;

  virtual void enterComparisonOperator(flicker::ComparisonOperatorContext *ctx) = 0;
  virtual void exitComparisonOperator(flicker::ComparisonOperatorContext *ctx) = 0;

  virtual void enterParenthesizedExpr(flicker::ParenthesizedExprContext *ctx) = 0;
  virtual void exitParenthesizedExpr(flicker::ParenthesizedExprContext *ctx) = 0;

  virtual void enterInterpolationExpr(flicker::InterpolationExprContext *ctx) = 0;
  virtual void exitInterpolationExpr(flicker::InterpolationExprContext *ctx) = 0;

  virtual void enterConstantExpr(flicker::ConstantExprContext *ctx) = 0;
  virtual void exitConstantExpr(flicker::ConstantExprContext *ctx) = 0;

  virtual void enterListOrMapLiteral(flicker::ListOrMapLiteralContext *ctx) = 0;
  virtual void exitListOrMapLiteral(flicker::ListOrMapLiteralContext *ctx) = 0;

  virtual void enterListLiteral(flicker::ListLiteralContext *ctx) = 0;
  virtual void exitListLiteral(flicker::ListLiteralContext *ctx) = 0;

  virtual void enterListItems(flicker::ListItemsContext *ctx) = 0;
  virtual void exitListItems(flicker::ListItemsContext *ctx) = 0;

  virtual void enterMapLiteral(flicker::MapLiteralContext *ctx) = 0;
  virtual void exitMapLiteral(flicker::MapLiteralContext *ctx) = 0;

  virtual void enterMapItems(flicker::MapItemsContext *ctx) = 0;
  virtual void exitMapItems(flicker::MapItemsContext *ctx) = 0;

  virtual void enterMapItem(flicker::MapItemContext *ctx) = 0;
  virtual void exitMapItem(flicker::MapItemContext *ctx) = 0;

  virtual void enterLambdaLiteral(flicker::LambdaLiteralContext *ctx) = 0;
  virtual void exitLambdaLiteral(flicker::LambdaLiteralContext *ctx) = 0;

  virtual void enterLambdaParams(flicker::LambdaParamsContext *ctx) = 0;
  virtual void exitLambdaParams(flicker::LambdaParamsContext *ctx) = 0;

  virtual void enterParenthesizedOptionalParamList(flicker::ParenthesizedOptionalParamListContext *ctx) = 0;
  virtual void exitParenthesizedOptionalParamList(flicker::ParenthesizedOptionalParamListContext *ctx) = 0;

  virtual void enterLambdaBody(flicker::LambdaBodyContext *ctx) = 0;
  virtual void exitLambdaBody(flicker::LambdaBodyContext *ctx) = 0;

  virtual void enterBraceBody(flicker::BraceBodyContext *ctx) = 0;
  virtual void exitBraceBody(flicker::BraceBodyContext *ctx) = 0;


};

}  // namespace antlr
