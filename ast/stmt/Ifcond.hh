#ifndef IFCOND__GUARD
#define IFCOND__GUARD

#include <vector>
#include "Statement.hh"
#include "../expr/Expr.hh"
#include "../Visitor.hh"

class Visitor;

class Ifcond : virtual public Statement {
private:
    using StmtPtr = std::unique_ptr<Statement>;
    using ExprPtr = std::unique_ptr<Expr>;
    ExprPtr cond;
    std::vector<StmtPtr> statements;

public:
    explicit Ifcond(ExprPtr cond, std::vector<Statement*> statements);
    ~Ifcond();
    
    Expr* getCond();
    std::vector<Statement*> getBody();
    std::unique_ptr<Statement> clone() const override;

    void accept(Visitor* visitor) override;
};

#endif 
