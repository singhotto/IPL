#ifndef DIVEXPR__GUARD
#define DIVEXPR__GUARD

#include "Expr.hh"
#include "../Visitor.hh"

class DivExpr : virtual public Expr {
private:
    ExprPtr left;
    ExprPtr right;
public:
    DivExpr(ExprPtr left, ExprPtr right);
    ~DivExpr();

    Expr* getLeft() const;
    Expr* getRight() const;

    void accept(Visitor* visitor) override;
};

#endif