// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <iostream>
#include "my_vector.hpp"

int main() {
    my_vector<int> vec;
    vec.reserve(20);
    my_vector<std::string> words{"hello", "my", "dear friend"};
    std::cout << vec.size() << std::endl;
    std::cout << vec.max_size() << std::endl;
    for (auto &el:words) {
        std::cout << el << std::endl;
    }

    return 0;
}
