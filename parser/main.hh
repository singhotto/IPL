#include <iostream>
#include <string>
#include "all_headers.hh"

#define U(X, Y) std::move(std::unique_ptr<X>(Y))

using StmtsVec = std::vector<Statement*>;
using ExprVec = std::vector<Expr*>;

inline void
yyerror(const char* msg) {
  std::cerr << msg << std::endl;
  exit(1);
}
