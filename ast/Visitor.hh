#ifndef VISITOR__GUARD
#define VISITOR__GUARD

class Id;
class Int;       // Forward declaration
class Float;   // Forward declaration
class Expr;   // Forward declaration
class AddExpr;   // Forward declaration
class ModExpr;   // Forward declaration
class SubtExpr;   // Forward declaration
class DivExpr;   // Forward declaration
class MulExpr;   // Forward declaration
class Statement;   // Forward declaration
class DefVar;   // Forward declaration
class DefFunc;   // Forward declaration
class CallFunc;   // Forward declaration
class PrintExpr;   // Forward declaration
class ReturnStmt;   // Forward declaration

class Visitor {
public:
    virtual ~Visitor() = default;

    virtual void visit(Id* id) = 0;
    virtual void visit(Int* integer) = 0;
    virtual void visit(Float* expr) = 0;
    virtual void visit(Expr* expr) = 0;
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
};

#endif // VISITOR__GUARD
