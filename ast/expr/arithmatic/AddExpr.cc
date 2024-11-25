#include "Log.hh"
#include "expr/arithmatic/AddExpr.hh"

AddExpr::AddExpr(ExprPtr left, ExprPtr right) : left(std::move(left)), right(std::move(right))
{
    LOG_OPERATION_START("AddExpr::AddExpr(ExprPtr, ExprPtr)");
    LOG_OPERATION_END("AddExpr::AddExpr(ExprPtr, ExprPtr)");
}

AddExpr::~AddExpr()
{
    LOG_OPERATION_START("AddExpr::~AddExpr()");
    LOG_OPERATION_END("AddExpr::~AddExpr()");
}

Expr *AddExpr::getLeft() const
{
    return left.get();
}

Expr* AddExpr::getRight() const
{
    return right.get();
}

std::unique_ptr<Expr> AddExpr::cloneExpr() const
{
    auto leftClone = left->cloneExpr();   
    auto rightClone = right->cloneExpr();

    return std::make_unique<AddExpr>(std::move(leftClone), std::move(rightClone));
}

void AddExpr::accept(Visitor* visitor)
{
    LOG_OPERATION_START("AddExpr::accept");
    visitor->visit(this);
    LOG_OPERATION_END("AddExpr::accept");
}
