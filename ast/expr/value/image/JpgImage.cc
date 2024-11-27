#include "expr/value/image/JpgImage.hh"
#include "JpgImage.hh"
#include "Log.hh"

JpgImage::JpgImage(const std::string filepath, int width, int height, int channels, int bitsPerChannel) {
    LOG_OPERATION_START("JpgImage::JpgImage(string, int, int, int, int)");
    assert(channels < 4);
    Image::name = getFileName(filepath);
    Image::width = width;
    Image::height = height;
    Image::channels = channels;
    Image::bitPerChannel = bitsPerChannel;
    Image::data = new float[width * height * channels];
    LOG_OPERATION_END("JpgImage::JpgImage(string, int, int, int, int)");
}

void JpgImage::load(const std::string &filename) {
    LOG_OPERATION_START("JpgImage::load(string)");
    Image::load(filename);
    LOG_OPERATION_END("JpgImage::load(string)");
}

void JpgImage::save(const std::string &filename) {
    LOG_OPERATION_START("JpgImage::save(string)");
    unsigned char *data = Utility::getInstance().cast2char(Image::getData(), Image::getWidth() * Image::getHeight() * Image::getChannels());
    // Save as JPEG
    if (!stbi_write_jpg(filename.c_str(), Image::getWidth(), Image::getHeight(), Image::getChannels(), data, 100))
        throw std::runtime_error("Failed to save image as JPEG: " + filename);
    LOG_OPERATION_END("JpgImage::save(string)");
}

void JpgImage::print() const {
    LOG_OPERATION_START("JpgImage::print()");
    std::cout << "Image Name: " << Image::getName() << "\n";
    std::cout << "Width: " << Image::getWidth() << "px" << "\n";
    std::cout << "Height: " << Image::getHeight() << "px" << "\n";
    std::cout << "Channels: " << Image::getChannels() << "\n";
    std::cout << "Bits Per Sample: " << Image::getBPC() << "\n";
    std::cout << "Image Type: " << "JPG" << "\n";
    LOG_OPERATION_END("JpgImage::print()");
}

std::unique_ptr<Value> JpgImage::cloneValue() const {
    LOG_OPERATION_START("JpgImage::cloneValue()");
    std::unique_ptr<JpgImage> clonedImage = std::make_unique<JpgImage>(
        Image::getName(),      // Filepath or name
        Image::getWidth(),     // Image width
        Image::getHeight(),    // Image height
        Image::getChannels(),  // Number of channels
        Image::getBPC()        // Bits per channel
    );

    // Copy image data
    size_t dataSize = Image::getWidth() * Image::getHeight() * Image::getChannels();
    float* clonedData = clonedImage.get()->data;
    std::copy(Image::getData(), Image::getData() + dataSize, clonedData);
    LOG_OPERATION_END("JpgImage::cloneValue()");
    return std::move(clonedImage);
}

std::unique_ptr<Expr> JpgImage::cloneExpr() const {
    LOG_OPERATION_START("JpgImage::cloneExpr()");
    std::unique_ptr<JpgImage> clonedImage = std::make_unique<JpgImage>(
        Image::getName(),      // Filepath or name
        Image::getWidth(),     // Image width
        Image::getHeight(),    // Image height
        Image::getChannels(),  // Number of channels
        Image::getBPC()        // Bits per channel
    );

    // Copy image data
    size_t dataSize = Image::getWidth() * Image::getHeight() * Image::getChannels();
    float* clonedData = clonedImage.get()->data;
    std::copy(Image::getData(), Image::getData() + dataSize, clonedData);
    LOG_OPERATION_END("JpgImage::cloneExpr()");
    return std::move(clonedImage);
}

void JpgImage::accept(Visitor *visitor) {
    LOG_OPERATION_START("JpgImage::accept(Visitor*)");
    visitor->visit(this);
    LOG_OPERATION_END("JpgImage::accept(Visitor*)");
}
