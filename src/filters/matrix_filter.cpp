#include "../../include/filters/matrix_filter.h"

Image MatrixFilter::Apply(const Image &image, const std::vector<float> &params) {
    int width = image.GetWidth();
    int height = image.GetHeight();
    Matrix matrix{image.GetMatrix()};
    Matrix ans{matrix};
    std::vector<Color> line_lower = matrix[0];
    std::vector<Color> line = matrix[0];
    std::vector<Color> line_upper = matrix[1];
    int left, right;  // NOLINT
    std::vector<Color> pixels;
    for (int i = 1; i < height + 1; ++i) {
        for (int j = 0; j < width; ++j) {
            left = std::max(0, j - 1);
            right = std::min(width - 1, j + 1);
            pixels = {line_upper[left], line_upper[j],    line_upper[right], line[left],       line[j],
                      line[right],      line_lower[left], line_lower[j],     line_lower[right]};
            ans[i - 1][j] = Transform(pixels, params);
        }
        line_lower.swap(line);
        line_upper.swap(line);
        line_upper = matrix[std::min(height - 1, i + 1)];
    }
    return Image{width, height, ans};
}
