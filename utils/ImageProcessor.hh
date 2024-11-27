#ifndef IMAGE_PROCESSOR_GUARD
#define IMAGE_PROCESSOR_GUARD

#include "Value.hh"
#include "expr/value/image/Image.hh"
#include "expr/value/image/PngImage.hh"
#include "expr/value/image/JpgImage.hh"
#include "expr/value/image/TiffImage.hh"
#include "expr/value/image/pixel/Pixel.hh"
#include "expr/value/image/pixel/GrayPixel.hh"
#include "expr/value/image/pixel/RgbPixel.hh"
#include "expr/value/image/pixel/RgbaPixel.hh"
#include <vector>
#include <string>
#include <stdexcept> 
#include <cmath>
#include <algorithm>
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

class ImageProcessor
{
private:
    // Private constructor to prevent instantiation
    ImageProcessor();

    // Delete copy constructor and assignment operator to avoid copies
    ImageProcessor(const ImageProcessor&) = delete;
    ImageProcessor& operator=(const ImageProcessor&) = delete;

    std::vector<float> getHistogram(Image* image);
    // void rotateImage(Image& img, char x);

    // void mirror(Image& img, char x);

    void grayscale2color(std::unique_ptr<Value>& image, char x);
public:
    // Static method to access the singleton instance
    static ImageProcessor& getInstance();

    void conv2Grayscale(std::unique_ptr<Value>& image);
    void conv2rgb(std::unique_ptr<Value>& image);
    void conv2rgba(std::unique_ptr<Value>& image);
    void conv2Bin(std::unique_ptr<Value>& image, int threshold = 150);

    void setIntensity(std::unique_ptr<Value>& image, const float intensity);
    void addBrightness(std::unique_ptr<Value>& image, int threshold);
    void negativeImage(std::unique_ptr<Value>& image);
    void histEqualization(std::unique_ptr<Value>& image);
};

#endif