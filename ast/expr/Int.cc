#include "../Log.hh"  // Include the macros header
#include "Int.hh"

Int::Int(int value) : value(value)
{
    LOG_OPERATION_START("Int::Int(int)");
    LOG_OPERATION_END("Int::Int(int)");
}

Int::~Int()
{
    LOG_OPERATION_START("Int::~Int");
    LOG_OPERATION_END("Int::~Int");
}

float Int::getValue() const
{
    return static_cast<float>(value);
}

void Int::accept(Visitor* visitor)
{
    LOG_OPERATION_START("Int::accept");
    visitor->visit(this);
    LOG_OPERATION_END("Int::accept");
}
