
// Generated from /home/fractioneater/stuff/git/flicker-3/src/antlr/flicker.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "flicker.h"


namespace antlr {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by flicker.
 */
class  flickerVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by flicker.
   */
    virtual std::any visitProgram(flicker::ProgramContext *context) = 0;

    virtual std::any visitNewline(flicker::NewlineContext *context) = 0;

    virtual std::any visitCodeItem(flicker::CodeItemContext *context) = 0;

    virtual std::any visitType(flicker::TypeContext *context) = 0;

    virtual std::any visitStatement(flicker::StatementContext *context) = 0;

    virtual std::any visitVariableDecl(flicker::VariableDeclContext *context) = 0;

    virtual std::any visitTypeParam(flicker::TypeParamContext *context) = 0;

    virtual std::any visitFunctionDecl(flicker::FunctionDeclContext *context) = 0;

    virtual std::any visitFuncReturnType(flicker::FuncReturnTypeContext *context) = 0;

    virtual std::any visitFunctionContents(flicker::FunctionContentsContext *context) = 0;

    virtual std::any visitParamList(flicker::ParamListContext *context) = 0;

    virtual std::any visitParam(flicker::ParamContext *context) = 0;

    virtual std::any visitBlock(flicker::BlockContext *context) = 0;

    virtual std::any visitBlockBody(flicker::BlockBodyContext *context) = 0;

    virtual std::any visitAccessSpecifier(flicker::AccessSpecifierContext *context) = 0;

    virtual std::any visitClassDecl(flicker::ClassDeclContext *context) = 0;

    virtual std::any visitClassBody(flicker::ClassBodyContext *context) = 0;

    virtual std::any visitCompanionNamespace(flicker::CompanionNamespaceContext *context) = 0;

    virtual std::any visitClassItem(flicker::ClassItemContext *context) = 0;

    virtual std::any visitMethod(flicker::MethodContext *context) = 0;

    virtual std::any visitUsingStatement(flicker::UsingStatementContext *context) = 0;

    virtual std::any visitImportList(flicker::ImportListContext *context) = 0;

    virtual std::any visitImportItem(flicker::ImportItemContext *context) = 0;

    virtual std::any visitLoopLabel(flicker::LoopLabelContext *context) = 0;

    virtual std::any visitDoStatement(flicker::DoStatementContext *context) = 0;

    virtual std::any visitBlockOrStatement(flicker::BlockOrStatementContext *context) = 0;

    virtual std::any visitIfStmt(flicker::IfStmtContext *context) = 0;

    virtual std::any visitWhileStmt(flicker::WhileStmtContext *context) = 0;

    virtual std::any visitEachStmt(flicker::EachStmtContext *context) = 0;

    virtual std::any visitForStmt(flicker::ForStmtContext *context) = 0;

    virtual std::any visitBreakStmt(flicker::BreakStmtContext *context) = 0;

    virtual std::any visitContinueStmt(flicker::ContinueStmtContext *context) = 0;

    virtual std::any visitWhenStmt(flicker::WhenStmtContext *context) = 0;

    virtual std::any visitReturnStmt(flicker::ReturnStmtContext *context) = 0;

    virtual std::any visitPrintStmt(flicker::PrintStmtContext *context) = 0;

    virtual std::any visitConsoleErrorStmt(flicker::ConsoleErrorStmtContext *context) = 0;

    virtual std::any visitPassStmt(flicker::PassStmtContext *context) = 0;

    virtual std::any visitWhenBody(flicker::WhenBodyContext *context) = 0;

    virtual std::any visitWhenContents(flicker::WhenContentsContext *context) = 0;

    virtual std::any visitWhenCase(flicker::WhenCaseContext *context) = 0;

    virtual std::any visitElseCase(flicker::ElseCaseContext *context) = 0;

    virtual std::any visitConstant(flicker::ConstantContext *context) = 0;

    virtual std::any visitPowerExpr(flicker::PowerExprContext *context) = 0;

