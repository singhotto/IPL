#include "Ifelse.hh"
#include "../Log.hh"

Ifelse::Ifelse(ExprPtr cond, std::vector<Statement *> thenBody, std::vector<Statement *> elseBody)
    : cond(std::move(cond))
{
    LOG_OPERATION_START("Ifelse::Ifelse(ExprPtr, std::vector<Statement *>)");

    this->thenBody.reserve(thenBody.size());
    for(auto i : thenBody){
        this->thenBody.push_back(StmtPtr(i));
    }

    this->elseBody.reserve(elseBody.size());
    for(auto i : elseBody){
        this->elseBody.push_back(StmtPtr(i));
    }
    
    LOG_OPERATION_END("Ifelse::Ifelse(ExprPtr, std::vector<Statement *>)");
}

Ifelse::~Ifelse()
{
    LOG_OPERATION_START("Ifelse::~Ifelse()");
    LOG_OPERATION_END("Ifelse::~Ifelse()");
}

Expr *Ifelse::getCond()
{
    LOG_OPERATION_START("Expr *Ifelse::getCond()");
    LOG_OPERATION_END("Expr *Ifelse::getCond()");
    return cond.get();
}

std::vector<Statement *> Ifelse::getBody()
{
    LOG_OPERATION_START("Ifelse::getBody()");
    std::vector<Statement *> temp;
    temp.reserve(thenBody.size());
    for(StmtPtr& stmt : thenBody){
        temp.push_back(stmt.get());
    }
    LOG_OPERATION_END("Ifelse::getBody()");
    return temp;
}

std::vector<Statement *> Ifelse::getElseBody()
{
    LOG_OPERATION_START("Ifelse::getElseBody()");
    std::vector<Statement *> temp;
    temp.reserve(elseBody.size());
    for(StmtPtr& stmt : elseBody){
        temp.push_back(stmt.get());
    }
    LOG_OPERATION_END("Ifelse::getElseBody()");
    return temp;
}

void Ifelse::accept(Visitor *visitor)
{
    LOG_OPERATION_START("Ifelse::accept");
    visitor->visit(this);
    LOG_OPERATION_END("Ifelse::accept");
}
