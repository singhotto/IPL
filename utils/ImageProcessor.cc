#include "ImageProcessor.hh"

#define WHITE 255.0f
#define BLACK 0.0f

float min(float a, float b)
{
    float res = a < b ? a : b;
    return res;
}

float max(float a, float b)
{
    float res = a > b ? a : b;
    return res;
}

void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

void swap(float &a, float &b)
{
    float c = a;
    a = b;
    b = c;
}

float gauss(float x, float y, int sigma)
{
    int sigma2 = sigma * sigma;

    return (1 / (2 * M_PI * sigma2)) * exp(-(x * x + y * y) / (2 * sigma2));
}

void calculateKernel(float *kernel, int size, int sigma)
{
    int center = size / 2;
    float sum = 0.0f;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int x = i - center;
            int y = j - center;
            float res = gauss(x, y, sigma);
            kernel[i * size + j] = res;
            sum += res;
        }
    }

    for (int i = 0; i < size * size; i++)
    {
        kernel[i] /= sum;
    }
}

void applykernel(Image *img, float *kernel, int ksize)
{
    int height = img->getHeight();
    int width = img->getWidth();
    float *data = img->getData();
    int cnls = img->getChannels();
    int work_cnls = cnls < 4 ? cnls : 3;
    int offset = ksize / 2;
    float *sumArr = new float[work_cnls];
    memset(sumArr, 0.0f, work_cnls * sizeof(float));

    for (int i = offset; i < height - offset; i++)
    {
        for (int j = offset; j < width - offset; j++)
        {
            for (int k = 0; k < ksize; k++)
            {
                int kRowIdx = k * ksize;
                for (int l = 0; l < ksize; l++)
                {
                    int kIdx = (kRowIdx + l);
                    int idx = ((i + k - offset) * width + (j + l - offset)) * cnls;
                    float kk = kernel[kIdx];

                    for (int m = 0; m < work_cnls; m++)
                        sumArr[m] += data[idx + m] * kk;
                }
            }

            int ii = (i * width + j) * cnls;
            for (int m = 0; m < work_cnls; m++)
                data[ii + m] = sumArr[m];

            memset(sumArr, 0.0f, work_cnls * sizeof(float));
        }
    }

    delete[] sumArr;
}

Image *ImageProcessor::createNewImage(const Image *original, int width, int height)
{
    ImageType format = getImageType(original->getName());

    if (format == ImageType::PNG)
    {
        return new PngImage(original->getName(), width, height, original->getChannels(), original->getBPC());
    }
    else if (format == ImageType::JPG || format == ImageType::JPEG)
    {
        return new JpgImage(original->getName(), width, height, original->getChannels(), original->getBPC());
    }
    else if (format == ImageType::TIFF)
    {
        return new TIFFImage(original->getName(), width, height, original->getChannels(), original->getBPC());
    }
    else
    {
        throw std::runtime_error("Unsupported image format");
    }
}

std::vector<float> ImageProcessor::getHistogram(Image *image)
{
    std::vector<float> hist(256, 0);

    float *data = image->getData();
    int size = image->getChannels() * image->getHeight() * image->getWidth();
    for (int i = 0; i < size; i++)
    {
        hist[(int)data[i]]++;
    }

    for (float &f : hist)
    {
        f = f / size;
    }

    return hist;
}

void ImageProcessor::rotateImage(std::unique_ptr<Value> &img, char x)
{
    Image *image = dynamic_cast<Image *>(img.get());

    assert(image != nullptr);

    int originalH = image->getHeight();
    int originalW = image->getWidth();
    int width = originalW;
    int height = originalH;

    if (x == 'l' || x == 'r')
        swap(width, height);

    std::unique_ptr<Image> newImage(createNewImage(image, width, height));

    assert(newImage != nullptr);

    if (x == 'l')
    {
        for (int i = 0; i < originalH; i++)
        {
            for (int j = 0; j < originalW; j++)
            {
                Pixel oldPixel = image->operator()(i, j);
                Pixel newPixel = newImage->operator()(originalW - j - 1, i);

                newPixel.copy(oldPixel);
            }
        }
    }

    if (x == 'r')
    {
        for (int i = 0; i < originalH; i++)
        {
            for (int j = 0; j < originalW; j++)
            {
                Pixel oldPixel = image->operator()(i, j);

                Pixel newPixel = newImage->operator()(j, originalH - i - 1);

                newPixel.copy(oldPixel);
            }
        }
    }

    if (x == 'd')
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                Pixel oldPixel = image->operator()(originalH - i - 1, originalW - j - 1);
                Pixel newPixel = newImage->operator()(i, j);

                newPixel.copy(oldPixel);
            }
        }
    }

    if (x == 'f')
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                Pixel oldPixel = image->operator()(i, originalW - j - 1);
                Pixel newPixel = newImage->operator()(i, j);

                newPixel.copy(oldPixel);
            }
        }
    }

    if (x == 'm')
    {
        for (int i = 0; i < originalH; i++)
        {
            for (int j = 0; j < originalW; j++)
            {
                Pixel oldPixel = image->operator()(i, j);

                Pixel newPixel = newImage->operator()(originalH - i - 1, j);

                newPixel.copy(oldPixel);
            }
        }
    }

    img = std::move(newImage);
}

