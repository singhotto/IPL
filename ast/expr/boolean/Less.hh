#ifndef LESS__GUARD
#define LESS__GUARD

#include "expr/boolean/BoolExpr.hh"
#include "Visitor.hh"

class Less : virtual public BoolExpr {
private:
    ExprPtr left;
    ExprPtr right;
public:
    Less(ExprPtr left, ExprPtr right);
    ~Less();

    Expr* getLeft() const override;
    Expr* getRight() const override;
    std::unique_ptr<Expr> cloneExpr() const override;

    void accept(Visitor* visitor) override;
};

#endif 
