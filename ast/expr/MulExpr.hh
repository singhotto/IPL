#ifndef MULEXPR__GUARD
#define MULEXPR__GUARD

#include "Expr.hh"
#include "../Visitor.hh"

class MulExpr : virtual public Expr {
private:
    ExprPtr left;
    ExprPtr right;
public:
    MulExpr(ExprPtr left, ExprPtr right);
    ~MulExpr();

    Expr* getLeft() const;
    Expr* getRight() const;

    void accept(Visitor* visitor) override;
};

#endif