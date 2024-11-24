#ifndef EXEC_CONTEXT__GUARD
#define EXEC_CONTEXT__GUARD

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <memory>
#include <cassert>
#include "Value.hh"
#include "expr/value/Number.hh"

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

    void addNewVariable(const std::string& name, Value* v);
    void updateVariable(const std::string& name, Value* v);

    Value* getVariable(const std::string name) const;
};

#endif