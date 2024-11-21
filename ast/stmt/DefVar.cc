#include "DefVar.hh"
#include "../Log.hh"  // Include the macros header

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

void DefVar::accept(Visitor *visitor)
{
    LOG_OPERATION_START("DefVar::accept");
    visitor->visit(this);
    LOG_OPERATION_END("DefVar::accept");
}
