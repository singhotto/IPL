#ifndef MODEXPR__GUARD
#define MODEXPR__GUARD

#include "Expr.hh"
#include "../Visitor.hh"

class ModExpr : virtual public Expr {
private:
    ExprPtr left;
    ExprPtr right;
public:
    ModExpr(ExprPtr left, ExprPtr right);
    ~ModExpr();

    Expr* getLeft() const;
    Expr* getRight() const;

    void accept(Visitor* visitor) override;
};

#endif