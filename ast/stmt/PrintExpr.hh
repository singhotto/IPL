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
    std::vector<ExprPtr> exprs;

public:
    PrintExpr(std::vector<Expr*> exprs);
    ~PrintExpr();

    std::vector<Expr*> getExprs();
    std::unique_ptr<Statement> clone() const override;

    void accept(Visitor* visitor) override;
};

#endif 
