#ifndef UTILITY__GUARD
#define UTILITY__GUARD

class Utility
{
private:
    // Private constructor to prevent instantiation
    Utility() = default;

    // Disable copy constructor and assignment operator
    Utility(const Utility&) = delete;
    Utility& operator=(const Utility&) = delete;

public:
    // Static method to get the singleton instance
    static Utility& getInstance();

    // Method to correct value range
    float correctRange(float value, float min = 0.0f, float max = 255.0f);
    static float* cast2float(unsigned char *input, int input_size);
    static unsigned char* cast2char(float *input, int input_size);
};

#endif // UTILITY__GUARD
