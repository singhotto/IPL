#include "../../Log.hh"
#include "AddExpr.hh"

AddExpr::AddExpr(ExprPtr left, ExprPtr right) : left(std::move(left)), right(std::move(right))
{
    LOG_OPERATION_START("AddExpr::AddExpr(ExprPtr, ExprPtr)");
    LOG_OPERATION_END("AddExpr::AddExpr(ExprPtr, ExprPtr)");
}

AddExpr::~AddExpr()
{
    LOG_OPERATION_START("AddExpr::~AddExpr()");
    LOG_OPERATION_END("AddExpr::~AddExpr()");
}

Expr *AddExpr::getLeft() const
{
    return left.get();
}

Expr* AddExpr::getRight() const
{
    return right.get();
}

void AddExpr::accept(Visitor* visitor)
{
    LOG_OPERATION_START("AddExpr::accept");
    visitor->visit(this);
    LOG_OPERATION_END("AddExpr::accept");
}
