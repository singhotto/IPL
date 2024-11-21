#ifndef STATEMENT__GUARD
#define STATEMENT__GUARD

#include "../Node.hh" 
#include <memory>
#include <iostream>

class Visitor; // Forward declaration

class Statement : virtual public Node {
public:
    virtual ~Statement() { std::cout<<"~Statement()\n"; };
};

#endif
