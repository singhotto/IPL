#ifndef DEF_FUNC__GUARD
#define DEF_FUNC__GUARD

#include "../Value.hh"
#include "Statement.hh"
#include "../expr/value/Id.hh"
#include <vector>
#include "../Visitor.hh"

class Visitor;

class DefFunc : virtual public Value, virtual public Statement {
private:
    using StmtPtr = std::unique_ptr<Statement>;
    using IdPtr = std::unique_ptr<Id>;
    IdPtr funcName;
    std::vector<IdPtr> args;
    std::vector<StmtPtr> statements;

public:
    explicit DefFunc(IdPtr id, std::vector<Id*> args, std::vector<Statement*> statements);
    explicit DefFunc(IdPtr id, std::vector<Statement*> statements);
    ~DefFunc();
    
    std::string getName();
    std::vector<Id*> funcArgs();
    std::vector<Statement*> funcStatements();
    void accept(Visitor* visitor) override;
};

#endif 
