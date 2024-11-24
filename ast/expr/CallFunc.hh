#ifndef CALL_FUNC__GUARD
#define CALL_FUNC__GUARD

#include "../Value.hh"
#include "../stmt/Statement.hh"
#include "Expr.hh"
#include "value/Id.hh"
#include <vector>
#include "../Visitor.hh" // Only necessary to define `accept`

class CallFunc : virtual public Statement, virtual public Expr {
private:
    using IdPtr = std::unique_ptr<Id>;
    using ExprPtr = std::unique_ptr<Expr>;
    IdPtr funcId;
    std::vector<ExprPtr> args;

public:
   CallFunc(IdPtr funcName, std::vector<Expr*> args);
   ~CallFunc();
   std::string funcName();
   std::vector<Expr*> funcArgs();
   std::unique_ptr<Expr> cloneExpr() const override;
   std::unique_ptr<Statement> clone() const override;

   void accept(Visitor* visitor) override;
};

#endif