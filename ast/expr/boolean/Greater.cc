#include "Greater.hh"
#include "../../Log.hh"

Greater::Greater(ExprPtr left, ExprPtr right) : left(std::move(left)), right(std::move(right))
{
    LOG_OPERATION_START("Greater::Greater(ExprPtr, ExprPtr)");
    LOG_OPERATION_END("Greater::Greater(ExprPtr, ExprPtr)");
}

Greater::~Greater()
{
    LOG_OPERATION_START("Greater::~Greater");
    LOG_OPERATION_END("Greater::~Greater");
}

Expr *Greater::getLeft() const
{
    return left.get();
}

Expr* Greater::getRight() const
{
    return right.get();
}

void Greater::accept(Visitor *visitor)
{
    LOG_OPERATION_START("Greater::accept");
    visitor->visit(this);
    LOG_OPERATION_END("Greater::accept");
}