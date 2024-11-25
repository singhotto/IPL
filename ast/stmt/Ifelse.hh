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
    using ExprPtr = std::unique_ptr<Expr>;
    ExprPtr cond;
    std::vector<StmtPtr> thenBody;
    std::vector<StmtPtr> elseBody;

public:
    explicit Ifelse(ExprPtr cond, std::vector<Statement*> thenBody, std::vector<Statement*> elseBody);
    ~Ifelse();
    
    Expr* getCond();
    std::vector<Statement*> getBody();
    std::vector<Statement*> getElseBody();
    std::unique_ptr<Statement> clone() const override;
    
    void accept(Visitor* visitor) override;
};

#endif 
