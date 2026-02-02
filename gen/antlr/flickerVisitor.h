
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

    virtual std::any visitStatementEnd(flicker::StatementEndContext *context) = 0;

    virtual std::any visitTopLevel(flicker::TopLevelContext *context) = 0;

    virtual std::any visitType(flicker::TypeContext *context) = 0;

    virtual std::any visitStatement(flicker::StatementContext *context) = 0;

    virtual std::any visitVariableDecl(flicker::VariableDeclContext *context) = 0;

    virtual std::any visitFunctionDecl(flicker::FunctionDeclContext *context) = 0;

    virtual std::any visitFuncReturnType(flicker::FuncReturnTypeContext *context) = 0;

    virtual std::any visitFunctionContents(flicker::FunctionContentsContext *context) = 0;

    virtual std::any visitParamList(flicker::ParamListContext *context) = 0;

    virtual std::any visitParam(flicker::ParamContext *context) = 0;

    virtual std::any visitBlock(flicker::BlockContext *context) = 0;

    virtual std::any visitBlockBody(flicker::BlockBodyContext *context) = 0;

    virtual std::any visitClassDecl(flicker::ClassDeclContext *context) = 0;

    virtual std::any visitClassBody(flicker::ClassBodyContext *context) = 0;

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

    virtual std::any visitExprMulDivMod(flicker::ExprMulDivModContext *context) = 0;

    virtual std::any visitExprAddSub(flicker::ExprAddSubContext *context) = 0;

    virtual std::any visitExprIdentifier(flicker::ExprIdentifierContext *context) = 0;

    virtual std::any visitExprRange(flicker::ExprRangeContext *context) = 0;

    virtual std::any visitExprAssign(flicker::ExprAssignContext *context) = 0;

    virtual std::any visitExprLambda(flicker::ExprLambdaContext *context) = 0;

    virtual std::any visitExprCompare(flicker::ExprCompareContext *context) = 0;

    virtual std::any visitExprMember(flicker::ExprMemberContext *context) = 0;

    virtual std::any visitExprParen(flicker::ExprParenContext *context) = 0;

    virtual std::any visitExprOr(flicker::ExprOrContext *context) = 0;

    virtual std::any visitExprInterpolation(flicker::ExprInterpolationContext *context) = 0;

    virtual std::any visitExprCall(flicker::ExprCallContext *context) = 0;

    virtual std::any visitExprListOrMap(flicker::ExprListOrMapContext *context) = 0;

    virtual std::any visitExprPrefix(flicker::ExprPrefixContext *context) = 0;

    virtual std::any visitExprBitwiseB(flicker::ExprBitwiseBContext *context) = 0;

    virtual std::any visitExprAnd(flicker::ExprAndContext *context) = 0;

    virtual std::any visitExprPower(flicker::ExprPowerContext *context) = 0;

    virtual std::any visitExprIndex(flicker::ExprIndexContext *context) = 0;

    virtual std::any visitExprIf(flicker::ExprIfContext *context) = 0;

    virtual std::any visitExprShift(flicker::ExprShiftContext *context) = 0;

    virtual std::any visitExprConstant(flicker::ExprConstantContext *context) = 0;

    virtual std::any visitExprStaticMember(flicker::ExprStaticMemberContext *context) = 0;

    virtual std::any visitComparisonOperator(flicker::ComparisonOperatorContext *context) = 0;

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

    virtual std::any visitLambdaBody(flicker::LambdaBodyContext *context) = 0;

    virtual std::any visitBraceBody(flicker::BraceBodyContext *context) = 0;

    virtual std::any visitTerminator(flicker::TerminatorContext *context) = 0;


};

}  // namespace antlr
