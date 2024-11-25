#include "stmt/Block.hh"
#include "Log.hh" // Include the macros header

Block::~Block()
{
    LOG_OPERATION_START("Block::~Block");
    LOG_OPERATION_END("Block::~Block");
}

Block::Block(std::vector<Statement *> statements)
{
    LOG_OPERATION_START("Block::Block(std::vector<Statement*>)");

    this->statements.reserve(statements.size());
    for (auto i : statements)
    {
        this->statements.push_back(StmtPtr(i));
    }

    LOG_OPERATION_END("Block::Block(std::vector<Statement*>)");
}

std::vector<Statement *> Block::getStatemets()
{
    LOG_OPERATION_START("Block::getStatemets");
    std::vector<Statement *> temp;
    temp.reserve(statements.size());
    for (StmtPtr &stmt : statements)
    {
        temp.push_back(stmt.get());
    }
    LOG_OPERATION_END("Block::getStatemets");
    return temp;
}

std::unique_ptr<Statement> Block::clone() const
{
    std::vector<Statement*> clonedStatements;
    for (const auto &stmt : statements)
    {
        clonedStatements.push_back(stmt->clone().release()); 
    }
    return std::make_unique<Block>(clonedStatements);
}

void Block::accept(Visitor *visitor)
{
    LOG_OPERATION_START("Block::accept");
    visitor->visit(this);
    LOG_OPERATION_END("Block::accept");
}
