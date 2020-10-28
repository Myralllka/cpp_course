// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com


//
// Created by myralllka on 10/21/20.
//

#include "lib_ratio.hpp"

ratio_t &ratio_t::operator+=(const ratio_t &rhs) {
    numerator = numerator * rhs.denominator + denominator * rhs.numerator;
    denominator = denominator * rhs.denominator;
    reduce();
    return *this;
}

ratio_t &ratio_t::operator-=(const ratio_t &rhs) {
    numerator = numerator * rhs.denominator - denominator * rhs.numerator;
    denominator = denominator * rhs.denominator;
    reduce();
    return *this;
}

std::ostream &operator<<(std::ostream &os, const ratio_t &arg) {
    if (arg.numerator == std::numeric_limits<ssize_t>::max()) {
        os << "infinity";
    } else if (arg.numerator == std::numeric_limits<ssize_t>::quiet_NaN() or
               arg.denominator == std::numeric_limits<ssize_t>::quiet_NaN()) {
        os << "NaN";
    } else {
        arg.denominator == 1 ? os << arg.numerator : os << arg.numerator << "/" << arg.denominator;
    }
    return os;
}

// istream operator can not read infinity
std::istream &operator>>(std::istream &input, ratio_t &el) {
    ssize_t a, b;
    std::string inf;
    if (input >> a) {
        if (input.peek() == '/') {
            char t;
            input >> t;
            if (input >> b) {
                el.numerator = a;
                el.denominator = b;
            }
        } else {
            el.numerator = a;
            el.denominator = 1;
        }
    }
    el.reduce();
    return input;
}

ratio_t &ratio_t::operator*=(const ratio_t &rhs) {
    numerator *= rhs.numerator;
    denominator *= rhs.denominator;
    reduce();
    return *this;
}

ratio_t &ratio_t::operator/=(const ratio_t &rhs) {
    numerator *= rhs.denominator;
    denominator *= rhs.numerator;
    reduce();
    return *this;
}

void ratio_t::set_numerator(ssize_t val) {
    numerator = val;
    reduce();
}

void ratio_t::set_denominator(ssize_t val) {
    if (val < 0) {
        numerator = -numerator;
    }
    denominator = +val;
    reduce();
}

ssize_t ratio_t::get_numerator() const {
    return numerator;
}

ssize_t ratio_t::get_denominator() const {
    return denominator;
}

ratio_t::operator double() const {
    return static_cast<double>(numerator) / static_cast<double>(denominator);
}

void ratio_t::reduce() {
    if (denominator == 0) {
        if (numerator == 0) {
            denominator = std::numeric_limits<ssize_t>::quiet_NaN();
            numerator = std::numeric_limits<ssize_t>::quiet_NaN();
        } else {
            numerator = std::numeric_limits<ssize_t>::max();
        }
    } else {
        size_t g = std::gcd(denominator, numerator);
        numerator /= g;
        denominator /= g;
    }
}

ratio_t &ratio_t::operator++() {
    numerator += denominator;
    return *this;
}

ratio_t &ratio_t::operator--() {
    numerator -= denominator;
    return *this;
}

const ratio_t ratio_t::operator++(int) {
    ratio_t copy{*this};
    ++(*this);
    return copy;
}

const ratio_t ratio_t::operator--(int) {
    ratio_t copy{*this};
    --(*this);
    return copy;
}

ratio_t operator+(ratio_t lhs, const ratio_t &rhs) {
    return lhs += rhs;
}

ratio_t operator-(ratio_t lhs, const ratio_t &rhs) {
    return lhs -= rhs;
}

ratio_t operator/(ratio_t lhs, const ratio_t &rhs) {
    return lhs /= rhs;
}

ratio_t operator*(ratio_t lhs, const ratio_t &rhs) {
    return lhs *= rhs;
}