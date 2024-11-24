#ifndef WHILE__GUARD
#define WHILE__GUARD

#include <vector>
#include "Statement.hh"
#include "../expr/Expr.hh"
#include "../Visitor.hh"

class Visitor;

class While : virtual public Statement {
private:
    using StmtPtr = std::unique_ptr<Statement>;
    using ExprPtr = std::unique_ptr<Expr>;
    ExprPtr cond;
    std::vector<StmtPtr> statements;

public:
    explicit While(ExprPtr cond, std::vector<Statement*> statements);
    ~While();
    
    Expr* getCond();
    std::vector<Statement*> getBody();
    std::unique_ptr<Statement> clone() const;

    void accept(Visitor* visitor) override;
};

#endif 
