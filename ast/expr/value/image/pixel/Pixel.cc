#include "expr/value/image/pixel/Pixel.hh"

float Pixel::getValue() const
{
    return *value;
}

void Pixel::setValue(const float newValue)
{
    *this->value = Utility::getInstance().correctRange(newValue);
}

void Pixel::operator+=(const float c)
{
    *this->value = getValue() + c;
}

void Pixel::operator*=(const float c)
{
    *this->value = getValue() * c;
}