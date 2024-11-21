#include "PrintExpr.hh"
#include "../Log.hh"  // Include the macros header

PrintExpr::PrintExpr(ExprPtr expr) : expr(std::move(expr))
{
    LOG_OPERATION_START("PrintExpr::PrintExpr(ExprPtr)");
    LOG_OPERATION_END("PrintExpr::PrintExpr(ExprPtr)");
}

PrintExpr::~PrintExpr()
{
    LOG_OPERATION_START("PrintExpr::~PrintExpr");
    LOG_OPERATION_END("PrintExpr::~PrintExpr");
}

Expr *PrintExpr::getExpr() const
{
    LOG_OPERATION_START("PrintExpr::getExpr");
    LOG_OPERATION_END("PrintExpr::getExpr");
    return expr.get();
}

void PrintExpr::accept(Visitor *visitor)
{
    LOG_OPERATION_START("PrintExpr::accept");
    visitor->visit(this);
    LOG_OPERATION_END("PrintExpr::accept");
}
