#ifndef LESS__GUARD
#define LESS__GUARD

#include "BoolExpr.hh"
#include "../../Visitor.hh"

class Less : virtual public BoolExpr {
private:
    ExprPtr left;
    ExprPtr right;
public:
    Less(ExprPtr left, ExprPtr right);
    ~Less();

    Expr* getLeft() const override;
    Expr* getRight() const override;

    void accept(Visitor* visitor) override;
};

#endif 
