#include "../../Log.hh"
#include "Float.hh"

Float::Float(float value) : value(value)
{
    LOG_OPERATION_START("Float::Float(float)");
    LOG_OPERATION_END("Float::Float(float)");
}

Float::~Float()
{
    LOG_OPERATION_START("Float::~Float()");
    LOG_OPERATION_END("Float::~Float()");
}

float Float::getValue() const
{
    return value;
}

void Float::accept(Visitor *visitor)
{
    LOG_OPERATION_START("Float::accept");
    visitor->visit(this);
    LOG_OPERATION_END("Float::accept");
}
