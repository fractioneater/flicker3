
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

  virtual void enterCodeItem(flicker::CodeItemContext * /*ctx*/) override { }
  virtual void exitCodeItem(flicker::CodeItemContext * /*ctx*/) override { }

  virtual void enterType(flicker::TypeContext * /*ctx*/) override { }
  virtual void exitType(flicker::TypeContext * /*ctx*/) override { }

  virtual void enterStatement(flicker::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(flicker::StatementContext * /*ctx*/) override { }

  virtual void enterVariableDecl(flicker::VariableDeclContext * /*ctx*/) override { }
  virtual void exitVariableDecl(flicker::VariableDeclContext * /*ctx*/) override { }

  virtual void enterTypeParam(flicker::TypeParamContext * /*ctx*/) override { }
  virtual void exitTypeParam(flicker::TypeParamContext * /*ctx*/) override { }

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

  virtual void enterAccessSpecifier(flicker::AccessSpecifierContext * /*ctx*/) override { }
  virtual void exitAccessSpecifier(flicker::AccessSpecifierContext * /*ctx*/) override { }

  virtual void enterClassDecl(flicker::ClassDeclContext * /*ctx*/) override { }
  virtual void exitClassDecl(flicker::ClassDeclContext * /*ctx*/) override { }

  virtual void enterClassBody(flicker::ClassBodyContext * /*ctx*/) override { }
  virtual void exitClassBody(flicker::ClassBodyContext * /*ctx*/) override { }

  virtual void enterCompanionNamespace(flicker::CompanionNamespaceContext * /*ctx*/) override { }
  virtual void exitCompanionNamespace(flicker::CompanionNamespaceContext * /*ctx*/) override { }

  virtual void enterClassItem(flicker::ClassItemContext * /*ctx*/) override { }
  virtual void exitClassItem(flicker::ClassItemContext * /*ctx*/) override { }

  virtual void enterMethod(flicker::MethodContext * /*ctx*/) override { }
  virtual void exitMethod(flicker::MethodContext * /*ctx*/) override { }

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

  virtual void enterConstant(flicker::ConstantContext * /*ctx*/) override { }
  virtual void exitConstant(flicker::ConstantContext * /*ctx*/) override { }

  virtual void enterPowerExpr(flicker::PowerExprContext * /*ctx*/) override { }
  virtual void exitPowerExpr(flicker::PowerExprContext * /*ctx*/) override { }

  virtual void enterTermExpr(flicker::TermExprContext * /*ctx*/) override { }
  virtual void exitTermExpr(flicker::TermExprContext * /*ctx*/) override { }

  virtual void enterBitShiftExpr(flicker::BitShiftExprContext * /*ctx*/) override { }
  virtual void exitBitShiftExpr(flicker::BitShiftExprContext * /*ctx*/) override { }

  virtual void enterFactorExpr(flicker::FactorExprContext * /*ctx*/) override { }
  virtual void exitFactorExpr(flicker::FactorExprContext * /*ctx*/) override { }

  virtual void enterLambdaCall(flicker::LambdaCallContext * /*ctx*/) override { }
  virtual void exitLambdaCall(flicker::LambdaCallContext * /*ctx*/) override { }

  virtual void enterParenExpr(flicker::ParenExprContext * /*ctx*/) override { }
  virtual void exitParenExpr(flicker::ParenExprContext * /*ctx*/) override { }

  virtual void enterLambda(flicker::LambdaContext * /*ctx*/) override { }
  virtual void exitLambda(flicker::LambdaContext * /*ctx*/) override { }

  virtual void enterBitwisExpr(flicker::BitwisExprContext * /*ctx*/) override { }
  virtual void exitBitwisExpr(flicker::BitwisExprContext * /*ctx*/) override { }

  virtual void enterNilCoalescingOp(flicker::NilCoalescingOpContext * /*ctx*/) override { }
  virtual void exitNilCoalescingOp(flicker::NilCoalescingOpContext * /*ctx*/) override { }

  virtual void enterMember(flicker::MemberContext * /*ctx*/) override { }
  virtual void exitMember(flicker::MemberContext * /*ctx*/) override { }

  virtual void enterIfExpr(flicker::IfExprContext * /*ctx*/) override { }
  virtual void exitIfExpr(flicker::IfExprContext * /*ctx*/) override { }

  virtual void enterArrayAccess(flicker::ArrayAccessContext * /*ctx*/) override { }
  virtual void exitArrayAccess(flicker::ArrayAccessContext * /*ctx*/) override { }

  virtual void enterListOrMap(flicker::ListOrMapContext * /*ctx*/) override { }
  virtual void exitListOrMap(flicker::ListOrMapContext * /*ctx*/) override { }

  virtual void enterIsExpr(flicker::IsExprContext * /*ctx*/) override { }
  virtual void exitIsExpr(flicker::IsExprContext * /*ctx*/) override { }

  virtual void enterIdentifier(flicker::IdentifierContext * /*ctx*/) override { }
  virtual void exitIdentifier(flicker::IdentifierContext * /*ctx*/) override { }

  virtual void enterComparison(flicker::ComparisonContext * /*ctx*/) override { }
  virtual void exitComparison(flicker::ComparisonContext * /*ctx*/) override { }

  virtual void enterInExpr(flicker::InExprContext * /*ctx*/) override { }
  virtual void exitInExpr(flicker::InExprContext * /*ctx*/) override { }

  virtual void enterAssignment(flicker::AssignmentContext * /*ctx*/) override { }
  virtual void exitAssignment(flicker::AssignmentContext * /*ctx*/) override { }

  virtual void enterOrExpr(flicker::OrExprContext * /*ctx*/) override { }
  virtual void exitOrExpr(flicker::OrExprContext * /*ctx*/) override { }

  virtual void enterCall(flicker::CallContext * /*ctx*/) override { }
  virtual void exitCall(flicker::CallContext * /*ctx*/) override { }

  virtual void enterPrefixExpr(flicker::PrefixExprContext * /*ctx*/) override { }
  virtual void exitPrefixExpr(flicker::PrefixExprContext * /*ctx*/) override { }

  virtual void enterInterpolation(flicker::InterpolationContext * /*ctx*/) override { }
  virtual void exitInterpolation(flicker::InterpolationContext * /*ctx*/) override { }

  virtual void enterNotExpr(flicker::NotExprContext * /*ctx*/) override { }
  virtual void exitNotExpr(flicker::NotExprContext * /*ctx*/) override { }

  virtual void enterScopedIdentifier(flicker::ScopedIdentifierContext * /*ctx*/) override { }
  virtual void exitScopedIdentifier(flicker::ScopedIdentifierContext * /*ctx*/) override { }

  virtual void enterRangeExpr(flicker::RangeExprContext * /*ctx*/) override { }
  virtual void exitRangeExpr(flicker::RangeExprContext * /*ctx*/) override { }

  virtual void enterAndExpr(flicker::AndExprContext * /*ctx*/) override { }
  virtual void exitAndExpr(flicker::AndExprContext * /*ctx*/) override { }

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

  virtual void enterBlockLambda(flicker::BlockLambdaContext * /*ctx*/) override { }
  virtual void exitBlockLambda(flicker::BlockLambdaContext * /*ctx*/) override { }

  virtual void enterBraceLambda(flicker::BraceLambdaContext * /*ctx*/) override { }
  virtual void exitBraceLambda(flicker::BraceLambdaContext * /*ctx*/) override { }

  virtual void enterStatementLambdaBody(flicker::StatementLambdaBodyContext * /*ctx*/) override { }
  virtual void exitStatementLambdaBody(flicker::StatementLambdaBodyContext * /*ctx*/) override { }

  virtual void enterExprLambdaBody(flicker::ExprLambdaBodyContext * /*ctx*/) override { }
  virtual void exitExprLambdaBody(flicker::ExprLambdaBodyContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace antlr
