#ifndef DEFVAR__GUARD
#define DEFVAR__GUARD

#include "Statement.hh"
#include "../Visitor.hh" 
#include "../expr/value/Id.hh"
#include "../expr/Expr.hh"

class DefVar : virtual public Statement {
private:
    using ExprPtr = std::unique_ptr<Expr>;
    using IdPtr = std::unique_ptr<Id>;
    IdPtr  idExp;
    ExprPtr value;

public:
    DefVar(IdPtr idExp);
    DefVar(IdPtr idExp, ExprPtr value);
    ~DefVar();

    Id* getId() const;
    Expr* getValue() const;
    std::unique_ptr<Statement> clone() const override;
    void accept(Visitor* visitor) override;
};

#endif 
