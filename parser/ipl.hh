#include <iostream>
#include <string>
#include "all_headers.hh"

#define U(X, Y) std::move(std::unique_ptr<X>(Y))

using StmtsVec = std::vector<Statement*>;
using IdVec = std::vector<Id*>;
using ExprVec = std::vector<Expr*>;
extern int yylineno;


inline int
yyerror(const char* msg) {
  std::cerr << "Syntax error at line " << yylineno << ": " << msg << std::endl;
  exit(1);
}


