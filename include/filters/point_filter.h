
#pragma once

#include "filter.h"

class PointFilter : public Filter {
public:
    ~PointFilter() override = default;

    Image Apply(const Image &image, const std::vector<float> &params) override;

    virtual Color Transform(const Color &pixel, const std::vector<float> &params) = 0;
};
