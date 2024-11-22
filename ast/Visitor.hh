#ifndef VISITOR__GUARD
#define VISITOR__GUARD

//Values
class Id;
class Int;      
class String;      
class Float;  
class Expr;  

//Arithmatic
class BinaryExpr;  
class AddExpr;  
class ModExpr;  
class SubtExpr;  
class DivExpr;  
class MulExpr;  
class CallFunc;  

//Statements
class Statement;  
class DefVar;  
class DefFunc;  
class PrintExpr;  
class ReturnStmt;  
class Ifcond;
class Ifelse;

//Boolean Logic
class And;  
class Equal;  
class Greater;  
class GreaterEqual;  
class Less;  
class LessEqual;  
class NotEqual;  
class Or;  

class Visitor {
public:
    virtual ~Visitor() = default;

    virtual void visit(Id* id) = 0;
    virtual void visit(String* id) = 0;
    virtual void visit(Int* integer) = 0;
    virtual void visit(Float* expr) = 0;

    virtual void visit(Expr* expr) = 0;
    virtual void visit(BinaryExpr* expr) = 0;
    virtual void visit(AddExpr* expr) = 0;
    virtual void visit(ModExpr* expr) = 0;
    virtual void visit(SubtExpr* expr) = 0;
    virtual void visit(DivExpr* expr) = 0;
    virtual void visit(MulExpr* expr) = 0;

    virtual void visit(Statement* expr) = 0;
    virtual void visit(DefVar* expr) = 0;
    virtual void visit(DefFunc* expr) = 0;
    virtual void visit(CallFunc* expr) = 0;
    virtual void visit(PrintExpr* expr) = 0;
    virtual void visit(ReturnStmt* expr) = 0;
    virtual void visit(Ifcond* expr) = 0;
    virtual void visit(Ifelse* expr) = 0;

    virtual void visit(And* expr) = 0;
    virtual void visit(Equal* expr) = 0;
    virtual void visit(Greater* expr) = 0;
    virtual void visit(GreaterEqual* expr) = 0;
    virtual void visit(Less* expr) = 0;
    virtual void visit(LessEqual* expr) = 0;
    virtual void visit(NotEqual* expr) = 0;
    virtual void visit(Or* expr) = 0;
};

#endif // VISITOR__GUARD
