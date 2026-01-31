
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

  virtual std::any visitStatementEnd(flicker::StatementEndContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTopLevel(flicker::TopLevelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(flicker::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclaration(flicker::DeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariableDecl(flicker::VariableDeclContext *ctx) override {
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

  virtual std::any visitClassDecl(flicker::ClassDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassBody(flicker::ClassBodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUse(flicker::UseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitImportList(flicker::ImportListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitKeywordStatement(flicker::KeywordStatementContext *ctx) override {
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

  virtual std::any visitExprMulDivMod(flicker::ExprMulDivModContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprAddSub(flicker::ExprAddSubContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprIdentifier(flicker::ExprIdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprRange(flicker::ExprRangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprAssign(flicker::ExprAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprLambda(flicker::ExprLambdaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprCompare(flicker::ExprCompareContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprMember(flicker::ExprMemberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprParen(flicker::ExprParenContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprOr(flicker::ExprOrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprInterpolation(flicker::ExprInterpolationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprCall(flicker::ExprCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprListOrMap(flicker::ExprListOrMapContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprPrefix(flicker::ExprPrefixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprBitwiseB(flicker::ExprBitwiseBContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprAnd(flicker::ExprAndContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprPower(flicker::ExprPowerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprIndex(flicker::ExprIndexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprIf(flicker::ExprIfContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprShift(flicker::ExprShiftContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprConstant(flicker::ExprConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprStaticMember(flicker::ExprStaticMemberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComparisonOperator(flicker::ComparisonOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParenthesizedExpr(flicker::ParenthesizedExprContext *ctx) override {
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

  virtual std::any visitLambdaBody(flicker::LambdaBodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBraceBody(flicker::BraceBodyContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace antlr
