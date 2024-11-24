#ifndef EQUAL__GUARD
#define EQUAL__GUARD

#include "BoolExpr.hh"
#include "../../Visitor.hh"

class Equal : virtual public BoolExpr {
private:
    ExprPtr left;
    ExprPtr right;
public:
    Equal(ExprPtr left, ExprPtr right);
    ~Equal();

    Expr* getLeft() const override;
    Expr* getRight() const override;
    std::unique_ptr<Expr> cloneExpr() const override;

    void accept(Visitor* visitor) override;
};

#endif 
