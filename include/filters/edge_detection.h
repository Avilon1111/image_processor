#pragma once

#include "matrix_filter.h"

class EdgeDetection : public MatrixFilter {
public:
    ~EdgeDetection() override = default;

    Color Transform(const std::vector<Color> &matrix_pixel, const std::vector<float> &params) override;
};