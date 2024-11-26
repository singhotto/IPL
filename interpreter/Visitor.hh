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
class Block;  
class DefVar;  
class Assign;  
class AddAssign;  
class Decrease;  
class Increase;  
class DivAssign;  
class MulAssign;  
class SubAssign;  
class DefFunc;  
class PrintExpr;  
class ReturnStmt;  
class Ifcond;
class Ifelse;
class ForLoop;
class While;

//Boolean Logic
class And;  
class Equal;  
class Greater;  
class GreaterEqual;  
class Less;  
class LessEqual;  
class NotEqual;  
class Or;  

//Images
class JpgImage;
class PngImage;
class TIFFImage;

//Image Operations
class Load;
class Save;

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
    virtual void visit(Block* expr) = 0;
    virtual void visit(DefVar* expr) = 0;
    virtual void visit(Assign* expr) = 0;
    virtual void visit(AddAssign* expr) = 0;
    virtual void visit(Decrease* expr) = 0;
    virtual void visit(Increase* expr) = 0;
    virtual void visit(DivAssign* expr) = 0;
    virtual void visit(SubAssign* expr) = 0;
    virtual void visit(MulAssign* expr) = 0;

    virtual void visit(DefFunc* expr) = 0;
    virtual void visit(CallFunc* expr) = 0;
    virtual void visit(PrintExpr* expr) = 0;
    virtual void visit(ReturnStmt* expr) = 0;
    virtual void visit(Ifcond* expr) = 0;
    virtual void visit(Ifelse* expr) = 0;
    virtual void visit(ForLoop* expr) = 0;
    virtual void visit(While* expr) = 0;

    virtual void visit(And* expr) = 0;
    virtual void visit(Equal* expr) = 0;
    virtual void visit(Greater* expr) = 0;
    virtual void visit(GreaterEqual* expr) = 0;
    virtual void visit(Less* expr) = 0;
    virtual void visit(LessEqual* expr) = 0;
    virtual void visit(NotEqual* expr) = 0;
    virtual void visit(Or* expr) = 0;

    virtual void visit(JpgImage* img) = 0;
    virtual void visit(PngImage* img) = 0;
    virtual void visit(TIFFImage* img) = 0;

    virtual void visit(Load* img) = 0;
    virtual void visit(Save* img) = 0;
};

#endif // VISITOR__GUARD
