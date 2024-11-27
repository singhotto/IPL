#ifndef IMAGE_OPERATION__GUARD
#define IMAGE_OPERATION__GUARD

enum class ImageOperation {
    LOAD,
    SAVE,
    CONV2BIN,
    CONV2GRAY,
    SETINTENSITY,
    ADDBRIGHTNESS,
    NEGATIVEIMAGE,
    HISTEQUALIZATION,
    CONV2RGBA,
    CONV2RGB,
    UNKNOWN
};

#include <string>

// Optional: Function to convert enum to string for display purposes
inline const char* toString(ImageOperation type) {
    switch (type) {
        case ImageOperation::LOAD: return "load";
        case ImageOperation::SAVE: return "save";
        case ImageOperation::CONV2BIN: return "conv2Bin";
        case ImageOperation::CONV2GRAY: return "conv2Gray";
        case ImageOperation::SETINTENSITY: return "setIntensity";
        case ImageOperation::ADDBRIGHTNESS: return "addBrightness";
        case ImageOperation::NEGATIVEIMAGE: return "negativeImage";
        case ImageOperation::HISTEQUALIZATION: return "histEqualization";
        case ImageOperation::CONV2RGBA: return "conv2Rgba";
        case ImageOperation::CONV2RGB: return "conv2Rgb";
        default: return "Unknown";
    }
}

const ImageOperation allImageOperations[] = {
    ImageOperation::LOAD,
    ImageOperation::SAVE,
    ImageOperation::CONV2BIN,
    ImageOperation::CONV2GRAY,
    ImageOperation::SETINTENSITY,
    ImageOperation::ADDBRIGHTNESS,
    ImageOperation::NEGATIVEIMAGE,
    ImageOperation::HISTEQUALIZATION,
    ImageOperation::CONV2RGBA,
    ImageOperation::CONV2RGB,
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
