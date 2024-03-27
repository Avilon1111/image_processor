#pragma once

#include "point_filter.h"

class Grayscale : public PointFilter {
public:
    ~Grayscale() override = default;

    Color Transform(const Color &pixel, const std::vector<float> &params) override;
};