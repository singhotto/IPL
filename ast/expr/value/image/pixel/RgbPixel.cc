#include "expr/value/image/pixel/RgbPixel.hh"

RgbPixel::RgbPixel(float *r, float *g, float *b) : g(g), b(b)
{
    Pixel::value = r;
}

void RgbPixel::setValue(const float newValue)
{
    Pixel::setValue(newValue);
    *this->g = Utility::getInstance().correctRange(newValue);
    *this->b = Utility::getInstance().correctRange(newValue);
}

void RgbPixel::setRGB(const float r, const float g, const float b)
{
    Pixel::setValue(r);
    *this->g = Utility::getInstance().correctRange(g);
    *this->b = Utility::getInstance().correctRange(b);
}

void RgbPixel::operator+=(const float c)
{
    Pixel::operator+=(c);
    *this->g = getG() + c;
    *this->b = getB() + c;
}

void RgbPixel::operator*=(const float c)
{
    Pixel::operator*=(c);
    *this->g = getG() * c;
    *this->b = getB() * c;
}

float RgbPixel::getR() const
{
    return Pixel::getValue();
}

float RgbPixel::getG() const
{
    return *g;
}

float RgbPixel::getB() const
{
    return *b;
}

void RgbPixel::correctPixel()
{
    setRGB(getR(), getG(), getB());
}


void RgbPixel::print() const
{
    std::cout<<"RGB Pixel: ("<<getR()<<", "<<getG()<<", "<<getB()<<") \n";
}
