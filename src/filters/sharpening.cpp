#include "../../include/filters/sharpening.h"
const int FIVE = 5;

Color Sharp::Transform(const std::vector<Color> &matrix_pixel, const std::vector<float> &params) {
    Color ans = FIVE * matrix_pixel[1 * 3 + 1] - matrix_pixel[0 * 3 + 1] - matrix_pixel[1 * 3 + 0] -
                matrix_pixel[1 * 3 + 2] - matrix_pixel[2 * 3 + 1];
    ans.Normalize();
    return ans;
}
