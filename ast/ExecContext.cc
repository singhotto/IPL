#include "ExecContext.hh"
#include "Log.hh"  // Include the macros header
            #include "expr/value/Number.hh"


ExecContext::ExecContext()
{
    LOG_OPERATION_START("ExecContext::ExecContext");
    scopeStack.push_back({});
    LOG_OPERATION_END("ExecContext::ExecContext");
}

ExecContext::~ExecContext()
{
    LOG_OPERATION_START("ExecContext::~ExecContext");
    if (!scopeStack.empty()){
        scopeStack.pop_back();
    }
    LOG_OPERATION_END("ExecContext::~ExecContext");
}

void ExecContext::newScope()
{
    LOG_OPERATION_START("ExecContext::newScope");
    scopeStack.push_back({});
    LOG_OPERATION_END("ExecContext::newScope");
}

void ExecContext::exitScope()
{
    LOG_OPERATION_START("ExecContext::exitScope");
    assert(scopeStack.size() > 1 && "Cannot exit the global scope!");
    scopeStack.pop_back();
    LOG_OPERATION_END("ExecContext::exitScope");
}

void ExecContext::addNewVariable(const std::string &name, Value *v)
{
    LOG_OPERATION_START("ExecContext::addNewVariable");
    assert(v != nullptr && "ExecContext::addNewVariable got Deleted Value");
    
    scopeStack.back()[name] = v;
    LOG_OPERATION_END("ExecContext::addNewVariable");
}

void ExecContext::updateVariable(const std::string &name, Value *v)
{
    LOG_OPERATION_START("ExecContext::updateVariable");
    assert(v != nullptr && "ExecContext::updateVariable got Deleted Value");
    
    for (auto it = scopeStack.rbegin(); it != scopeStack.rend(); ++it) {
        auto& currentScope = *it;
        if (currentScope.find(name) != currentScope.end()) {
            LOG_OPERATION_END("ExecContext::updateVariable");
            currentScope[name] = v;
            return;
        }
    }

    LOG_OPERATION_END("ExecContext::updateVariable");
}

Value *ExecContext::getVariable(const std::string name) const
{
    LOG_OPERATION_START("ExecContext::getVariable");
    
    for (auto it = scopeStack.rbegin(); it != scopeStack.rend(); ++it) {
        auto currentScope = *it;
        if (currentScope.find(name) != currentScope.end()) {
            LOG_OPERATION_END("ExecContext::getVariable");
            return currentScope[name];
        }
    }
    LOG_OPERATION_END("ExecContext::getVariable BUT NOT FOUND");
    return nullptr;
}

