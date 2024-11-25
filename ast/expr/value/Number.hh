#ifndef NUMBER__GUARD
#define NUMBER__GUARD

#include "Log.hh"
#include "Value.hh"
#include "expr/Expr.hh"
#include "Visitor.hh" 

class Visitor; // Forward declaration

class Number : virtual public Value, virtual public Expr {
public:
    virtual ~Number() { 
        LOG_OPERATION_START("Number::~Number()");
        LOG_OPERATION_END("Number::~Number()");
    };
    virtual float getValue() const = 0;
    virtual void setValue(float x) = 0;
};

#endif // Number__GUARD
