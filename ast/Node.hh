#ifndef NODE__GUARD
#define NODE__GUARD

#include<memory>
class Visitor; // Forward declaration

class Node {
public:
    virtual ~Node() = default;  // Virtual destructor
    Node() = default;
    virtual void accept(Visitor* visitor) = 0;  // Pure virtual function for visitor pattern
};

#endif // NODE__GUARD
