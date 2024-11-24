#ifndef FLOAT__GUARD
#define FLOAT__GUARD

#include "Number.hh"
#include "../../Visitor.hh" 

class Visitor;

class Float : virtual public Number {
private:
    float value;
public:
    explicit Float(float value);
    ~Float();
    float getValue() const override;
    void setValue(float x) override;
    void print() const override;
    std::unique_ptr<Value> cloneValue() const override;
    std::unique_ptr<Expr> cloneExpr() const override;
    void accept(Visitor* visitor) override;
};

#endif
