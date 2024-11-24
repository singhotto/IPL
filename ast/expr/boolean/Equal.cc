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

std::unique_ptr<Expr> Equal::cloneExpr() const
{
    auto leftClone = left->cloneExpr();   
    auto rightClone = right->cloneExpr();

    return std::make_unique<Equal>(std::move(leftClone), std::move(rightClone));
}

void Equal::accept(Visitor *visitor)
{
    LOG_OPERATION_START("Equal::accept");
    visitor->visit(this);
    LOG_OPERATION_END("Equal::accept");
}
