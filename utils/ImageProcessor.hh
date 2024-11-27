#ifndef IMAGE_PROCESSOR_GUARD
#define IMAGE_PROCESSOR_GUARD

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

    void grayscale2color(Image* image, char x);
public:
    // Static method to access the singleton instance
    static ImageProcessor& getInstance();

    void conv2Grayscale(Image* image);
    void conv2rgb(Image*  image);
    void conv2rgba(Image*  image);
    void conv2Bin(Image* image, int threshold = 150);

    void setIntensity(Image*  image, const float intensity);
    void addBrightness(Image*  image, int threshold);
    void negativeImage(Image*  image);
    void histEqualization(Image*  image);
};

#endif