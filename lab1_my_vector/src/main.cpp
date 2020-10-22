// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <iostream>
#include <vector>
#include "my_vector.hpp"

int main() {
    my_vector<std::string> vec{5, "A"};
    my_vector<std::string> vec2{vec};
//    for (size_t i = 0; i < 1000000; ++i) {
//        vec.push_back(std::to_string(i));
//    }
//    vec.print();
    std::vector<int> real_vector{1, 2, 3, 4, 5, 6, 7};
//    my_vector<std::string> vec2{17};

//    vec = vec2;
//    real_vector.ins
    vec2.print();
    return 0;
}
