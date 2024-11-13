#ifndef ASTNODE__GUARD
#define ASTNODE__GUARD

#include "../Visitor.hh"

class ASTNode
{
public:
    virtual ~ASTNode() = default;
    virtual void accept(Visitor& visitor) = 0;
};
#endif