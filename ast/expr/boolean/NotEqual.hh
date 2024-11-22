#ifndef NOTEQUAL__GUARD
#define NOTEQUAL__GUARD

#include "BoolExpr.hh"
#include "../../Visitor.hh"

class NotEqual : virtual public BoolExpr {
private:
    ExprPtr left;
    ExprPtr right;
public:
    NotEqual(ExprPtr left, ExprPtr right);
    ~NotEqual();

    Expr* getLeft() const override;
    Expr* getRight() const override;

    void accept(Visitor* visitor) override;
};

#endif 
