#include <memory>
#include <vector>
#include <string>
#include <type_traits>

#include "expr/value/Int.hh"
#include "expr/value/String.hh"
#include "expr/value/Float.hh"
#include "expr/value/Id.hh"
#include "expr/value/Bool.hh"
#include "expr/value/image/Image.hh"
#include "expr/value/image/JpgImage.hh"
#include "expr/value/image/PngImage.hh"
#include "expr/value/image/TiffImage.hh"
#include "ImageType.hh"

#include "expr/Expr.hh"
#include "expr/arithmatic/MinusExpr.hh"
#include "expr/arithmatic/AddExpr.hh"
#include "expr/arithmatic/DivExpr.hh"
#include "expr/arithmatic/MulExpr.hh"
#include "expr/arithmatic/ModExpr.hh"
#include "expr/arithmatic/SubtExpr.hh"

#include "stmt/Statement.hh"
#include "stmt/Block.hh"
#include "stmt/DefVar.hh"
#include "stmt/assignment/Assign.hh"
#include "stmt/assignment/AddAssign.hh"
#include "stmt/assignment/MulAssign.hh"
#include "stmt/assignment/DivAssign.hh"
#include "stmt/assignment/SubAssign.hh"
#include "stmt/assignment/AddAssign.hh"
#include "stmt/assignment/Decrease.hh"
#include "stmt/assignment/Increase.hh"
#include "stmt/DefFunc.hh"
#include "expr/CallFunc.hh"
#include "stmt/PrintExpr.hh"
#include "stmt/ReturnStmt.hh"
#include "stmt/Ifcond.hh"
#include "stmt/Ifelse.hh"
#include "stmt/ForLoop.hh"
#include "stmt/While.hh"

#include "expr/boolean/Not.hh"
#include "expr/boolean/And.hh"
#include "expr/boolean/Or.hh"
#include "expr/boolean/Equal.hh"
#include "expr/boolean/Greater.hh"
#include "expr/boolean/GreaterEqual.hh"
#include "expr/boolean/Less.hh"
#include "expr/boolean/LessEqual.hh"
#include "expr/boolean/NotEqual.hh"

class IPLFactory
{
private:
    using ExprPtr = std::unique_ptr<Expr>;
    using StmtPtr = std::unique_ptr<Statement>;
    using BoolPtr = std::unique_ptr<Bool>;
    using IdPtr = std::unique_ptr<Id>;

public:
    static Id *createId(std::string name)
    {
        return new Id(name);
    }

    static String *createString(std::string str)
    {
        std::string new_str = str.substr(1, str.size() - 2);
        return new String(new_str);
    }

    static String *createEString(std::string str)
    {
        return new String(str);
    }

    static Int *createInt(int value)
    {
        return new Int(value);
    }

    static Float *createFloat(float value)
    {
        return new Float(value);
    }

    static Bool *createBool(bool val)
    {
        return new Bool(val);
    }

    static Image *createImage(std::string filename)
    {
        ImageType type = getImageType(filename);


        Image* img = nullptr; // Declare once

        switch (type)
        {
        case ImageType::JPEG:
        case ImageType::JPG:
            img = new JpgImage();
            break;

        case ImageType::PNG:
            img = new PngImage();
            break;

        case ImageType::TIFF:
            img = new TIFFImage();
            break;

        default:
            throw std::invalid_argument("Unsupported image type for file: " + filename);
        }

        // Load the image after it's created
        img->load(filename);

        return img;
    }

    static Equal *createEqual(
        ExprPtr left,
        ExprPtr right)
    {
        return new Equal(std::move(left), std::move(right));
    }

    static NotEqual *createNotEqual(
        ExprPtr left,
        ExprPtr right)
    {
        return new NotEqual(std::move(left), std::move(right));
    }

    static And *createAnd(
        ExprPtr left,
        ExprPtr right)
    {
        return new And(std::move(left), std::move(right));
    }

