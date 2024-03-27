#include "../../include/data/matrix.h"

Matrix::Matrix(int width, int height)
    : width_(width), height_(height), colors_(std::vector<std::vector<Color>>(height, std::vector<Color>(width))) {
}

std::vector<Color> Matrix::operator[](int y) const {
    return colors_[y];
}

std::vector<Color> &Matrix::operator[](int y) {
    return colors_[y];
}

Matrix Transpose(const Matrix &matrix) {
    int width_matrix = matrix.GetWidth();
    int height_matrix = matrix.GetHeight();

    Matrix result{height_matrix, width_matrix};
    std::vector<Color> line;
    for (int i = 0; i < height_matrix; ++i) {
        line = matrix[i];
        for (int j = 0; j < width_matrix; ++j) {
            result[j][i] = line[j];
        }
    }
    return result;
}

int Matrix::GetWidth() const {
    return width_;
}

int Matrix::GetHeight() const {
    return height_;
}
