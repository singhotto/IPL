#ifndef DIVASSIGN__GUARD
#define DIVASSIGN__GUARD

#include "../Statement.hh"
#include "../../Visitor.hh" 
#include "../../expr/value/Id.hh"
#include "../../expr/Expr.hh"

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

    void accept(Visitor* visitor) override;
};

#endif 
