#include<iostream>
#include<string>
#include<memory>
#include "Interpreter.hh"
#include "IPLFactory.hh"
#include "Node.hh"
#include "expr/Expr.hh"
#include "expr/AddExpr.hh"
#include "expr/Int.hh"
#include "expr/Id.hh"
#include "stmt/Statement.hh"
#include "stmt/DefVar.hh"
#include "stmt/DefFunc.hh"
#include "stmt/PrintExpr.hh"
#include "stmt/ReturnStmt.hh"

#include <vector>

using IdPtr = std::unique_ptr<Id>;
using ExprPtr = std::unique_ptr<Expr>;

int main(){
    Interpreter& eval = Interpreter::getInstance();


    std::unique_ptr<Int> ib(IPLFactory::createInt(8));
    IdPtr funcName(IPLFactory::createId("a"));
    IdPtr aa(IPLFactory::createId("a"));
    IdPtr res(IPLFactory::createId("c"));
    auto var_a = IPLFactory::createDefVar(std::move(funcName), std::move(ib));
    auto rtn = IPLFactory::createReturnStmt(std::move(aa));
    // // // Expr* addExp2 = IPLFactory::createAddExpr(addExp1, c);
    // // // Expr* mulExpr1 = IPLFactory::createMulExpr(addExp2, d);
    // // // Expr* sub = IPLFactory::createSubtExpr(mulExpr1, e);
    // // // Expr* divExpr2 = IPLFactory::createDivExpr(mulExpr1,f);
    // std::cout<<"Var Defined\n";
    // eval.visit(var_a);

    // IdPtr funcName1(IPLFactory::createId("a"));
    // auto print = IPLFactory::createPrintExpr(std::move(funcName1));
    // auto print1 = IPLFactory::createPrintExpr(ida);
    // auto print2 = IPLFactory::createPrintExpr(ida);

    // std::vector<std::unique_ptr<Id>> args;

    std::vector<Statement*> statems;
    statems.push_back(var_a);
    statems.push_back(rtn);
    // statems.push_back(print);

    IdPtr funcN1(IPLFactory::createId(std::string("foo")));
    IdPtr funcN2(IPLFactory::createId(std::string("foo")));

    auto  foo = (IPLFactory::createDefFunc(std::move(funcN1), statems));
    
    std::unique_ptr<CallFunc> call_foo(IPLFactory::createCallFunc(std::move(funcN2)));


    auto var_c = IPLFactory::createDefVar(std::move(res), std::move(call_foo));


    IdPtr funcName1(IPLFactory::createId("c"));
    auto print = IPLFactory::createPrintExpr(std::move(funcName1));

    // eval.visit(print);
    eval.visit(foo);
    eval.visit(var_c);
    eval.visit(print);
    // eval.visit(call_foo);

    // // std::cout<<eval->getResult()<<"\n";

    // eval.visit(foo);
    // eval.visit(call_foo);
    // eval.visit(print2);
    // delete eval;
    
    return 0;
}
