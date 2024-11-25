#ifndef GREATER__GUARD
#define GREATER__GUARD

#include "expr/boolean/BoolExpr.hh"
#include "Visitor.hh"

class Greater : virtual public BoolExpr {
private:
    ExprPtr left;
    ExprPtr right;
public:
    Greater(ExprPtr left, ExprPtr right);
    ~Greater();

    Expr* getLeft() const override;
    Expr* getRight() const override;
    std::unique_ptr<Expr> cloneExpr() const override;

    void accept(Visitor* visitor) override;
};

#endif 
