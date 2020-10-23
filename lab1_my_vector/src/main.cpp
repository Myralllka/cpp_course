// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <iostream>
#include <vector>
#include "my_vector.hpp"

int main() {
//    my_vector<std::string> vec{"A", "B", "C", "D", "E"};
    my_vector<size_t> int_vector{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
    my_vector<size_t> int_vector2{100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 112, 14567, 56237};
    std::vector<size_t> real_vector{1, 2, 3, 4, 5, 6, 7};
    int_vector.insert(int_vector.end(), int_vector2.begin(), int_vector2.end());
//    real_vector.insert
//    real_vector.push_back(23);
    int_vector.print();
//    vec2.print();
    return 0;
}
