#ifndef JPGIMAGE__GUARD
#define JPGIMAGE__GUARD

#include "expr/value/image/Image.hh"

class JpgImage : virtual public Image
{
private:
    /* data */
public:
    JpgImage() = default;
    JpgImage(const std::string filepath, int width, int height, int channels, int bitsPerChannel = 8);
    ~JpgImage() = default;

    void load(const std::string &filename) override;
    void save(const std::string &filename) override;

    void print() const override;
    std::unique_ptr<Value> cloneValue() const override;
    std::unique_ptr<Expr> cloneExpr() const override;
    void accept(Visitor* visitor) override;
};

#endif