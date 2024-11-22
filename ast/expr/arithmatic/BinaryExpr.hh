#ifndef BINEXPR__GUARD
#define BINEXPR__GUARD

#include "../Expr.hh"
#include <iostream>
#include "../../Visitor.hh"

class BinaryExpr : virtual public Expr {
public:
    virtual ~BinaryExpr() { std::cout<<"~BinaryExpr()\n"; };
    virtual Expr* getLeft() const = 0;
    virtual Expr* getRight() const = 0;
};

#endif // ADDEXPR__GUARD
