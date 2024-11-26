#include "Load.hh"
#include "Log.hh"

Load::Load(const std::string path) : path(path)
{
    LOG_OPERATION_START("Load::Load(string)");
    LOG_OPERATION_END("Load::Load(string)");
}

Load::~Load()
{
    LOG_OPERATION_START("Load::~Load()");
    LOG_OPERATION_END("Load::~Load()");
}

std::string Load::getPath() const
{
    return path;
}

std::unique_ptr<Expr> Load::cloneExpr() const
{
    return std::make_unique<Load>(*this);
}

void Load::accept(Visitor *visitor)
{
    LOG_OPERATION_START("Load::accept");
    visitor->visit(this);
    LOG_OPERATION_END("Load::accept");
}
