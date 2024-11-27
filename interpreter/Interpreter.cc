#include "Interpreter.hh"
#include "IPLFactory.hh"
#include "Value.hh"

#include "ImageProcessor.hh"
#include "ImageOperation.hh"

#include "expr/value/image/Image.hh"
#include "expr/value/image/JpgImage.hh"
#include "expr/value/image/PngImage.hh"
#include "expr/value/image/TIFFImage.hh"

#include "expr/value/Int.hh"
#include "expr/arithmatic/AddExpr.hh"
#include "expr/Expr.hh"
#include "expr/value/Id.hh"
#include "expr/CallFunc.hh"

#include "stmt/Statement.hh"
#include "stmt/assignment/Assign.hh"
#include "stmt/assignment/AddAssign.hh"
#include "stmt/assignment/MulAssign.hh"
#include "stmt/assignment/DivAssign.hh"
#include "stmt/assignment/SubAssign.hh"
#include "stmt/assignment/AddAssign.hh"
#include "stmt/assignment/Decrease.hh"
#include "stmt/assignment/Increase.hh"

#include "stmt/Block.hh"
#include "stmt/DefVar.hh"
#include "stmt/DefFunc.hh"
#include "stmt/Ifcond.hh"
#include "stmt/Ifelse.hh"
#include "stmt/PrintExpr.hh"
#include "stmt/ReturnStmt.hh"
#include "stmt/ForLoop.hh"
#include "stmt/While.hh"

#include "Log.hh"

bool Interpreter::isDefaultFunction(const std::string &funcName)
{
    return isImageOperation(funcName);
}

void Interpreter::defaultFunction(CallFunc *func)
{
    LOG_OPERATION_START("Interpreter::defaultFunction(CallFunc *func)");
    ImageOperation op = getImageOperation(func->funcName());
    auto globalParms = func->funcArgs(); 

    switch (op)
    {
    case ImageOperation::LOAD: {
        assert(globalParms.size() == 1);
        globalParms[0]->accept(this);
        String* str = dynamic_cast<String*>(current.get());
        assert(str != nullptr);
        std::string path = str->getStr();  // Now inside a block scope
        current = ValuePtr(IPLFactory::createImage(path));
        break;
    }

    case ImageOperation::SAVE: {
        assert(globalParms.size() == 2);

        globalParms[1]->accept(this);
        String* str = dynamic_cast<String*>(current.get());
        assert(str != nullptr);
        std::string path = str->getStr(); 

        globalParms[0]->accept(this);
        Image* image = dynamic_cast<Image*>(current.get());
        assert(image != nullptr);

        image->save(path);
        break;
    }
    
    default:
        break;
    }
    LOG_OPERATION_END("Interpreter::defaultFunction(CallFunc *func)");
}


float Interpreter::binaryNumber(BinaryExpr* expr, char op)
{
    expr->getLeft()->accept(this);
    Number* l = dynamic_cast<Number*>(current.get());
    assert(l != nullptr);
    float left = l->getValue();

    expr->getRight()->accept(this);
    Number* r = dynamic_cast<Number*>(current.get());
    assert(r != nullptr);
    float right = r->getValue();

    switch (op) {
        case '+':
            return left + right;
        case '-':
            return left - right;
        case '*':
            return left * right;
        case '/':
            return left / right;
        case '%':
            return int(left) % int(right);
        default:
            assert(0 && "Error Arithmatic Operation");
            break;
    }
}

bool Interpreter::boolean(BoolExpr *expr, int op)
{
    expr->getLeft()->accept(this);
    Number* l = dynamic_cast<Number*>(current.get());
    assert(l != nullptr);
    int left = l->getValue();

    expr->getRight()->accept(this);
    Number* r = dynamic_cast<Number*>(current.get());
    assert(r != nullptr);
    int right = r->getValue();
    
    switch (op) {
        case 1:
            return left && right;
        case 2:
            return left || right;
        case 3:
            return left == right;
        case 4:
            return left != right;
        case 5:
            return left > right;
        case 6:
            return left >= right;
        case 7:
            return left < right;
        case 8:
            return left <= right;
        default:
            assert(0 && "Error Boolean Operation");
            break;
    }
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
    current = context.getVariable(name)->cloneValue();
    LOG_OPERATION_END("Interpreter::visit(Id *id)");
}

