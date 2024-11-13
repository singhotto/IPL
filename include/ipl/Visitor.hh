#ifndef VISITOR__GUARD
#define VISITOR__GUARD

#include "ast/VarNode.hh"

class Visitor
{
public:
    virtual ~Visitor() = default;

    virtual void visit(VarNode& node) = 0;
};


#endif