// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <iostream>
#include <vector>
#include "tests.h"

int main() {
    if (!constructors_setters_getters_test()) {
        std::cout << "passed" << std::endl;
    } else {
        std::cout << constructors_setters_getters_test() << " - failed" << std::endl;
        return 1;
    }

    if (!operators_test()) {
        std::cout << "passed" << std::endl;
    } else {
        std::cout << operators_test() << " - failed" << std::endl;
        return 1;
    }

    if (!algo_test()) {
        std::cout << "passed" << std::endl;
    } else {
        std::cout << algo_test() << " - failed" << std::endl;
        return 1;
    }
    double res = 4;
    int flag = -1;
    for (size_t n = 1; n < 20000; ++n) {
        auto tmp = ratio_t{4*flag, static_cast<ssize_t>(n*2+1)};
        res += static_cast<double>(tmp);
        flag = -flag;
    }
    auto p = static_cast<double>(res);
    std::cout << p;

    return 0;
}
