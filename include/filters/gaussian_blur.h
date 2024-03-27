#pragma once

#include "filter.h"
#include "cmath"

class GaussianBlur : public Filter {
public:
    ~GaussianBlur() override = default;

    Image Apply(const Image &image, const std::vector<float> &params) override;

private:
    static std::vector<Color> HorizontalBlur(const std::vector<Color> &line, float sigma);
};
