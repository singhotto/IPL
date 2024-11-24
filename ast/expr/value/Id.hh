#ifndef ID__GUARD
#define ID__GUARD

#include<string>
#include "../Expr.hh"
#include "../../Visitor.hh" 

class Visitor;

class Id : virtual public Expr {
private:
    std::string name;
public:
    explicit Id(const std::string name);
    ~Id();
    std::string getName() const;
    std::unique_ptr<Expr> cloneExpr() const override;
    std::unique_ptr<Id> cloneId() const;
    void accept(Visitor* visitor) override;
};

#endif 
