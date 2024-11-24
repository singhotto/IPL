#ifndef AND__GUARD
#define AND__GUARD

#include "BoolExpr.hh"
#include "../../Visitor.hh"

class And : virtual public BoolExpr {
private:
    ExprPtr left;
    ExprPtr right;
public:
    And(ExprPtr left, ExprPtr right);
    ~And();

    Expr* getLeft() const override;
    Expr* getRight() const override;
    std::unique_ptr<Expr> cloneExpr() const override;

    void accept(Visitor* visitor) override;
};

#endif 
