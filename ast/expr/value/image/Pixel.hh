#ifndef PIXEL__GUARD
#define PIXEL__GUARD

#include <cassert>
#include <iterator>

class Pixel
{
private:
    float *data[4];
    int channels;

public:
    Pixel();
    Pixel(float *r);
    Pixel(float *r, float *g);
    Pixel(float *r, float *g, float *b);
    Pixel(float *r, float *g, float *b, float *a);

    Pixel(const Pixel &other);
    Pixel(Pixel &&other) noexcept;

    Pixel &operator=(const Pixel &other);
    Pixel &operator=(Pixel &&other) noexcept;

    const float *const *begin() const;
    const float *const *end() const;

    float** begin();
    float** end();

    ~Pixel() = default;

    float &operator[](int i);

    int getChannels() const;

    void copy(Pixel &other);

    void setValue(float value);
};

#endif