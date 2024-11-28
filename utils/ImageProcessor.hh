#ifndef IMAGE_PROCESSOR_GUARD
#define IMAGE_PROCESSOR_GUARD

#include "Value.hh"
#include "ChartGenerator/Chart.hh"
#include "expr/value/image/Image.hh"
#include "expr/value/image/PngImage.hh"
#include "expr/value/image/JpgImage.hh"
#include "expr/value/image/TiffImage.hh"
#include "expr/value/image/Pixel.hh"
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
    ImageProcessor(const ImageProcessor &) = delete;
    ImageProcessor &operator=(const ImageProcessor &) = delete;

    std::vector<float> getHistogram(Image *image);
    Image *createNewImage(const Image *original, int width, int height);
    void rotateImage(std::unique_ptr<Value> &image, char x);

    // void mirror(Image& img, char x);

    void grayscale2color(std::unique_ptr<Value> &image, char x);

public:
    // Static method to access the singleton instance
    static ImageProcessor &getInstance();

    void toGray(std::unique_ptr<Value> &image);
    void toRGB(std::unique_ptr<Value> &image);
    void toRGBA(std::unique_ptr<Value> &image);
    void toBin(std::unique_ptr<Value> &image, int threshold = 150);

    void setIntensity(std::unique_ptr<Value> &image, const float intensity);
    void addBrightness(std::unique_ptr<Value> &image, int threshold);
    void invert(std::unique_ptr<Value> &image);
    void equalizeHist(std::unique_ptr<Value> &image);

    void rotateLeft(std::unique_ptr<Value> &image);
    void rotateRight(std::unique_ptr<Value> &image);
    void rotateDown(std::unique_ptr<Value> &image);
    void mirrorX(std::unique_ptr<Value> &image);
    void mirrorY(std::unique_ptr<Value> &image);

    void medianFilter(std::unique_ptr<Value> &image, int sigma);
    void gaussianSmoothing(std::unique_ptr<Value> &image, int sigma);

    void addNoise(std::unique_ptr<Value> &image, float ratio);

    void saveHistogram(std::unique_ptr<Value> &image, const std::string path);
};

#endif