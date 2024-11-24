#include "PrintExpr.hh"
#include "../Log.hh"  // Include the macros header

PrintExpr::PrintExpr(std::vector<Expr *> exprs)
{
    LOG_OPERATION_START("PrintExpr::PrintExpr(std::vector<Expr *>)");
    this->exprs.reserve(exprs.size());
    for(auto i : exprs){
        this->exprs.push_back(ExprPtr(i));
    }
    
    LOG_OPERATION_END("PrintExpr::PrintExpr(std::vector<Expr *>)");
}

PrintExpr::~PrintExpr()
{
    LOG_OPERATION_START("PrintExpr::~PrintExpr");
    LOG_OPERATION_END("PrintExpr::~PrintExpr");
}

std::vector<Expr*> PrintExpr::getExprs() 
{
    LOG_OPERATION_START("PrintExpr::getExprs");
    std::vector<Expr *> temp;
    temp.reserve(exprs.size());
    for(ExprPtr& expr : exprs){
        temp.push_back(expr.get());
    }
    LOG_OPERATION_END("PrintExpr::getExprs");
    
    return temp;
}

void PrintExpr::accept(Visitor *visitor)
{
    LOG_OPERATION_START("PrintExpr::accept");
    visitor->visit(this);
    LOG_OPERATION_END("PrintExpr::accept");
}
