#ifndef BOOLEXPR__GUARD
#define BOOLEXPR__GUARD

#include "../Expr.hh"
#include <iostream>
#include "../../Visitor.hh"
#include "../../Log.hh"

class BoolExpr : virtual public Expr {
public:
    virtual ~BoolExpr() { 
        LOG_OPERATION_START("BoolExpr::~BoolExpr()");
        LOG_OPERATION_END("BoolExpr::~BoolExpr()");
    };
    virtual Expr* getLeft() const = 0;
    virtual Expr* getRight() const = 0;
};

#endif 
