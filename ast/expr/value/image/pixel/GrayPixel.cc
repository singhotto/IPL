#include "expr/value/image/pixel/GrayPixel.hh"

GrayPixel::GrayPixel(float *v)
{
    Pixel::value = v;
}

void GrayPixel::setValue(const float newValue)
{
    *(Pixel::value) = Utility::getInstance().correctRange(newValue);
}

void GrayPixel::operator+=(const float c)
{
    *(Pixel::value) = getValue() + c;
}

void GrayPixel::operator*=(const float c)
{
    *(Pixel::value) = getValue() * c;
}

float GrayPixel::getValue() const
{
    return *(Pixel::value);
}

void GrayPixel::correctPixel()
{
    setValue(getValue());
}

void GrayPixel::print() const
{
    std::cout<<"Gray Pixel value : "<<getValue()<<"\n";
}
