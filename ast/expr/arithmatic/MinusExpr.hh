#ifndef MINUSEXPR__GUARD
#define MINUSEXPR__GUARD

#include "expr/Expr.hh"
#include "Visitor.hh"

class MinusExpr : virtual public Expr {
private:
    ExprPtr e;
public:
    MinusExpr(ExprPtr e);
    ~MinusExpr();

    Expr* getExpr() const;
    std::unique_ptr<Expr> cloneExpr() const override;

    void accept(Visitor* visitor) override;
};

#endif 
