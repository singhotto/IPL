#ifndef INTERPRETER__GUARD
#define INTERPRETER__GUARD

#include <cassert>
#include <iostream>
#include "Visitor.hh"
#include "Value.hh"
#include "ExecContext.hh"

class Interpreter : virtual public Visitor
{
private:
    ExecContext context;
    Value* current = nullptr;

    // Private copy constructor and assignment operator to prevent copying
    Interpreter(const Interpreter&) = delete;
    Interpreter& operator=(const Interpreter&) = delete;

    void binaryNumber(BinaryExpr* expr, float& left, float& right);

public:
    
    // Private constructor to prevent direct instantiation
    Interpreter() = default;
    ~Interpreter();
    // Public static method to access the single instance
    static Interpreter& getInstance();

    void visit(Id* id) override;
    void visit(String* str) override;
    void visit(Int* integer) override;
    void visit(Float* expr) override;
    void visit(Expr* expr) override;
    void visit(BinaryExpr* expr) override;
    void visit(AddExpr* expr) override;
    void visit(ModExpr* expr) override;
    void visit(SubtExpr* expr) override;
    void visit(DivExpr* expr) override;
    void visit(MulExpr* expr) override;
    void visit(Statement* stmt) override;
    void visit(DefVar* stmt) override;
    void visit(DefFunc* func) override;
    void visit(CallFunc* func) override;
    void visit(PrintExpr* expr) override;
    void visit(ReturnStmt* expr) override;
};

#endif // INTERPRETER__GUARD
