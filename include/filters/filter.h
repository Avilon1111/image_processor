#pragma once

#include "../data/image.h"

class Filter {
public:
    Filter() = default;

    virtual ~Filter() = default;

    virtual Image Apply(const Image &image, const std::vector<float> &params) = 0;
};
