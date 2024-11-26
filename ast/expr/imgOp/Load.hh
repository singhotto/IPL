#ifndef LOAD__GUARD
#define LOAD__GUARD

#include "expr/Expr.hh"
#include "Visitor.hh"
#include <string>

class Load : virtual public Expr {
private:
    std::string path;
public:
    Load(const std::string path);
    ~Load();

    std::string getPath() const;
    std::unique_ptr<Expr> cloneExpr() const override;

    void accept(Visitor* visitor) override;
};

#endif 
