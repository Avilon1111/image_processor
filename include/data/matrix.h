#pragma once

#include "color.h"
#include <vector>

class Matrix {
public:
    Matrix() = default;

    ~Matrix() = default;

    Matrix(int width, int height);

    std::vector<Color> operator[](int y) const;

    std::vector<Color> &operator[](int y);

    int GetWidth() const;

    int GetHeight() const;

private:
    int width_;
    int height_;
    std::vector<std::vector<Color>> colors_;
};

Matrix Transpose(const Matrix &matrix);