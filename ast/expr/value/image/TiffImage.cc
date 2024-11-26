#include "expr/value/image/TiffImage.hh"
#include "TiffImage.hh"
#include "Log.hh"

void LOG_ERROR(std::string msg){
    std::cout<<msg<<"\n";
}

TIFFImage::TIFFImage(const std::string filepath, int width, int height, int channels, int bitsPerChannel)
{
    LOG_OPERATION_START("TIFFImage::TIFFImage(string, int, int, int, int)");
    assert(channels < 5);
    Image::name = getFileName(filepath);
    Image::width = width;
    Image::height = height;
    Image::channels = channels;
    Image::bitPerChannel = bitsPerChannel;
    Image::data = new float[width * height * channels];
    LOG_OPERATION_END("TIFFImage::TIFFImage(string, int, int, int, int)");
}

void TIFFImage::load(const std::string &filename)
{
    LOG_OPERATION_START("TIFFImage::load(string)");

    TIFF *tiff = TIFFOpen(filename.c_str(), "r");
    if (!tiff)
    {
        LOG_ERROR("Error opening file: " + filename);
        return;
    }

    Image::name = getFileName(filename);

    TIFFGetField(tiff, TIFFTAG_IMAGEWIDTH, &(Image::width));
    TIFFGetField(tiff, TIFFTAG_IMAGELENGTH, &(Image::height));
    TIFFGetField(tiff, TIFFTAG_BITSPERSAMPLE, &(Image::bitPerChannel));
    TIFFGetField(tiff, TIFFTAG_SAMPLESPERPIXEL, &(Image::channels));

    int size = Image::width * Image::height * Image::channels;
    unsigned char *data = new unsigned char[size];
    tsize_t scanlineSize = TIFFScanlineSize(tiff);
    unsigned char *buffer = new unsigned char[scanlineSize];

    for (int row = 0; row < Image::height; row++)
    {
        if (TIFFReadScanline(tiff, buffer, row) < 0)
        {
            LOG_ERROR("Error reading scanline " + std::to_string(row));
            TIFFClose(tiff);
            delete[] buffer;
            return;
        }
        for (int col = 0; col < Image::width; col++)
        {
            for (int ch = 0; ch < Image::channels; ch++)
            {
                int idx = (row * Image::width + col) * Image::channels + ch;
                data[idx] = buffer[col * Image::channels + ch];
            }
        }
    }

    delete[] buffer;
    TIFFClose(tiff);

    Image::data = Utility::cast2float(data, Image::width * Image::height * Image::channels);
    delete[] data;

    LOG_OPERATION_END("TIFFImage::load(string)");
}

void TIFFImage::save(const std::string &filename)
{
    LOG_OPERATION_START("TIFFImage::save(string)");

    if (Image::data == nullptr)
    {
        LOG_ERROR("No image data to save!");
        return;
    }

    TIFF *tiff = TIFFOpen(filename.c_str(), "w");
    if (!tiff)
    {
        LOG_ERROR("Could not open file for writing: " + filename);
        return;
    }

    TIFFSetField(tiff, TIFFTAG_IMAGEWIDTH, Image::width);
    TIFFSetField(tiff, TIFFTAG_IMAGELENGTH, Image::height);
    TIFFSetField(tiff, TIFFTAG_SAMPLESPERPIXEL, Image::channels);
    TIFFSetField(tiff, TIFFTAG_BITSPERSAMPLE, Image::bitPerChannel);
    TIFFSetField(tiff, TIFFTAG_ORIENTATION, ORIENTATION_TOPLEFT);
    TIFFSetField(tiff, TIFFTAG_PLANARCONFIG, PLANARCONFIG_CONTIG);

    if (Image::channels == 1)
        TIFFSetField(tiff, TIFFTAG_PHOTOMETRIC, PHOTOMETRIC_MINISBLACK);
    else if (Image::channels == 3)
        TIFFSetField(tiff, TIFFTAG_PHOTOMETRIC, PHOTOMETRIC_RGB);

    unsigned char *dd = Utility::cast2char(Image::data, Image::width * Image::height * Image::channels);

    for (int row = 0; row < Image::height; row++)
    {
        if (TIFFWriteScanline(tiff, dd + row * Image::width * Image::channels, row) < 0)
        {
            LOG_ERROR("Error writing scanline " + std::to_string(row));
            TIFFClose(tiff);
            return;
        }
    }

    TIFFClose(tiff);

    LOG_OPERATION_END("TIFFImage::save(string)");
}

void TIFFImage::print() const
{
    LOG_OPERATION_START("TIFFImage::print()");
    std::cout << "Image Name: " << Image::getName() << "\n";
    std::cout << "Width: " << Image::getWidth() << "px" << "\n";
    std::cout << "Height: " << Image::getHeight() << "px" << "\n";
    std::cout << "Channels: " << Image::getChannels() << "\n";
    std::cout << "Bits Per Sample: " << Image::getBPC() << "\n";
    std::cout << "Image Type: " << "TIFF" << "\n";
    LOG_OPERATION_END("TIFFImage::print()");
}

std::unique_ptr<Value> TIFFImage::cloneValue() const
{
    LOG_OPERATION_START("TIFFImage::cloneValue()");

    std::unique_ptr<TIFFImage> clonedImage = std::make_unique<TIFFImage>(
        Image::getName(),
        Image::getWidth(),
        Image::getHeight(),
        Image::getChannels(),
        Image::getBPC());

    size_t dataSize = Image::getWidth() * Image::getHeight() * Image::getChannels();
    float *clonedData = clonedImage.get()->data;
    std::copy(Image::getData(), Image::getData() + dataSize, clonedData);

    LOG_OPERATION_END("TIFFImage::cloneValue()");
    return std::move(clonedImage);
}

std::unique_ptr<Expr> TIFFImage::cloneExpr() const
{
    LOG_OPERATION_START("TIFFImage::cloneExpr()");

    std::unique_ptr<TIFFImage> clonedImage = std::make_unique<TIFFImage>(
        Image::getName(),
        Image::getWidth(),
        Image::getHeight(),
        Image::getChannels(),
        Image::getBPC());

    size_t dataSize = Image::getWidth() * Image::getHeight() * Image::getChannels();
    float *clonedData = clonedImage.get()->data;
    std::copy(Image::getData(), Image::getData() + dataSize, clonedData);

    LOG_OPERATION_END("TIFFImage::cloneExpr()");
    return std::move(clonedImage);
}

void TIFFImage::accept(Visitor *visitor)
{
    LOG_OPERATION_START("TIFFImage::accept(Visitor*)");
    visitor->visit(this);
    LOG_OPERATION_END("TIFFImage::accept(Visitor*)");
}
