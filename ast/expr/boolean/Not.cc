#include "Not.hh"
#include "Log.hh"

Not::Not(ExprPtr e) : e(std::move(e))
{
    LOG_OPERATION_START("Not::Not(ExprPtr, ExprPtr)");
    LOG_OPERATION_END("Not::Not(ExprPtr, ExprPtr)");
}

Not::~Not()
{
    LOG_OPERATION_START("Not::~Not");
    LOG_OPERATION_END("Not::~Not");
}

Expr *Not::getExpr() const
{
    return e.get();
}


std::unique_ptr<Expr> Not::cloneExpr() const
{
    auto val = e->cloneExpr();  

    return std::make_unique<Not>(std::move(val));
}

void Not::accept(Visitor *visitor)
{
    LOG_OPERATION_START("Not::accept");
    visitor->visit(this);
    LOG_OPERATION_END("Not::accept");
}
