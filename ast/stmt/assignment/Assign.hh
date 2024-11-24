#ifndef ASSIGN__GUARD
#define ASSIGN__GUARD

#include "../Statement.hh"
#include "../../Visitor.hh" 
#include "../../expr/value/Id.hh"
#include "../../expr/Expr.hh"

class Assign : virtual public Statement {
private:
    using ExprPtr = std::unique_ptr<Expr>;
    using IdPtr = std::unique_ptr<Id>;
    IdPtr  idExp;
    ExprPtr value;

public:
    Assign(IdPtr idExp, ExprPtr value);
    ~Assign();

    Id* getId() const;
    Expr* getValue() const;
    std::unique_ptr<Statement> clone() const;

    void accept(Visitor* visitor) override;
};

#endif 
