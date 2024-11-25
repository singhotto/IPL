#ifndef EXPR__GUARD
#define EXPR__GUARD

#include "Node.hh"
#include "Log.hh"
#include <iostream> 

class Visitor; // Forward declaration

class Expr : virtual public Node {
protected:
    using ExprPtr = std::unique_ptr<Expr>;
public:
    virtual ~Expr() { 
        LOG_OPERATION_START("Expr::~Expr()");
        LOG_OPERATION_END("Expr::~Expr()");
    };
    virtual std::unique_ptr<Expr> cloneExpr() const = 0;
};

#endif // EXPR__GUARD
