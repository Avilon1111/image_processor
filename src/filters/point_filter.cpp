#include "../../include/filters/point_filter.h"

Image PointFilter::Apply(const Image &image, const std::vector<float> &params) {
    int width = image.GetWidth();
    int height = image.GetHeight();
    Matrix matrix{image.GetMatrix()};
    std::vector<Color> line;
    for (int i = 0; i < height; ++i) {
        line = matrix[i];
        for (int j = 0; j < width; ++j) {
            matrix[i][j] = Transform(line[j], params);
        }
    }
    return Image{width, height, matrix};
}
