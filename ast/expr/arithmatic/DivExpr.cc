#include "../../Log.hh"
#include "DivExpr.hh"

DivExpr::DivExpr(ExprPtr left, ExprPtr right) : left(std::move(left)), right(std::move(right))
{
    LOG_OPERATION_START("DivExpr::DivExpr(ExprPtr, ExprPtr)");
    LOG_OPERATION_END("DivExpr::DivExpr(ExprPtr, ExprPtr)");
}

DivExpr::~DivExpr()
{
    LOG_OPERATION_START("DivExpr::~DivExpr()");
    LOG_OPERATION_END("DivExpr::~DivExpr()");
}

Expr *DivExpr::getLeft() const
{
    return left.get();
}

Expr *DivExpr::getRight() const
{
    return right.get();
}

std::unique_ptr<Expr> DivExpr::cloneExpr() const
{
    auto leftClone = left->cloneExpr();   
    auto rightClone = right->cloneExpr();

    return std::make_unique<DivExpr>(std::move(leftClone), std::move(rightClone));
}

void DivExpr::accept(Visitor *visitor)
{
    LOG_OPERATION_START("DivExpr::accept");
    visitor->visit(this);
    LOG_OPERATION_END("DivExpr::accept");
}
