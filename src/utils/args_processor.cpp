#include "../../include/utils/args_processor.h"

ArgsProcessor::ArgsProcessor(int argc, char **argv) {
    input_file_name_ = argv[1];
    output_file_name_ = argv[2];

    std::vector<float> parameters;
    std::string func_name;
    for (int i = 3; i < argc; ++i) {
        if (argv[i][0] == '-') {
            if (!func_name.empty()) {
                filters_.push_back(FilterInfo(func_name, parameters));
                parameters.clear();
            }
            func_name = argv[i];
        } else {
            parameters.push_back(std::stof(argv[i]));
        }
    }
    if (!func_name.empty()) {
        filters_.push_back(FilterInfo(func_name, parameters));
    }
}

const std::string &ArgsProcessor::GetInputFile() const {
    return input_file_name_;
}

const std::string &ArgsProcessor::GetOutputFile() const {
    return output_file_name_;
}

const std::vector<FilterInfo> &ArgsProcessor::GetFilters() const {
    return filters_;
}

FilterInfo::FilterInfo(std::string name, std::vector<float> params) : name_(name), params_(params) {
}

std::string FilterInfo::GetFilterName() {
    return name_;
}

std::vector<float> FilterInfo::GetFilterParams() {
    return params_;
}
