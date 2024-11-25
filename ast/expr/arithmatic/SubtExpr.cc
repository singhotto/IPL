#include "expr/arithmatic/SubtExpr.hh"
#include "Log.hh"

SubtExpr::SubtExpr(ExprPtr left, ExprPtr right) : left(std::move(left)), right(std::move(right))
{
    LOG_OPERATION_START("SubtExpr::SubtExpr(ExprPtr, ExprPtr)");
    LOG_OPERATION_END("SubtExpr::SubtExpr(ExprPtr, ExprPtr)");
}

SubtExpr::~SubtExpr()
{
    LOG_OPERATION_START("SubtExpr::~SubtExpr");
    LOG_OPERATION_END("SubtExpr::~SubtExpr");
}

Expr *SubtExpr::getLeft() const
{
    return left.get();
}

Expr* SubtExpr::getRight() const
{
    return right.get();
}

std::unique_ptr<Expr> SubtExpr::cloneExpr() const
{
    auto leftClone = left->cloneExpr();   
    auto rightClone = right->cloneExpr();

    return std::make_unique<SubtExpr>(std::move(leftClone), std::move(rightClone));
}

void SubtExpr::accept(Visitor *visitor)
{
    LOG_OPERATION_START("SubtExpr::~SubtExpr");
    visitor->visit(this);
    LOG_OPERATION_END("SubtExpr::~SubtExpr");
}