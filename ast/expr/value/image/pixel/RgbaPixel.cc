#include "expr/value/image/pixel/RgbaPixel.hh"

RgbaPixel::RgbaPixel(float *r, float *g, float *b, float *a) : RgbPixel(r, g, b), a(a)
{
}

void RgbaPixel::setAlpha(const float alpha)
{
    *this->a = Utility::getInstance().correctRange(alpha);
}

float RgbaPixel::getAlpha() const
{
    return *a;
}

void RgbaPixel::print() const
{
    std::cout<<"RGBA Pixel: ("<<getR()<<", "<<getG()<<", "<<getB()<<", "<<getAlpha()<<") \n";
}
