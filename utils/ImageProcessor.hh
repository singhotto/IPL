#ifndef IMAGE_PROCESSOR_GUARD
#define IMAGE_PROCESSOR_GUARD

#include "expr/value/image/Image.hh"
#include "expr/value/image/PngImage.hh"
#include "expr/value/image/JpgImage.hh"
#include "expr/value/image/TiffImage.hh"
#include "expr/value/image/Pixel/Pixel.hh"
#include "expr/value/image/Pixel/GrayPixel.hh"
#include "expr/value/image/Pixel/RgbPixel.hh"
#include "expr/value/image/Pixel/RgbaPixel.hh"
#include <vector>
#include <string>
#include <stdexcept> 
#include <cmath>
#include <algorithm>
#include <cstdlib> 
#include <ctime> 

class ImageProcessor
{
private:
    // Private constructor to prevent instantiation
    ImageProcessor();

    // Delete copy constructor and assignment operator to avoid copies
    ImageProcessor(const ImageProcessor&) = delete;
    ImageProcessor& operator=(const ImageProcessor&) = delete;

    std::vector<float> getHistogram(std::unique_ptr<Image>& image);
    // void rotateImage(Image& img, char x);

    // void mirror(Image& img, char x);

    void grayscale2color(std::unique_ptr<Image>& image, char x);
public:
    // Static method to access the singleton instance
    static ImageProcessor& getInstance();

    void conv2Grayscale(std::unique_ptr<Image>& image);
    void conv2rgb(std::unique_ptr<Image>& image);
    void conv2rgba(std::unique_ptr<Image>& image);

    void toBinary(Image* image, int threshold = 150);
    void setIntensity(std::unique_ptr<Image>& image, const float intensity);
    void addBrightness(std::unique_ptr<Image>& image, int threshold);
    void negativeImage(std::unique_ptr<Image>& image);
    void histEqualization(std::unique_ptr<Image>& image);
};

#endif