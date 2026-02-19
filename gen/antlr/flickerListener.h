
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

  virtual void enterCodeItem(flicker::CodeItemContext *ctx) = 0;
  virtual void exitCodeItem(flicker::CodeItemContext *ctx) = 0;

  virtual void enterType(flicker::TypeContext *ctx) = 0;
  virtual void exitType(flicker::TypeContext *ctx) = 0;

  virtual void enterStatement(flicker::StatementContext *ctx) = 0;
  virtual void exitStatement(flicker::StatementContext *ctx) = 0;

  virtual void enterDeclaration(flicker::DeclarationContext *ctx) = 0;
  virtual void exitDeclaration(flicker::DeclarationContext *ctx) = 0;

  virtual void enterNamespace(flicker::NamespaceContext *ctx) = 0;
  virtual void exitNamespace(flicker::NamespaceContext *ctx) = 0;

  virtual void enterVariableDecl(flicker::VariableDeclContext *ctx) = 0;
  virtual void exitVariableDecl(flicker::VariableDeclContext *ctx) = 0;

  virtual void enterTypeParam(flicker::TypeParamContext *ctx) = 0;
  virtual void exitTypeParam(flicker::TypeParamContext *ctx) = 0;

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

  virtual void enterAccessSpecifier(flicker::AccessSpecifierContext *ctx) = 0;
  virtual void exitAccessSpecifier(flicker::AccessSpecifierContext *ctx) = 0;

  virtual void enterClassDecl(flicker::ClassDeclContext *ctx) = 0;
  virtual void exitClassDecl(flicker::ClassDeclContext *ctx) = 0;

  virtual void enterClassBody(flicker::ClassBodyContext *ctx) = 0;
  virtual void exitClassBody(flicker::ClassBodyContext *ctx) = 0;

  virtual void enterCompanionNamespace(flicker::CompanionNamespaceContext *ctx) = 0;
  virtual void exitCompanionNamespace(flicker::CompanionNamespaceContext *ctx) = 0;

  virtual void enterClassItem(flicker::ClassItemContext *ctx) = 0;
  virtual void exitClassItem(flicker::ClassItemContext *ctx) = 0;

  virtual void enterInitializer(flicker::InitializerContext *ctx) = 0;
  virtual void exitInitializer(flicker::InitializerContext *ctx) = 0;

  virtual void enterInitParamList(flicker::InitParamListContext *ctx) = 0;
  virtual void exitInitParamList(flicker::InitParamListContext *ctx) = 0;

  virtual void enterInitParam(flicker::InitParamContext *ctx) = 0;
  virtual void exitInitParam(flicker::InitParamContext *ctx) = 0;

  virtual void enterSuperInitParams(flicker::SuperInitParamsContext *ctx) = 0;
  virtual void exitSuperInitParams(flicker::SuperInitParamsContext *ctx) = 0;

  virtual void enterMethod(flicker::MethodContext *ctx) = 0;
  virtual void exitMethod(flicker::MethodContext *ctx) = 0;

  virtual void enterUsingStatement(flicker::UsingStatementContext *ctx) = 0;
  virtual void exitUsingStatement(flicker::UsingStatementContext *ctx) = 0;

  virtual void enterImportList(flicker::ImportListContext *ctx) = 0;
  virtual void exitImportList(flicker::ImportListContext *ctx) = 0;

  virtual void enterImportItem(flicker::ImportItemContext *ctx) = 0;
  virtual void exitImportItem(flicker::ImportItemContext *ctx) = 0;

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

  virtual void enterConstant(flicker::ConstantContext *ctx) = 0;
  virtual void exitConstant(flicker::ConstantContext *ctx) = 0;

  virtual void enterPowerExpr(flicker::PowerExprContext *ctx) = 0;
  virtual void exitPowerExpr(flicker::PowerExprContext *ctx) = 0;

  virtual void enterTermExpr(flicker::TermExprContext *ctx) = 0;
  virtual void exitTermExpr(flicker::TermExprContext *ctx) = 0;

  virtual void enterBitShiftExpr(flicker::BitShiftExprContext *ctx) = 0;
  virtual void exitBitShiftExpr(flicker::BitShiftExprContext *ctx) = 0;

  virtual void enterFactorExpr(flicker::FactorExprContext *ctx) = 0;
  virtual void exitFactorExpr(flicker::FactorExprContext *ctx) = 0;

  virtual void enterLambdaCall(flicker::LambdaCallContext *ctx) = 0;
  virtual void exitLambdaCall(flicker::LambdaCallContext *ctx) = 0;

  virtual void enterParenExpr(flicker::ParenExprContext *ctx) = 0;
  virtual void exitParenExpr(flicker::ParenExprContext *ctx) = 0;

  virtual void enterLambda(flicker::LambdaContext *ctx) = 0;
  virtual void exitLambda(flicker::LambdaContext *ctx) = 0;

  virtual void enterBitwisExpr(flicker::BitwisExprContext *ctx) = 0;
  virtual void exitBitwisExpr(flicker::BitwisExprContext *ctx) = 0;

  virtual void enterNilCoalescingOp(flicker::NilCoalescingOpContext *ctx) = 0;
  virtual void exitNilCoalescingOp(flicker::NilCoalescingOpContext *ctx) = 0;

  virtual void enterMember(flicker::MemberContext *ctx) = 0;
  virtual void exitMember(flicker::MemberContext *ctx) = 0;

  virtual void enterIfExpr(flicker::IfExprContext *ctx) = 0;
  virtual void exitIfExpr(flicker::IfExprContext *ctx) = 0;

  virtual void enterArrayAccess(flicker::ArrayAccessContext *ctx) = 0;
  virtual void exitArrayAccess(flicker::ArrayAccessContext *ctx) = 0;

  virtual void enterPostfixExpr(flicker::PostfixExprContext *ctx) = 0;
  virtual void exitPostfixExpr(flicker::PostfixExprContext *ctx) = 0;

  virtual void enterListOrMap(flicker::ListOrMapContext *ctx) = 0;
  virtual void exitListOrMap(flicker::ListOrMapContext *ctx) = 0;

  virtual void enterIsExpr(flicker::IsExprContext *ctx) = 0;
  virtual void exitIsExpr(flicker::IsExprContext *ctx) = 0;

  virtual void enterIdentifier(flicker::IdentifierContext *ctx) = 0;
  virtual void exitIdentifier(flicker::IdentifierContext *ctx) = 0;

  virtual void enterComparison(flicker::ComparisonContext *ctx) = 0;
  virtual void exitComparison(flicker::ComparisonContext *ctx) = 0;

  virtual void enterInExpr(flicker::InExprContext *ctx) = 0;
  virtual void exitInExpr(flicker::InExprContext *ctx) = 0;

  virtual void enterAssignment(flicker::AssignmentContext *ctx) = 0;
  virtual void exitAssignment(flicker::AssignmentContext *ctx) = 0;

  virtual void enterOrExpr(flicker::OrExprContext *ctx) = 0;
  virtual void exitOrExpr(flicker::OrExprContext *ctx) = 0;

  virtual void enterCall(flicker::CallContext *ctx) = 0;
  virtual void exitCall(flicker::CallContext *ctx) = 0;

  virtual void enterPrefixExpr(flicker::PrefixExprContext *ctx) = 0;
  virtual void exitPrefixExpr(flicker::PrefixExprContext *ctx) = 0;

  virtual void enterInterpolation(flicker::InterpolationContext *ctx) = 0;
  virtual void exitInterpolation(flicker::InterpolationContext *ctx) = 0;

  virtual void enterNotExpr(flicker::NotExprContext *ctx) = 0;
  virtual void exitNotExpr(flicker::NotExprContext *ctx) = 0;

  virtual void enterScopedIdentifier(flicker::ScopedIdentifierContext *ctx) = 0;
  virtual void exitScopedIdentifier(flicker::ScopedIdentifierContext *ctx) = 0;

  virtual void enterRangeExpr(flicker::RangeExprContext *ctx) = 0;
  virtual void exitRangeExpr(flicker::RangeExprContext *ctx) = 0;

  virtual void enterAndExpr(flicker::AndExprContext *ctx) = 0;
  virtual void exitAndExpr(flicker::AndExprContext *ctx) = 0;

  virtual void enterComparisonOperator(flicker::ComparisonOperatorContext *ctx) = 0;
  virtual void exitComparisonOperator(flicker::ComparisonOperatorContext *ctx) = 0;

  virtual void enterAssignOperator(flicker::AssignOperatorContext *ctx) = 0;
  virtual void exitAssignOperator(flicker::AssignOperatorContext *ctx) = 0;

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

  virtual void enterBlockLambda(flicker::BlockLambdaContext *ctx) = 0;
  virtual void exitBlockLambda(flicker::BlockLambdaContext *ctx) = 0;

  virtual void enterBraceLambda(flicker::BraceLambdaContext *ctx) = 0;
  virtual void exitBraceLambda(flicker::BraceLambdaContext *ctx) = 0;

  virtual void enterStatementLambdaBody(flicker::StatementLambdaBodyContext *ctx) = 0;
  virtual void exitStatementLambdaBody(flicker::StatementLambdaBodyContext *ctx) = 0;

  virtual void enterExprLambdaBody(flicker::ExprLambdaBodyContext *ctx) = 0;
  virtual void exitExprLambdaBody(flicker::ExprLambdaBodyContext *ctx) = 0;


};

}  // namespace antlr
