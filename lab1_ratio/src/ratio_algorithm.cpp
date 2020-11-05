//
// Created by myralllka on 10/28/20.
//

#include "lib_ratio.hpp"

ratio_t &rmax(ratio_t &lhs, ratio_t &rhs) {
    return lhs.numerator * rhs.denominator > rhs.numerator * lhs.denominator ? lhs : rhs;
}

ratio_t &rmin(ratio_t &lhs, ratio_t &rhs) {
    return lhs.numerator * rhs.denominator < rhs.numerator * lhs.denominator ? lhs : rhs;
}

ratio_t rabs(ratio_t &num) {
    return ratio_t{std::abs(num.numerator), std::abs(num.denominator)};
}