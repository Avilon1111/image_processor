#include "../../include/data/color.h"

Color::Color() {
    Set(0, 0, 0);
}

Color::Color(float r, float g, float b) {
    Set(r, g, b);
}

float Color::GetRed() const {
    return r_;
}

float Color::GetGreen() const {
    return g_;
}

float Color::GetBlue() const {
    return b_;
}

Color &operator+=(Color &lhs, const Color &rhs) {
    lhs.r_ += rhs.r_;
    lhs.g_ += rhs.g_;
    lhs.b_ += rhs.b_;
    lhs.Set(lhs.r_, lhs.g_, lhs.b_);
    return lhs;
}

Color &operator*=(Color &lhs, const Color &rhs) {
    lhs.r_ *= rhs.r_;
    lhs.g_ *= rhs.g_;
    lhs.b_ *= rhs.b_;
    lhs.Set(lhs.r_, lhs.g_, lhs.b_);
    return lhs;
}

Color operator+(const Color &pixel) {
    return pixel;
}

Color operator-(const Color &pixel) {
    return Color{-pixel.GetRed(), -pixel.GetGreen(), -pixel.GetBlue()};
}

Color &operator-=(Color &lhs, const Color &rhs) {
    lhs += -rhs;
    return lhs;
}

Color &operator/=(Color &lhs, const Color &rhs) {
    lhs *= Color{1 / rhs.GetRed(), 1 / rhs.GetGreen(), 1 / rhs.GetBlue()};
    return lhs;
}

Color operator+(const Color &lhs, const Color &rhs) {
    Color result{lhs};
    result += rhs;
    return result;
}

Color operator-(const Color &lhs, const Color &rhs) {
    Color result{lhs};
    result -= rhs;
    return result;
}

Color operator*(const Color &lhs, const Color &rhs) {
    Color result{lhs};
    result *= rhs;
    return result;
}

Color operator/(const Color &lhs, const Color &rhs) {
    Color result{lhs};
    result /= rhs;
    return result;
}

bool operator==(const Color &lhs, const Color &rhs) {
    return lhs.GetRed() == rhs.GetRed() && lhs.GetBlue() == rhs.GetBlue() && lhs.GetGreen() == rhs.GetGreen();
}

bool operator!=(const Color &lhs, const Color &rhs) {
    return !(lhs == rhs);
}

Color operator-(const float &lhs, const Color &rhs) {
    return Color(lhs, lhs, lhs) - rhs;
}

Color operator-(const Color &lhs, const float &rhs) {
    return rhs - lhs;
}

Color operator+(const float &lhs, const Color &rhs) {
    return Color(lhs, lhs, lhs) + rhs;
}

Color operator+(const Color &lhs, const float &rhs) {
    return rhs + lhs;
}

Color operator*(const float &lhs, const Color &rhs) {
    return Color(lhs, lhs, lhs) * rhs;
}

Color operator*(const Color &lhs, const float &rhs) {
    return rhs * lhs;
}

Color operator/(const float &lhs, const Color &rhs) {
    return Color(lhs, lhs, lhs) / rhs;
}

Color operator/(const Color &lhs, const float &rhs) {
    return rhs / lhs;
}

Color &operator*=(Color &lhs, const float &number) {
    lhs *= Color(number, number, number);
    return lhs;
}

void Color::Set(float r, float g, float b) {
    r_ = r;
    g_ = g;
    b_ = b;
}

void Color::Normalize() {
    r_ = std::min(1.f, std::max(r_, 0.f));
    g_ = std::min(1.f, std::max(g_, 0.f));
    b_ = std::min(1.f, std::max(b_, 0.f));
}
