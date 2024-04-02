#include "../../include/io/bmp.h"

const float C1 = 255.0f;

Image BMP::Load(const std::string &input_path) {

    std::ifstream f;
    f.open(input_path, std::ios::in | std::ios::binary);

    if (!f.is_open()) {
        std::runtime_error("File could not be opened");
    }
    f.read(reinterpret_cast<char *>(&bmp_file_header_), sizeof(bmp_file_header_));
    if (bmp_file_header_.file_type != SIGNATURE) {
        throw std::runtime_error("Error! Unrecognized file format.");
    }
    f.read(reinterpret_cast<char *>(&bmp_info_header_), sizeof(bmp_info_header_));

    bmp_info_header_.size = sizeof(BMPInfoHeader);
    bmp_file_header_.offset_data = sizeof(BMPFileHeader) + sizeof(BMPInfoHeader);
    bmp_info_header_.unused[2] = 0;
    bmp_file_header_.file_size = bmp_file_header_.offset_data;

    Matrix colors{static_cast<int>(bmp_info_header_.width), static_cast<int>(bmp_info_header_.height)};

    const int padding_amount = ((4 - (bmp_info_header_.width * 3) % 4) % 4);

    float r, g, b;  // NOLINT
    std::vector<Color> line(bmp_info_header_.width);
    unsigned char color[3 * bmp_info_header_.width];
    unsigned char *blue_pointer;  // NOLINT
    for (int y = 0; y < bmp_info_header_.height; ++y) {
        f.read(reinterpret_cast<char *>(color), 3 * bmp_info_header_.width);
        for (int x = 0; x < bmp_info_header_.width; ++x) {
            blue_pointer = &color[0];
            blue_pointer += 3 * x;
            b = static_cast<float>(*(blue_pointer)) / C1;
            g = static_cast<float>(*(blue_pointer + 1)) / C1;
            r = static_cast<float>(*(blue_pointer + 2)) / C1;

            line[x] = Color{r, g, b};
        }
        colors[y].swap(line);
        f.ignore(padding_amount);
    }
    f.close();
    Image ans{bmp_info_header_.width, bmp_info_header_.height, colors};

    return ans;
}

void BMP::Save(const Image &image, const std::string &output_path) {
    bmp_info_header_.width = image.GetWidth();
    bmp_info_header_.height = image.GetHeight();
    std::ofstream f;
    f.open(output_path, std::ios::out | std::ios::binary);

    if (!f.is_open()) {
        std::runtime_error("File could not be opened");
    }

    const int padding_amount = ((4 - (bmp_info_header_.width * 3) % 4) % 4);

    if (bmp_info_header_.bit_count != SIX * 4) {
        throw("The program can treat only 24 bits per pixel BMP files");
    }

    f.write(reinterpret_cast<char *>(&bmp_file_header_), sizeof(bmp_file_header_));
    f.write(reinterpret_cast<char *>(&bmp_info_header_), sizeof(bmp_info_header_));

    Matrix m = image.GetMatrix();
    Color col;
    std::vector<Color> line;
    unsigned char pad[3]{0, 0, 0};
    unsigned char line_output[3 * bmp_info_header_.width];

    for (int y = 0; y < bmp_info_header_.height; ++y) {
        line = m[y];
        for (int x = 0; x < bmp_info_header_.width; ++x) {
            col = line[x];

            line_output[3 * x + 2] = static_cast<unsigned char>(col.GetRed() * C1);
            line_output[3 * x + 1] = static_cast<unsigned char>(col.GetGreen() * C1);
            line_output[3 * x] = static_cast<unsigned char>(col.GetBlue() * C1);
        }
        f.write(reinterpret_cast<char *>(line_output), 3 * bmp_info_header_.width);
        f.write(reinterpret_cast<char *>(pad), padding_amount);
    }

    f.close();
}
