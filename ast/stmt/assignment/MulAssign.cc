#include "MulAssign.hh"
#include "../../Log.hh"

MulAssign::MulAssign(IdPtr idExp, ExprPtr value) 
    : idExp(std::move(idExp)), value(std::move(value))
{
    LOG_OPERATION_START("MulAssign::MulAssign(IdPtr, ExprPtr)");
    LOG_OPERATION_END("MulAssign::MulAssign(IdPtr, ExprPtr)");
}

MulAssign::~MulAssign()
{
    LOG_OPERATION_START("MulAssign::~MulAssign");
    LOG_OPERATION_END("MulAssign::~MulAssign");
}

Id *MulAssign::getId() const
{
    LOG_OPERATION_START("MulAssign::getId");
    LOG_OPERATION_END("MulAssign::getId");
    return idExp.get();
}

Expr *MulAssign::getValue() const
{
    LOG_OPERATION_START("MulAssign::getValue");
    LOG_OPERATION_END("MulAssign::getValue");
    return value.get();
}

void MulAssign::accept(Visitor *visitor)
{
    LOG_OPERATION_START("MulAssign::accept");
    visitor->visit(this);
    LOG_OPERATION_END("MulAssign::accept");
}
