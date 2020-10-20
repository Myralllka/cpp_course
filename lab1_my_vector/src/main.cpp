// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <iostream>
#include <vector>
#include "my_vector.hpp"

int vact() {
    std::vector<int> int_vector;

    int_vector.data();
//    for (int i = 0; i < 100; ++i) {
//        int_vector.push_back(i);
//    }
    int_vector.push_back(5);
    int_vector.begin();
//    std::cout << int_vector.capacity() << std::endl;
//    for (size_t i = 0; i < int_vector.size(); ++i) {
//        std::cout << int_vector.max_size() << std::endl;
//    }

    return 0;
}

int main() {
    my_vector<int> vec;
    vec.reserve(20);
    my_vector<std::string> words{"hello", "my", "dear friend"};
    std::cout << vec.size() << std::endl;
    std::cout << vec.max_size() << std::endl;

    vact();
    return 0;
}
