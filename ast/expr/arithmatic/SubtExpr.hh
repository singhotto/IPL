#ifndef SUBTEXPR__GUARD
#define SUBTEXPR__GUARD

#include "BinaryExpr.hh"
#include "../../Visitor.hh"

class SubtExpr : virtual public BinaryExpr {
private:
    ExprPtr left;
    ExprPtr right;
public:
    SubtExpr(ExprPtr left, ExprPtr right);
    ~SubtExpr();

    Expr* getLeft() const override;
    Expr* getRight() const override;

    void accept(Visitor* visitor) override;
};

#endif