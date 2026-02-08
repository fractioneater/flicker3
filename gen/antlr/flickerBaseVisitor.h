
// Generated from /home/fractioneater/stuff/git/flicker-3/src/antlr/flicker.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "flickerVisitor.h"


namespace antlr {

/**
 * This class provides an empty implementation of flickerVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  flickerBaseVisitor : public flickerVisitor {
public:

  virtual std::any visitProgram(flicker::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNewline(flicker::NewlineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCodeItem(flicker::CodeItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType(flicker::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(flicker::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariableDecl(flicker::VariableDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeParam(flicker::TypeParamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionDecl(flicker::FunctionDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncReturnType(flicker::FuncReturnTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionContents(flicker::FunctionContentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParamList(flicker::ParamListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParam(flicker::ParamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(flicker::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlockBody(flicker::BlockBodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAccessSpecifier(flicker::AccessSpecifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassDecl(flicker::ClassDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassBody(flicker::ClassBodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompanionNamespace(flicker::CompanionNamespaceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassItem(flicker::ClassItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMethod(flicker::MethodContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUsingStatement(flicker::UsingStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitImportList(flicker::ImportListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitImportItem(flicker::ImportItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLoopLabel(flicker::LoopLabelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDoStatement(flicker::DoStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlockOrStatement(flicker::BlockOrStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfStmt(flicker::IfStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhileStmt(flicker::WhileStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEachStmt(flicker::EachStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForStmt(flicker::ForStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBreakStmt(flicker::BreakStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitContinueStmt(flicker::ContinueStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhenStmt(flicker::WhenStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnStmt(flicker::ReturnStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrintStmt(flicker::PrintStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConsoleErrorStmt(flicker::ConsoleErrorStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPassStmt(flicker::PassStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhenBody(flicker::WhenBodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhenContents(flicker::WhenContentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhenCase(flicker::WhenCaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElseCase(flicker::ElseCaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstant(flicker::ConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPowerExpr(flicker::PowerExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTermExpr(flicker::TermExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitShiftExpr(flicker::BitShiftExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactorExpr(flicker::FactorExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLambdaCall(flicker::LambdaCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParenExpr(flicker::ParenExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLambda(flicker::LambdaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitwisExpr(flicker::BitwisExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNilCoalescingOp(flicker::NilCoalescingOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMember(flicker::MemberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfExpr(flicker::IfExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayAccess(flicker::ArrayAccessContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPostfixExpr(flicker::PostfixExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitListOrMap(flicker::ListOrMapContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIsExpr(flicker::IsExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdentifier(flicker::IdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComparison(flicker::ComparisonContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInExpr(flicker::InExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignment(flicker::AssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOrExpr(flicker::OrExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCall(flicker::CallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrefixExpr(flicker::PrefixExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInterpolation(flicker::InterpolationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNotExpr(flicker::NotExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitScopedIdentifier(flicker::ScopedIdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRangeExpr(flicker::RangeExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAndExpr(flicker::AndExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComparisonOperator(flicker::ComparisonOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignOperator(flicker::AssignOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInterpolationExpr(flicker::InterpolationExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstantExpr(flicker::ConstantExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitListOrMapLiteral(flicker::ListOrMapLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitListLiteral(flicker::ListLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitListItems(flicker::ListItemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMapLiteral(flicker::MapLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMapItems(flicker::MapItemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMapItem(flicker::MapItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLambdaLiteral(flicker::LambdaLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLambdaParams(flicker::LambdaParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParenthesizedOptionalParamList(flicker::ParenthesizedOptionalParamListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlockLambda(flicker::BlockLambdaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBraceLambda(flicker::BraceLambdaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementLambdaBody(flicker::StatementLambdaBodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprLambdaBody(flicker::ExprLambdaBodyContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace antlr
