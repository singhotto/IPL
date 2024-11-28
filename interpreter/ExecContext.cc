#include "ExecContext.hh"
#include "Log.hh" 

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

void ExecContext::addNewVariable(const std::string &name, ValuePtr v)
{
    LOG_OPERATION_START("ExecContext::addNewVariable");
    assert(v != nullptr && "ExecContext::addNewVariable got Deleted Value");
    
    scopeStack.back()[name] = std::move(v);
    LOG_OPERATION_END("ExecContext::addNewVariable");
}

void ExecContext::updateVariable(const std::string &name, ValuePtr v)
{
    LOG_OPERATION_START("ExecContext::updateVariable");
    assert(v != nullptr && "ExecContext::updateVariable got Deleted Value");
    
    for (auto it = scopeStack.rbegin(); it != scopeStack.rend(); ++it) {
        auto& currentScope = *it;
        if (currentScope.find(name) != currentScope.end()) {
            LOG_OPERATION_END("ExecContext::updateVariable");
            currentScope[name] = std::move(v);
            return;
        }
    }

    LOG_OPERATION_END("ExecContext::updateVariable");
}

Value* ExecContext::getVariable(const std::string name) const
{
    LOG_OPERATION_START("ExecContext::getVariable");
    
    for (auto it = scopeStack.rbegin(); it != scopeStack.rend(); ++it) {
        const auto& currentScope = *it; // Use reference instead of copying
        auto varIt = currentScope.find(name);
        if (varIt != currentScope.end()) {
            LOG_OPERATION_END("ExecContext::getVariable");
            return varIt->second.get();
        }
    }

    LOG_OPERATION_END("ExecContext::getVariable BUT NOT FOUND");
    return nullptr;
}

std::unique_ptr<Value> &ExecContext::getVariableRef(const std::string name)
{
    LOG_OPERATION_START("ExecContext::getVariableRef");

    for (auto it = scopeStack.rbegin(); it != scopeStack.rend(); ++it) {
        auto& currentScope = *it; // Use reference
        auto varIt = currentScope.find(name);
        if (varIt != currentScope.end()) {
            LOG_OPERATION_END("ExecContext::getVariableRef");
            return varIt->second; // Return reference to unique_ptr
        }
    }

    LOG_OPERATION_END("ExecContext::getVariableRef BUT NOT FOUND");
    throw std::runtime_error("Variable " + name + " not found!"); // Handle error properly
}
