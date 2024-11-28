#ifndef IMAGE_H
#define IMAGE_H

#include "lib/stb_image.h"
#include "lib/stb_image_write.h"

#include "ImageType.hh"
#include "Utility.hh"
#include "expr/value/image/Pixel.hh"

#include <iostream>
#include <string>
#include <memory>
#include <cassert>
#include <fstream>
#include <tiffio.h>
#include "Value.hh"
#include "expr/Expr.hh"
#include "Visitor.hh" 

class Visitor;

class Image : virtual public Value, virtual public Expr
{
protected:
    std::string name;
    float *data;
    int width;
    int height;
    int channels;
    int bitPerChannel;

public:
    virtual ~Image();

    // Virtual function to load the image
    virtual void load(const std::string &filename) = 0;

    // Virtual function to save the image
    virtual void save(const std::string &filename) = 0;

    int getWidth() const;
    int getHeight() const;
    int getChannels() const;
    float *getData() const;
    int getBPC() const;
    std::string getName() const;

    Pixel operator()(int row, int col);
};

#endif // IMAGE_H
