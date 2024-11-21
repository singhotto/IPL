#ifndef SUBTEXPR__GUARD
#define SUBTEXPR__GUARD

#include "Expr.hh"
#include "../Visitor.hh"

class SubtExpr : virtual public Expr {
private:
    ExprPtr left;
    ExprPtr right;
public:
    SubtExpr(ExprPtr left, ExprPtr right);
    ~SubtExpr();

    Expr* getLeft() const;
    Expr* getRight() const;

    void accept(Visitor* visitor) override;
};

#endif