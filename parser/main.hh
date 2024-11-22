#include <iostream>
#include <string>
#include "../ast/Interpreter.hh"
#include "../ast/IPLFactory.hh"
#include "../ast/Node.hh"
#include "../ast/Value.hh"
#include "../ast/Visitor.hh"
#include "../ast/expr/Expr.hh"
#include "../ast/expr/value/Int.hh"
#include "../ast/expr/value/String.hh"
#include "../ast/expr/value/Float.hh"
#include "../ast/expr/value/Id.hh"
#include "../ast/expr/arithmatic/AddExpr.hh"
#include "../ast/expr/arithmatic/SubtExpr.hh"
#include "../ast/expr/arithmatic/DivExpr.hh"
#include "../ast/expr/arithmatic/ModExpr.hh"
#include "../ast/expr/arithmatic/MulExpr.hh"
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

