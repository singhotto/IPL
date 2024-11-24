#include "DefFunc.hh"
#include "../Log.hh"  // Include the macros header

DefFunc::~DefFunc()
{
    LOG_OPERATION_START("DefFunc::~DefFunc");
    LOG_OPERATION_END("DefFunc::~DefFunc");
}

DefFunc::DefFunc(IdPtr id, std::vector<Id *> args, std::vector<Statement *> statements) : funcName(std::move(id))
{
    LOG_OPERATION_START("DefFunc::DefFunc(IdPtr, std::vector<Id *>, std::vector<Statement*>&&)");
    
    this->args.reserve(args.size());
    for(auto i : args){
        this->args.push_back(IdPtr(i));
    }

    this->statements.reserve(statements.size());
    for(auto i : statements){
        this->statements.push_back(StmtPtr(i));
    }
    
    LOG_OPERATION_END("DefFunc::DefFunc(IdPtr, std::vector<Id *>, std::vector<Statement*>&&)");
}

std::string DefFunc::getName()
{
    LOG_OPERATION_START("DefFunc::getName");
    std::string name = funcName->getName();
    LOG_OPERATION_END("DefFunc::getName");
    return name;
}

std::vector<Id *> DefFunc::funcArgs()
{
    LOG_OPERATION_START("DefFunc::funcArgs");
    std::vector<Id *> temp;
    temp.reserve(args.size());
    for(IdPtr& id : args){
        temp.push_back(id.get());
    }
    LOG_OPERATION_END("DefFunc::funcArgs");
    return temp;
}

std::vector<Statement *> DefFunc::funcStatements()
{
    LOG_OPERATION_START("DefFunc::funcStatements");
    std::vector<Statement *> temp;
    temp.reserve(statements.size());
    for(StmtPtr& stmt : statements){
        temp.push_back(stmt.get());
    }
    LOG_OPERATION_END("DefFunc::funcStatements");
    return temp;
}

void DefFunc::print() const
{
    std::cout<<funcName->getName();
}

std::unique_ptr<Value> DefFunc::clone() const
{
    return std::make_unique<DefFunc>(*this);
}

void DefFunc::accept(Visitor *visitor)
{
    LOG_OPERATION_START("DefFunc::accept");
    visitor->visit(this);
    LOG_OPERATION_END("DefFunc::accept");
}
