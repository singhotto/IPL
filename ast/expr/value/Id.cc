#include "expr/value/Id.hh"
#include "Log.hh"

Id::Id(const std::string name) : name(std::move(name))
{
    LOG_OPERATION_START("Id::Id");
    LOG_OPERATION_END("Id::Id");
}

std::string Id::getName() const
{
    LOG_OPERATION_START("Id::getName");
    LOG_OPERATION_END("Id::getName");
    return name;
}

std::unique_ptr<Expr> Id::cloneExpr() const
{
    return std::make_unique<Id>(name);
}

std::unique_ptr<Id> Id::cloneId() const
{
    return std::make_unique<Id>(name);
}

void Id::accept(Visitor *visitor)
{
    LOG_OPERATION_START("Id::accept");
    visitor->visit(this);
    LOG_OPERATION_END("Id::accept");
}

Id::~Id()
{
    LOG_OPERATION_START("Id::~Id");
    LOG_OPERATION_END("Id::~Id");
}
