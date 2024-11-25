#ifndef BOOL__GUARD
#define BOOL__GUARD

#include "Value.hh"
#include "expr/Expr.hh"
#include "Visitor.hh" 

class Visitor;

class Bool : virtual public Value, virtual public Expr {
private:
    bool value;
public:
    explicit Bool(const bool value);
    ~Bool();
    bool getValue() const;
    void print() const override;
    std::unique_ptr<Value> cloneValue() const override;
    std::unique_ptr<Expr> cloneExpr() const override;
    void accept(Visitor* visitor) override;
};

#endif // INT__GUARD
