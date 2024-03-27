#include "../data/image.h"

class ImageFormat {
public:
    ImageFormat() = default;

    virtual ~ImageFormat() = default;

    virtual void Save(const Image &image, const std::string &output_path) = 0;

    virtual Image Load(const std::string &input_path) = 0;
};