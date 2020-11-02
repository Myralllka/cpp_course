// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com


//
// Created by myralllka on 02/11/2020.
//

#include <test.h>
#include <string>
#include "my_vector.hpp"

int test_constructor() {
    my_vector<int> int_empty{};
    my_vector<int> int_1{1, 2, 3};
    my_vector<int> int_2(5, 6);
    my_vector<int> int_3{5, 6};
    my_vector<int> int_copy{int_1};

    my_vector<std::string> string_empty{};
    my_vector<std::string> string_1{"a", "b", "c"};
    my_vector<std::string> string_2{1, "c"};
    my_vector<std::string> string_copy{string_1};

    my_vector<my_vector<int>> mv_empty{};
    my_vector<my_vector<int>> mv_1{my_vector<int>{1}, my_vector<int>{2}, my_vector<int>(1000, 2)};
    my_vector<my_vector<int>> mv_copy{mv_1};


    if (int_empty != int_copy) {

    }
    return 0;
}

int test_push() {
    return 0;
}


int test_getters() {
    return 0;
}

int test_operators() {
    return 0;
}

int test_insertions() {
    return 0;
}

int test_iterators() {
    return 0;
}