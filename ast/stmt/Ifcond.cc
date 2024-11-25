#include "stmt/Ifcond.hh"
#include "Log.hh"

Ifcond::Ifcond(ExprPtr cond, std::vector<Statement *> statements)
    : cond(std::move(cond))
{
    LOG_OPERATION_START("Ifcond::Ifcond(ExprPtr, std::vector<Statement *>)");

    this->statements.reserve(statements.size());
    for (auto i : statements)
    {
        this->statements.push_back(StmtPtr(i));
    }

    LOG_OPERATION_END("Ifcond::Ifcond(ExprPtr, std::vector<Statement *>)");
}

Ifcond::~Ifcond()
{
    LOG_OPERATION_START("Ifcond::~Ifcond()");
    LOG_OPERATION_END("Ifcond::~Ifcond()");
}

Expr *Ifcond::getCond()
{
    LOG_OPERATION_START("Expr *Ifcond::getCond()");
    LOG_OPERATION_END("Expr *Ifcond::getCond()");
    return cond.get();
}

std::vector<Statement *> Ifcond::getBody()
{
    LOG_OPERATION_START("Ifcond::getBody()");
    std::vector<Statement *> temp;
    temp.reserve(statements.size());
    for (StmtPtr &stmt : statements)
    {
        temp.push_back(stmt.get());
    }
    LOG_OPERATION_END("Ifcond::getBody()");
    return temp;
}

std::unique_ptr<Statement> Ifcond::clone() const
{
    std::vector<Statement*> clonedStatements;
    for (const auto &stmt : statements)
    {
        clonedStatements.push_back(stmt->clone().release()); 
    }
    return std::make_unique<Ifcond>(
        cond->cloneExpr(), 
        clonedStatements                
    );
}

void Ifcond::accept(Visitor *visitor)
{
    LOG_OPERATION_START("Ifcond::accept");
    visitor->visit(this);
    LOG_OPERATION_END("Ifcond::accept");
}
