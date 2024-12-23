#ifndef WHILE__GUARD
#define WHILE__GUARD

#include <vector>
#include "stmt/Statement.hh"
#include "Visitor.hh"
#include "expr/Expr.hh"

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
    std::unique_ptr<Statement> clone() const override;

    void accept(Visitor* visitor) override;
};

#endif 
