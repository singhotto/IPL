#ifndef IMAGE_TYPE_GUARD
#define IMAGE_TYPE_GUARD

enum class ImageType {
    JPEG,
    JPG,
    PNG,
    GIF,
    BMP,
    TIFF,
    WEBP,
    TGA,
    DCM,
    UNKNOWN
};

#include <string>

// Optional: Function to convert enum to string for display purposes
inline const char* toString(ImageType type) {
    switch (type) {
        case ImageType::JPEG: return "jpeg";
        case ImageType::JPG: return "jpg";
        case ImageType::PNG: return "png";
        case ImageType::GIF: return "gif";
        case ImageType::BMP: return "bmp";
        case ImageType::TIFF: return "tiff";
        case ImageType::WEBP: return "webp";
        case ImageType::TGA: return "tga";
        case ImageType::DCM: return "dcm";
        default: return "Unknown";
    }
}

const ImageType allImageTypes[] = {
    ImageType::JPEG,
    ImageType::JPG,
    ImageType::PNG,
    ImageType::GIF,
    ImageType::BMP,
    ImageType::TIFF,
    ImageType::WEBP,
    ImageType::TGA,
    ImageType::DCM,
    ImageType::UNKNOWN
};


inline std::string replaceExtension(const std::string &filename, const ImageType type)
{
    // Find the last dot in the filename
    std::size_t dotPos = filename.find_last_of('.');

    if (dotPos != std::string::npos)
    {
        // Replace the extension
        return filename.substr(0, dotPos + 1) + toString(type);
    }
    else
    {
        // No extension found, just append the new one
        return filename + toString(type);
    }
}


inline ImageType getImageType(const std::string &fileName)
{
    // Extract the extension by finding the last period
    std::string extension = fileName.substr(fileName.find_last_of(".") + 1);

    // Convert extension to lowercase for case-insensitive comparison
    for (auto &c : extension)
    {
        c = tolower(c);
    }

    // Match extension to ImageType
    for (ImageType type : allImageTypes)
    {
        if (extension == toString(type))
            return type;
    }

    return ImageType::UNKNOWN;
}

inline std::string getFileName(const std::string &path)
{
    // Find the last '/' or '\\' in the path
    std::size_t pos = path.find_last_of("/\\");
    if (pos != std::string::npos)
    {
        return path.substr(pos + 1); // Extract filename
    }
    return path; // If no slash found, the path is already the filename
}

#endif // IMAGETYPE_H
