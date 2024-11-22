#ifndef IFELSE__GUARD
#define IFELSE__GUARD

#include <vector>
#include "Statement.hh"
#include "../expr/value/Bool.hh"
#include "../Visitor.hh"

class Visitor;

class Ifelse : virtual public Statement {
private:
    using StmtPtr = std::unique_ptr<Statement>;
    using BoolPtr = std::unique_ptr<Bool>;
    BoolPtr cond;
    std::vector<StmtPtr> thenBody;
    std::vector<StmtPtr> elseBody;

public:
    explicit Ifelse(BoolPtr cond, std::vector<Statement*> thenBody, std::vector<Statement*> elseBody);
    ~Ifelse();
    
    Bool* getCond();
    std::vector<Statement*> getBody();
    std::vector<Statement*> getElseBody();
    void accept(Visitor* visitor) override;
};

#endif 
