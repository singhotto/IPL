#include "Interpreter.hh"
#include "IPLFactory.hh"
#include "Value.hh"
#include "expr/value/Int.hh"
#include "expr/arithmatic/AddExpr.hh"
#include "expr/Expr.hh"
#include "expr/value/Id.hh"
#include "stmt/Statement.hh"
#include "stmt/DefVar.hh"
#include "stmt/DefFunc.hh"
#include "expr/CallFunc.hh"
#include "stmt/PrintExpr.hh"
#include "stmt/ReturnStmt.hh"
#include "Log.hh"

bool g_logOperations = false;

void Interpreter::binaryNumber(BinaryExpr *expr, float &left, float &right)
{
    expr->getLeft()->accept(this);
    Number* l = dynamic_cast<Number*>(current);
    assert(l != nullptr);
    left = l->getValue();

    expr->getRight()->accept(this);
    Number* r = dynamic_cast<Number*>(current);
    assert(r != nullptr);
    right = r->getValue();
}

Interpreter::~Interpreter()
{
    LOG_OPERATION_START("Interpreter::~Interpreter");
    LOG_OPERATION_END("Interpreter::~Interpreter");
}

Interpreter& Interpreter::getInstance() {
    LOG_OPERATION_START("Interpreter::getInstance");
    static Interpreter instance;
    LOG_OPERATION_END("Interpreter::getInstance");
    return instance;
}

void Interpreter::visit(Id *id)
{
    LOG_OPERATION_START("Interpreter::visit(Id *id)");
    assert(id != nullptr);
    std::string name = id->getName();
    current = context.getVariable(name);
    LOG_OPERATION_END("Interpreter::visit(Id *id)");
}

void Interpreter::visit(String *str)
{
    LOG_OPERATION_START("Interpreter::visit(Id *id)");
    assert(str != nullptr);
    current = str;
    LOG_OPERATION_END("Interpreter::visit(Id *id)");
}

void Interpreter::visit(Int *integer)
{
    LOG_OPERATION_START("Interpreter::visit(Int *integer)");
    current = integer;
    LOG_OPERATION_END("Interpreter::visit(Int *integer)");
}

void Interpreter::visit(Float *fvalue)
{
    LOG_OPERATION_START("Interpreter::visit(Float *fvalue)");
    current = fvalue;
    LOG_OPERATION_END("Interpreter::visit(Float *fvalue)");
}

void Interpreter::visit(AddExpr *expr)
{
    LOG_OPERATION_START("Interpreter::visit(AddExpr *expr)");

    float leftValue = 0.0f;
    float rightValue = 0.0f;

    binaryNumber(expr, leftValue, rightValue);

    current = IPLFactory::createFloat(leftValue + rightValue);

    LOG_OPERATION_END("Interpreter::visit(AddExpr *expr)");
}

void Interpreter::visit(ModExpr *expr)
{
    LOG_OPERATION_START("Interpreter::visit(ModExpr *expr)");

    float leftfValue = 0.0f;
    float rightfValue = 0.0f;

    binaryNumber(expr, leftfValue, rightfValue);

    int leftValue = static_cast<int>(leftfValue);
    int rightValue = static_cast<int>(rightfValue);
    
    current = IPLFactory::createFloat((float)(leftValue % rightValue));

    LOG_OPERATION_END("Interpreter::visit(ModExpr *expr)");
}

void Interpreter::visit(SubtExpr *expr)
{
    LOG_OPERATION_START("Interpreter::visit(SubtExpr *expr)");

    float leftValue = 0.0f;
    float rightValue = 0.0f;

    binaryNumber(expr, leftValue, rightValue);

    current = IPLFactory::createFloat(leftValue - rightValue);

    LOG_OPERATION_END("Interpreter::visit(SubtExpr *expr)");
}

