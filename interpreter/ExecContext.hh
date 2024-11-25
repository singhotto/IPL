#ifndef EXEC_CONTEXT__GUARD
#define EXEC_CONTEXT__GUARD

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <memory>
#include <cassert>
#include "Value.hh"

class ExecContext
{
private:
    using ValuePtr = std::unique_ptr<Value>;
    std::vector<std::unordered_map<std::string, ValuePtr>> scopeStack;

public:
    ExecContext();
    ~ExecContext();

    void newScope();
    void exitScope();

    void addNewVariable(const std::string& name, ValuePtr v);
    void updateVariable(const std::string& name, ValuePtr v);

    Value* getVariable(const std::string name) const;
};

#endif