void Interpreter::visit(String *str)
{
    LOG_OPERATION_START("Interpreter::visit(Id *id)");
    assert(str != nullptr);
    current = str->cloneValue();
    LOG_OPERATION_END("Interpreter::visit(Id *id)");
}

void Interpreter::visit(Int *integer)
{
    LOG_OPERATION_START("Interpreter::visit(Int *integer)");
    current = integer->cloneValue();
    LOG_OPERATION_END("Interpreter::visit(Int *integer)");
}

void Interpreter::visit(Float *fvalue)
{
    LOG_OPERATION_START("Interpreter::visit(Float *fvalue)");
    current = fvalue->cloneValue();
    LOG_OPERATION_END("Interpreter::visit(Float *fvalue)");
}

void Interpreter::visit(AddExpr *expr)
{
    LOG_OPERATION_START("Interpreter::visit(AddExpr *expr)");
    expr->getLeft()->accept(this);
    String* str1 = dynamic_cast<String*>(current.get());

    if(str1){
        expr->getRight()->accept(this);
        String* str2 = dynamic_cast<String*>(current.get());
        current = std::unique_ptr<String>(IPLFactory::createEString(str1->getStr() + str2->getStr()));
    }else{
        current = FloatPtr(IPLFactory::createFloat(binaryNumber(expr, '+')));
    }

    LOG_OPERATION_END("Interpreter::visit(AddExpr *expr)");
}

void Interpreter::visit(ModExpr *expr)
{
    LOG_OPERATION_START("Interpreter::visit(ModExpr *expr)");

    current = FloatPtr(IPLFactory::createFloat(binaryNumber(expr, '%')));

    LOG_OPERATION_END("Interpreter::visit(ModExpr *expr)");
}

void Interpreter::visit(SubtExpr *expr)
{
    LOG_OPERATION_START("Interpreter::visit(SubtExpr *expr)");

    current = FloatPtr(IPLFactory::createFloat(binaryNumber(expr, '-')));

    LOG_OPERATION_END("Interpreter::visit(SubtExpr *expr)");
}

void Interpreter::visit(DivExpr *expr)
{
    LOG_OPERATION_START("Interpreter::visit(DivExpr *expr)");

    current = FloatPtr(IPLFactory::createFloat(binaryNumber(expr, '/')));
    
    LOG_OPERATION_END("Interpreter::visit(DivExpr *expr)");
}

void Interpreter::visit(MulExpr *expr)
{
    LOG_OPERATION_START("Interpreter::visit(MulExpr *expr)");

    current = FloatPtr(IPLFactory::createFloat(binaryNumber(expr, '*')));
    
    LOG_OPERATION_END("Interpreter::visit(MulExpr *expr)");
}

void Interpreter::visit(Statement *stmt)
{
    LOG_OPERATION_START("Interpreter::visit(Statement *stmt)");
    stmt->accept(this);
    LOG_OPERATION_END("Interpreter::visit(Statement *stmt)");
}

void Interpreter::visit(Block *stmt)
{
    LOG_OPERATION_START("Interpreter::visit(Block *stmt)");
    auto stmts =  stmt->getStatemets();

    for(Statement* s : stmts){
        s->accept(this);
    }

    LOG_OPERATION_END("Interpreter::visit(Block *stmt)");
}

void Interpreter::visit(DefVar *stmt)
{
    LOG_OPERATION_START("Interpreter::visit(DefVar *stmt)");
    stmt->getValue()->accept(this);
    Value* val = dynamic_cast<Value*>(current.get());
    assert(val != nullptr);
    Id* id = stmt->getId();
    context.addNewVariable(id->getName(), val->cloneValue());
    LOG_OPERATION_END("Interpreter::visit(DefVar *stmt)");
}

