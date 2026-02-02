
// Generated from /home/fractioneater/stuff/git/flicker-3/src/antlr/flicker.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "flickerListener.h"


namespace antlr {

/**
 * This class provides an empty implementation of flickerListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  flickerBaseListener : public flickerListener {
public:

  virtual void enterProgram(flicker::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(flicker::ProgramContext * /*ctx*/) override { }

  virtual void enterNewline(flicker::NewlineContext * /*ctx*/) override { }
  virtual void exitNewline(flicker::NewlineContext * /*ctx*/) override { }

  virtual void enterStatementEnd(flicker::StatementEndContext * /*ctx*/) override { }
  virtual void exitStatementEnd(flicker::StatementEndContext * /*ctx*/) override { }

  virtual void enterTopLevel(flicker::TopLevelContext * /*ctx*/) override { }
  virtual void exitTopLevel(flicker::TopLevelContext * /*ctx*/) override { }

  virtual void enterType(flicker::TypeContext * /*ctx*/) override { }
  virtual void exitType(flicker::TypeContext * /*ctx*/) override { }

  virtual void enterStatement(flicker::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(flicker::StatementContext * /*ctx*/) override { }

  virtual void enterVariableDecl(flicker::VariableDeclContext * /*ctx*/) override { }
  virtual void exitVariableDecl(flicker::VariableDeclContext * /*ctx*/) override { }

  virtual void enterFunctionDecl(flicker::FunctionDeclContext * /*ctx*/) override { }
  virtual void exitFunctionDecl(flicker::FunctionDeclContext * /*ctx*/) override { }

  virtual void enterFuncReturnType(flicker::FuncReturnTypeContext * /*ctx*/) override { }
  virtual void exitFuncReturnType(flicker::FuncReturnTypeContext * /*ctx*/) override { }

  virtual void enterFunctionContents(flicker::FunctionContentsContext * /*ctx*/) override { }
  virtual void exitFunctionContents(flicker::FunctionContentsContext * /*ctx*/) override { }

  virtual void enterParamList(flicker::ParamListContext * /*ctx*/) override { }
  virtual void exitParamList(flicker::ParamListContext * /*ctx*/) override { }

  virtual void enterParam(flicker::ParamContext * /*ctx*/) override { }
  virtual void exitParam(flicker::ParamContext * /*ctx*/) override { }

  virtual void enterBlock(flicker::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(flicker::BlockContext * /*ctx*/) override { }

  virtual void enterBlockBody(flicker::BlockBodyContext * /*ctx*/) override { }
  virtual void exitBlockBody(flicker::BlockBodyContext * /*ctx*/) override { }

  virtual void enterClassDecl(flicker::ClassDeclContext * /*ctx*/) override { }
  virtual void exitClassDecl(flicker::ClassDeclContext * /*ctx*/) override { }

  virtual void enterClassBody(flicker::ClassBodyContext * /*ctx*/) override { }
  virtual void exitClassBody(flicker::ClassBodyContext * /*ctx*/) override { }

  virtual void enterUsingStatement(flicker::UsingStatementContext * /*ctx*/) override { }
  virtual void exitUsingStatement(flicker::UsingStatementContext * /*ctx*/) override { }

  virtual void enterImportList(flicker::ImportListContext * /*ctx*/) override { }
  virtual void exitImportList(flicker::ImportListContext * /*ctx*/) override { }

  virtual void enterImportItem(flicker::ImportItemContext * /*ctx*/) override { }
  virtual void exitImportItem(flicker::ImportItemContext * /*ctx*/) override { }

  virtual void enterLoopLabel(flicker::LoopLabelContext * /*ctx*/) override { }
  virtual void exitLoopLabel(flicker::LoopLabelContext * /*ctx*/) override { }

  virtual void enterDoStatement(flicker::DoStatementContext * /*ctx*/) override { }
  virtual void exitDoStatement(flicker::DoStatementContext * /*ctx*/) override { }

  virtual void enterBlockOrStatement(flicker::BlockOrStatementContext * /*ctx*/) override { }
  virtual void exitBlockOrStatement(flicker::BlockOrStatementContext * /*ctx*/) override { }

  virtual void enterIfStmt(flicker::IfStmtContext * /*ctx*/) override { }
  virtual void exitIfStmt(flicker::IfStmtContext * /*ctx*/) override { }

  virtual void enterWhileStmt(flicker::WhileStmtContext * /*ctx*/) override { }
  virtual void exitWhileStmt(flicker::WhileStmtContext * /*ctx*/) override { }

  virtual void enterEachStmt(flicker::EachStmtContext * /*ctx*/) override { }
  virtual void exitEachStmt(flicker::EachStmtContext * /*ctx*/) override { }

  virtual void enterForStmt(flicker::ForStmtContext * /*ctx*/) override { }
  virtual void exitForStmt(flicker::ForStmtContext * /*ctx*/) override { }

  virtual void enterBreakStmt(flicker::BreakStmtContext * /*ctx*/) override { }
  virtual void exitBreakStmt(flicker::BreakStmtContext * /*ctx*/) override { }

  virtual void enterContinueStmt(flicker::ContinueStmtContext * /*ctx*/) override { }
  virtual void exitContinueStmt(flicker::ContinueStmtContext * /*ctx*/) override { }

  virtual void enterWhenStmt(flicker::WhenStmtContext * /*ctx*/) override { }
  virtual void exitWhenStmt(flicker::WhenStmtContext * /*ctx*/) override { }

  virtual void enterReturnStmt(flicker::ReturnStmtContext * /*ctx*/) override { }
  virtual void exitReturnStmt(flicker::ReturnStmtContext * /*ctx*/) override { }

  virtual void enterPrintStmt(flicker::PrintStmtContext * /*ctx*/) override { }
  virtual void exitPrintStmt(flicker::PrintStmtContext * /*ctx*/) override { }

  virtual void enterConsoleErrorStmt(flicker::ConsoleErrorStmtContext * /*ctx*/) override { }
  virtual void exitConsoleErrorStmt(flicker::ConsoleErrorStmtContext * /*ctx*/) override { }

  virtual void enterPassStmt(flicker::PassStmtContext * /*ctx*/) override { }
  virtual void exitPassStmt(flicker::PassStmtContext * /*ctx*/) override { }

  virtual void enterWhenBody(flicker::WhenBodyContext * /*ctx*/) override { }
  virtual void exitWhenBody(flicker::WhenBodyContext * /*ctx*/) override { }

  virtual void enterWhenContents(flicker::WhenContentsContext * /*ctx*/) override { }
  virtual void exitWhenContents(flicker::WhenContentsContext * /*ctx*/) override { }

  virtual void enterWhenCase(flicker::WhenCaseContext * /*ctx*/) override { }
  virtual void exitWhenCase(flicker::WhenCaseContext * /*ctx*/) override { }

  virtual void enterElseCase(flicker::ElseCaseContext * /*ctx*/) override { }
  virtual void exitElseCase(flicker::ElseCaseContext * /*ctx*/) override { }

  virtual void enterExprMulDivMod(flicker::ExprMulDivModContext * /*ctx*/) override { }
  virtual void exitExprMulDivMod(flicker::ExprMulDivModContext * /*ctx*/) override { }

  virtual void enterExprAddSub(flicker::ExprAddSubContext * /*ctx*/) override { }
  virtual void exitExprAddSub(flicker::ExprAddSubContext * /*ctx*/) override { }

  virtual void enterExprIdentifier(flicker::ExprIdentifierContext * /*ctx*/) override { }
  virtual void exitExprIdentifier(flicker::ExprIdentifierContext * /*ctx*/) override { }

  virtual void enterExprRange(flicker::ExprRangeContext * /*ctx*/) override { }
  virtual void exitExprRange(flicker::ExprRangeContext * /*ctx*/) override { }

  virtual void enterExprAssign(flicker::ExprAssignContext * /*ctx*/) override { }
  virtual void exitExprAssign(flicker::ExprAssignContext * /*ctx*/) override { }

  virtual void enterExprLambda(flicker::ExprLambdaContext * /*ctx*/) override { }
  virtual void exitExprLambda(flicker::ExprLambdaContext * /*ctx*/) override { }

  virtual void enterExprCompare(flicker::ExprCompareContext * /*ctx*/) override { }
  virtual void exitExprCompare(flicker::ExprCompareContext * /*ctx*/) override { }

  virtual void enterExprMember(flicker::ExprMemberContext * /*ctx*/) override { }
  virtual void exitExprMember(flicker::ExprMemberContext * /*ctx*/) override { }

  virtual void enterExprParen(flicker::ExprParenContext * /*ctx*/) override { }
  virtual void exitExprParen(flicker::ExprParenContext * /*ctx*/) override { }

  virtual void enterExprOr(flicker::ExprOrContext * /*ctx*/) override { }
  virtual void exitExprOr(flicker::ExprOrContext * /*ctx*/) override { }

  virtual void enterExprInterpolation(flicker::ExprInterpolationContext * /*ctx*/) override { }
  virtual void exitExprInterpolation(flicker::ExprInterpolationContext * /*ctx*/) override { }

  virtual void enterExprCall(flicker::ExprCallContext * /*ctx*/) override { }
  virtual void exitExprCall(flicker::ExprCallContext * /*ctx*/) override { }

  virtual void enterExprListOrMap(flicker::ExprListOrMapContext * /*ctx*/) override { }
  virtual void exitExprListOrMap(flicker::ExprListOrMapContext * /*ctx*/) override { }

  virtual void enterExprPrefix(flicker::ExprPrefixContext * /*ctx*/) override { }
  virtual void exitExprPrefix(flicker::ExprPrefixContext * /*ctx*/) override { }

  virtual void enterExprBitwiseB(flicker::ExprBitwiseBContext * /*ctx*/) override { }
  virtual void exitExprBitwiseB(flicker::ExprBitwiseBContext * /*ctx*/) override { }

  virtual void enterExprAnd(flicker::ExprAndContext * /*ctx*/) override { }
  virtual void exitExprAnd(flicker::ExprAndContext * /*ctx*/) override { }

  virtual void enterExprPower(flicker::ExprPowerContext * /*ctx*/) override { }
  virtual void exitExprPower(flicker::ExprPowerContext * /*ctx*/) override { }

  virtual void enterExprIndex(flicker::ExprIndexContext * /*ctx*/) override { }
  virtual void exitExprIndex(flicker::ExprIndexContext * /*ctx*/) override { }

  virtual void enterExprIf(flicker::ExprIfContext * /*ctx*/) override { }
  virtual void exitExprIf(flicker::ExprIfContext * /*ctx*/) override { }

  virtual void enterExprShift(flicker::ExprShiftContext * /*ctx*/) override { }
  virtual void exitExprShift(flicker::ExprShiftContext * /*ctx*/) override { }

  virtual void enterExprConstant(flicker::ExprConstantContext * /*ctx*/) override { }
  virtual void exitExprConstant(flicker::ExprConstantContext * /*ctx*/) override { }

  virtual void enterExprStaticMember(flicker::ExprStaticMemberContext * /*ctx*/) override { }
  virtual void exitExprStaticMember(flicker::ExprStaticMemberContext * /*ctx*/) override { }

  virtual void enterComparisonOperator(flicker::ComparisonOperatorContext * /*ctx*/) override { }
  virtual void exitComparisonOperator(flicker::ComparisonOperatorContext * /*ctx*/) override { }

  virtual void enterInterpolationExpr(flicker::InterpolationExprContext * /*ctx*/) override { }
  virtual void exitInterpolationExpr(flicker::InterpolationExprContext * /*ctx*/) override { }

  virtual void enterConstantExpr(flicker::ConstantExprContext * /*ctx*/) override { }
  virtual void exitConstantExpr(flicker::ConstantExprContext * /*ctx*/) override { }

  virtual void enterListOrMapLiteral(flicker::ListOrMapLiteralContext * /*ctx*/) override { }
  virtual void exitListOrMapLiteral(flicker::ListOrMapLiteralContext * /*ctx*/) override { }

  virtual void enterListLiteral(flicker::ListLiteralContext * /*ctx*/) override { }
  virtual void exitListLiteral(flicker::ListLiteralContext * /*ctx*/) override { }

  virtual void enterListItems(flicker::ListItemsContext * /*ctx*/) override { }
  virtual void exitListItems(flicker::ListItemsContext * /*ctx*/) override { }

  virtual void enterMapLiteral(flicker::MapLiteralContext * /*ctx*/) override { }
  virtual void exitMapLiteral(flicker::MapLiteralContext * /*ctx*/) override { }

  virtual void enterMapItems(flicker::MapItemsContext * /*ctx*/) override { }
  virtual void exitMapItems(flicker::MapItemsContext * /*ctx*/) override { }

  virtual void enterMapItem(flicker::MapItemContext * /*ctx*/) override { }
  virtual void exitMapItem(flicker::MapItemContext * /*ctx*/) override { }

  virtual void enterLambdaLiteral(flicker::LambdaLiteralContext * /*ctx*/) override { }
  virtual void exitLambdaLiteral(flicker::LambdaLiteralContext * /*ctx*/) override { }

  virtual void enterLambdaParams(flicker::LambdaParamsContext * /*ctx*/) override { }
  virtual void exitLambdaParams(flicker::LambdaParamsContext * /*ctx*/) override { }

  virtual void enterParenthesizedOptionalParamList(flicker::ParenthesizedOptionalParamListContext * /*ctx*/) override { }
  virtual void exitParenthesizedOptionalParamList(flicker::ParenthesizedOptionalParamListContext * /*ctx*/) override { }

  virtual void enterLambdaBody(flicker::LambdaBodyContext * /*ctx*/) override { }
  virtual void exitLambdaBody(flicker::LambdaBodyContext * /*ctx*/) override { }

  virtual void enterBraceBody(flicker::BraceBodyContext * /*ctx*/) override { }
  virtual void exitBraceBody(flicker::BraceBodyContext * /*ctx*/) override { }

  virtual void enterTerminator(flicker::TerminatorContext * /*ctx*/) override { }
  virtual void exitTerminator(flicker::TerminatorContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace antlr
