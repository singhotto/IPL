#ifndef PIXEL__GUARD
#define PIXEL__GUARD

#include "Utility.hh"
#include <iostream>

class Pixel
{
protected:
    float *value;

public:
    virtual ~Pixel() = default;

    virtual void setValue(const float newValue) = 0;

    virtual void operator+=(const float c) = 0;

    virtual void operator*=(const float c) = 0;

    float getValue() const;
    
    virtual void correctPixel() = 0;
    virtual void print() const = 0;
};

#endif