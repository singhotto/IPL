#include <iostream>
#include <string>
#include "../ast/Interpreter.hh"
#include "../ast/IPLFactory.hh"
#include "../ast/Node.hh"
#include "../ast/Value.hh"
#include "../ast/Visitor.hh"
#include "../ast/expr/Expr.hh"
#include "../ast/expr/Int.hh"
#include "../ast/expr/Float.hh"
#include "../ast/expr/AddExpr.hh"
#include "../ast/expr/SubtExpr.hh"
#include "../ast/expr/DivExpr.hh"
#include "../ast/expr/ModExpr.hh"
#include "../ast/expr/MulExpr.hh"
#include "../ast/expr/Id.hh"
#include "../ast/stmt/DefFunc.hh"
#include "../ast/stmt/DefVar.hh"
#include "../ast/stmt/PrintExpr.hh"
#include "../ast/stmt/ReturnStmt.hh"
#include "../ast/stmt/Statement.hh"

#define U(X, Y) std::move(std::unique_ptr<X>(Y))

inline void
yyerror(const char* msg) {
  std::cerr << msg << std::endl;
  exit(1);
}

