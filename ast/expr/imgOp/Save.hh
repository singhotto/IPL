#ifndef SAVE__GUARD
#define SAVE__GUARD

#include "expr/Expr.hh"
#include "Visitor.hh"
#include <string>

class Save : virtual public Expr {
private:
    ExprPtr path;
    ExprPtr img;
public:
    Save(ExprPtr path, ExprPtr img);
    ~Save();

    ExprPtr getImage();
    ExprPtr getPath();
    ExprPtr cloneExpr() const override;

    void accept(Visitor* visitor) override;
};

#endif 
