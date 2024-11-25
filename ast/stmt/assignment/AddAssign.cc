#include "stmt/assignment/AddAssign.hh"
#include "Log.hh"

AddAssign::AddAssign(IdPtr idExp, ExprPtr value)
    : idExp(std::move(idExp)), value(std::move(value))
{
    LOG_OPERATION_START("AddAssign::AddAssign(IdPtr, ExprPtr)");
    LOG_OPERATION_END("AddAssign::AddAssign(IdPtr, ExprPtr)");
}

AddAssign::~AddAssign()
{
    LOG_OPERATION_START("AddAssign::~AddAssign");
    LOG_OPERATION_END("AddAssign::~AddAssign");
}

Id *AddAssign::getId() const
{
    LOG_OPERATION_START("AddAssign::getId");
    LOG_OPERATION_END("AddAssign::getId");
    return idExp.get();
}

Expr *AddAssign::getValue() const
{
    LOG_OPERATION_START("AddAssign::getValue");
    LOG_OPERATION_END("AddAssign::getValue");
    return value.get();
}

std::unique_ptr<Statement> AddAssign::clone() const
{
    auto idExpClone = idExp->cloneId(); // Clone the Id object
    auto valueClone = value->cloneExpr(); // Clone the Expr object

    // Return a new AddAssign object with the cloned members
    return std::make_unique<AddAssign>(std::move(idExpClone), std::move(valueClone));
}

void AddAssign::accept(Visitor *visitor)
{
    LOG_OPERATION_START("AddAssign::accept");
    visitor->visit(this);
    LOG_OPERATION_END("AddAssign::accept");
}
