#ifndef INT__GUARD
#define INT__GUARD

#include <iostream>
#include "../Value.hh"
#include "Expr.hh"
#include "../Visitor.hh" // Only necessary to define `accept`

class Visitor;

class Int : virtual public Value, virtual public Expr {
private:
    int value;
public:
    explicit Int(int value);
    ~Int();
    float getValue() const override;
    void accept(Visitor* visitor) override;
};

#endif // INT__GUARD
