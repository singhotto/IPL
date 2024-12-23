#ifndef BLOCK__GUARD
#define BLOCK__GUARD

#include <vector>
#include "stmt/Statement.hh"
#include "Visitor.hh"

class Visitor;

class Block : virtual public Statement {
private:
    using StmtPtr = std::unique_ptr<Statement>;
    std::vector<StmtPtr> statements;

public:
    explicit Block(std::vector<Statement*> statements);
    ~Block();
    
    std::vector<Statement*> getStatemets();
    std::unique_ptr<Statement> clone() const override;
    void accept(Visitor* visitor) override;
};

#endif 
