#include "expr/arithmatic/ModExpr.hh"
#include "Log.hh"

ModExpr::ModExpr(ExprPtr left, ExprPtr right) : left(std::move(left)), right(std::move(right))
{
    LOG_OPERATION_START("ModExpr::ModExpr(ExprPtr, ExprPtr)");
    LOG_OPERATION_END("ModExpr::ModExpr(ExprPtr, ExprPtr)");
}

ModExpr::~ModExpr()
{
    LOG_OPERATION_START("ModExpr::~ModExpr");
    LOG_OPERATION_END("ModExpr::~ModExpr");
}

Expr *ModExpr::getLeft() const
{
    return left.get();
}

Expr* ModExpr::getRight() const
{
    return right.get();
}

std::unique_ptr<Expr> ModExpr::cloneExpr() const
{
    auto leftClone = left->cloneExpr();   
    auto rightClone = right->cloneExpr();

    return std::make_unique<ModExpr>(std::move(leftClone), std::move(rightClone));
}

void ModExpr::accept(Visitor *visitor)
{
    LOG_OPERATION_START("ModExpr::accept");
    visitor->visit(this);
    LOG_OPERATION_END("ModExpr::accept");
}
