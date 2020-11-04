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
    if (!mv_empty.is_empty()) return 8;
    return 0;
}

int test_operators() {
    INIT
    // equalities already tested in test_constructor
    if (int_1 > int_1_bigger) return 1;
    if (int_1 < int_1_smaller) return 2;
    if (int_1 >= int_1_bigger) return 3;
    if (int_1 <= int_1_smaller) return 4;
    if (int_1[1] != 2) return 5;
    if (string_1[2] != "c") return 6;
    try {
        int_1.at(static_cast<size_t>(4));
    } catch (ArrayOutOfBoundsException &err) {
        std::cerr << "successfully throwed an exception" << std::endl;
    }
    my_vector<std::string> cp = string_1_smaller;

    return 0;
}

int test_iterators() {
    INIT
    for (auto &el1:int_1) {
        ++el1;
    }
    size_t a = 0;
    for (auto &el1:int_1) {
        if (el1 - 1 != int_copy[a++]) {
            return 1;
        }
    }
    a = 0;
    for (const auto &el1:int_1) {
        if (el1 - 1 != int_copy[a++]) {
            return 2;
        }
    }
    a = 0;
    for (auto el = int_1.cbegin(); el != int_1.cend(); ++el) {
        if (*el - 1 != int_copy[a++]) {
            return 3;
        }
    }
    return 0;
}

int test_insertions() {
    INIT
    int_1.insert(int_1.begin() + 1, int_3.begin(), int_3.end());
    if (int_1[1] != int_3[0] or int_1[2] != int_3[1]) return 1;
    int_2.insert(int_2.cbegin(), 4);
    if (int_2[0] != 4) return 2;
    int_3.insert(int_3.cbegin() + 2, {1, 2, 3});
    if (int_3[2] != 1 or int_3[3] != 2 or int_3[4] != 3) return 3;
    int_1.push_back(199);
    my_vector<int> b{my_vector<int>{10, 11, 12, 13, 14, 15}};
    mv_1.push_back(b);
    if (mv_1.back() != b) return 4;
    mv_1.push_back(std::move(b));

//    mv_copy.emplace_back();
    return 0;
}

int test_other() {
    INIT
    size_t n = 56;
    auto a = my_vector<int>{};
    a.reserve(n);
    if (a.capacity() != n) return 1;
    for (size_t i = 0; i < n; ++i) {
        a.push_back(i);
    }
    a.erase(a.begin() + 2, a.begin() + 22);
    if (a.size() != n - 20) return 2;
    a.pop_back();
    if (a.size() != n - 21) return 3;
    int_1.fast_clear();
    a.resize(12);
//    for (auto &el:a) {
//        std::cout << el << ", ";
//    }
    std::cout << "\n";
    a.erase(a.begin());
    a.erase(a.end());
//    for (auto &el:a) {
//        std::cout << el << ", ";
//    }
    a.shrink_to_fit();
    if (a.size() != a.capacity()) return 4;
    string_1.swap(string_1_bigger);
    if (string_copy != string_1_bigger) return 5;


    return 0;
}