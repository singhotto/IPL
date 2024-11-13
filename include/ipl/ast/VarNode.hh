#ifndef VARNODE__GUARD
#define VARNODE__GUARD

#include<string>
#include<memory>
#include "ASTNode.hh"

class VarNode : public ASTNode
{
private:
    std::string var_name;
    std::shared_ptr<ASTNode> expr;
public:
    VarNode(const std::string& name, std::shared_ptr<ASTNode> expr);

    void accept(Visitor& visitor) override;
};
#endif