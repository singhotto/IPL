#ifndef IFCOND__GUARD
#define IFCOND__GUARD

#include <vector>
#include "Statement.hh"
#include "../expr/value/Bool.hh"
#include "../Visitor.hh"

class Visitor;

class Ifcond : virtual public Statement {
private:
    using StmtPtr = std::unique_ptr<Statement>;
    using BoolPtr = std::unique_ptr<Bool>;
    BoolPtr cond;
    std::vector<StmtPtr> statements;

public:
    explicit Ifcond(BoolPtr cond, std::vector<Statement*> statements);
    ~Ifcond();
    
    Bool* getCond();
    std::vector<Statement*> getBody();
    void accept(Visitor* visitor) override;
};

#endif 
