#include "Equal.hh"
#include "../../Log.hh"

Equal::Equal(ExprPtr left, ExprPtr right) : left(std::move(left)), right(std::move(right))
{
    LOG_OPERATION_START("Equal::Equal(ExprPtr, ExprPtr)");
    LOG_OPERATION_END("Equal::Equal(ExprPtr, ExprPtr)");
}

Equal::~Equal()
{
    LOG_OPERATION_START("Equal::~Equal");
    LOG_OPERATION_END("Equal::~Equal");
}

Expr *Equal::getLeft() const
{
    return left.get();
}

Expr* Equal::getRight() const
{
    return right.get();
}

void Equal::accept(Visitor *visitor)
{
    LOG_OPERATION_START("Equal::accept");
    visitor->visit(this);
    LOG_OPERATION_END("Equal::accept");
}
