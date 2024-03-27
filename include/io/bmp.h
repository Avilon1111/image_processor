#pragma once

#include <cstdint>
#include "fstream"
#include "iostream"
#include "../data/image.h"
#include "image_format.h"

const int SIX = 6;
const uint16_t SIGNATURE = {0x4D42};
#pragma pack(push, 1)

struct BMPFileHeader {
    uint16_t file_type{SIGNATURE};
    uint32_t file_size{0};
    uint16_t unused[2]{0};
    uint32_t offset_data{0};
};

struct BMPInfoHeader {
    uint32_t size{0};
    int32_t width{0};
    int32_t height{0};
    uint16_t planes{1};
    uint16_t bit_count{0};
    uint32_t unused[SIX]{0};
};
#pragma pack(pop)

class BMP : public ImageFormat {
public:
    ~BMP() override = default;

    void Save(const Image &image, const std::string &output_path) override;

    Image Load(const std::string &input_path) override;

private:
    BMPFileHeader bmp_file_header_;
    BMPInfoHeader bmp_info_header_;
};
