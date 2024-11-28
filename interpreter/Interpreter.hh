#ifndef INTERPRETER__GUARD
#define INTERPRETER__GUARD

#include <cassert>
#include <iostream>
#include "Visitor.hh"
#include "Value.hh"
#include "ExecContext.hh"
#include "expr/boolean/BoolExpr.hh"
#include "expr/value/Float.hh"
#include "expr/value/Bool.hh"
#include "expr/value/image/Image.hh"

class Interpreter : virtual public Visitor
{
private:
    using ValuePtr = std::unique_ptr<Value>;
    using FloatPtr = std::unique_ptr<Float>;
    using BoolPtr = std::unique_ptr<Bool>;

    ExecContext context;
    ValuePtr current;
    bool funcReturn = false;

    // Private copy constructor and assignment operator to prevent copying
    Interpreter(const Interpreter&) = delete;
    Interpreter& operator=(const Interpreter&) = delete;

    float binaryNumber(BinaryExpr* expr, char op);
    bool checkBool(BoolExpr *expr, int op);
    bool boolean(BoolExpr* expr, int op);

    bool isIPFunction(const std::string& funcName);
    void ipFunction(CallFunc* func);

    std::string getString(Expr* e);
    ValuePtr& getImage(Expr* e);
    float getNumber(Expr* e);

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

    void visit(MinusExpr* expr) override;
    void visit(BinaryExpr* expr) override;
    void visit(AddExpr* expr) override;
    void visit(ModExpr* expr) override;
    void visit(SubtExpr* expr) override;
    void visit(DivExpr* expr) override;
    void visit(MulExpr* expr) override;

    void visit(Statement* stmt) override;
    void visit(Block* stmt) override;
    void visit(DefVar* stmt) override;
    void visit(Assign* stmt) override;
    void visit(AddAssign* stmt) override;
    void visit(Decrease* stmt) override;
    void visit(Increase* stmt) override;
    void visit(DivAssign* stmt) override;
    void visit(SubAssign* stmt) override;
    void visit(MulAssign* stmt) override;


    void visit(DefFunc* func) override;
    void visit(CallFunc* func) override;
    void visit(PrintExpr* expr) override;
    void visit(ReturnStmt* expr) override;
    void visit(Ifcond* expr) override;
    void visit(Ifelse* expr) override;
    void visit(ForLoop* expr) override;
    void visit(While* expr) override;

    void visit(And* expr) override;
    void visit(Equal* expr) override;
    void visit(Greater* expr) override;
    void visit(GreaterEqual* expr) override;
    void visit(Less* expr) override;
    void visit(LessEqual* expr) override;
    void visit(NotEqual* expr) override;
    void visit(Or* expr) override;
    void visit(Not* expr) override;

    void visit(JpgImage* img) override;
    void visit(PngImage* img) override;
    void visit(TIFFImage* img) override;
};

#endif // INTERPRETER__GUARD
