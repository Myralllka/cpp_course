// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

//
// Created by myralllka on 10/20/20.
//

#ifndef TEST_MY_VECTOR_REALIZATION_H
#define TEST_MY_VECTOR_REALIZATION_H

#include <iostream>

#include "my_vector.hpp"
#include "exceptions/out_of_bound_exeption.h"

template<typename T>
[[maybe_unused]] size_t my_vector<T>::size() const {
    return size_m;
}

template<typename T>
[[maybe_unused]] size_t my_vector<T>::capacity() const {
    return capacity_m;
}

template<typename T>
[[maybe_unused]] size_t my_vector<T>::max_size() const {
    const size_t power = sizeof(size_t) * 8 - 1;
    size_t a = 2;
    a <<= power - 1;
    return a / sizeof(T) - 1;
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
[[maybe_unused]] void my_vector<T>::clear() {
    size_m = 0;
}

template<typename T>
[[maybe_unused]] void my_vector<T>::reserve(size_t size) {
    if (size < capacity_m) {
        return;
    }
    capacity_m = size;
    std::unique_ptr<T[]> new_buffer = std::make_unique<T[]>(size);
    buffer_m.swap(new_buffer);
}

template<typename T>
const T &my_vector<T>::operator[](size_t index) const {
    return buffer_m[index];
}

template<typename T>
T &my_vector<T>::operator[](size_t index) {
    return buffer_m[index];
}

template<typename T>
[[maybe_unused]] const T &my_vector<T>::at(size_t index) const {
    if (index < 0 or index > size_m) {
        throw ArrayOutOfBoundsException();
    }
    return buffer_m[index];
}


template<typename T>
T &my_vector<T>::at(size_t index) {
    if (index < 0 or index > size_m) {
        throw ArrayOutOfBoundsException();
    }
    return buffer_m[index];;
}

template<typename T>
void my_vector<T>::double_capacity_if_bound() {
    if (size_m == capacity_m) {
        capacity_m = size_m * 2;
        std::unique_ptr<T[]> new_buffer = std::make_unique<T[]>(capacity());
        buffer_m.swap(new_buffer);
    }
}

template<typename T>
[[maybe_unused]] void my_vector<T>::push_back(T &&element) {
    double_capacity_if_bound();
    buffer_m[size_m++] = std::move(element);
}

template<typename T>
[[maybe_unused]] void my_vector<T>::push_back(T &element) {
    double_capacity_if_bound();
    buffer_m[size_m++] = element;
}

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

template<typename T>
my_vector<T> &my_vector<T>::operator=(const my_vector &other) {
    my_vector<T> temp{other};
    swap(temp);
    return *this;
}

template<typename T>
[[maybe_unused]] void my_vector<T>::swap(my_vector<T> other) {
    std::swap(other.size_m, size_m);
    std::swap(other.capacity_m, capacity_m);
    std::swap(other.buffer_m, buffer_m);
}

template<typename T>
[[maybe_unused]] void my_vector<T>::shrink_to_fit() {

}


//template<typename T>
//void my_vector<T>::insert(const T *positin, const T &value) {
//    if (size_m < capacity_m) {
//
//    }
//}
//
//template<typename T>
//void my_vector<T>::insert(const T *positin, T &value) {
//
//}
//
//template<typename T>
//void my_vector<T>::insert(const T *positin, const T *begin, const T *end, T &value) {
//
//}
//
//template<typename T>
//void my_vector<T>::insert(const T *positin, std::initializer_list<T> elements) {
//
//}

template<>
[[maybe_unused]] void my_vector<size_t>::print() {
    prt();
}

template<typename T>
void my_vector<T>::prt() {
    for (size_t i = 0; i < size_m; ++i) {
        std::cout << buffer_m[i] << ", ";
    }
    std::cout << std::endl;
}

template<>
[[maybe_unused]] void my_vector<std::string>::print() {
    prt();
}

#endif //TEST_MY_VECTOR_REALIZATION_H
