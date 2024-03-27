#pragma once

#include "memory"
#include "filters/filter.h"
#include "data/image.h"

#include "utils/args_processor.h"
#include "filters/crop.h"
#include "filters/edge_detection.h"
#include "filters/gaussian_blur.h"
#include "filters/grayscale.h"
#include "filters/matrix_filter.h"
#include "filters/negative.h"
#include "filters/sharpening.h"

class Pipeline {
public:
    explicit Pipeline(const std::vector<FilterInfo> &filters);

    Image ProcessAll(const Image &image);

private:
    static Image Process(const Image &image, std::string_view filter_name, const std::vector<float> &filter_params);

private:
    std::vector<FilterInfo> filters_;
};
