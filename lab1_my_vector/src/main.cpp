// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <iostream>
#include <vector>
#include "my_vector.hpp"
#include "test.h"

int main() {
    if (test_constructor() != 0) {
        std::cout << "failed constructors: " << test_constructor() << std::endl;
    } else {
        std::cout << "success constructors"<< std::endl;
    }

    if (test_push() != 0) {
        std::cout << "failed push: " << test_push() << std::endl;
    }

    if (test_getters() != 0) {
        std::cout << "failed getters: " << test_getters() << std::endl;
    }

    if (test_constructor() != 0) {
        std::cout << "failed constructors: " << test_constructor() << std::endl;
    }

    if (test_operators() != 0) {
        std::cout << "failed operators: " << test_operators() << std::endl;
    }

    if (test_insertions() != 0) {
        std::cout << "failed insertions: " << test_operators() << std::endl;
    }

    if (test_iterators() != 0) {
        std::cout << "failed iterators: " << test_iterators() << std::endl;
    }



    return 0;
}
