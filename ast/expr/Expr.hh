#ifndef EXPR__GUARD
#define EXPR__GUARD

#include "../Node.hh" // Required for inheritance
#include <iostream> 

class Visitor; // Forward declaration

class Expr : virtual public Node {
protected:
    using ExprPtr = std::unique_ptr<Expr>;
public:
    virtual ~Expr() { std::cout<<"Expr::~Expr\n"; };
};

#endif // EXPR__GUARD
