#pragma once

#include "matrix.h"
#include "string"

class Image {
public:
    Image() = default;

    ~Image() = default;

    Image(int width, int height);

    Image(int width, int height, const Matrix &colors);

    int GetWidth() const;

    int GetHeight() const;

    Matrix GetMatrix() const;

    Color GetColor(int i, int j) const;

private:
    int width_;
    int height_;
    Matrix colors_;
};
