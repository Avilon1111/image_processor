#pragma once

#include "point_filter.h"

class Negative : public PointFilter {
public:
    ~Negative() override = default;

    Color Transform(const Color &pixel, const std::vector<float> &params) override;
};