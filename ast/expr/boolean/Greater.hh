#ifndef GREATER__GUARD
#define GREATER__GUARD

#include "BoolExpr.hh"
#include "../../Visitor.hh"

class Greater : virtual public BoolExpr {
private:
    ExprPtr left;
    ExprPtr right;
public:
    Greater(ExprPtr left, ExprPtr right);
    ~Greater();

    Expr* getLeft() const override;
    Expr* getRight() const override;

    void accept(Visitor* visitor) override;
};

#endif 
