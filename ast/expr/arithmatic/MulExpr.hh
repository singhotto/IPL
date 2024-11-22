#ifndef MULEXPR__GUARD
#define MULEXPR__GUARD

#include "BinaryExpr.hh"
#include "../../Visitor.hh"

class MulExpr : virtual public BinaryExpr {
private:
    ExprPtr left;
    ExprPtr right;
public:
    MulExpr(ExprPtr left, ExprPtr right);
    ~MulExpr();

    Expr* getLeft() const override;
    Expr* getRight() const override;

    void accept(Visitor* visitor) override;
};

#endif