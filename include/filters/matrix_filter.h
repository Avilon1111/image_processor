#pragma once

#include "filter.h"

class MatrixFilter : public Filter {
public:
    ~MatrixFilter() override = default;

    Image Apply(const Image &image, const std::vector<float> &params) override;

    virtual Color Transform(const std::vector<Color> &matrix_pixel, const std::vector<float> &params) = 0;
};