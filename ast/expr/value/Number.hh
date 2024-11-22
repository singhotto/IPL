#ifndef NUMBER__GUARD
#define NUMBER__GUARD

#include "../../Value.hh"
#include "../Expr.hh"
#include "../../Visitor.hh" // Only necessary to define `accept`

class Visitor; // Forward declaration

class Number : virtual public Value, virtual public Expr {
public:
    virtual ~Number() { std::cout<<"Number::~Number\n"; };
    virtual float getValue() const = 0;
};

#endif // Number__GUARD
