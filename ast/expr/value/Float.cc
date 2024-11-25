#include "Log.hh"
#include "expr/value/Float.hh"

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

void Float::setValue(float x)
{
    this->value = x;
}

void Float::print() const
{
    std::cout<<value;
}

std::unique_ptr<Value> Float::cloneValue() const
{
    return std::make_unique<Float>(*this);
}

std::unique_ptr<Expr> Float::cloneExpr() const
{
    return std::make_unique<Float>(*this);
}

void Float::accept(Visitor *visitor)
{
    LOG_OPERATION_START("Float::accept");
    visitor->visit(this);
    LOG_OPERATION_END("Float::accept");
}
