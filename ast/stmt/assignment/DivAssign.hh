#ifndef DIVASSIGN__GUARD
#define DIVASSIGN__GUARD

#include "stmt/Statement.hh"
#include "Visitor.hh" 
#include "expr/value/Id.hh"
#include "expr/Expr.hh"

class DivAssign : virtual public Statement {
private:
    using ExprPtr = std::unique_ptr<Expr>;
    using IdPtr = std::unique_ptr<Id>;
    IdPtr  idExp;
    ExprPtr value;

public:
    DivAssign(IdPtr idExp, ExprPtr value);
    ~DivAssign();

    Id* getId() const;
    Expr* getValue() const;
    std::unique_ptr<Statement> clone() const override;

    void accept(Visitor* visitor) override;
};

#endif 
