#ifndef ADDEXPR__GUARD
#define ADDEXPR__GUARD

#include "BinaryExpr.hh"
#include "../../Visitor.hh"

class AddExpr : virtual public BinaryExpr {
private:
    ExprPtr left;
    ExprPtr right;
public:
    AddExpr(ExprPtr left, ExprPtr right);
    ~AddExpr();

    Expr* getLeft() const override;
    Expr* getRight() const override;

    void accept(Visitor* visitor) override;
};

#endif 
