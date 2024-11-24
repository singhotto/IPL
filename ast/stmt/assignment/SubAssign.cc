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

std::unique_ptr<Statement> SubAssign::clone() const
{
    auto idExpClone = idExp->cloneId(); // Clone the Id object
    auto valueClone = value->cloneExpr(); // Clone the Expr object

    // Return a new SubAssign object with the cloned members
    return std::make_unique<SubAssign>(std::move(idExpClone), std::move(valueClone));
}

void SubAssign::accept(Visitor *visitor)
{
    LOG_OPERATION_START("SubAssign::accept");
    visitor->visit(this);
    LOG_OPERATION_END("SubAssign::accept");
}
