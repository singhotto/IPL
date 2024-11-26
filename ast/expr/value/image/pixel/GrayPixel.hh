#ifndef GRAY_PIXEL__GUARD
#define GRAY_PIXEL__GUARD

#include "expr/value/image/pixel/Pixel.hh"

class GrayPixel : public Pixel
{
public:
    GrayPixel(float* v);
    
    void setValue(const float newValue) override;

    void operator+=(const float c) override;

    void operator*=(const float c) override;

    float getValue() const;

    void correctPixel() override;
    void print() const override;
};

#endif