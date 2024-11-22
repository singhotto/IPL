#include "SubtExpr.hh"
#include "../../Log.hh"

SubtExpr::SubtExpr(ExprPtr left, ExprPtr right) : left(std::move(left)), right(std::move(right))
{
    LOG_OPERATION_START("SubtExpr::SubtExpr(ExprPtr, ExprPtr)");
    LOG_OPERATION_END("SubtExpr::SubtExpr(ExprPtr, ExprPtr)");
}

SubtExpr::~SubtExpr()
{
    LOG_OPERATION_START("SubtExpr::~SubtExpr");
    LOG_OPERATION_END("SubtExpr::~SubtExpr");
}

Expr *SubtExpr::getLeft() const
{
    return left.get();
}

Expr* SubtExpr::getRight() const
{
    return right.get();
}

void SubtExpr::accept(Visitor *visitor)
{
    LOG_OPERATION_START("SubtExpr::~SubtExpr");
    visitor->visit(this);
    LOG_OPERATION_END("SubtExpr::~SubtExpr");
}