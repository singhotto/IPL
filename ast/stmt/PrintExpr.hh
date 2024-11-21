#ifndef PRINTEXPR__GUARD
#define PRINTEXPR__GUARD

#include "Statement.hh"
#include <vector>
#include "../Visitor.hh" // Only necessary to define `accept`
#include "../expr/Expr.hh"

class Expr;
class Visitor;

class PrintExpr : virtual public Statement {
private:
    using ExprPtr = std::unique_ptr<Expr>;
    ExprPtr expr;

public:
    PrintExpr(ExprPtr expr);
    ~PrintExpr();

    Expr* getExpr() const;
    void accept(Visitor* visitor) override;
};

#endif 
