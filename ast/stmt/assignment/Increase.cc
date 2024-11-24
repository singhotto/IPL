#include "Increase.hh"
#include "../../Log.hh"

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


void Increase::accept(Visitor *visitor)
{
    LOG_OPERATION_START("Increase::accept");
    visitor->visit(this);
    LOG_OPERATION_END("Increase::accept");
}
