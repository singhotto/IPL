#include "NotEqual.hh"
#include "../../Log.hh"

NotEqual::NotEqual(ExprPtr left, ExprPtr right) : left(std::move(left)), right(std::move(right))
{
    LOG_OPERATION_START("NotEqual::NotEqual(ExprPtr, ExprPtr)");
    LOG_OPERATION_END("NotEqual::NotEqual(ExprPtr, ExprPtr)");
}

NotEqual::~NotEqual()
{
    LOG_OPERATION_START("NotEqual::~NotEqual");
    LOG_OPERATION_END("NotEqual::~NotEqual");
}

Expr *NotEqual::getLeft() const
{
    return left.get();
}

Expr* NotEqual::getRight() const
{
    return right.get();
}

void NotEqual::accept(Visitor *visitor)
{
    LOG_OPERATION_START("NotEqual::accept");
    visitor->visit(this);
    LOG_OPERATION_END("NotEqual::accept");
}
