#include "Log.hh"
#include "expr/arithmatic/MulExpr.hh"

MulExpr::MulExpr(ExprPtr left, ExprPtr right) : left(std::move(left)), right(std::move(right))
{
    LOG_OPERATION_START("MulExpr::MulExpr(ExprPtr, ExprPtr)");
    LOG_OPERATION_END("MulExpr::MulExpr(ExprPtr, ExprPtr)");
}

MulExpr::~MulExpr()
{
    LOG_OPERATION_START("MulExpr::~MulExpr");
    LOG_OPERATION_END("MulExpr::~MulExpr");
}

Expr *MulExpr::getLeft() const
{
    return left.get();
}

Expr* MulExpr::getRight() const
{
    return right.get();
}

std::unique_ptr<Expr> MulExpr::cloneExpr() const
{
    auto leftClone = left->cloneExpr();   
    auto rightClone = right->cloneExpr();

    return std::make_unique<MulExpr>(std::move(leftClone), std::move(rightClone));
}

void MulExpr::accept(Visitor *visitor)
{
    LOG_OPERATION_START("MulExpr::accept");
    visitor->visit(this);
    LOG_OPERATION_END("MulExpr::accept");
}
