#ifndef IMAGE_OPERATION__GUARD
#define IMAGE_OPERATION__GUARD

enum class ImageOperation {
    LOAD,
    SAVE,
    TOBIN,
    TOGRAY,
    SETINTENSITY,
    ADDBRIGHTNESS,
    INVERT,
    EQUALIZEHIST,
    TORGBA,
    TORGB,
    ROTATERIGHT,
    ROTATELEFT,
    ROTATEDOWN,
    MIRRORX,
    MIRRORY,
    TILE,
    REPLACECOLOR,
    MEDIANFILTER,
    GAUSSIANSMOOTHING,
    ADDNOISE,
    SAVEHISTOGRAM,
    UNKNOWN
};

#include <string>

// Optional: Function to convert enum to string for display purposes
inline const char* toString(ImageOperation type) {
    switch (type) {
        case ImageOperation::LOAD: return "load";
        case ImageOperation::SAVE: return "save";
        case ImageOperation::TOBIN: return "toBin";
        case ImageOperation::TOGRAY: return "toGray";
        case ImageOperation::SETINTENSITY: return "setIntensity";
        case ImageOperation::ADDBRIGHTNESS: return "addBrightness";
        case ImageOperation::INVERT: return "invert";
        case ImageOperation::EQUALIZEHIST: return "equalizeHist";
        case ImageOperation::TORGBA: return "toRGBA";
        case ImageOperation::TORGB: return "toRGB";
        case ImageOperation::ROTATERIGHT: return "rotateRight";
        case ImageOperation::ROTATELEFT: return "rotateLeft";
        case ImageOperation::ROTATEDOWN: return "rotateDown";
        case ImageOperation::MIRRORX: return "mirrorX";
        case ImageOperation::MIRRORY: return "mirrorY";
        case ImageOperation::TILE: return "tile";
        case ImageOperation::REPLACECOLOR: return "replaceColor";
        case ImageOperation::MEDIANFILTER: return "medianFilter";
        case ImageOperation::GAUSSIANSMOOTHING: return "gaussianSmoothing";
        case ImageOperation::ADDNOISE: return "addNoise";
        case ImageOperation::SAVEHISTOGRAM: return "saveHistogram";
        default: return "Unknown";
    }
}

const ImageOperation allImageOperations[] = {
    ImageOperation::LOAD,
    ImageOperation::SAVE,
    ImageOperation::TOBIN,
    ImageOperation::TOGRAY,
    ImageOperation::SETINTENSITY,
    ImageOperation::ADDBRIGHTNESS,
    ImageOperation::INVERT,
    ImageOperation::EQUALIZEHIST,
    ImageOperation::TORGBA,
    ImageOperation::TORGB,
    ImageOperation::ROTATERIGHT,
    ImageOperation::ROTATELEFT,
    ImageOperation::ROTATEDOWN,
    ImageOperation::MIRRORX,
    ImageOperation::MIRRORY,
    ImageOperation::TILE,
    ImageOperation::REPLACECOLOR,
    ImageOperation::MEDIANFILTER,
    ImageOperation::GAUSSIANSMOOTHING,
    ImageOperation::ADDNOISE,
    ImageOperation::SAVEHISTOGRAM,
    ImageOperation::UNKNOWN
};

inline ImageOperation getImageOperation(std::string operation)
{
    for (ImageOperation type : allImageOperations)
    {
        if (operation == toString(type))
            return type;
    }

    return ImageOperation::UNKNOWN;
}


#endif 
