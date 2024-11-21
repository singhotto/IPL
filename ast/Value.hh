#ifndef VALUE__GUARD
#define VALUE__GUARD

#include <iostream>

class Value {
public:
    virtual ~Value() { std::cout<<"Value::~Value\n"; };
    virtual float getValue() const = 0;
};

#endif // VALUE__GUARD