void Interpreter::visit(Assign *stmt)
{
    LOG_OPERATION_START("Interpreter::visit(Assign *stmt)");

    stmt->getValue()->accept(this);
    Value* val = dynamic_cast<Value*>(current.get());
    assert(val != nullptr);

    const std::string& var_name = stmt->getId()->getName();
    if(context.getVariable(var_name)){
        context.updateVariable(var_name, val->cloneValue());
    }else{
        throw std::string("Undeclaired Varibale ") + var_name + "\n";
    }

    LOG_OPERATION_END("Interpreter::visit(Assign *stmt)");
}

void Interpreter::visit(AddAssign *stmt)
{
    LOG_OPERATION_START("Interpreter::visit(AddAssign *stmt)");
    
    stmt->getValue()->accept(this);
    Number* val = dynamic_cast<Number*>(current.get());
    assert(val != nullptr);

    const std::string& var_name = stmt->getId()->getName();
    Number* old = dynamic_cast<Number*>(context.getVariable(var_name));
    if(old){
        old->setValue(val->getValue() + old->getValue());
    }else{
        throw std::string("Undeclaired Varibale ") + var_name + "\n";
    }

    LOG_OPERATION_END("Interpreter::visit(AddAssign *stmt)");
}

void Interpreter::visit(Decrease *stmt)
{
    LOG_OPERATION_START("Interpreter::visit(Decrease *stmt)");

    const std::string& var_name = stmt->getId()->getName();
    Number* old = dynamic_cast<Number*>(context.getVariable(var_name));
    if(old){
        old->setValue(old->getValue() - 1);
    }else{
        throw std::string("Undeclaired Varibale ") + var_name + "\n";
    }

    LOG_OPERATION_END("Interpreter::visit(Decrease *stmt)");
}

void Interpreter::visit(Increase *stmt)
{
    LOG_OPERATION_START("Interpreter::visit(Increase *stmt)");

    const std::string& var_name = stmt->getId()->getName();
    Number* old = dynamic_cast<Number*>(context.getVariable(var_name));
    if(old){
        old->setValue(old->getValue() + 1);
    }else{
        throw std::string("Undeclaired Varibale ") + var_name + "\n";
    }
    
    LOG_OPERATION_END("Interpreter::visit(Increase *stmt)");
}

void Interpreter::visit(DivAssign *stmt)
{
    LOG_OPERATION_START("Interpreter::visit(DivAssign *stmt)");
    
    stmt->getValue()->accept(this);
    Number* val = dynamic_cast<Number*>(current.get());
    assert(val != nullptr);

    const std::string& var_name = stmt->getId()->getName();
    Number* old = dynamic_cast<Number*>(context.getVariable(var_name));
    if(old){
        old->setValue((float)old->getValue() / val->getValue());
    }else{
        throw std::string("Undeclaired Varibale ") + var_name + "\n";
    }

    LOG_OPERATION_END("Interpreter::visit(DivAssign *stmt)");
}

void Interpreter::visit(SubAssign *stmt)
{
    LOG_OPERATION_START("Interpreter::visit(SubAssign *stmt)");
    
    stmt->getValue()->accept(this);
    Number* val = dynamic_cast<Number*>(current.get());
    assert(val != nullptr);

    const std::string& var_name = stmt->getId()->getName();
    Number* old = dynamic_cast<Number*>(context.getVariable(var_name));
    if(old){
        old->setValue(old->getValue() - val->getValue());
    }else{
        throw std::string("Undeclaired Varibale ") + var_name + "\n";
    }

    LOG_OPERATION_END("Interpreter::visit(SubAssign *stmt)");
}

void Interpreter::visit(MulAssign *stmt)
{
    LOG_OPERATION_START("Interpreter::visit(MulAssign *stmt)");
    
    stmt->getValue()->accept(this);
    Number* val = dynamic_cast<Number*>(current.get());
    assert(val != nullptr);

    const std::string& var_name = stmt->getId()->getName();
    Number* old = dynamic_cast<Number*>(context.getVariable(var_name));
    if(old){
        old->setValue(old->getValue() * val->getValue());
    }else{
        throw std::string("Undeclaired Varibale ") + var_name + "\n";
    }

    LOG_OPERATION_END("Interpreter::visit(MulAssign *stmt)");
}

