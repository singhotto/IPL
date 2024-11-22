#include "LessEqual.hh"
#include "../../Log.hh"

LessEqual::LessEqual(ExprPtr left, ExprPtr right) : left(std::move(left)), right(std::move(right))
{
    LOG_OPERATION_START("LessEqual::LessEqual(ExprPtr, ExprPtr)");
    LOG_OPERATION_END("LessEqual::LessEqual(ExprPtr, ExprPtr)");
}

LessEqual::~LessEqual()
{
    LOG_OPERATION_START("LessEqual::~LessEqual");
    LOG_OPERATION_END("LessEqual::~LessEqual");
}

Expr *LessEqual::getLeft() const
{
    return left.get();
}

Expr* LessEqual::getRight() const
{
    return right.get();
}

void LessEqual::accept(Visitor *visitor)
{
    LOG_OPERATION_START("LessEqual::accept");
    visitor->visit(this);
    LOG_OPERATION_END("LessEqual::accept");
}
