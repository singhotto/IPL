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
    using ValuePtr = Value*;
    std::vector<std::unordered_map<std::string, Value*>> scopeStack;

public:
    ExecContext();
    ~ExecContext();

    void newScope();
    void exitScope();

    void setVariable(const std::string& name, Value* v);
    // void setVariable(const std::string& name, ValuePtr v);

    Value* getVariable(const std::string name) const;
};

#endif