#include "stmt/DefFunc.hh"
#include "Log.hh" 

DefFunc::~DefFunc()
{
    LOG_OPERATION_START("DefFunc::~DefFunc");
    LOG_OPERATION_END("DefFunc::~DefFunc");
}

DefFunc::DefFunc(DefFunc &&other) noexcept
    : funcName(std::move(other.funcName)),
      args(std::move(other.args)),
      statements(std::move(other.statements))
{
}

DefFunc &DefFunc::operator=(DefFunc &&other) noexcept
{
    if (this != &other)
    {
        funcName = std::move(other.funcName);
        args = std::move(other.args);
        statements = std::move(other.statements);
    }
    return *this;
}

DefFunc::DefFunc(IdPtr id, std::vector<Id *> args, std::vector<Statement *> statements) : funcName(std::move(id))
{
    LOG_OPERATION_START("DefFunc::DefFunc(IdPtr, std::vector<Id *>, std::vector<Statement*>&&)");

    this->args.reserve(args.size());
    for (auto i : args)
    {
        this->args.push_back(IdPtr(i));
    }

    this->statements.reserve(statements.size());
    for (auto i : statements)
    {
        this->statements.push_back(StmtPtr(i));
    }

    LOG_OPERATION_END("DefFunc::DefFunc(IdPtr, std::vector<Id *>, std::vector<Statement*>&&)");
}

std::string DefFunc::getName()
{
    LOG_OPERATION_START("DefFunc::getName");
    std::string name = funcName->getName();
    LOG_OPERATION_END("DefFunc::getName");
    return name;
}

std::vector<Id *> DefFunc::funcArgs()
{
    LOG_OPERATION_START("DefFunc::funcArgs");
    std::vector<Id *> temp;
    temp.reserve(args.size());
    for (IdPtr &id : args)
    {
        temp.push_back(id.get());
    }
    LOG_OPERATION_END("DefFunc::funcArgs");
    return temp;
}

std::vector<Statement *> DefFunc::funcStatements()
{
    LOG_OPERATION_START("DefFunc::funcStatements");
    std::vector<Statement *> temp;
    temp.reserve(statements.size());
    for (StmtPtr &stmt : statements)
    {
        temp.push_back(stmt.get());
    }
    LOG_OPERATION_END("DefFunc::funcStatements");
    return temp;
}

void DefFunc::print() const
{
    std::cout << funcName->getName();
}

std::unique_ptr<Value> DefFunc::cloneValue() const
{
    std::vector<Id*> clonedArgs;
    for (const auto &arg : args)
    {
        clonedArgs.push_back(new Id(arg->getName())); // Clone each argument
    }

    std::vector<Statement*> clonedStatements;
    for (const auto &stmt : statements)
    {
        clonedStatements.push_back(stmt->clone().release()); // Clone each statement
    }

    return std::make_unique<DefFunc>(
        std::make_unique<Id>(funcName->getName()), // Clone funcName
        clonedArgs,        // Clone the arguments
        clonedStatements   // Clone the statements
    );
}

std::unique_ptr<Statement> DefFunc::clone() const
{
    std::vector<Id*> clonedArgs;
    for (const auto &arg : args)
    {
        clonedArgs.push_back(new Id(arg->getName())); // Clone each argument
    }


    std::vector<Statement*> clonedStatements;
    for (const auto &stmt : statements)
    {
        clonedStatements.push_back(stmt->clone().release()); // Clone each statement
    }

    return std::make_unique<DefFunc>(
        std::make_unique<Id>(funcName->getName()), // Clone funcName
        clonedArgs,        // Clone the arguments
        clonedStatements   // Clone the statements
    );
}

void DefFunc::accept(Visitor *visitor)
{
    LOG_OPERATION_START("DefFunc::accept");
    visitor->visit(this);
    LOG_OPERATION_END("DefFunc::accept");
}
