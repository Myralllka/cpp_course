//
// Created by myralllka on 10/21/20.
//

#ifndef RATIO_LIB_RATIO_H
#define RATIO_LIB_RATIO_H

#include <memory>
#include <numeric>
#include <iostream>
#include <limits>
#include "cmath"

class ratio_t {
private:
    ssize_t numerator, denominator;

    void reduce();

public:
    ratio_t() : numerator(0), denominator(1) {}

    ratio_t(ssize_t num, ssize_t denom) {
        if (denom == 0) {
            if (num == 0) {
                numerator = std::numeric_limits<ssize_t>::quiet_NaN();
                denominator = std::numeric_limits<ssize_t>::quiet_NaN();
            } else {
                numerator = std::numeric_limits<ssize_t>::max();// TODO infinity
                denominator = 0;
            }
        } else {
            numerator = num;
            denominator = denom;
        }
        reduce();
    }

    ratio_t(ratio_t const &other) {
        numerator = other.numerator;
        denominator = other.denominator;
    }

    ratio_t(ratio_t &&other) noexcept {
        numerator = other.numerator;
        denominator = other.denominator;
        other.~ratio_t();
    }

    ~ratio_t() = default;

// setters and getters
    void set_numerator(ssize_t val);

    void set_denominator(ssize_t val);

    [[nodiscard]] ssize_t get_numerator() const;

    [[nodiscard]] ssize_t get_denominator() const;

// operators
    ratio_t &operator=(ratio_t &&rhs) noexcept {
        numerator = rhs.numerator;
        denominator = rhs.denominator;
        rhs.~ratio_t();
        return *this;
    }

    ratio_t &operator=(ratio_t const &rhs) noexcept {
        numerator = rhs.numerator;
        denominator = rhs.denominator;
        rhs.~ratio_t();
        return *this;
    }

    ratio_t &operator+=(const ratio_t &rhs);

    ratio_t &operator-=(const ratio_t &rhs);

    ratio_t &operator*=(const ratio_t &rhs);

    ratio_t &operator/=(const ratio_t &rhs);

    ratio_t &operator++();

    const ratio_t operator++(int);

    ratio_t &operator--();

    const ratio_t operator--(int);

    auto operator<=>(const ratio_t &) const = default;

    friend std::ostream &operator<<(std::ostream &os, const ratio_t &arg);

    friend std::istream &operator>>(std::istream &input, ratio_t &el);

    explicit operator double() const;

    template<class T>
    operator double() const = delete;

// Algorithms
    friend ratio_t &rmax(ratio_t &lhs, ratio_t &rhs);

    friend ratio_t &rmin(ratio_t &lhs, ratio_t &rhs);

    friend ratio_t rabs(ratio_t &num);
};

ratio_t operator+(ratio_t lhs, const ratio_t &rhs);

ratio_t operator-(ratio_t lhs, const ratio_t &rhs);

ratio_t operator*(ratio_t lhs, const ratio_t &rhs);

ratio_t operator/(ratio_t lhs, const ratio_t &rhs);

std::ostream &operator<<(std::ostream &os, const ratio_t &arg);

#endif //RATIO_LIB_RATIO_H