void ImageProcessor::grayscale2color(std::unique_ptr<Value> &img, char x)
{
    Image *image = dynamic_cast<Image *>(img.get());

    assert(image != nullptr);
    int cnls = 3;
    int height = image->getHeight();
    int width = image->getWidth();
    int imgCnls = image->getChannels();

    if (x == 'a')
        cnls = 4;

    if (imgCnls == cnls)
        return;

    std::string name = image->getName();

    std::unique_ptr<Image> newImg = nullptr;

    if (x == 'a')
    {
        name = replaceExtension(image->getName(), ImageType::PNG);
        newImg = std::make_unique<PngImage>(name, width, height, cnls);
    }
    else
    {
        newImg = std::make_unique<JpgImage>(name, width, height, cnls);
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            Pixel p = image->operator()(i, j);
            Pixel np = newImg->operator()(i, j);
            np.setValue(p[0]);
        }
    }

    img = std::move(newImg);
}

ImageProcessor::ImageProcessor() {}

ImageProcessor &ImageProcessor::getInstance()
{
    static ImageProcessor instance; // Guaranteed to be destroyed, instantiated on first use.
    return instance;
}

void ImageProcessor::toGray(std::unique_ptr<Value> &img)
{
    Image *image = dynamic_cast<Image *>(img.get());

    assert(image != nullptr);

    if (image->getChannels() < 3)
    {
        std::cout << "It's not a color Image!!!\n";
        return;
    }

    float temp;

    for (int i = 0; i < image->getHeight(); i++)
    {
        for (int j = 0; j < image->getWidth(); j++)
        {
            Pixel pp = image->operator()(i, j);
            temp = pp[0] * 0.299f + pp[1] * 0.587f + pp[2] * 0.114f;
            pp.setValue(temp);
        }
    }
}

void ImageProcessor::toRGB(std::unique_ptr<Value> &image)
{
    grayscale2color(image, 'c');
}

void ImageProcessor::toRGBA(std::unique_ptr<Value> &image)
{
    grayscale2color(image, 'a');
}

void ImageProcessor::toBin(std::unique_ptr<Value> &img, int threshold)
{
    Image *image = dynamic_cast<Image *>(img.get());

    assert(image != nullptr);
    int cnls = image->getChannels();
    float temp;
    for (int i = 0; i < image->getHeight(); i++)
    {
        for (int j = 0; j < image->getWidth(); j++)
        {
            Pixel pp = image->operator()(i, j);

            if (cnls > 1)
            {
                temp = pp[0] * 0.299f + pp[1] * 0.587f + pp[2] * 0.114f;
                temp = temp > threshold ? WHITE : BLACK;
                pp.setValue(temp);
                if (cnls == 4)
                    pp[3] = WHITE;
            }
            else
            {
                temp = pp[0] > threshold ? WHITE : BLACK;
                pp.setValue(temp);
            }
        }
    }
}

void ImageProcessor::setIntensity(std::unique_ptr<Value> &img, const float intensity)
{
    Image *image = dynamic_cast<Image *>(img.get());

    assert(image != nullptr);
    if (image->getChannels() != 4)
        throw std::runtime_error("It's not a four channel image!!!");

    float newIntensity = Utility::getInstance().correctRange(intensity);

    for (int i = 0; i < image->getHeight(); i++)
    {
        for (int j = 0; j < image->getWidth(); j++)
        {
            Pixel pp = image->operator()(i, j);
            pp[3] = newIntensity;
        }
    }
}