void Interpreter::visit(DefFunc *func)
{
    LOG_OPERATION_START("Interpreter::visit(DefFunc *func)");
    context.addNewVariable(func->getName(), func->cloneValue());
    LOG_OPERATION_END("Interpreter::visit(DefFunc *func)");
}

void Interpreter::visit(CallFunc *func)
{
    LOG_OPERATION_START("Interpreter::visit(CallFunc *func)");

    Value* fName = context.getVariable(func->funcName());
    if(isDefaultFunction(func->funcName())){
        defaultFunction(func);
    } else{
        DefFunc* f = dynamic_cast<DefFunc*>(fName); //function
        auto globalParms = func->funcArgs(); 
        auto internalParms = f->funcArgs();

        assert(f != nullptr);
        assert(internalParms.size() == globalParms.size());
        
        context.newScope();


        for(int i = 0; i<internalParms.size(); i++){
            const std::string& name = internalParms[i]->getName();
            globalParms[i]->accept(this);
            context.addNewVariable(name, current->cloneValue());
        }
        auto statements = f->funcStatements();
        for(int i = 0; i<statements.size(); i++){
            statements[i]->accept(this);

            if(funcReturn){
                funcReturn = false;
                break;
            }
        }
        context.exitScope();
    }
    LOG_OPERATION_END("Interpreter::visit(CallFunc *func)");
}

void Interpreter::visit(PrintExpr *expr)
{
    LOG_OPERATION_START("Interpreter::visit(PrintExpr *expr)");

    for(Expr* e : expr->getExprs()){
        assert(e != nullptr);
        e->accept(this);

        assert(current != nullptr);

        current->print();
    }
    
    std::cout<<"\n";

    LOG_OPERATION_END("Interpreter::visit(PrintExpr *expr)");
}

void Interpreter::visit(ReturnStmt *stmt)
{
    LOG_OPERATION_START("Interpreter::visit(ReturnStmt *stmt)");
    stmt->getValue()->accept(this);
    funcReturn = true;
    LOG_OPERATION_END("Interpreter::visit(ReturnStmt *stmt)");
}

void Interpreter::visit(Ifcond *expr)
{
    LOG_OPERATION_START("Interpreter::visit(Ifcond *expr)");

    expr->getCond()->accept(this);

    Bool* cond = dynamic_cast<Bool*>(current.get());

    assert(cond != nullptr);

    context.newScope();

    if(cond->getValue()){
        auto statements = expr->getBody();
        for(int i = 0; i<statements.size(); i++){
            statements[i]->accept(this);
        }
    }

    context.exitScope();
    
    LOG_OPERATION_END("Interpreter::visit(Ifcond *expr)");
}

void Interpreter::visit(Ifelse *expr)
{
    LOG_OPERATION_START("Interpreter::visit(Ifelse *expr)");

    
    expr->getCond()->accept(this);

    Bool* cond = dynamic_cast<Bool*>(current.get());

    assert(cond != nullptr);

    context.newScope();

    if(cond->getValue()){
        auto statements = expr->getBody();
        for(int i = 0; i<statements.size(); i++){
            statements[i]->accept(this);
        }
    }else{
        auto statements = expr->getElseBody();
        for(int i = 0; i<statements.size(); i++){
            statements[i]->accept(this);
        }
    }

    context.exitScope();
    
    LOG_OPERATION_END("Interpreter::visit(Ifelse *expr)");
}

void Interpreter::visit(ForLoop *for_stmt)
{
    LOG_OPERATION_START("Interpreter::visit(ForLoop *expr)");

    context.newScope();

    DefVar* var_def = dynamic_cast<DefVar*>(for_stmt->getInitial());

    assert(var_def != nullptr);

    var_def->accept(this);

    for_stmt->getCond()->accept(this);

    Bool* v = dynamic_cast<Bool*>(current.get());

    assert(v != nullptr);

    auto stmt_list = for_stmt->getBody();


    while (v->getValue())
    {
        for(auto& stmt : stmt_list){
            stmt->accept(this);
        }

        for_stmt->getUpdate()->accept(this);

        for_stmt->getCond()->accept(this);

        v = dynamic_cast<Bool*>(current.get());
    }
    context.exitScope();

    LOG_OPERATION_END("Interpreter::visit(ForLoop *expr)");
}

