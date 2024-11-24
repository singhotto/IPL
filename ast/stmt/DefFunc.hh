#ifndef DEF_FUNC__GUARD
#define DEF_FUNC__GUARD

#include <vector>
#include "Statement.hh"
#include "../Value.hh"
#include "../Visitor.hh"
#include "../expr/value/Id.hh"

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
    ~DefFunc();

    DefFunc(DefFunc&& other) noexcept;
    DefFunc& operator=(DefFunc&& other) noexcept;

    DefFunc(const DefFunc&) = delete;
    DefFunc& operator=(const DefFunc&) = delete;
    
    std::string getName();
    std::vector<Id*> funcArgs();
    std::vector<Statement*> funcStatements();
    void print() const override;
    std::unique_ptr<Value> cloneValue() const override;
    std::unique_ptr<Statement> clone() const override;

    void accept(Visitor* visitor) override;
};

#endif 
