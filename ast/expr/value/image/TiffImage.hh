#ifndef TIFFIMAGE__GUARD
#define TIFFIMAGE__GUARD

#include "expr/value/image/Image.hh"

class TIFFImage : public Image
{
private:
    /* data */
public:
    TIFFImage() = default;
    TIFFImage(const std::string filepath, int width, int height, int channels, int bitsPerChannel = 8);
    ~TIFFImage() = default;

    void load(const std::string &filename) override;
    void save(const std::string &filename) override;
    
    void print() const override;
    std::unique_ptr<Value> cloneValue() const override;
    std::unique_ptr<Expr> cloneExpr() const override;
    void accept(Visitor* visitor) override;
};

#endif