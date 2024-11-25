#ifndef DIVEXPR__GUARD
#define DIVEXPR__GUARD

#include "expr/arithmatic/BinaryExpr.hh"
#include "Visitor.hh"

class DivExpr : virtual public BinaryExpr {
private:
    ExprPtr left;
    ExprPtr right;
public:
    DivExpr(ExprPtr left, ExprPtr right);
    ~DivExpr();

    Expr* getLeft() const override;
    Expr* getRight() const override;
    std::unique_ptr<Expr> cloneExpr() const override;

    void accept(Visitor* visitor) override;
};

#endif