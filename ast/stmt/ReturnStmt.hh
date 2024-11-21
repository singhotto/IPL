#ifndef RETURN_STMT__GUARD
#define RETURN_STMT__GUARD

#include "Statement.hh"
#include "../Visitor.hh" 
#include "../expr/Expr.hh"

class ReturnStmt : virtual public Statement 
{
private:
    using ExprPtr = std::unique_ptr<Expr>;
    ExprPtr val;
public:
    ReturnStmt(ExprPtr val);
    ~ReturnStmt();
    
    Expr* getValue() const;


    void accept(Visitor* visitor) override;
};

#endif