#ifndef GREATEREQUAL__GUARD
#define GREATEREQUAL__GUARD

#include "expr/boolean/BoolExpr.hh"
#include "Visitor.hh"

class GreaterEqual : virtual public BoolExpr {
private:
    ExprPtr left;
    ExprPtr right;
public:
    GreaterEqual(ExprPtr left, ExprPtr right);
    ~GreaterEqual();

    Expr* getLeft() const override;
    Expr* getRight() const override;
    std::unique_ptr<Expr> cloneExpr() const override;

    void accept(Visitor* visitor) override;
};

#endif 
