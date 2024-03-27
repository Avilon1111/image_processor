#pragma once

#include "matrix_filter.h"

class Sharp : public MatrixFilter {
public:
    ~Sharp() override = default;

    Color Transform(const std::vector<Color> &matrix_pixel, const std::vector<float> &params) override;
};