    virtual std::any visitTermExpr(flicker::TermExprContext *context) = 0;

    virtual std::any visitBitShiftExpr(flicker::BitShiftExprContext *context) = 0;

    virtual std::any visitFactorExpr(flicker::FactorExprContext *context) = 0;

    virtual std::any visitLambdaCall(flicker::LambdaCallContext *context) = 0;

    virtual std::any visitParenExpr(flicker::ParenExprContext *context) = 0;

    virtual std::any visitLambda(flicker::LambdaContext *context) = 0;

    virtual std::any visitBitwisExpr(flicker::BitwisExprContext *context) = 0;

    virtual std::any visitNilCoalescingOp(flicker::NilCoalescingOpContext *context) = 0;

    virtual std::any visitMember(flicker::MemberContext *context) = 0;

    virtual std::any visitIfExpr(flicker::IfExprContext *context) = 0;

    virtual std::any visitArrayAccess(flicker::ArrayAccessContext *context) = 0;

    virtual std::any visitPostfixExpr(flicker::PostfixExprContext *context) = 0;

    virtual std::any visitListOrMap(flicker::ListOrMapContext *context) = 0;

    virtual std::any visitIsExpr(flicker::IsExprContext *context) = 0;

    virtual std::any visitIdentifier(flicker::IdentifierContext *context) = 0;

    virtual std::any visitComparison(flicker::ComparisonContext *context) = 0;

    virtual std::any visitInExpr(flicker::InExprContext *context) = 0;

    virtual std::any visitAssignment(flicker::AssignmentContext *context) = 0;

    virtual std::any visitOrExpr(flicker::OrExprContext *context) = 0;

    virtual std::any visitCall(flicker::CallContext *context) = 0;

    virtual std::any visitPrefixExpr(flicker::PrefixExprContext *context) = 0;

    virtual std::any visitInterpolation(flicker::InterpolationContext *context) = 0;

    virtual std::any visitNotExpr(flicker::NotExprContext *context) = 0;

    virtual std::any visitScopedIdentifier(flicker::ScopedIdentifierContext *context) = 0;

    virtual std::any visitRangeExpr(flicker::RangeExprContext *context) = 0;

    virtual std::any visitAndExpr(flicker::AndExprContext *context) = 0;

    virtual std::any visitComparisonOperator(flicker::ComparisonOperatorContext *context) = 0;

    virtual std::any visitAssignOperator(flicker::AssignOperatorContext *context) = 0;

    virtual std::any visitInterpolationExpr(flicker::InterpolationExprContext *context) = 0;

    virtual std::any visitConstantExpr(flicker::ConstantExprContext *context) = 0;

    virtual std::any visitListOrMapLiteral(flicker::ListOrMapLiteralContext *context) = 0;

    virtual std::any visitListLiteral(flicker::ListLiteralContext *context) = 0;

    virtual std::any visitListItems(flicker::ListItemsContext *context) = 0;

    virtual std::any visitMapLiteral(flicker::MapLiteralContext *context) = 0;

    virtual std::any visitMapItems(flicker::MapItemsContext *context) = 0;

    virtual std::any visitMapItem(flicker::MapItemContext *context) = 0;

    virtual std::any visitLambdaLiteral(flicker::LambdaLiteralContext *context) = 0;

    virtual std::any visitLambdaParams(flicker::LambdaParamsContext *context) = 0;

    virtual std::any visitParenthesizedOptionalParamList(flicker::ParenthesizedOptionalParamListContext *context) = 0;

    virtual std::any visitBlockLambda(flicker::BlockLambdaContext *context) = 0;

    virtual std::any visitBraceLambda(flicker::BraceLambdaContext *context) = 0;

    virtual std::any visitStatementLambdaBody(flicker::StatementLambdaBodyContext *context) = 0;

    virtual std::any visitExprLambdaBody(flicker::ExprLambdaBodyContext *context) = 0;


};

}  // namespace antlr
