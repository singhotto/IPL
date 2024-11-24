#include "../Log.hh" // Include the macros header
#include "CallFunc.hh"

CallFunc::CallFunc(IdPtr funcName, std::vector<Expr *> args) : funcId(std::move(funcName))
{
    LOG_OPERATION_START("CallFunc::CallFunc(IdPtr, std::vector<Expr *>)");
    this->args.reserve(args.size());
    for (auto i : args)
    {
        this->args.push_back(ExprPtr(i));
    }
    LOG_OPERATION_END("CallFunc::CallFunc(IdPtr, std::vector<Expr *>)");
}

CallFunc::~CallFunc()
{
    LOG_OPERATION_START("CallFunc::~CallFunc()");
    LOG_OPERATION_END("CallFunc::~CallFunc()");
}

std::string CallFunc::funcName()
{
    LOG_OPERATION_START("CallFunc::funcName");
    LOG_OPERATION_END("CallFunc::funcName");
    return funcId->getName();
}

std::vector<Expr *> CallFunc::funcArgs()
{
    LOG_OPERATION_START("CallFunc::funcArgs()");
    std::vector<Expr *> temp;
    temp.reserve(args.size());
    for (ExprPtr &id : args)
    {
        temp.push_back(id.get());
    }
    LOG_OPERATION_END("CallFunc::funcArgs()");
    return temp;
}

std::unique_ptr<Expr> CallFunc::cloneExpr() const
{
    std::vector<Expr *> clonedArgs;
    for (const auto &arg : args)
    {
        clonedArgs.push_back(arg->cloneExpr().release()); // Clone each argument
    }

    return std::make_unique<CallFunc>(funcId->cloneId(), clonedArgs);
}

std::unique_ptr<Statement> CallFunc::clone() const
{
    std::vector<Expr *> clonedArgs;
    for (const auto &arg : args)
    {
        clonedArgs.push_back(arg->cloneExpr().release()); // Clone each argument
    }

    return std::make_unique<CallFunc>(funcId->cloneId(), clonedArgs);
}

void CallFunc::accept(Visitor *visitor)
{
    LOG_OPERATION_START("CallFunc::accept");
    visitor->visit(this);
    LOG_OPERATION_END("CallFunc::accept");
}
