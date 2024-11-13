#ifndef IPLINTERPRETER__GUARD
#define IPLINTERPRETER__GUARD

#include "IPLContext.hh"
#include "Visitor.hh"
#include "ast/VarNode.hh"

class IPLInterpreter : public Visitor
{
private:
    IPLContext& context;

public:
    IPLInterpreter(IPLContext& context);

    void visit(VarNode& node) override;
};

#endif