#ifndef BOOL__GUARD
#define BOOL__GUARD

#include "../../Value.hh"
#include "../Expr.hh"
#include "../../Visitor.hh" // Only necessary to define `accept`

class Visitor;

class Bool : virtual public Value, virtual public Expr {
private:
    bool value;
public:
    explicit Bool(const bool value);
    ~Bool();
    bool getValue() const;
    void accept(Visitor* visitor) override;
};

#endif // INT__GUARD
