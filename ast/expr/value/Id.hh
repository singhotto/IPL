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
    void accept(Visitor* visitor) override;
};

#endif // INT__GUARD
