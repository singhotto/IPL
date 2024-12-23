#ifndef MODEXPR__GUARD
#define MODEXPR__GUARD

#include "expr/arithmatic/BinaryExpr.hh"
#include "Visitor.hh"

class ModExpr : virtual public BinaryExpr {
private:
    ExprPtr left;
    ExprPtr right;
public:
    ModExpr(ExprPtr left, ExprPtr right);
    ~ModExpr();

    Expr* getLeft() const override;
    Expr* getRight() const override;
    std::unique_ptr<Expr> cloneExpr() const override;

    void accept(Visitor* visitor) override;
};

#endif