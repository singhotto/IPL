#ifndef ADDEXPR__GUARD
#define ADDEXPR__GUARD

#include "expr/arithmatic/BinaryExpr.hh"
#include "Visitor.hh"

class AddExpr : virtual public BinaryExpr {
private:
    ExprPtr left;
    ExprPtr right;
public:
    AddExpr(ExprPtr left, ExprPtr right);
    ~AddExpr();

    Expr* getLeft() const override;
    Expr* getRight() const override;
    std::unique_ptr<Expr> cloneExpr() const override;

    void accept(Visitor* visitor) override;
};

#endif 
