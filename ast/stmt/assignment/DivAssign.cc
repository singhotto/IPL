#include "DivAssign.hh"
#include "../../Log.hh"

DivAssign::DivAssign(IdPtr idExp, ExprPtr value) 
    : idExp(std::move(idExp)), value(std::move(value))
{
    LOG_OPERATION_START("DivAssign::DivAssign(IdPtr, ExprPtr)");
    LOG_OPERATION_END("DivAssign::DivAssign(IdPtr, ExprPtr)");
}

DivAssign::~DivAssign()
{
    LOG_OPERATION_START("DivAssign::~DivAssign");
    LOG_OPERATION_END("DivAssign::~DivAssign");
}

Id *DivAssign::getId() const
{
    LOG_OPERATION_START("DivAssign::getId");
    LOG_OPERATION_END("DivAssign::getId");
    return idExp.get();
}

Expr *DivAssign::getValue() const
{
    LOG_OPERATION_START("DivAssign::getValue");
    LOG_OPERATION_END("DivAssign::getValue");
    return value.get();
}

std::unique_ptr<Statement> DivAssign::clone() const
{
    auto idExpClone = idExp->cloneId(); // Clone the Id object
    auto valueClone = value->cloneExpr(); // Clone the Expr object

    // Return a new DivAssign object with the cloned members
    return std::make_unique<DivAssign>(std::move(idExpClone), std::move(valueClone));
}

void DivAssign::accept(Visitor *visitor)
{
    LOG_OPERATION_START("DivAssign::accept");
    visitor->visit(this);
    LOG_OPERATION_END("DivAssign::accept");
}
