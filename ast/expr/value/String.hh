#ifndef STRING__GUARD
#define STRING__GUARD

#include<string>
#include "../../Value.hh"
#include "../Expr.hh"
#include "../../Visitor.hh" // Only necessary to define `accept`

class Visitor;

class String : virtual public Value, virtual public Expr {
private:
    std::string str;
public:
    explicit String(const std::string str);
    ~String();
    std::string getStr() const;
    void accept(Visitor* visitor) override;
};

#endif // INT__GUARD
