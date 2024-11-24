#include "While.hh"
#include "../Log.hh"

While::While(ExprPtr cond, std::vector<Statement *> statements) : cond(std::move(cond))
{
    LOG_OPERATION_START("While::While(ExprPtr, std::vector<Statement *>)");

    this->statements.reserve(statements.size());
    for(auto i : statements){
        this->statements.push_back(StmtPtr(i));
    }
    
    LOG_OPERATION_END("While::While(ExprPtr, std::vector<Statement *>)");
}

While::~While()
{
    LOG_OPERATION_START("While::~While");
    LOG_OPERATION_END("While::~While");
}


Expr *While::getCond()
{
    LOG_OPERATION_START("While::getCond()");
    return cond.get();
    LOG_OPERATION_END("While::getCond()");
}


std::vector<Statement *> While::getBody()
{
    LOG_OPERATION_START("While::getBody()");
    std::vector<Statement *> temp;
    temp.reserve(statements.size());
    for(StmtPtr& stmt : statements){
        temp.push_back(stmt.get());
    }
    LOG_OPERATION_END("While::getBody()");
    return temp;
}

void While::accept(Visitor *visitor)
{
    LOG_OPERATION_START("While::accept");
    visitor->visit(this);
    LOG_OPERATION_END("While::accept");
}
