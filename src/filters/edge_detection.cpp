#include "../../include/filters/edge_detection.h"

Color EdgeDetection::Transform(const std::vector<Color> &matrix_pixel, const std::vector<float> &params) {
    Color ans = 4 * matrix_pixel[1 * 3 + 1] - matrix_pixel[0 * 3 + 1] - matrix_pixel[1 * 3 + 0] -
                matrix_pixel[1 * 3 + 2] - matrix_pixel[2 * 3 + 1];
    if (ans.GetRed() > params[0]) {
        return Color{1, 1, 1};
    }
    return Color{0, 0, 0};
}
