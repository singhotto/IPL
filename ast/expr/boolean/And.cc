#include "expr/boolean/And.hh"
#include "Log.hh"

And::And(ExprPtr left, ExprPtr right) : left(std::move(left)), right(std::move(right))
{
    LOG_OPERATION_START("And::And(ExprPtr, ExprPtr)");
    LOG_OPERATION_END("And::And(ExprPtr, ExprPtr)");
}

And::~And()
{
    LOG_OPERATION_START("And::~And");
    LOG_OPERATION_END("And::~And");
}

Expr *And::getLeft() const
{
    return left.get();
}

Expr *And::getRight() const
{
    return right.get();
}

std::unique_ptr<Expr> And::cloneExpr() const
{
    auto leftClone = left->cloneExpr();   
    auto rightClone = right->cloneExpr();

    return std::make_unique<And>(std::move(leftClone), std::move(rightClone));
}

void And::accept(Visitor *visitor)
{
    LOG_OPERATION_START("And::accept");
    visitor->visit(this);
    LOG_OPERATION_END("And::accept");
}
