#pragma once

#include "filter.h"
#include "cmath"

class Crop : public Filter {
public:
    ~Crop() override = default;

    Image Apply(const Image &image, const std::vector<float> &params) override;
};