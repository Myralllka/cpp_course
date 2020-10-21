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
    std::unique_ptr<T[]> buffer;
    size_t real_size;
    size_t real_capacity;
public:
    my_vector() : buffer(new T[1]), real_size(0), real_capacity(1) {};

    [[maybe_unused]] my_vector(std::initializer_list<T> el) : buffer(new T[el.size()]),
                                                              real_size(el.size()),
                                                              real_capacity(el.size() * 2) {
        size_t i = 0;
        for (auto &&entry:el) {
            buffer[i++] = std::move(entry);
        }
    }

    ~my_vector() {
        real_size = 0;
        real_capacity = 0;
        buffer.reset();
    };

    [[maybe_unused]] [[maybe_unused]] size_t size();

    [[maybe_unused]] [[maybe_unused]] size_t max_size();

    [[maybe_unused]] [[maybe_unused]] [[maybe_unused]] size_t capacity();

    [[maybe_unused]] [[maybe_unused]] void reserve(size_t size);

    [[maybe_unused]] const T &operator[](size_t index);

    [[maybe_unused]] [[maybe_unused]] T back();

    [[maybe_unused]] [[maybe_unused]] T front();

    [[maybe_unused]] [[maybe_unused]] void push_back(T &&element);

    [[maybe_unused]] void pop_back(T &&element) {}

    [[maybe_unused]] void pop_front(T &&element) {}

    [[maybe_unused]] void insert(T &element);

    [[nodiscard]] const T *begin() const;

    T *begin();

    [[nodiscard]] const T *end() const;

    T *end();

    [[maybe_unused]] [[maybe_unused]] void clear();
};

#include "my_vector_realization.hpp"

#endif //TEST_MY_VECTOR_H
