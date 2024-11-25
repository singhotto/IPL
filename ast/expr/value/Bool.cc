#include "Log.hh"
#include "expr/value/Bool.hh"

Bool::Bool(bool value) : value(value)
{
    LOG_OPERATION_START("Bool::Bool(Bool)");
    LOG_OPERATION_END("Bool::Bool(Bool)");
}

Bool::~Bool()
{
    LOG_OPERATION_START("Bool::~Bool()");
    LOG_OPERATION_END("Bool::~Bool()");
}

bool Bool::getValue() const
{
    return value;
}

void Bool::print() const
{
    if(value){
        std::cout<<"true";
    }else{
        std::cout<<"false";
    }
}

std::unique_ptr<Value> Bool::cloneValue() const
{
    return std::make_unique<Bool>(*this);
}

std::unique_ptr<Expr> Bool::cloneExpr() const
{
    return std::make_unique<Bool>(*this);
}

void Bool::accept(Visitor *visitor)
{
    LOG_OPERATION_START("Bool::accept");
    visitor->visit(this);
    LOG_OPERATION_END("Bool::accept");
}
