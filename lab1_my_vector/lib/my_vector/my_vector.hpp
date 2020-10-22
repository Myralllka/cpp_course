// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

//
// Created by myralllka on 10/20/20.
//

#ifndef TEST_MY_VECTOR_H
#define TEST_MY_VECTOR_H

#include "memory"

template<typename T>
class my_vector {
private:
    std::unique_ptr<T[]> buffer_m;
    size_t size_m;
    size_t capacity_m;
public:
    my_vector() : buffer_m(new T[1]), size_m{0}, capacity_m{1} {};

    [[maybe_unused]] explicit my_vector(size_t size, T init_val = T{}) : size_m{size},
                                                                         capacity_m{size == 0 ? 2 : size} {
        for (size_t i = 0; i < size; ++i) {
            buffer_m[i] = init_val;
        }
    }

    [[maybe_unused]] my_vector(std::initializer_list<T> el) : buffer_m{new T[el.size()]},
                                                              size_m{el.size()},
                                                              capacity_m{el.size() * 2} {
        size_t i = 0;
        for (auto &&entry:el) {
            buffer_m[i++] = std::move(entry);
        }
    }

    ~my_vector() {
        buffer_m.reset();
        buffer_m = nullptr;
    };

    [[maybe_unused]] [[maybe_unused]] size_t size();

    [[maybe_unused]] [[maybe_unused]] size_t max_size();

    [[maybe_unused]] [[maybe_unused]] [[maybe_unused]] size_t capacity();

    [[maybe_unused]] [[maybe_unused]] void reserve(size_t size);

    [[maybe_unused]] const T &operator[](size_t index);

    [[maybe_unused]] [[maybe_unused]] T back();

    [[maybe_unused]] [[maybe_unused]] T front();

    [[maybe_unused]] [[maybe_unused]] void push_back(T &&element);

//    [[maybe_unused]] void pop_back(T &&element) {}
//
//    [[maybe_unused]] void pop_front(T &&element) {}

//    [[maybe_unused]] void insert(T &element);

    [[nodiscard]] const T *begin() const;

    T *begin();

    [[nodiscard]] const T *end() const;

    T *end();

    [[maybe_unused]] [[maybe_unused]] void clear();
};

#include "my_vector_realization.hpp"

#endif //TEST_MY_VECTOR_H
