// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

//
// Created by myralllka on 10/20/20.
//

#ifndef TEST_MY_VECTOR_REALIZATION_H
#define TEST_MY_VECTOR_REALIZATION_H

#include "my_vector.hpp"

template<typename T>
[[maybe_unused]] size_t my_vector<T>::size() {
    return real_size;
}

template<typename T>
[[maybe_unused]] size_t my_vector<T>::capacity() {
    return real_capacity;
}

template<typename T>
[[maybe_unused]] size_t my_vector<T>::max_size() {
    return sizeof(size_t) * 8;
}

template<typename T>
[[maybe_unused]] void my_vector<T>::clear() {
    buffer.reset();
    buffer = new T[1];
    real_size = 0;
    real_capacity = 1;
}

template<typename T>
[[maybe_unused]] void my_vector<T>::reserve(size_t size) {
    real_size = size;
    real_capacity = size;
    std::unique_ptr<T[]> new_buffer{new T[size]};
    buffer.swap(new_buffer);
    new_buffer.reset();
}

template<typename T>
[[maybe_unused]] T my_vector<T>::front() {
    return buffer[0];
}

template<typename T>
[[maybe_unused]] T my_vector<T>::back() {
    return buffer[real_size];
}

template<typename T>
const T &my_vector<T>::operator[](size_t index) {
    return buffer.get(index);
}

template<typename T>
[[maybe_unused]] void my_vector<T>::push_back(T &&element) {
    if (real_size == real_capacity) {
        std::unique_ptr<T[]> new_buffer{new T[real_size * 2]};
        real_capacity = real_size * 2;
        buffer.swap(new_buffer);
        new_buffer.reset();
    }
    buffer[real_size++] = std::move(element);
}

template<typename T>
[[maybe_unused]] void my_vector<T>::insert(T &element) {}

template<typename T>
const T *my_vector<T>::begin() const {
    return &buffer[0];
}

template<typename T>
T *my_vector<T>::begin() {
    return &buffer[0];
}

template<typename T>
const T *my_vector<T>::end() const {
    return &buffer[real_size];
}

template<typename T>
T *my_vector<T>::end() {
    return &buffer[real_size];
}

#endif //TEST_MY_VECTOR_REALIZATION_H
