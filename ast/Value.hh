#ifndef VALUE__GUARD
#define VALUE__GUARD

#include <iostream>
#include<memory>
#include "Log.hh"

class Value {
public:
    virtual ~Value() { 
        LOG_OPERATION_START("Value::~Value()");
        LOG_OPERATION_END("Value::~Value()");
    };
    virtual std::unique_ptr<Value> cloneValue() const = 0;
    virtual void print() const = 0;
};

#endif // VALUE__GUARD
