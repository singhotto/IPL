#include "MinusExpr.hh"
#include "Log.hh"

MinusExpr::MinusExpr(ExprPtr e) : e(std::move(e))
{
    LOG_OPERATION_START("MinusExpr::MinusExpr(ExprPtr, ExprPtr)");
    LOG_OPERATION_END("MinusExpr::MinusExpr(ExprPtr, ExprPtr)");
}

MinusExpr::~MinusExpr()
{
    LOG_OPERATION_START("MinusExpr::~MinusExpr()");
    LOG_OPERATION_END("MinusExpr::~MinusExpr()");
}

Expr *MinusExpr::getExpr() const
{
    return e.get();
}


std::unique_ptr<Expr> MinusExpr::cloneExpr() const
{
    auto val = e->cloneExpr();   

    return std::make_unique<MinusExpr>(std::move(val));
}

void MinusExpr::accept(Visitor* visitor)
{
    LOG_OPERATION_START("MinusExpr::accept");
    visitor->visit(this);
    LOG_OPERATION_END("MinusExpr::accept");
}
