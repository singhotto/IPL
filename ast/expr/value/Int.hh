#ifndef INT__GUARD
#define INT__GUARD

#include "Number.hh"
#include "../../Visitor.hh" 

class Visitor;

class Int : virtual public Number {
private:
    int value;
public:
    explicit Int(int value);
    ~Int();
    
    float getValue() const override;
    void accept(Visitor* visitor) override;
};

#endif // INT__GUARD
