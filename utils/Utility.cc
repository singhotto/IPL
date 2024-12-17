#include "Utility.hh"

// Static method to get the singleton instance
Utility& Utility::getInstance()
{
    static Utility instance; // Guaranteed to be destroyed and instantiated on first use
    return instance;
}

bool Utility::isCorrect(float v)
{
    return v >= 0 && v<=255;
}

bool Utility::isCorrect(float r, float g, float b)
{
    return isCorrect(r) && isCorrect(g) && isCorrect(b);
}

float Utility::correctRange(float value, float min, float max)
{
    if(value<min)
        return min;

    if(value > max)
        return max;

    return value;
}


float* Utility::cast2float(unsigned char *input, int input_size)
{
    float* data = new float[input_size];

    for (int i = 0; i < input_size; i++)
        data[i] = (float)input[i];

    return data;
}

unsigned char* Utility::cast2char(float *input, int input_size)
{
    unsigned char* data = new unsigned char[input_size];

    for (int i = 0; i < input_size; i++)
        data[i] = (unsigned char)input[i];

    return data;
}