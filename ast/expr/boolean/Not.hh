#ifndef NOT__GUARD
#define NOT__GUARD

#include "expr/Expr.hh"
#include "Visitor.hh"

class Not : virtual public Expr {
private:
    ExprPtr e;
public:
    Not(ExprPtr e);
    ~Not();

    Expr* getExpr() const;
    std::unique_ptr<Expr> cloneExpr() const override;

    void accept(Visitor* visitor) override;
};

#endif 
