#ifndef FLOAT__GUARD
#define FLOAT__GUARD

#include "../Value.hh"
#include "Expr.hh"
#include "../Visitor.hh" // Only necessary to define `accept`

class Visitor;

class Float : virtual public Value, virtual public Expr {
private:
    float value;
public:
    explicit Float(float value);
    ~Float();
    float getValue() const override;
    void accept(Visitor* visitor) override;
};

#endif // INT__GUARD
