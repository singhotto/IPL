#include "Less.hh"
#include "../../Log.hh"

Less::Less(ExprPtr left, ExprPtr right) : left(std::move(left)), right(std::move(right))
{
    LOG_OPERATION_START("Less::Less(ExprPtr, ExprPtr)");
    LOG_OPERATION_END("Less::Less(ExprPtr, ExprPtr)");
}

Less::~Less()
{
    LOG_OPERATION_START("Less::~Less");
    LOG_OPERATION_END("Less::~Less");
}

Expr *Less::getLeft() const
{
    return left.get();
}

std::unique_ptr<Expr> Less::cloneExpr() const
{
    auto leftClone = left->cloneExpr();   
    auto rightClone = right->cloneExpr();

    return std::make_unique<Less>(std::move(leftClone), std::move(rightClone));
}

Expr* Less::getRight() const
{
    return right.get();
}

void Less::accept(Visitor *visitor)
{
    LOG_OPERATION_START("Less::accept");
    visitor->visit(this);
    LOG_OPERATION_END("Less::accept");
}
