#include "GreaterEqual.hh"
#include "../../Log.hh"

GreaterEqual::GreaterEqual(ExprPtr left, ExprPtr right) : left(std::move(left)), right(std::move(right))
{
    LOG_OPERATION_START("GreaterEqual::GreaterEqual(ExprPtr, ExprPtr)");
    LOG_OPERATION_END("GreaterEqual::GreaterEqual(ExprPtr, ExprPtr)");
}

GreaterEqual::~GreaterEqual()
{
    LOG_OPERATION_START("GreaterEqual::~GreaterEqual");
    LOG_OPERATION_END("GreaterEqual::~GreaterEqual");
}

Expr *GreaterEqual::getLeft() const
{
    return left.get();
}

Expr* GreaterEqual::getRight() const
{
    return right.get();
}

void GreaterEqual::accept(Visitor *visitor)
{
    LOG_OPERATION_START("GreaterEqual::accept");
    visitor->visit(this);
    LOG_OPERATION_END("GreaterEqual::accept");
}
