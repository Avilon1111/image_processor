#include "../../include/filters/gaussian_blur.h"

Image GaussianBlur::Apply(const Image &image, const std::vector<float> &params) {
    int width = image.GetWidth();
    int height = image.GetHeight();
    float sigma = params[0];
    Matrix matrix{image.GetMatrix()};

    Matrix horizontal_blur{width, height};
    for (int i = 0; i < height; ++i) {
        horizontal_blur[i] = HorizontalBlur(matrix[i], sigma);
    }
    Matrix matrix_transposed{Transpose(horizontal_blur)};
    for (int i = 0; i < width; ++i) {
        matrix_transposed[i] = HorizontalBlur(matrix_transposed[i], sigma);
    }
    Matrix vertical_blur{Transpose(matrix_transposed)};

    return Image{width, height, vertical_blur};
}

std::vector<Color> GaussianBlur::HorizontalBlur(const std::vector<Color> &line, float sigma) {
    int size = static_cast<int>(line.size());
    std::vector<Color> result(size);

    const float const1 = 0.39894;

    int delta = static_cast<int>(std::ceil(3 * sigma));
    int i_left, i_right;  // NOLINT
    Color ans;
    for (int pixel_id = 0; pixel_id < size; ++pixel_id) {
        i_left = pixel_id - delta;
        i_right = pixel_id + delta;
        ans = {0, 0, 0};
        for (int i = i_left; i < i_right; ++i) {
            float dif_pos = static_cast<float>(pixel_id - i);
            if (i < 0) {
                ans += line[0] * std::exp(-(dif_pos * dif_pos) / (2 * sigma * sigma));
            } else if (i >= size) {
                ans += line[size - 1] * std::exp(-(dif_pos * dif_pos) / (2 * sigma * sigma));
            } else {
                ans += line[i] * std::exp(-(dif_pos * dif_pos) / (2 * sigma * sigma));
            }
        }
        ans *= const1 / sigma;
        result[pixel_id] = ans;
    }
    return result;
}
