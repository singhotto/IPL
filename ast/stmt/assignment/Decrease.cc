#include "Decrease.hh"
#include "../../Log.hh"

Decrease::Decrease(IdPtr idExp) 
    : idExp(std::move(idExp))
{
    LOG_OPERATION_START("Decrease::Decrease(IdPtr)");
    LOG_OPERATION_END("Decrease::Decrease(IdPtr)");
}

Decrease::~Decrease()
{
    LOG_OPERATION_START("Decrease::~Decrease");
    LOG_OPERATION_END("Decrease::~Decrease");
}

Id *Decrease::getId() const
{
    LOG_OPERATION_START("Decrease::getId");
    LOG_OPERATION_END("Decrease::getId");
    return idExp.get();
}


void Decrease::accept(Visitor *visitor)
{
    LOG_OPERATION_START("Decrease::accept");
    visitor->visit(this);
    LOG_OPERATION_END("Decrease::accept");
}