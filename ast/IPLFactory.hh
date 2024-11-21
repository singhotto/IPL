#include <memory>
#include <vector>
#include <string>
#include <type_traits>

#include "expr/Int.hh"
#include "expr/Float.hh"
#include "expr/Expr.hh"
#include "expr/AddExpr.hh"
#include "expr/DivExpr.hh"
#include "expr/MulExpr.hh"
#include "expr/ModExpr.hh"
#include "expr/SubtExpr.hh"
#include "expr/Id.hh"
#include "stmt/Statement.hh"
#include "stmt/DefVar.hh"
#include "stmt/DefFunc.hh"
#include "expr/CallFunc.hh"
#include "stmt/PrintExpr.hh"
#include "stmt/ReturnStmt.hh"

class IPLFactory
{
private:
    using ExprPtr = std::unique_ptr<Expr>;

public:
    static Id *createId(std::string name)
    {
        return new Id(name);
    }

    template <typename T>
    static Expr* createValue(T value) {
        if constexpr (std::is_same_v<T, int>) {
            return new Int(value);
        } else if constexpr (std::is_same_v<T, float>) {
            return new Float(value);
        } else {
            static_assert(false, "Unsupported type!");
        }
    }

    static Int *createInt(int value)
    {
        return new Int(value);
    }

    static Float *createFloat(float value)
    {
        return new Float(value);
    }

    static AddExpr *createAddExpr(
        ExprPtr left,
        ExprPtr right)
    {
        return new AddExpr(std::move(left), std::move(right));
    }

    static DivExpr *createDivExpr(
        ExprPtr left,
        ExprPtr right)
    {
        return new DivExpr(std::move(left), std::move(right));
    }

    static MulExpr *createMulExpr(
        ExprPtr left,
        ExprPtr right)
    {
        return new MulExpr(std::move(left), std::move(right));
    }

    static SubtExpr *createSubtExpr(
        ExprPtr left,
        ExprPtr right)
    {
        return new SubtExpr(std::move(left), std::move(right));
    }

    static ModExpr *createModExpr(
        ExprPtr left,
        ExprPtr right)
    {
        return new ModExpr(std::move(left), std::move(right));
    }


    static DefVar *createDefVar(
        std::unique_ptr<Id> id,
        ExprPtr val)
    {
        return new DefVar(std::move(id), std::move(val));
    }

    static DefFunc *createDefFunc(
        std::unique_ptr<Id>  id, std::vector<Id*> args, std::vector<Statement*> stmts)
    {
        return new DefFunc(std::move(id), args, stmts);
    }

    static DefFunc *createDefFunc(
        std::unique_ptr<Id> id, std::vector<Statement*> stmts)
    {
        return new DefFunc(std::move(id), stmts);
    }

    static CallFunc *createCallFunc(
        std::unique_ptr<Id> funcName, std::vector<Id *> args)
    {
        return new CallFunc(std::move(funcName), std::move(args));
    }


    static CallFunc *createCallFunc(
        std::unique_ptr<Id> funcName)
    {
        return new CallFunc(std::move(funcName));
    }

    static PrintExpr *createPrintExpr(
        ExprPtr expr)
    {
        return new PrintExpr(std::move(expr));
    }

    static ReturnStmt *createReturnStmt(
        ExprPtr expr)
    {
        return new ReturnStmt(std::move(expr));
    }
};
