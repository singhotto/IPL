#include "Or.hh"
#include "../../Log.hh"

Or::Or(ExprPtr left, ExprPtr right) : left(std::move(left)), right(std::move(right))
{
    LOG_OPERATION_START("Or::Or(ExprPtr, ExprPtr)");
    LOG_OPERATION_END("Or::Or(ExprPtr, ExprPtr)");
}

Or::~Or()
{
    LOG_OPERATION_START("Or::~Or");
    LOG_OPERATION_END("Or::~Or");
}

Expr *Or::getLeft() const
{
    return left.get();
}

Expr* Or::getRight() const
{
    return right.get();
}

void Or::accept(Visitor *visitor)
{
    LOG_OPERATION_START("Or::accept");
    visitor->visit(this);
    LOG_OPERATION_END("Or::accept");
}
