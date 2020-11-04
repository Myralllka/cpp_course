// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <iostream>
#include "test.h"

int main() {
    auto a = test_constructor();
    if (a != 0) {
        std::cout << "failed constructors: " << a << std::endl;
        return -1;
    } else
        std::cout << "success constructors" << std::endl;
    a = test_getters();
    if (a != 0) {
        std::cout << "failed getters: " << a << std::endl;
        return -1;
    } else
        std::cout << "success getters" << std::endl;
    a = test_operators();
    if (a != 0) {
        std::cout << "failed operators: " << a << std::endl;
        return -1;
    } else
        std::cout << "success operators" << std::endl;
    a = test_iterators();
    if (a != 0) {
        std::cout << "failed iterators: " << a << std::endl;
        return -1;
    } else
        std::cout << "success iterators" << std::endl;
    a = test_insertions();
    if (a != 0) {
        std::cout << "failed insertions: " << a << std::endl;
    } else
        std::cout << "success insertions" << std::endl;
    a = test_other();
    if (a != 0) {
        std::cout << "failed other: " << a << std::endl;
        return -1;
    } else
        std::cout << "success other" << std::endl;

    return 0;
}
