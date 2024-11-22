#ifndef LESSEQUAL__GUARD
#define LESSEQUAL__GUARD

#include "BoolExpr.hh"
#include "../../Visitor.hh"

class LessEqual : virtual public BoolExpr {
private:
    ExprPtr left;
    ExprPtr right;
public:
    LessEqual(ExprPtr left, ExprPtr right);
    ~LessEqual();

    Expr* getLeft() const override;
    Expr* getRight() const override;

    void accept(Visitor* visitor) override;
};

#endif 
