#include "stmt/ForLoop.hh"
#include "Log.hh"

ForLoop::ForLoop(StmtPtr initial, ExprPtr cond, StmtPtr update, std::vector<Statement *> statements) : initial(std::move(initial)), cond(std::move(cond)), update(std::move(update))
{
    LOG_OPERATION_START("ForLoop::ForLoop(IdPtr)");

    this->statements.reserve(statements.size());
    for (auto i : statements)
    {
        this->statements.push_back(StmtPtr(i));
    }

    LOG_OPERATION_END("ForLoop::ForLoop(IdPtr)");
}

ForLoop::~ForLoop()
{
    LOG_OPERATION_START("ForLoop::~ForLoop");
    LOG_OPERATION_END("ForLoop::~ForLoop");
}

Statement *ForLoop::getInitial()
{
    LOG_OPERATION_START("ForLoop::getInitial()");
    return initial.get();
    LOG_OPERATION_END("ForLoop::getInitial()");
}

Expr *ForLoop::getCond()
{
    LOG_OPERATION_START("ForLoop::getCond()");
    return cond.get();
    LOG_OPERATION_END("ForLoop::getCond()");
}

Statement *ForLoop::getUpdate()
{
    LOG_OPERATION_START("ForLoop::getUpdate()");
    return update.get();
    LOG_OPERATION_END("ForLoop::getUpdate()");
}

std::vector<Statement *> ForLoop::getBody()
{
    LOG_OPERATION_START("ForLoop::getBody()");
    std::vector<Statement *> temp;
    temp.reserve(statements.size());
    for (StmtPtr &stmt : statements)
    {
        temp.push_back(stmt.get());
    }
    LOG_OPERATION_END("ForLoop::getBody()");
    return temp;
}

std::unique_ptr<Statement> ForLoop::clone() const
{
    std::vector<Statement*> clonedStatements;
    for (const auto &stmt : statements)
    {
        clonedStatements.push_back(stmt->clone().release()); 
    }
    return std::make_unique<ForLoop>(
        initial->clone(), 
        cond->cloneExpr(),       
        update->clone(),   
        clonedStatements                      
    );
}

void ForLoop::accept(Visitor *visitor)
{
    LOG_OPERATION_START("ForLoop::accept");
    visitor->visit(this);
    LOG_OPERATION_END("ForLoop::accept");
}
