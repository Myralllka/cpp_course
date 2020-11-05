//
// Created by myralllka on 10/28/20.
//

#include <sstream>
#include "tests.h"

ratio_t a{}, b{}, c{}, d{}, e{};

int constructors_setters_getters_test() {
    a = ratio_t{};
    b = ratio_t{1, 2};
    c = ratio_t{333, 999};
    d = ratio_t{0, 0};
    e = ratio_t{1, 0};
    if (a.get_numerator() != 0) return 1;
    if (a.get_denominator() != 1) return 2;
    if (b.get_numerator() != 1) return 3;
    if (b.get_denominator() != 2) return 4;
    if (c.get_numerator() != 1) return 5;
    if (c.get_denominator() != 3) return 6;
    a.set_numerator(12);
    a.set_denominator(34);
    if (a.get_numerator() != 6) return 7;
    if (a.get_denominator() != 17) return 8;
    if (d.get_denominator() != std::numeric_limits<ssize_t>::quiet_NaN()) return 9;
    if (d.get_numerator() != std::numeric_limits<ssize_t>::quiet_NaN()) return 10;
    if (e.get_numerator() != std::numeric_limits<ssize_t>::max()) return 11;
    return 0;
}

int operators_test() {
    a = ratio_t{};
    b = ratio_t{1, 2};
    c = ratio_t{333, 999};
    d = ratio_t{1, 12};
    e = ratio_t{0, 0};
    auto f = ratio_t{4, 3};
    auto sum = ratio_t{7, 12};
    auto eq = ratio_t{1, 3};
    auto prod = ratio_t{4, 36};
    auto dev = ratio_t{4, 1};
    if (b + d != sum) return 1;
    if (c < b) return 2;
    if (eq != c) return 3;
    if (not(eq >= c)) return 4;
    std::string out = "1/3";
    std::stringstream ratio_out{};
    ratio_out << c;
    if (ratio_out.str() != out) return 5;
//    std::cin >> a;
//    if (a != c) return 6;
    if (++c != f) return 7;
    if (c++ != f) return 8;
    c--;
    if (--c != eq) return 9;
    if (c-- != eq) return 10;
    c++;
    if (d * f != prod) return 11;
    if (c / d != dev) return 12;
    double r = 1.0 / 12;
    if (static_cast<double>(d) - r >= std::numeric_limits<double>::epsilon()) return 13;
    return 0;
}

int algo_test() {
    a = ratio_t{};
    b = ratio_t{1, 2};
    c = ratio_t{333, 999};
    d = ratio_t{1, 12};
    e = ratio_t{0, 0};
    auto neg = ratio_t{-2, 3};
    if (rabs(neg) != ratio_t{2, 3}) return 1;
    if (rmax(b, c) != b) return 2;
    if (rmin(b, c) != c) return 3;
    return 0;
}