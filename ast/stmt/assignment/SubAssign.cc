#include "SubAssign.hh"
#include "../../Log.hh"

SubAssign::SubAssign(IdPtr idExp, ExprPtr value) 
    : idExp(std::move(idExp)), value(std::move(value))
{
    LOG_OPERATION_START("SubAssign::SubAssign(IdPtr, ExprPtr)");
    LOG_OPERATION_END("SubAssign::SubAssign(IdPtr, ExprPtr)");
}

SubAssign::~SubAssign()
{
    LOG_OPERATION_START("SubAssign::~SubAssign");
    LOG_OPERATION_END("SubAssign::~SubAssign");
}

Id *SubAssign::getId() const
{
    LOG_OPERATION_START("SubAssign::getId");
    LOG_OPERATION_END("SubAssign::getId");
    return idExp.get();
}

Expr *SubAssign::getValue() const
{
    LOG_OPERATION_START("SubAssign::getValue");
    LOG_OPERATION_END("SubAssign::getValue");
    return value.get();
}

void SubAssign::accept(Visitor *visitor)
{
    LOG_OPERATION_START("SubAssign::accept");
    visitor->visit(this);
    LOG_OPERATION_END("SubAssign::accept");
}
