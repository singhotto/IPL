#include "Save.hh"
#include "Log.hh"

Save::Save(ExprPtr path, ExprPtr img) : path(std::move(path)), img(std::move(img))
{
    LOG_OPERATION_START("Save::Save(string)");
    LOG_OPERATION_END("Save::Save(string)");
}

Save::~Save()
{
    LOG_OPERATION_START("Save::~Save()");
    LOG_OPERATION_END("Save::~Save()");
}

std::unique_ptr<Expr> Save::getImage()
{
    return std::move(img);
}

std::unique_ptr<Expr> Save::getPath()
{
    return std::move(path);
}

std::unique_ptr<Expr> Save::cloneExpr() const
{
    return std::make_unique<Save>(path->cloneExpr(), img->cloneExpr());
}

void Save::accept(Visitor *visitor)
{
    LOG_OPERATION_START("Bool::accept");
    visitor->visit(this);
    LOG_OPERATION_END("Bool::accept");
}
