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

std::unique_ptr<Statement> MulAssign::clone() const
{
    auto idExpClone = idExp->cloneId(); // Clone the Id object
    auto valueClone = value->cloneExpr(); // Clone the Expr object

    // Return a new MulAssign object with the cloned members
    return std::make_unique<MulAssign>(std::move(idExpClone), std::move(valueClone));
}

void MulAssign::accept(Visitor *visitor)
{
    LOG_OPERATION_START("MulAssign::accept");
    visitor->visit(this);
    LOG_OPERATION_END("MulAssign::accept");
}
