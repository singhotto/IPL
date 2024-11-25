#include "Log.hh"  
#include "stmt/ReturnStmt.hh"

ReturnStmt::ReturnStmt(ExprPtr val) : val(std::move(val))
{
    LOG_OPERATION_START("ReturnStmt::ReturnStmt(ExprPtr)");
    LOG_OPERATION_END("ReturnStmt::ReturnStmt(ExprPtr)");
}

ReturnStmt::~ReturnStmt()
{
    LOG_OPERATION_START("ReturnStmt::~ReturnStmt()");
    LOG_OPERATION_END("ReturnStmt::~ReturnStmt()");
}

Expr *ReturnStmt::getValue() const
{
    LOG_OPERATION_START("ReturnStmt::getValue");
    LOG_OPERATION_END("ReturnStmt::getValue");
    return val.get();
}

std::unique_ptr<Statement> ReturnStmt::clone() const
{
    return std::make_unique<ReturnStmt>(val->cloneExpr());
}

void ReturnStmt::accept(Visitor *visitor)
{
    LOG_OPERATION_START("ReturnStmt::accept");
    visitor->visit(this);
    LOG_OPERATION_END("ReturnStmt::accept");
}