void Interpreter::visit(While *while_stmt)
{
    LOG_OPERATION_START("Interpreter::visit(While *while_stmt)");

    while_stmt->getCond()->accept(this);

    Bool* v = dynamic_cast<Bool*>(current.get());

    assert(v != nullptr);

    auto stmt_list = while_stmt->getBody();


    while (v->getValue())
    {
        context.newScope();

        for(auto& stmt : stmt_list)
            stmt->accept(this);

        context.exitScope();

        while_stmt->getCond()->accept(this);

        v = dynamic_cast<Bool*>(current.get());
    }

    LOG_OPERATION_END("Interpreter::visit(While *while_stmt)");
}

void Interpreter::visit(And *expr)
{
    LOG_OPERATION_START("Interpreter::visit(And *expr)");

    current = BoolPtr(IPLFactory::createBool(boolean(expr, 1)));
    
    LOG_OPERATION_END("Interpreter::visit(And *expr)");
}

void Interpreter::visit(Equal *expr)
{
    LOG_OPERATION_START("Interpreter::visit(Equal *expr)");

    current = BoolPtr(IPLFactory::createBool(boolean(expr, 3)));
    
    LOG_OPERATION_END("Interpreter::visit(Equal *expr)");
}

void Interpreter::visit(Greater *expr)
{
    LOG_OPERATION_START("Interpreter::visit(Greater *expr)");

    current = BoolPtr(IPLFactory::createBool(boolean(expr, 5)));
    
    LOG_OPERATION_END("Interpreter::visit(Greater *expr)");
}

void Interpreter::visit(GreaterEqual *expr)
{
    LOG_OPERATION_START("Interpreter::visit(GreaterEqual *expr)");

    current = BoolPtr(IPLFactory::createBool(boolean(expr, 6)));
    
    LOG_OPERATION_END("Interpreter::visit(GreaterEqual *expr)");
}

void Interpreter::visit(Less *expr)
{
    LOG_OPERATION_START("Interpreter::visit(Less *expr)");

    current = BoolPtr(IPLFactory::createBool(boolean(expr, 7)));
    
    LOG_OPERATION_END("Interpreter::visit(Less *expr)");
}

void Interpreter::visit(LessEqual *expr)
{
    LOG_OPERATION_START("Interpreter::visit(LessEqual *expr)");

    current = BoolPtr(IPLFactory::createBool(boolean(expr, 8)));
    
    LOG_OPERATION_END("Interpreter::visit(LessEqual *expr)");
}

void Interpreter::visit(NotEqual *expr)
{
    LOG_OPERATION_START("Interpreter::visit(NotEqual *expr)");

    current = BoolPtr(IPLFactory::createBool(boolean(expr, 4)));
    
    LOG_OPERATION_END("Interpreter::visit(NotEqual *expr)");
}

void Interpreter::visit(Or *expr)
{
    LOG_OPERATION_START("Interpreter::visit(Or *expr)");

    current = BoolPtr(IPLFactory::createBool(boolean(expr, 2)));
    
    LOG_OPERATION_END("Interpreter::visit(Or *expr)");
}

void Interpreter::visit(JpgImage *img)
{
    LOG_OPERATION_START("Interpreter::visit(JpgImage *img)");

    current = img->cloneValue();
    
    LOG_OPERATION_END("Interpreter::visit(JpgImage *img)");
}

void Interpreter::visit(PngImage *img)
{
    LOG_OPERATION_START("Interpreter::visit(PngImage *img)");

    current = img->cloneValue();
    
    LOG_OPERATION_END("Interpreter::visit(PngImage *img)");
}

void Interpreter::visit(TIFFImage *img)
{
    LOG_OPERATION_START("Interpreter::visit(TIFFImage *img)");

    current = img->cloneValue();
    
    LOG_OPERATION_END("Interpreter::visit(TIFFImage *img)");
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