void Interpreter::visit(DivExpr *expr)
{
    LOG_OPERATION_START("Interpreter::visit(DivExpr *expr)");

    float leftValue = 0.0f;
    float rightValue = 0.0f;

    binaryNumber(expr, leftValue, rightValue);

    current = IPLFactory::createFloat(leftValue / rightValue);
    
    LOG_OPERATION_END("Interpreter::visit(DivExpr *expr)");
}

void Interpreter::visit(MulExpr *expr)
{
    LOG_OPERATION_START("Interpreter::visit(MulExpr *expr)");

    float leftValue = 0.0f;
    float rightValue = 0.0f;

    binaryNumber(expr, leftValue, rightValue);

    current = IPLFactory::createFloat(leftValue * rightValue);
    
    LOG_OPERATION_END("Interpreter::visit(MulExpr *expr)");
}

void Interpreter::visit(Statement *stmt)
{
    LOG_OPERATION_START("Interpreter::visit(Statement *stmt)");
    stmt->accept(this);
    LOG_OPERATION_END("Interpreter::visit(Statement *stmt)");
}

void Interpreter::visit(DefVar *stmt)
{
    LOG_OPERATION_START("Interpreter::visit(DefVar *stmt)");
    stmt->getValue()->accept(this);
    Value* val = dynamic_cast<Value*>(current);
    assert(val != nullptr);
    Id* id = stmt->getId();
    context.setVariable(id->getName(), val);
    LOG_OPERATION_END("Interpreter::visit(DefVar *stmt)");
}

void Interpreter::visit(DefFunc *func)
{
    LOG_OPERATION_START("Interpreter::visit(DefFunc *func)");
    context.setVariable(func->getName(), func);
    LOG_OPERATION_END("Interpreter::visit(DefFunc *func)");
}

void Interpreter::visit(CallFunc *func)
{
    LOG_OPERATION_START("Interpreter::visit(CallFunc *func)");
    Value* fName = context.getVariable(func->funcName());
    DefFunc* f = dynamic_cast<DefFunc*>(fName);
    auto internalParms = func->funcArgs();
    auto globalParms = f->funcArgs();

    assert(f != nullptr);
    assert(internalParms.size() == globalParms.size());
    
    context.newScope();


    for(int i = 0; i<internalParms.size(); i++){
        const std::string& name = internalParms[i]->getName();
        Value* value = context.getVariable(globalParms[i]->getName());
        context.setVariable(name, value);
    }
    auto statements = f->funcStatements();
    for(int i = 0; i<statements.size(); i++){
        statements[i]->accept(this);
    }
    context.exitScope();
    LOG_OPERATION_END("Interpreter::visit(CallFunc *func)");
}

void Interpreter::visit(PrintExpr *expr)
{
    LOG_OPERATION_START("Interpreter::visit(PrintExpr *expr)");
    Expr* e = expr->getExpr();
    assert(e != nullptr);
    e->accept(this);
    assert(current != nullptr);
    Number* num = dynamic_cast<Number*>(current);
    String* str = dynamic_cast<String*>(current);
    if(num){
        std::cout << num->getValue() << std::endl;
    }else if(str){
        std::cout << str->getStr() << std::endl;
    }else{
        assert(0 && "it's not Printable");
    }

    LOG_OPERATION_END("Interpreter::visit(PrintExpr *expr)");
}

void Interpreter::visit(ReturnStmt *expr)
{
    LOG_OPERATION_START("Interpreter::visit(ReturnStmt *expr)");
    expr->getValue()->accept(this);
    LOG_OPERATION_END("Interpreter::visit(ReturnStmt *expr)");
}

void Interpreter::visit(Expr *expr)
{
    LOG_OPERATION_START("Interpreter::visit(Expr *expr)");
    expr->accept(this);
    LOG_OPERATION_END("Interpreter::visit(Expr *expr)");
}

void Interpreter::visit(BinaryExpr *expr)
{
    LOG_OPERATION_START("Interpreter::visit(BinaryExpr *expr)");
    expr->accept(this);
    LOG_OPERATION_END("Interpreter::visit(BinaryExpr *expr)");
}