#include "../include/pipeline.h"

Image Pipeline::ProcessAll(const Image &image) {
    Image image_res{image};
    for (FilterInfo filter : filters_) {
        image_res = Process(image_res, filter.GetFilterName(), filter.GetFilterParams());
    }

    return image_res;
}

Image Pipeline::Process(const Image &image, std::string_view filter_name, const std::vector<float> &filter_params) {
    Image after;
    if (filter_name == "-crop") {
        std::unique_ptr<Filter> cr = std::make_unique<Crop>();
        after = cr->Apply(image, filter_params);
    } else if (filter_name == "-gs") {
        std::unique_ptr<PointFilter> gs = std::make_unique<Grayscale>();
        after = gs->Apply(image, filter_params);
    } else if (filter_name == "-neg") {
        std::unique_ptr<PointFilter> neg = std::make_unique<Negative>();
        after = neg->Apply(image, filter_params);
    } else if (filter_name == "-sharp") {
        std::unique_ptr<MatrixFilter> sh = std::make_unique<Sharp>();
        after = sh->Apply(image, filter_params);
    } else if (filter_name == "-edge") {
        std::unique_ptr<PointFilter> gs = std::make_unique<Grayscale>();
        after = gs->Apply(image, {});
        std::unique_ptr<MatrixFilter> ed = std::make_unique<EdgeDetection>();
        after = ed->Apply(after, filter_params);
    } else if (filter_name == "-blur") {
        std::unique_ptr<Filter> gb = std::make_unique<GaussianBlur>();
        after = gb->Apply(image, filter_params);
    }
    return after;
}

Pipeline::Pipeline(const std::vector<FilterInfo> &filters) : filters_(filters) {
}
