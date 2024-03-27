#include "../../include/data/image.h"

Image::Image(int width, int height) : width_(width), height_(height), colors_(Matrix(width, height)) {
}

Image::Image(int width, int height, const Matrix &colors) : width_(width), height_(height), colors_(colors) {
}

int Image::GetWidth() const {
    return width_;
}

int Image::GetHeight() const {
    return height_;
}

Color Image::GetColor(int i, int j) const {
    return colors_[i][j];
}

Matrix Image::GetMatrix() const {
    return colors_;
}
