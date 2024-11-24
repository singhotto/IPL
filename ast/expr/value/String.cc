#include "String.hh"
#include "../../Log.hh"

String::String(const std::string str) : str(str)
{
    LOG_OPERATION_START("String::String(const std::string)");
    LOG_OPERATION_END("String::String(const std::string)");
}

String::~String()
{
    LOG_OPERATION_START("String::~String()");
    LOG_OPERATION_END("String::~String()");
}

std::string String::getStr() const
{
    return str;
}

void String::print() const
{
    std::cout<<str;
}

void String::accept(Visitor *visitor)
{
    LOG_OPERATION_START("void String::accept");
    visitor->visit(this);
    LOG_OPERATION_END("void String::accept");
}
