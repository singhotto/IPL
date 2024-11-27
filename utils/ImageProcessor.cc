#include "ImageProcessor.hh"

#define WHITE 255
#define BLACK 0

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

void applykernel(Image &img, float *kernel, int ksize)
{
    int height = img.getHeight();
    int width = img.getWidth();
    float *data = img.getData();
    int cnls = img.getChannels();
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

std::vector<float> ImageProcessor::getHistogram(Image* img)
{
    
    std::vector<float> hist(256, 0);

    float *data = img->getData();
    int size = img->getChannels() * img->getHeight() * img->getWidth();
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

void ImageProcessor::grayscale2color(Image* image, char x)
{
    int cnls = 3;
    int height = image->getHeight();
    int width = image->getWidth();
    float v1, v2, v3;
    int imgCnls = image->getChannels();

    if (x == 'a')
        cnls = 4;

    if (imgCnls == cnls)
        return;

    std::string name = image->getName();

    Image* newImg = nullptr;

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
            std::unique_ptr<Pixel> p = image->operator()(i, j);
            std::unique_ptr<Pixel> np = newImg->operator()(i, j);
            np->setValue(p->getValue());
        }
    }

    image = std::move(newImg);
}

ImageProcessor::ImageProcessor() {}

ImageProcessor &ImageProcessor::getInstance()
{
    static ImageProcessor instance; // Guaranteed to be destroyed, instantiated on first use.
    return instance;
}

void ImageProcessor::conv2Grayscale(Image* image)
{
    if (image->getChannels() < 3)
    {
        std::cout << "It's not a color Image!!!\n";
        return;
    }
    std::cout << "ok channels:" << image->getChannels() << "\n";
    float temp;

    for (int i = 0; i < image->getHeight(); i++)
    {
        for (int j = 0; j < image->getWidth(); j++)
        {
            std::unique_ptr<Pixel> pp = image->operator()(i, j);
            RgbPixel *rgbPixel = dynamic_cast<RgbPixel *>(pp.get());
            temp = rgbPixel->getR() * 0.299f + rgbPixel->getG() * 0.587f + rgbPixel->getB() * 0.114f;
            rgbPixel->setValue(temp);
        }
    }
}

void ImageProcessor::conv2rgb(Image* image)
{
    grayscale2color(image, 'c');
}

void ImageProcessor::conv2rgba(Image* image)
{
    grayscale2color(image, 'a');
}

void ImageProcessor::conv2Bin(Image* image, int threshold)
{
    int cnls = image->getChannels();
    float temp, v;
    for (int i = 0; i < image->getHeight(); i++)
    {
        for (int j = 0; j < image->getWidth(); j++)
        {
            std::unique_ptr<Pixel> pp = image->operator()(i, j);
            if (RgbPixel *rgbPixel = dynamic_cast<RgbPixel *>(pp.get()))
            {
                temp = rgbPixel->getR() * 0.299f + rgbPixel->getG() * 0.587f + rgbPixel->getB() * 0.114f;
                temp = temp > threshold ? WHITE : BLACK;
                rgbPixel->setValue(temp);
                if (RgbaPixel *rgbaPixel = dynamic_cast<RgbaPixel *>(pp.get()))
                {
                    rgbaPixel->setAlpha(WHITE);
                }
            }
            else
            {
                temp = pp->getValue() > threshold ? WHITE : BLACK;
                pp->setValue(temp);
            }
        }
    }
}

void ImageProcessor::setIntensity(Image*  image, const float intensity)
{
    if (image->getChannels() != 4)
        throw std::runtime_error("It's not a four channel image!!!");

    for (int i = 0; i < image->getHeight(); i++)
    {
        for (int j = 0; j < image->getWidth(); j++)
        {
            std::unique_ptr<Pixel> pp = image->operator()(i, j);
            if (RgbaPixel *rgbaPixel = dynamic_cast<RgbaPixel *>(pp.get()))
                rgbaPixel->setAlpha(intensity);
        }
    }
}

void ImageProcessor::addBrightness(Image*  image, int threshold)
{
    int cnls = image->getChannels();
    float r, g, b;
    for (int i = 0; i < image->getHeight(); i++)
    {
        for (int j = 0; j < image->getWidth(); j++)
        {
            std::unique_ptr<Pixel> pp = image->operator()(i, j);
            if (RgbPixel *rgbPixel = dynamic_cast<RgbPixel *>(pp.get()))
            {
                rgbPixel->operator+=(threshold);
                if (RgbaPixel *rgbaPixel = dynamic_cast<RgbaPixel *>(pp.get()))
                {
                    rgbaPixel->setAlpha(WHITE);
                }
            }
            else
            {
                pp->operator+=(threshold);
            }
        }
    }
}

void ImageProcessor::negativeImage(Image*  image)
{
    int height = image->getHeight();
    int width = image->getWidth();
    int cnls = image->getChannels();
    const float c = 255.0f;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            std::unique_ptr<Pixel> pp = image->operator()(i, j);
            if (RgbPixel *rgbPixel = dynamic_cast<RgbPixel *>(pp.get()))
            {
                rgbPixel->operator*=(-1.0f);
                rgbPixel->operator+=(WHITE);
                rgbPixel->correctPixel();
            }
            else
            {
                pp->operator*=(-1.0f);
                pp->operator+=(WHITE);
                pp->correctPixel();
            }
        }
    }
}

void ImageProcessor::histEqualization(Image*  image)
{
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
