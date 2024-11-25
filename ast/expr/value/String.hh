#ifndef STRING__GUARD
#define STRING__GUARD

#include<string>
#include "Value.hh"
#include "expr/Expr.hh"
#include "Visitor.hh" 

class Visitor;

class String : virtual public Value, virtual public Expr {
private:
    std::string str;
public:
    explicit String(const std::string str);
    ~String();
    std::string getStr() const;
    void print() const override;
    std::unique_ptr<Value> cloneValue() const override;
    std::unique_ptr<Expr> cloneExpr() const override;
    void accept(Visitor* visitor) override;
};

#endif 
