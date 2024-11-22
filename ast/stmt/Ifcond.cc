#include "Ifcond.hh"
#include "../Log.hh"

Ifcond::Ifcond(BoolPtr cond, std::vector<Statement *> statements)
    : cond(std::move(cond))
{
    LOG_OPERATION_START("Ifcond::Ifcond(BoolPtr, std::vector<Statement *>)");

    this->statements.reserve(statements.size());
    for(auto i : statements){
        this->statements.push_back(StmtPtr(i));
    }
    
    LOG_OPERATION_END("Ifcond::Ifcond(BoolPtr, std::vector<Statement *>)");
}

Ifcond::~Ifcond()
{
    LOG_OPERATION_START("Ifcond::~Ifcond()");
    LOG_OPERATION_END("Ifcond::~Ifcond()");
}

Bool *Ifcond::getCond()
{
    LOG_OPERATION_START("Bool *Ifcond::getCond()");
    LOG_OPERATION_END("Bool *Ifcond::getCond()");
    return cond.get();
}

std::vector<Statement *> Ifcond::getBody()
{
    LOG_OPERATION_START("Ifcond::getBody()");
    std::vector<Statement *> temp;
    temp.reserve(statements.size());
    for(StmtPtr& stmt : statements){
        temp.push_back(stmt.get());
    }
    LOG_OPERATION_END("Ifcond::getBody()");
    return temp;
}

void Ifcond::accept(Visitor *visitor)
{
    LOG_OPERATION_START("Ifcond::accept");
    visitor->visit(this);
    LOG_OPERATION_END("Ifcond::accept");
}
