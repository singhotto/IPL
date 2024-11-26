#ifndef RGBA_PIXEL__GUARD
#define RGBA_PIXEL__GUARD

#include "expr/value/image/pixel/RgbPixel.hh"

class RgbaPixel : public RgbPixel
{
private:
    float *a;

public:
    RgbaPixel(float *r, float *g, float *b, float *a);

    void setAlpha(const float alpha);

    float getAlpha() const;

    void print() const override;
};

#endif