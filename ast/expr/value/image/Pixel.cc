#include "Pixel.hh"

Pixel::Pixel() : data{nullptr, nullptr, nullptr, nullptr}, channels(0)
{
}

Pixel::Pixel(float *r) : channels(1)
{
    data[0] = r;
    for (int i = 1; i < 4; i++)
        data[i] = nullptr;
}

Pixel::Pixel(float *r, float *g) : channels(2)
{
    data[0] = r;
    data[1] = g;
    for (int i = 2; i < 4; i++)
        data[i] = nullptr;
}

Pixel::Pixel(float *r, float *g, float *b) : channels(3)
{
    data[0] = r;
    data[1] = g;
    data[2] = b;
    for (int i = 3; i < 4; i++)
        data[i] = nullptr;
}

Pixel::Pixel(float *r, float *g, float *b, float *a) : channels(4)
{
    data[0] = r;
    data[1] = g;
    data[2] = b;
    data[3] = a;
}

Pixel::Pixel(const Pixel &other) : channels(other.channels)
{
    for (int i = 0; i < 4; ++i)
    {
        data[i] = other.data[i];
    }
}

Pixel::Pixel(Pixel &&other) noexcept : channels(other.channels)
{
    for (int i = 0; i < 4; ++i)
    {
        data[i] = other.data[i];
        other.data[i] = nullptr;
    }
    other.channels = 0;
}

Pixel &Pixel::operator=(const Pixel &other)
{
    if (this == &other)
        return *this;

    channels = other.channels;
    for (int i = 0; i < 4; ++i)
    {
        data[i] = other.data[i];
    }
    return *this;
}

Pixel &Pixel::operator=(Pixel &&other) noexcept
{
    if (this == &other)
        return *this;

    channels = other.channels;
    for (int i = 0; i < 4; ++i)
    {
        data[i] = other.data[i];
        other.data[i] = nullptr;
    }
    other.channels = 0;

    return *this;
}

const float *const *Pixel::begin() const
{
    return data;
}

const float *const *Pixel::end() const
{
    int mx = channels==4 ? 3 : channels;
    return data + mx;
}

float **Pixel::begin()
{
    return data;
}

float **Pixel::end()
{
    int mx = channels==4 ? 3 : channels;
    return data + mx;
}

float &Pixel::operator[](int i)
{
    assert(i > -1 && i < 4);

    return *data[i];
}

int Pixel::getChannels() const
{
    return channels;
}

void Pixel::copy(Pixel &other)
{
    assert(channels == other.channels);
    for (int i = 0; i < channels; i++)
    {
        *data[i] = other[i];
    }
}

void Pixel::setValue(float value)
{
    int mx = channels == 4 ? 3 : channels;
    for (int i = 0; i < mx; i++)
    {
        *data[i] = value;
    }
}