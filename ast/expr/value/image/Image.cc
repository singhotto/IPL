#include "expr/value/image/Image.hh"

Image::~Image()
{
    if (data)
        delete[] data;
}

void Image::load(const std::string &filePath)
{
    std::ifstream file(filePath.c_str());

    if (file.is_open())
        file.close();
    else
        throw std::runtime_error("File does not exist.");
    unsigned char *temp = stbi_load(filePath.c_str(), &width, &height, &channels, 0);

    data = Utility::getInstance().cast2float(temp, width * height * channels);
    name = getFileName(filePath);
    bitPerChannel = 8;

    stbi_image_free(temp);
}

int Image::getWidth() const
{
    return width;
}

int Image::getHeight() const
{
    return height;
}

int Image::getChannels() const
{
    return channels;
}

int Image::getBPC() const
{
    return bitPerChannel;
}

float *Image::getData() const
{
    return data;
}

std::string Image::getName() const
{
    return name;
}

Pixel Image::operator()(int row, int col)
{
    // Check bounds
    if (row < 0 || row >= this->height || col < 0 || col >= this->width)
    {
        throw std::out_of_range(
            "Pixel Index out of bounds: (" + std::to_string(row) + ", " + std::to_string(col) +
            ") for image dimensions (" + std::to_string(this->height) + "x" + std::to_string(this->width) + ")");
    }

    // Calculate the index in the 1D vector
    int pointer = (row * this->width + col) * this->channels;

    if (this->channels == 1)
        return Pixel(&data[pointer]); // Assuming Pixel constructor for single channel

    else if (this->channels == 3)
        return Pixel(&data[pointer], &data[pointer + 1], &data[pointer + 2]);

    else if (this->channels == 4)
        return Pixel(&data[pointer], &data[pointer + 1], &data[pointer + 2], &data[pointer + 3]);

    throw std::invalid_argument("Unsupported number of channels");
}