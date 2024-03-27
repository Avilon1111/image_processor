#include "../../include/filters/negative.h"

Color Negative::Transform(const Color &pixel, const std::vector<float> &params) {
    Color ans = (1.f - pixel);
    ans.Normalize();
    return ans;
}
