#ifndef ADDEXPR__GUARD
#define ADDEXPR__GUARD

#include "Expr.hh"
#include "../Visitor.hh"

class AddExpr : virtual public Expr {
private:
    ExprPtr left;
    ExprPtr right;
public:
    AddExpr(ExprPtr left, ExprPtr right);
    ~AddExpr();

    Expr* getLeft() const;
    Expr* getRight() const;

    void accept(Visitor* visitor) override;
};

#endif 
