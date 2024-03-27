#pragma once

#include "cmath"

class Color {
public:
    Color();

    Color(float r, float g, float b);

    float GetRed() const;

    float GetGreen() const;

    float GetBlue() const;

    friend Color &operator+=(Color &lhs, const Color &rhs);

    friend Color &operator*=(Color &lhs, const Color &rhs);

    void Normalize();

private:
    void Set(float r, float g, float b);

    float r_;
    float g_;
    float b_;
};

Color operator+(const Color &pixel);

Color operator-(const Color &pixel);

Color &operator-=(Color &lhs, const Color &rhs);

Color &operator/=(Color &lhs, const Color &rhs);

Color &operator*=(Color &lhs, const float &number);

Color operator+(const Color &lhs, const Color &rhs);

Color operator+(const float &lhs, const Color &rhs);

Color operator+(const Color &lhs, const float &rhs);

Color operator-(const Color &lhs, const Color &rhs);

Color operator-(const float &lhs, const Color &rhs);

Color operator-(const Color &lhs, const float &rhs);

Color operator*(const Color &lhs, const Color &rhs);

Color operator*(const float &lhs, const Color &rhs);

Color operator*(const Color &lhs, const float &rhs);

Color operator/(const Color &lhs, const Color &rhs);

Color operator/(const float &lhs, const Color &rhs);

Color operator/(const Color &lhs, const float &rhs);

bool operator==(const Color &lhs, const Color &rhs);

bool operator!=(const Color &lhs, const Color &rhs);