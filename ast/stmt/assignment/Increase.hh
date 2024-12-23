#ifndef INCREASE__GUARD
#define INCREASE__GUARD

#include "stmt/Statement.hh"
#include "Visitor.hh" 
#include "expr/value/Id.hh"
#include "expr/Expr.hh"

class Increase : virtual public Statement {
private:
    using IdPtr = std::unique_ptr<Id>;
    IdPtr  idExp;

public:
    Increase(IdPtr idExp);
    ~Increase();

    Id* getId() const;
    std::unique_ptr<Statement> clone() const override;

    void accept(Visitor* visitor) override;
};

#endif 
