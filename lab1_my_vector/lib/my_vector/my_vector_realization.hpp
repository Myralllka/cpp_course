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
    return size_m;
}

template<typename T>
[[maybe_unused]] size_t my_vector<T>::capacity() {
    return capacity_m;
}

template<typename T>
[[maybe_unused]] size_t my_vector<T>::max_size() {
    return sizeof(size_t) * 8;
}

template<typename T>
[[maybe_unused]] void my_vector<T>::clear() {
    buffer_m.reset();
    buffer_m = new T[1];
    size_m = 0;
    capacity_m = 1;
}

template<typename T>
[[maybe_unused]] void my_vector<T>::reserve(size_t size) {
    capacity_m = size;
    std::unique_ptr<T[]> new_buffer{new T[size]};
    buffer_m.swap(new_buffer);
    new_buffer.reset();
}

template<typename T>
[[maybe_unused]] T my_vector<T>::front() {
    return buffer_m[0];
}

template<typename T>
[[maybe_unused]] T my_vector<T>::back() {
    return buffer_m[size_m];
}

template<typename T>
const T &my_vector<T>::operator[](size_t index) {
    return buffer_m.get(index);
}

template<typename T>
[[maybe_unused]] void my_vector<T>::push_back(T &&element) {
    if (size_m == capacity_m) {
        capacity_m = size_m * 2;
        std::unique_ptr<T[]> new_buffer{new T[capacity_m]};
        buffer_m.swap(new_buffer);
        new_buffer.reset();
    }
    buffer_m[size_m++] = std::move(element);
}

//template<typename T>
//[[maybe_unused]] void my_vector<T>::insert(T &element) {
//
//}

template<typename T>
const T *my_vector<T>::begin() const {
    return &buffer_m[0];
}

template<typename T>
T *my_vector<T>::begin() {
    return &buffer_m[0];
}

template<typename T>
const T *my_vector<T>::end() const {
    return &buffer_m[size_m];
}

template<typename T>
T *my_vector<T>::end() {
    return &buffer_m[size_m];
}

#endif //TEST_MY_VECTOR_REALIZATION_H
