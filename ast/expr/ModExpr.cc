#include "ModExpr.hh"
#include "../Log.hh"

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

void ModExpr::accept(Visitor *visitor)
{
    LOG_OPERATION_START("ModExpr::accept");
    visitor->visit(this);
    LOG_OPERATION_END("ModExpr::accept");
}
