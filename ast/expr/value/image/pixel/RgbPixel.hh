#ifndef RGB_PIXEL__GUARD
#define RGB_PIXEL__GUARD

#include "expr/value/image/pixel/Pixel.hh"

class RgbPixel : public Pixel
{
protected:
    float *g;
    float *b;

public:
    RgbPixel(float *r, float *g, float *b);
    ~RgbPixel() = default;

    void setValue(const float newValue) override;
    void setRGB(const float r, const float g, const float b);

    void operator+=(const float c) override;

    void operator*=(const float c) override;

    float getR() const;
    float getG() const;
    float getB() const;

    void correctPixel() override;
    void print() const override;
};
#endif