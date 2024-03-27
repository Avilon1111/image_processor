#pragma once

#include "tuple"
#include "vector"
#include "string"

class FilterInfo {
public:
    FilterInfo() = default;

    FilterInfo(std::string name, std::vector<float> params);

    std::string GetFilterName();

    std::vector<float> GetFilterParams();

private:
    std::string name_;
    std::vector<float> params_;
};

class ArgsProcessor {
public:
    ArgsProcessor(int argc, char **argv);

public:
    const std::string &GetInputFile() const;

    const std::string &GetOutputFile() const;

    const std::vector<FilterInfo> &GetFilters() const;

private:
    std::string input_file_name_;
    std::string output_file_name_;
    std::vector<FilterInfo> filters_;
};
