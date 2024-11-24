#ifndef NUMBER__GUARD
#define NUMBER__GUARD

#include "../../Value.hh"
#include "../../Log.hh"
#include "../Expr.hh"
#include "../../Visitor.hh" // Only necessary to define `accept`

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
