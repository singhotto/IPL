#ifndef DIVEXPR__GUARD
#define DIVEXPR__GUARD

#include "BinaryExpr.hh"
#include "../../Visitor.hh"

class DivExpr : virtual public BinaryExpr {
private:
    ExprPtr left;
    ExprPtr right;
public:
    DivExpr(ExprPtr left, ExprPtr right);
    ~DivExpr();

    Expr* getLeft() const override;
    Expr* getRight() const override;

    void accept(Visitor* visitor) override;
};

#endif