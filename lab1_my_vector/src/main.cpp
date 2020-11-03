// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <iostream>
#include "test.h"

int main() {
    if (test_constructor() != 0) {
        std::cout << "failed constructors: " << test_constructor() << std::endl;
    } else {
        std::cout << "success constructors"<< std::endl;
    }

    if (test_getters() != 0) {
        std::cout << "failed getters: " << test_getters() << std::endl;
    } else {
        std::cout << "success getters"<< std::endl;
    }

    if (test_operators() != 0) {
        std::cout << "failed operators: " << test_operators() << std::endl;
    } else {
        std::cout << "success operators"<< std::endl;
    }

    if (test_iterators() != 0) {
        std::cout << "failed iterators: " << test_iterators() << std::endl;
    } else {
        std::cout << "success iterators"<< std::endl;
    }

    if (test_insertions() != 0) {
        std::cout << "failed insertions: " << test_operators() << std::endl;
    } else {
        std::cout << "success insertions"<< std::endl;
    }

    return 0;
}
