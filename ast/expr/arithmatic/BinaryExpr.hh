#ifndef BINEXPR__GUARD
#define BINEXPR__GUARD

#include "expr/Expr.hh"
#include <iostream>
#include "Visitor.hh"
#include "Log.hh"

class BinaryExpr : virtual public Expr {
public:
    virtual ~BinaryExpr() { 
        LOG_OPERATION_START("Expr::~Expr()");
        LOG_OPERATION_END("Expr::~Expr()");
    };
    virtual Expr* getLeft() const = 0;
    virtual Expr* getRight() const = 0;
};

#endif // ADDEXPR__GUARD
