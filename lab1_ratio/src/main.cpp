// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <iostream>
#include "tests.h"

int main() {
    if (!constructors_setters_getters_test()) {
        std::cout << "passed" << std::endl;
    } else {
        std::cout << constructors_setters_getters_test() << " - failed"<< std::endl;
        return 1;
    }

    if (!operators_test()) {
        std::cout << "passed" << std::endl;
    } else {
        std::cout << operators_test() << " - failed"<< std::endl;
        return 1;
    }
    return 0;
}
