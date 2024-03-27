#include "../../include/filters/crop.h"

Image Crop::Apply(const Image &image, const std::vector<float> &params) {
    int width = image.GetWidth();
    int height = image.GetHeight();

    int width_sp = std::min(static_cast<int>(params[0]), width);
    int height_sp = height - std::min(height, static_cast<int>(params[1]));

    Matrix image_matrix{image.GetMatrix()};
    Matrix matrix{width_sp, height - height_sp};
    std::vector<Color> line;
    for (int i = height_sp; i < height; ++i) {
        line = image_matrix[i];
        for (int j = 0; j < width_sp; ++j) {
            matrix[i - height_sp][j] = line[j];
        }
    }
    return Image{width_sp, height - height_sp, matrix};
}
