#include "Assign.hh"
#include "../../Log.hh"

Assign::Assign(IdPtr idExp, ExprPtr value) 
    : idExp(std::move(idExp)), value(std::move(value))
{
    LOG_OPERATION_START("Assign::Assign(IdPtr, ExprPtr)");
    LOG_OPERATION_END("Assign::Assign(IdPtr, ExprPtr)");
}

Assign::~Assign()
{
    LOG_OPERATION_START("Assign::~Assign");
    LOG_OPERATION_END("Assign::~Assign");
}

Id *Assign::getId() const
{
    LOG_OPERATION_START("Assign::getId");
    LOG_OPERATION_END("Assign::getId");
    return idExp.get();
}

Expr *Assign::getValue() const
{
    LOG_OPERATION_START("Assign::getValue");
    LOG_OPERATION_END("Assign::getValue");
    return value.get();
}

void Assign::accept(Visitor *visitor)
{
    LOG_OPERATION_START("Assign::accept");
    visitor->visit(this);
    LOG_OPERATION_END("Assign::accept");
}
