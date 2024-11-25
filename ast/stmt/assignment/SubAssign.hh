#ifndef SUBASSIGN__GUARD
#define SUBASSIGN__GUARD

#include "stmt/Statement.hh"
#include "Visitor.hh" 
#include "expr/value/Id.hh"
#include "expr/Expr.hh"

class SubAssign : virtual public Statement {
private:
    using ExprPtr = std::unique_ptr<Expr>;
    using IdPtr = std::unique_ptr<Id>;
    IdPtr  idExp;
    ExprPtr value;

public:
    SubAssign(IdPtr idExp, ExprPtr value);
    ~SubAssign();

    Id* getId() const;
    Expr* getValue() const;
    std::unique_ptr<Statement> clone() const;

    void accept(Visitor* visitor) override;
};

#endif 