void ImageProcessor::addBrightness(std::unique_ptr<Value> &img, int threshold)
{
    Image *image = dynamic_cast<Image *>(img.get());

    assert(image != nullptr);
    int cnls = image->getChannels();

    for (int i = 0; i < image->getHeight(); i++)
    {
        for (int j = 0; j < image->getWidth(); j++)
        {
            Pixel pp = image->operator()(i, j);

            for (float *f : pp)
                *f = Utility::getInstance().correctRange(*f + threshold);

            if (cnls == 4)
                pp[3] = WHITE;
        }
    }
}

void ImageProcessor::invert(std::unique_ptr<Value> &img)
{
    Image *image = dynamic_cast<Image *>(img.get());

    assert(image != nullptr);
    int height = image->getHeight();
    int width = image->getWidth();

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            Pixel pp = image->operator()(i, j);

            for (float *p : pp)
                *p = Utility::getInstance().correctRange(WHITE - *p);
        }
    }
}

void ImageProcessor::equalizeHist(std::unique_ptr<Value> &img)
{
    Image *image = dynamic_cast<Image *>(img.get());

    assert(image != nullptr);
    std::vector<float> hist = getHistogram(image);
    std::vector<int> histEq(256, 0);

    float sum = 0.0f;
    int size = image->getChannels() * image->getHeight() * image->getWidth();
    float *data = image->getData();

    for (int i = 0; i < 256; i++)
    {
        sum += hist[i];
        histEq[i] = sum * 255 + 0.5;
    }

    for (int i = 0; i < size; i++)
    {
        data[i] = histEq[(int)data[i]];
    }
}

void ImageProcessor::rotateLeft(std::unique_ptr<Value> &image)
{
    rotateImage(image, 'l');
}

void ImageProcessor::rotateRight(std::unique_ptr<Value> &image)
{
    rotateImage(image, 'r');
}

void ImageProcessor::rotateDown(std::unique_ptr<Value> &image)
{
    rotateImage(image, 'd');
}

void ImageProcessor::mirrorX(std::unique_ptr<Value> &image)
{
    rotateImage(image, 'f');
}

void ImageProcessor::mirrorY(std::unique_ptr<Value> &image)
{
    rotateImage(image, 'm');
}

bool in_range(int input, int output, int window)
{
    int upper = input - window;
    int lower = input + window;
    if (output >= upper && output <= lower)
        return true;
    return false;
}

void ImageProcessor::replaceColor(std::unique_ptr<Value> &img, int inp_r, int inp_g, int inp_b, int out_r, int out_g, int out_b)
{
    Image *image = dynamic_cast<Image *>(img.get());

    assert(image != nullptr);
    assert(Utility::getInstance().isCorrect(inp_r, inp_g, inp_b));
    assert(Utility::getInstance().isCorrect(out_r, out_g, out_b));

    int height = image->getHeight();
    int width = image->getWidth();
    int ws = 60;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            Pixel pp = image->operator()(i, j);

            if (in_range(inp_r, pp[0], ws) && in_range(inp_g, pp[1], ws) && in_range(inp_b, pp[2], ws))
            {
                pp[0] = out_r;
                pp[1] = out_g;
                pp[2] = out_b;
            }
        }
    }
}

void ImageProcessor::medianFilter(std::unique_ptr<Value> &img, int sigma)
{
    Image *image = dynamic_cast<Image *>(img.get());

    assert(image != nullptr);
    if (sigma % 2 == 0)
    {
        sigma += 1;
    }

    int offset = sigma / 2;
    int height = image->getHeight();
    int width = image->getWidth();
    float *data = image->getData();
    int cnls = image->getChannels();

    int work_cnls = cnls < 4 ? cnls : 3;
    std::vector<std::vector<float>> window(work_cnls, std::vector<float>());

    for (int i = 0; i < work_cnls; i++)
    {
        window[i].reserve(sigma * sigma);
    }

    for (int i = offset; i < height - offset; i++)
    {
        for (int j = offset; j < width - offset; j++)
        {
            for (int ik = -offset; ik < offset + 1; ik++)
            {
                int rowPointer = (i + ik) * width;
                for (int jk = -offset; jk < offset + 1; jk++)
                {
                    int pointer = (rowPointer + j + jk) * cnls;
                    for (int m = 0; m < work_cnls; m++)
                    {
                        std::vector<float> *curr = &window[m];
                        curr->push_back(data[pointer + m]);
                    }
                }
            }

            int pp = (i * width + j) * cnls;
            for (int m = 0; m < work_cnls; m++)
            {
                std::vector<float> *curr = &window[m];

                sort(curr->begin(), curr->end());

                data[pp + m] = curr->at(curr->size() / 2);
                curr->clear();
            }
        }
    }
}

