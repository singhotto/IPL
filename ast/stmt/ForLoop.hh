#ifndef FORLOOP__GUARD
#define FORLOOP__GUARD

#include <vector>
#include "stmt/Statement.hh"
#include "Visitor.hh"
#include "expr/Expr.hh"

class Visitor;

class ForLoop : virtual public Statement {
private:
    using StmtPtr = std::unique_ptr<Statement>;
    using ExprPtr = std::unique_ptr<Expr>;
    StmtPtr initial;
    ExprPtr cond;
    StmtPtr update;
    std::vector<StmtPtr> statements;

public:
    explicit ForLoop(StmtPtr initial, ExprPtr cond, StmtPtr update, std::vector<Statement*> statements);
    ~ForLoop();
    
    Statement* getInitial();
    Expr* getCond();
    Statement* getUpdate();
    std::vector<Statement*> getBody();
    std::unique_ptr<Statement> clone() const override;

    void accept(Visitor* visitor) override;
};

#endif 
