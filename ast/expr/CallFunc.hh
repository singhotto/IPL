#ifndef CALL_FUNC__GUARD
#define CALL_FUNC__GUARD

#include "../Value.hh"
#include "../stmt/Statement.hh"
#include "Expr.hh"
#include "Id.hh"
#include <vector>
#include "../Visitor.hh" // Only necessary to define `accept`

class CallFunc : virtual public Statement, virtual public Expr {
private:
    using IdPtr = std::unique_ptr<Id>;
    IdPtr funcId;
    std::vector<IdPtr> args;

public:
   CallFunc(IdPtr funcName, std::vector<Id*> args);
   CallFunc(IdPtr funcName);
   ~CallFunc();
   std::string funcName();
   std::vector<Id*> funcArgs();
   void accept(Visitor* visitor) override;
};

#endif