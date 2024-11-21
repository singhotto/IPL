#include "../Log.hh"  // Include the macros header
#include "MulExpr.hh"

MulExpr::MulExpr(ExprPtr left, ExprPtr right) : left(std::move(left)), right(std::move(right))
{
    LOG_OPERATION_START("MulExpr::MulExpr(ExprPtr, ExprPtr)");
    LOG_OPERATION_END("MulExpr::MulExpr(ExprPtr, ExprPtr)");
}

MulExpr::~MulExpr()
{
    LOG_OPERATION_START("MulExpr::~MulExpr");
    LOG_OPERATION_END("MulExpr::~MulExpr");
}

Expr *MulExpr::getLeft() const
{
    return left.get();
}

Expr* MulExpr::getRight() const
{
    return right.get();
}

void MulExpr::accept(Visitor *visitor)
{
    LOG_OPERATION_START("MulExpr::accept");
    visitor->visit(this);
    LOG_OPERATION_END("MulExpr::accept");
}
