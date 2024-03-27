#include "../../include/filters/grayscale.h"

const float RED = 0.299f;
const float GREEN = 0.587f;
const float BLUE = 0.114f;

Color Grayscale::Transform(const Color &pixel, const std::vector<float> &params) {

    float num = RED * pixel.GetRed() + GREEN * pixel.GetGreen() + BLUE * pixel.GetBlue();
    Color ans = Color{num, num, num};
    ans.Normalize();
    return ans;
}
