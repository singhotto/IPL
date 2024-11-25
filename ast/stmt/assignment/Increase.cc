#include "stmt/assignment/Increase.hh"
#include "Log.hh"

Increase::Increase(IdPtr idExp) 
    : idExp(std::move(idExp))
{
    LOG_OPERATION_START("Increase::Increase(IdPtr)");
    LOG_OPERATION_END("Increase::Increase(IdPtr)");
}

Increase::~Increase()
{
    LOG_OPERATION_START("Increase::~Increase");
    LOG_OPERATION_END("Increase::~Increase");
}

Id *Increase::getId() const
{
    LOG_OPERATION_START("Increase::getId");
    LOG_OPERATION_END("Increase::getId");
    return idExp.get();
}

std::unique_ptr<Statement> Increase::clone() const
{
    auto idExpClone = idExp->cloneId(); // Clone the Id object

    // Return a new Increase object with the cloned members
    return std::make_unique<Increase>(std::move(idExpClone));
}

void Increase::accept(Visitor *visitor)
{
    LOG_OPERATION_START("Increase::accept");
    visitor->visit(this);
    LOG_OPERATION_END("Increase::accept");
}
