#include "DefVar.hh"
#include "../Log.hh"

DefVar::DefVar(IdPtr idExp) : idExp(std::move(idExp)), value(ExprPtr())
{
    LOG_OPERATION_START("DefVar::DefVar(IdPtr)");
    LOG_OPERATION_END("DefVar::DefVar(IdPtr)");
}

DefVar::DefVar(IdPtr idExp, ExprPtr value)
    : idExp(std::move(idExp)), value(std::move(value))
{
    LOG_OPERATION_START("DefVar::DefVar(IdPtr, ExprPtr)");
    LOG_OPERATION_END("DefVar::DefVar(IdPtr, ExprPtr)");
}

DefVar::~DefVar()
{
    LOG_OPERATION_START("DefVar::~DefVar");
    LOG_OPERATION_END("DefVar::~DefVar");
}

Id *DefVar::getId() const
{
    LOG_OPERATION_START("DefVar::getId");
    LOG_OPERATION_END("DefVar::getId");
    return idExp.get();
}

Expr *DefVar::getValue() const
{
    LOG_OPERATION_START("DefVar::getValue");
    LOG_OPERATION_END("DefVar::getValue");
    return value.get();
}

std::unique_ptr<Statement> DefVar::clone() const
{
    // Clone the Id (idExp)
    auto idExpClone = idExp->cloneId(); 

    // Check if `value` exists and clone it if it does
    if (value)
    {
        auto valueClone = value->cloneExpr(); // Clone the concrete Expr (value)
        return std::make_unique<DefVar>(std::move(idExpClone), std::move(valueClone)); // Clone both members
    }
    // If no value exists, create DefVar with only idExpClone
    return std::make_unique<DefVar>(std::move(idExpClone));
}

void DefVar::accept(Visitor *visitor)
{
    LOG_OPERATION_START("DefVar::accept");
    visitor->visit(this);
    LOG_OPERATION_END("DefVar::accept");
}
