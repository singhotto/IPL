#ifndef DECREASE__GUARD
#define DECREASE__GUARD

#include "../Statement.hh"
#include "../../Visitor.hh" 
#include "../../expr/value/Id.hh"
#include "../../expr/Expr.hh"

class Decrease : virtual public Statement {
private:
    using IdPtr = std::unique_ptr<Id>;
    IdPtr  idExp;

public:
    Decrease(IdPtr idExp);
    ~Decrease();

    Id* getId() const;
    std::unique_ptr<Statement> clone() const;

    void accept(Visitor* visitor) override;
};

#endif 
