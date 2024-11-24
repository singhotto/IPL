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

std::unique_ptr<Expr> Or::cloneExpr() const
{
    auto leftClone = left->cloneExpr();   
    auto rightClone = right->cloneExpr();

    return std::make_unique<Or>(std::move(leftClone), std::move(rightClone));
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