    static Or *createOr(
        ExprPtr left,
        ExprPtr right)
    {
        return new Or(std::move(left), std::move(right));
    }

    static Greater *createGreater(
        ExprPtr left,
        ExprPtr right)
    {
        return new Greater(std::move(left), std::move(right));
    }

    static GreaterEqual *createGreaterEqual(
        ExprPtr left,
        ExprPtr right)
    {
        return new GreaterEqual(std::move(left), std::move(right));
    }

    static Less *createLess(
        ExprPtr left,
        ExprPtr right)
    {
        return new Less(std::move(left), std::move(right));
    }

    static LessEqual *createLessEqual(
        ExprPtr left,
        ExprPtr right)
    {
        return new LessEqual(std::move(left), std::move(right));
    }

    static MinusExpr *createMinusExpr(
        ExprPtr left
    )
    {
        return new MinusExpr(std::move(left));
    }

    static Not *createNot(
        ExprPtr left
    )
    {
        return new Not(std::move(left));
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

    static Block *createBlock(
        std::vector<Statement *> stmts)
    {
        return new Block(std::move(stmts));
    }

    static DefVar *createDefVar(
        IdPtr id)
    {
        return new DefVar(std::move(id));
    }

    static DefVar *createDefVar(
        IdPtr id,
        ExprPtr val)
    {
        return new DefVar(std::move(id), std::move(val));
    }

    static Assign *createAssign(
        IdPtr id,
        ExprPtr val)
    {
        return new Assign(std::move(id), std::move(val));
    }

    static AddAssign *createAddAssign(
        IdPtr id,
        ExprPtr val)
    {
        return new AddAssign(std::move(id), std::move(val));
    }

    static MulAssign *createMulAssign(
        IdPtr id,
        ExprPtr val)
    {
        return new MulAssign(std::move(id), std::move(val));
    }

    static DivAssign *createDivAssign(
        IdPtr id,
        ExprPtr val)
    {
        return new DivAssign(std::move(id), std::move(val));
    }

    static SubAssign *createSubAssign(
        IdPtr id,
        ExprPtr val)
    {
        return new SubAssign(std::move(id), std::move(val));
    }

    static Increase *createIncrease(
        IdPtr id)
    {
        return new Increase(std::move(id));
    }

    static Decrease *createDecrease(
        IdPtr id)
    {
        return new Decrease(std::move(id));
    }

    static ForLoop *createForLoop(
        StmtPtr stmt,
        ExprPtr cond,
        StmtPtr update,
        std::vector<Statement *> stmts)
    {
        return new ForLoop(std::move(stmt), std::move(cond), std::move(update), std::move(stmts));
    }

    static While *createWhile(
        ExprPtr cond,
        std::vector<Statement *> stmts)
    {
        return new While(std::move(cond), std::move(stmts));
    }

    static DefFunc *createDefFunc(
        IdPtr id, std::vector<Id *> args, std::vector<Statement *> stmts)
    {
        return new DefFunc(std::move(id), args, stmts);
    }

    static CallFunc *createCallFunc(
        IdPtr funcName, std::vector<Expr *> args)
    {
        return new CallFunc(std::move(funcName), std::move(args));
    }

    static PrintExpr *createPrintExpr(
        std::vector<Expr *> expr)
    {
        return new PrintExpr(std::move(expr));
    }

    static ReturnStmt *createReturnStmt(
        ExprPtr expr)
    {
        return new ReturnStmt(std::move(expr));
    }

    static Ifcond *createIfcond(
        ExprPtr cond, std::vector<Statement *> statements)
    {
        return new Ifcond(std::move(cond), std::move(statements));
    }

    static Ifelse *createIfelse(
        ExprPtr cond, std::vector<Statement *> thanBody, std::vector<Statement *> elseBody)
    {
        return new Ifelse(std::move(cond), std::move(thanBody), std::move(elseBody));
    }
};
