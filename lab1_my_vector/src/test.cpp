// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com


//
// Created by myralllka on 02/11/2020.
//

#include <test.h>
#include <string>
#include "my_vector.hpp"

#define INIT     my_vector<int> int_empty{}; \
my_vector<int> int_1{1, 2, 3};               \
my_vector<int> int_1_bigger{1, 2, 4};\
my_vector<int> int_1_smaller{1, 2, 2};\
my_vector<int> int_2(5, 6); \
my_vector<int> int_3{5, 6}; \
my_vector<int> int_copy{int_1}; \
my_vector<std::string> string_empty{}; \
my_vector<std::string> string_1{"a", "b", "c"}; \
my_vector<std::string> string_1_bigger{"a", "b", "f"}; \
my_vector<std::string> string_1_smaller{"a", "b", "a"}; \
my_vector<std::string> string_2{1, "c"}; \
my_vector<std::string> string_copy{string_1}; \
my_vector<my_vector<int>> mv_empty{}; \
my_vector<my_vector<int>> mv_1{my_vector<int>{1}, my_vector<int>{2}, my_vector<int>(1000, 2)}; \
my_vector<my_vector<int>> mv_copy{mv_1};

int test_constructor() {
    INIT

    if (int_copy != int_1) return 1;
    if (string_copy != string_1) return 2;
    if (mv_copy != mv_1) return 3;

    my_vector<int> int_move{std::move(int_copy)};
    my_vector<std::string> string_move{std::move(string_copy)};
    my_vector<my_vector<int>> mv_move{std::move(mv_copy)};

    if (int_move != int_1) return 4;
    if (string_move != string_1) return 5;
    if (mv_move != mv_1) return 6;

    return 0;
}

int test_getters() {
    INIT

    if (int_2.size() != 5) return 1;
    if (string_1.size() != 3) return 2;
    if (mv_1.size() != 3) return 3;
    if (mv_empty.capacity() != 2) return 4;
    if (mv_1.capacity() != 6) return 5;
    if (int_1.front() != 1) return 6;
    if (int_1.back() != 3) return 6;
    if (int_2.front() != int_2.back()) return 7;
    if (! mv_empty.is_empty()) return 8;
    return 0;
}

int test_operators() {
    INIT
    // equalities already tested in test_constructor
    if (int_1 > int_1_bigger) return 1;
    if (int_1 < int_1_smaller) return 2;
    if (!(int_1 >= int_1_bigger)) return 3;
    if (!(int_1 <= int_1_smaller)) return 4;
    if (int_2[1] != 2) return 5;
    if (string_1[2] != "c") return 6;
    try {
        int_1.at(3);
    } catch (ArrayOutOfBoundsException &err) {
        std::cout << "throwed an exception" << std::endl;
    }
    my_vector<std::string> cp = string_1_smaller;

    return 0;
}

int test_insertions() {
    INIT

    return 0;
}

int test_iterators() {
    INIT

    return 0;
}