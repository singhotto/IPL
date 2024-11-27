#ifndef IMAGE_OPERATION__GUARD
#define IMAGE_OPERATION__GUARD

enum class ImageOperation {
    LOAD,
    SAVE,
    CONV2BIN,
    CONV2GRAY,
    UNKNOWN
};

#include <string>

// Optional: Function to convert enum to string for display purposes
inline const char* toString(ImageOperation type) {
    switch (type) {
        case ImageOperation::LOAD: return "load";
        case ImageOperation::SAVE: return "save";
        case ImageOperation::CONV2BIN: return "conv2bin";
        case ImageOperation::CONV2GRAY: return "conv2gray";
        default: return "Unknown";
    }
}

const ImageOperation allImageOperations[] = {
    ImageOperation::LOAD,
    ImageOperation::SAVE,
    ImageOperation::CONV2BIN,
    ImageOperation::CONV2GRAY,
    ImageOperation::UNKNOWN
};

inline ImageOperation getImageOperation(std::string operation)
{
    // Convert extension to lowercase for case-insensitive comparison
    for (auto &c : operation)
    {
        c = tolower(c);
    }

    // Match extension to ImageOperation
    for (ImageOperation type : allImageOperations)
    {
        if (operation == toString(type))
            return type;
    }

    return ImageOperation::UNKNOWN;
}

inline bool isImageOperation(const std::string& operation) {
    std::string lowerOp = operation;
    for (auto &c : lowerOp) {
        c = tolower(c);
    }

    for (ImageOperation type : allImageOperations) {
        if (lowerOp == toString(type) && type != ImageOperation::UNKNOWN) {
            return true;
        }
    }

    return false;
}


#endif // ImageOperation_H
