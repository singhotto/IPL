#include "expr/value/image/PngImage.hh"
#include "PngImage.hh"
#include "Log.hh"

PngImage::PngImage(const std::string filepath, int width, int height, int channels, int bitsPerChannel) {
    LOG_OPERATION_START("PngImage::PngImage(string, int, int, int, int)");
    assert(channels < 5);
    Image::name = getFileName(filepath);
    Image::width = width;
    Image::height = height;
    Image::channels = channels;
    Image::bitPerChannel = bitsPerChannel;
    Image::data = new float[width * height * channels];
    LOG_OPERATION_END("PngImage::PngImage(string, int, int, int, int)");
}

void PngImage::load(const std::string &filename) {
    LOG_OPERATION_START("PngImage::load(string)");
    Image::load(filename);
    LOG_OPERATION_END("PngImage::load(string)");
}

void PngImage::save(const std::string &filename) {
    LOG_OPERATION_START("PngImage::save(string)");
    unsigned char *data = Utility::getInstance().cast2char(Image::getData(), Image::getWidth() * Image::getHeight() * Image::getChannels());
    // Save as PNG
    if (!stbi_write_png(filename.c_str(), Image::getWidth(), Image::getHeight(), Image::getChannels(), data, Image::getWidth() * Image::getChannels()))
        throw std::runtime_error("Failed to save image as PNG: " + filename);
    LOG_OPERATION_END("PngImage::save(string)");
}

void PngImage::print() const {
    LOG_OPERATION_START("PngImage::print()");
    std::cout << "Image Name: " << Image::getName() << "\n";
    std::cout << "Width: " << Image::getWidth() << "px" << "\n";
    std::cout << "Height: " << Image::getHeight() << "px" << "\n";
    std::cout << "Channels: " << Image::getChannels() << "\n";
    std::cout << "Bits Per Sample: " << Image::getBPC() << "\n";
    std::cout << "Image Type: " << "PNG" << "\n";
    LOG_OPERATION_END("PngImage::print()");
}

std::unique_ptr<Value> PngImage::cloneValue() const {
    LOG_OPERATION_START("PngImage::cloneValue()");
    std::unique_ptr<PngImage> clonedImage = std::make_unique<PngImage>(
        Image::getName(),     // Filepath or name
        Image::getWidth(),    // Image width
        Image::getHeight(),   // Image height
        Image::getChannels(), // Number of channels
        Image::getBPC()       // Bits per channel
    );

    // Copy image data
    size_t dataSize = Image::getWidth() * Image::getHeight() * Image::getChannels();
    float *clonedData = clonedImage.get()->data;
    std::copy(Image::getData(), Image::getData() + dataSize, clonedData);

    LOG_OPERATION_END("PngImage::cloneValue()");
    return std::move(clonedImage);
}

std::unique_ptr<Expr> PngImage::cloneExpr() const {
    LOG_OPERATION_START("PngImage::cloneExpr()");
    std::unique_ptr<PngImage> clonedImage = std::make_unique<PngImage>(
        Image::getName(),     // Filepath or name
        Image::getWidth(),    // Image width
        Image::getHeight(),   // Image height
        Image::getChannels(), // Number of channels
        Image::getBPC()       // Bits per channel
    );

    // Copy image data
    size_t dataSize = Image::getWidth() * Image::getHeight() * Image::getChannels();
    float *clonedData = clonedImage.get()->data;
    std::copy(Image::getData(), Image::getData() + dataSize, clonedData);

    LOG_OPERATION_END("PngImage::cloneExpr()");
    return std::move(clonedImage);
}

void PngImage::accept(Visitor *visitor) {
    LOG_OPERATION_START("PngImage::accept(Visitor*)");
    visitor->visit(this);
    LOG_OPERATION_END("PngImage::accept(Visitor*)");
}
