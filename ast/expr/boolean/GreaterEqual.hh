#ifndef GREATEREQUAL__GUARD
#define GREATEREQUAL__GUARD

#include "BoolExpr.hh"
#include "../../Visitor.hh"

class GreaterEqual : virtual public BoolExpr {
private:
    ExprPtr left;
    ExprPtr right;
public:
    GreaterEqual(ExprPtr left, ExprPtr right);
    ~GreaterEqual();

    Expr* getLeft() const override;
    Expr* getRight() const override;

    void accept(Visitor* visitor) override;
};

#endif 
