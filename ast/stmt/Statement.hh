#ifndef STATEMENT__GUARD
#define STATEMENT__GUARD

#include "Node.hh" 
#include "Log.hh"  
#include <memory>
#include <iostream>

class Visitor; // Forward declaration

class Statement : virtual public Node {
public:
    virtual ~Statement() { 
        LOG_OPERATION_START("Statement::~Statement()");
        LOG_OPERATION_END("Statement::~Statement()");
    };
    virtual std::unique_ptr<Statement> clone() const = 0;
};

#endif
