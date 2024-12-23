#ifndef OR__GUARD
#define OR__GUARD

#include "expr/boolean/BoolExpr.hh"
#include "Visitor.hh"

class Or : virtual public BoolExpr {
private:
    ExprPtr left;
    ExprPtr right;
public:
    Or(ExprPtr left, ExprPtr right);
    ~Or();

    Expr* getLeft() const override;
    Expr* getRight() const override;
    std::unique_ptr<Expr> cloneExpr() const override;

    void accept(Visitor* visitor) override;
};

#endif 