void ImageProcessor::gaussianSmoothing(std::unique_ptr<Value> &img, int sigma)
{
    Image *image = dynamic_cast<Image *>(img.get());

    assert(image != nullptr);

    int kernelSize = 6 * sigma + 1;

    float *kernel = new float[kernelSize * kernelSize];

    calculateKernel(kernel, kernelSize, sigma);

    applykernel(image, kernel, kernelSize);

    delete[] kernel;
}

void ImageProcessor::addNoise(std::unique_ptr<Value> &img, float ratio)
{
    Image *image = dynamic_cast<Image *>(img.get());

    assert(image != nullptr);

    ratio = Utility::getInstance().correctRange(ratio, 0.0f, 1.0f);

    int height = image->getHeight();
    int width = image->getWidth();
    float *data = image->getData();
    int cnls = image->getChannels();
    int work_cnls = cnls < 4 ? cnls : 3;
    int noisyPixels = ratio * height * width;
    srand(static_cast<unsigned>(time(0)));

    for (int i = 0; i < noisyPixels; i++)
    {
        int y = rand() % height;
        int x = rand() % width;
        bool salt = rand() % 2;
        int pointer = (y * width + x) * cnls;

        for (int j = 0; j < work_cnls; j++)
        {
            data[pointer + j] = salt ? WHITE : BLACK;
        }
    }
}

void ImageProcessor::tile(std::unique_ptr<Value> &input, int n_r, int n_c, std::unique_ptr<Value> &output)
{
    Image *inp = dynamic_cast<Image *>(input.get());

    assert(inp != nullptr);

    Image *out = dynamic_cast<Image *>(output.get());

    assert(out != nullptr);

    // Get dimensions and data pointers
    int inp_height = inp->getHeight();
    int inp_width = inp->getWidth();
    int inp_channels = inp->getChannels();
    float *inp_data = inp->getData();

    int out_height = out->getHeight();
    int out_width = out->getWidth();
    int out_channels = out->getChannels();
    float *out_data = out->getData();

    assert((inp_height * n_r) <= out_height);
    assert((inp_width * n_c) <= out_width);

    // Copy input pixels to the output grid
    for (int row = 0; row < n_r; ++row) {         // Iterate over rows of tiles
        for (int col = 0; col < n_c; ++col) {     // Iterate over columns of tiles
            for (int y = 0; y < inp_height; ++y) { // Iterate over rows of input image
                for (int x = 0; x < inp_width; ++x) { // Iterate over columns of input image
                    for (int c = 0; c < inp_channels; ++c) { // Iterate over channels
                        // Compute the position in the output image
                        int out_y = row * inp_height + y; // Y-coordinate in the output image
                        int out_x = col * inp_width + x;  // X-coordinate in the output image
                        int out_idx = (out_y * out_width + out_x) * out_channels + c;

                        // Compute the position in the input image
                        int inp_idx = (y * inp_width + x) * inp_channels + c;

                        // Copy pixel data
                        out_data[out_idx] = inp_data[inp_idx];
                    }
                }
            }
        }
    }
}

void ImageProcessor::saveHistogram(std::unique_ptr<Value> &img, const std::string path)
{
    Image *image = dynamic_cast<Image *>(img.get());

    assert(image != nullptr);
    std::vector<float> hist = getHistogram(image);

    std::vector<std::string> labels;
    labels.reserve(255);

    for (int i = 0; i < 256; i++)
    {
        labels.push_back(std::to_string(i));
    }

    Chart chart(hist, labels);

    chart.drawAxes();

    chart.drawBars({0, 100, 200});
    chart.drawXLabels({255, 10, 50});

    chart.writeBMP(path.c_str());
}
