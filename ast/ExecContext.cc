#include "ExecContext.hh"
#include "Log.hh"  // Include the macros header

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
        // for (auto& map : scopeStack) {
        //     // Iterate over each unordered_map in the vector
        //     for (auto& pair : map) {
        //         std::cout << "Key: " << pair.first << ", Value: " << pair.second->getValue() << std::endl;
        //     }
        // }
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

void ExecContext::setVariable(const std::string &name, Value *v)
{
    LOG_OPERATION_START("ExecContext::setVariable");
    assert(v != nullptr && "ExecContext::setVariable got Deleted Value");

    scopeStack.back()[name] = v;
    LOG_OPERATION_END("ExecContext::setVariable");
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
