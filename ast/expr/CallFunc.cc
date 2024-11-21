#include "../Log.hh"  // Include the macros header
#include "CallFunc.hh"

CallFunc::CallFunc(IdPtr funcName, std::vector<Id *> args) : funcId(std::move(funcName))
{
    LOG_OPERATION_START("CallFunc::CallFunc(IdPtr, std::vector<Id *>)");
    this->args.reserve(args.size());
    for (auto i : args) {
        this->args.push_back(IdPtr(i));
    }
    LOG_OPERATION_END("CallFunc::CallFunc(IdPtr, std::vector<Id *>)");
}

CallFunc::CallFunc(IdPtr funcName) : funcId(std::move(funcName))
{
    LOG_OPERATION_START("CallFunc::CallFuncIdPtr)");
    LOG_OPERATION_END("CallFunc::CallFuncIdPtr)");
}

CallFunc::~CallFunc()
{
    LOG_OPERATION_START("CallFunc::~CallFunc()");
    LOG_OPERATION_END("CallFunc::~CallFunc()");
}

std::string CallFunc::funcName()
{
    return funcId->getName();
}

std::vector<Id *> CallFunc::funcArgs()
{
    std::vector<Id *> temp;
    temp.reserve(args.size());
    for (IdPtr& id : args) {
        temp.push_back(id.get());
    }
    return temp;
}

void CallFunc::accept(Visitor *visitor)
{
    LOG_OPERATION_START("CallFunc::accept");
    visitor->visit(this);
    LOG_OPERATION_END("CallFunc::accept");
}
