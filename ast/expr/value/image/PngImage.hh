#ifndef PNGIMAGE__GUARD
#define PNGIMAGE__GUARD

#include "expr/value/image/Image.hh"

class PngImage : public Image
{
private:
    /* data */
public:
    PngImage() = default;
    PngImage(const std::string filepath, int width, int height, int channels, int bitsPerChannel = 8);
    ~PngImage() = default;

    void load(const std::string &filename) override;
    void save(const std::string &filename) override;

    void print() const override;
    std::unique_ptr<Value> cloneValue() const override;
    std::unique_ptr<Expr> cloneExpr() const override;
    void accept(Visitor* visitor) override;
};

#endif