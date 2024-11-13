#ifndef IPLCONTEXT__GUARD
#define IPLCONTEXT__GUARD

#include <variant>
#include <string>
#include <unordered_map>

using VarValue = std::variant<int, float, char>;

class IPLContext
{
private:
    std::unordered_map<std::string, VarValue> variables;
    static IPLContext* instance;

    IPLContext() = default;
    
    IPLContext(const IPLContext&) = delete;
    IPLContext& operator=(const IPLContext&) = delete;
    
public:
    static IPLContext& getInstance();

    template <typename T>
    void setVariable(const std::string& name, const T& value);

    template <typename T>
    T getVariable(const std::string& name) const;

    bool hasVariable(const std::string& name) const;
};

IPLContext* IPLContext::instance = nullptr;

IPLContext& IPLContext::getInstance()
{
    if (instance == nullptr)
    {
        instance = new IPLContext();
    }
    return *instance;
}

template <typename T>
void IPLContext::setVariable(const std::string& name, const T& value)
{
    variables[name] = value;
}

template <typename T>
T IPLContext::getVariable(const std::string& name) const
{
    auto it = variables.find(name);
    if (it != variables.end())
    {
        return std::get<T>(it->second);
    }
    throw std::runtime_error("Variable not found.");
}

bool IPLContext::hasVariable(const std::string& name) const
{
    return variables.find(name) != variables.end();
}

#endif
