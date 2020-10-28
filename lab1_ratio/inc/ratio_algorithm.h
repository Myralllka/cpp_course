//
// Created by myralllka on 10/28/20.
//

#ifndef TEST_RATIO_ALGORITHM_H
#define TEST_RATIO_ALGORITHM_H

#include "lib_ratio.hpp"

ratio_t &rmax(ratio_t &lhs, ratio_t &rhs) {
    return lhs.numerator * rhs.denominator > rhs.numerator * lhs.denominator ? lhs : rhs;
}

ratio_t &rmin(ratio_t &lhs, ratio_t &rhs) {
    return lhs.numerator * rhs.denominator < rhs.numerator * lhs.denominator ? lhs : rhs;
}

ratio_t rabs(ratio_t &num) {
    return ratio_t{+num.numerator, +num.denominator};
}

#endif //TEST_RATIO_ALGORITHM_H
