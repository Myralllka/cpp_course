// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

//
// Created by myralllka on 10/20/20.
//

#ifndef TEST_MY_VECTOR_REALIZATION_H
#define TEST_MY_VECTOR_REALIZATION_H
#define DEBUG

#include <iostream>
#include <cstring>

#include "my_vector.hpp"
#include "exceptions/out_of_bound_exeption.h"

template<typename T>
size_t my_vector<T>::size() const {
#ifdef DEBUG
    std::cout << "size_t my_vector<T>::size() const" << std::endl;
#endif
    return size_m;
}

template<typename T>
size_t my_vector<T>::capacity() const {
#ifdef DEBUG
    std::cout << "size_t my_vector<T>::capacity() const" << std::endl;
#endif
    return capacity_m;
}

template<typename T>
size_t my_vector<T>::max_size() const {
#ifdef DEBUG
    std::cout << "size_t my_vector<T>::max_size() const" << std::endl;
#endif
    const size_t power = sizeof(size_t) * 8 - 1;
    size_t a = 2;
    a <<= power - 1;
    return a / sizeof(T) - 1;
}

template<typename T>
T &my_vector<T>::front() {
#ifdef DEBUG
    std::cout << "T &my_vector<T>::front()" << std::endl;
#endif
    return buffer_m[0];
}

template<typename T>
[[maybe_unused]] const T &my_vector<T>::front() const {
#ifdef DEBUG
    std::cout << "const T &my_vector<T>::front() const" << std::endl;
#endif
    return buffer_m[0];
}

template<typename T>
T &my_vector<T>::back() {
#ifdef DEBUG
    std::cout << "T &my_vector<T>::back()" << std::endl;
#endif
    return buffer_m[size_m - 1];
}

template<typename T>
const T &my_vector<T>::back() const {
#ifdef DEBUG
    std::cout << "const T &my_vector<T>::back() const" << std::endl;
#endif
    return buffer_m[size_m - 1];
}

template<typename T>
void my_vector<T>::clear() {
#ifdef DEBUG
    std::cout << "void my_vector<T>::clear()" << std::endl;
#endif
    erase(begin(), end());
}

template<typename T>
void my_vector<T>::fast_clear() {
#ifdef DEBUG
    std::cout << "void my_vector<T>::fast_clear()" << std::endl;
#endif
    size_m = 0;
}

template<typename T>
void my_vector<T>::reserve(size_t size) {
#ifdef DEBUG
    std::cout << "void my_vector<T>::reserve(size_t size)" << std::endl;
#endif
    if (size < capacity_m) {
        return;
    }
    capacity_m = size;
    std::unique_ptr<T[]> new_buffer = std::make_unique<T[]>(size);
    buffer_m.reset(new_buffer);
}

template<typename T>
const T &my_vector<T>::operator[](size_t index) const {
#ifdef DEBUG
    std::cout << "const T &my_vector<T>::operator[](size_t index) const" << std::endl;
#endif
    return buffer_m[index];
}

template<typename T>
T &my_vector<T>::operator[](size_t index) {
#ifdef DEBUG
    std::cout << "T &my_vector<T>::operator[](size_t index)" << std::endl;
#endif
    return buffer_m[index];
}

template<typename T>
my_vector<T> &my_vector<T>::operator=(const my_vector &other) {
#ifdef DEBUG
    std::cout << "my_vector<T> &my_vector<T>::operator=(const my_vector &other)" << std::endl;
#endif
    my_vector<T> temp{other};
    swap(temp);
    return *this;
}

template<typename T>
bool my_vector<T>::operator==(const my_vector<T> &other) {
#ifdef DEBUG
    std::cout << "bool my_vector<T>::operator==(const my_vector<T> &other)" << std::endl;
#endif
    if (size_m != other.size_m) {
        return false;
    }
    for (size_t i = 0; i < size_m; ++i) {
        if (operator[](i) != other[i]) {
            return false;
        }
    }
    return true;
}

template<typename T>
bool my_vector<T>::operator!=(const my_vector<T> &other) {
#ifdef DEBUG
    std::cout << "bool my_vector<T>::operator!=(const my_vector<T> &other)" << std::endl;
#endif
    return !operator==(other);
}

template<typename T>
bool my_vector<T>::operator>=(const my_vector<T> &other) {
#ifdef DEBUG
    std::cout << "bool my_vector<T>::operator>=(const my_vector<T> &other)" << std::endl;
#endif
    return !operator<(other);
}

template<typename T>
bool my_vector<T>::operator<=(const my_vector<T> &other) {
#ifdef DEBUG
    std::cout << "bool my_vector<T>::operator<=(const my_vector<T> &other)" << std::endl;
#endif
    return operator<(other) or operator==(other);
}

template<typename T>
bool my_vector<T>::operator<(const my_vector<T> &other) {
#ifdef DEBUG
    std::cout << "bool my_vector<T>::operator<(const my_vector<T> &other)" << std::endl;
#endif
    if (size_m > other.size_m) {
        return false;
    } else if (size_m == other.size_m) {
        for (size_t i = 0; i < size_m; ++i) {
            if (operator[](i) >= other[i]) {
                return false;
            }
        }
    }
    return true;

}

template<typename T>
bool my_vector<T>::operator>(const my_vector<T> &other) {
#ifdef DEBUG
    std::cout << "bool my_vector<T>::operator>(const my_vector<T> &other)" << std::endl;
#endif
    return !operator<=(other);
}

template<typename T>
const T &my_vector<T>::at(size_t index) const {
#ifdef DEBUG
    std::cout << "const T &my_vector<T>::at(size_t index) const" << std::endl;
#endif
    if (index < 0 or index > size_m) {
        throw ArrayOutOfBoundsException();
    }
    return buffer_m[index];
}

template<typename T>
T &my_vector<T>::at(size_t index) {
#ifdef DEBUG
    std::cout << "T &my_vector<T>::at(size_t index)" << std::endl;
#endif
    if (index < 0 or index > size_m) {
        throw ArrayOutOfBoundsException();
    }
    return buffer_m[index];
}

template<typename T>
void my_vector<T>::double_capacity_if_bound(size_t i) {
    if (size_m + i == capacity_m) {
#ifdef DEBUG
        std::cout << "void my_vector<T>::double_capacity_if_bound(size_t i)" << std::endl;
#endif
        capacity_m = size_m * 2;
        std::unique_ptr<T[]> new_buffer = std::make_unique<T[]>(capacity_m);
        buffer_m.swap(new_buffer);
    }
}

template<typename T>
void my_vector<T>::push_back(T &&element) {
#ifdef DEBUG
    std::cout << "void my_vector<T>::push_back(T &&element)" << std::endl;
#endif
    double_capacity_if_bound();
    buffer_m[size_m++] = std::move(element);
}

template<typename T>
void my_vector<T>::push_back(T &element) {
#ifdef DEBUG
    std::cout << "void my_vector<T>::push_back(T &element)" << std::endl;
#endif
    double_capacity_if_bound();
    buffer_m[size_m++] = element;
}

template<typename T>
const T *my_vector<T>::cbegin() const {
#ifdef DEBUG
    std::cout << "const T *my_vector<T>::cbegin() const" << std::endl;
#endif
    return &buffer_m[0];
}

template<typename T>
T *my_vector<T>::begin() {
#ifdef DEBUG
    std::cout << "T *my_vector<T>::begin()" << std::endl;
#endif
    return &buffer_m[0];
}

template<typename T>
const T *my_vector<T>::cend() const {
#ifdef DEBUG
    std::cout << "const T *my_vector<T>::cend() const" << std::endl;
#endif
    return &buffer_m[size_m];
}

template<typename T>
T *my_vector<T>::end() {
#ifdef DEBUG
    std::cout << "T *my_vector<T>::end()" << std::endl;
#endif
    return &buffer_m[size_m];
}

template<typename T>
void my_vector<T>::swap(my_vector<T> other) {
#ifdef DEBUG
    std::cout << "void my_vector<T>::swap(my_vector<T> other)" << std::endl;
#endif
    std::swap(other.size_m, size_m);
    std::swap(other.capacity_m, capacity_m);
    std::swap(other.buffer_m, buffer_m);
}

template<typename T>
void my_vector<T>::shrink_to_fit() {
#ifdef DEBUG
    std::cout << "void my_vector<T>::shrink_to_fit()" << std::endl;
#endif
    capacity_m = size_m;
    std::unique_ptr<T[]> new_buffer = std::make_unique<T[]>(capacity_m);
    buffer_m.swap(new_buffer);
}

template<typename T>
void my_vector<T>::insert(const T *position, const T &value) {
#ifdef DEBUG
    std::cout << "void my_vector<T>::insert(const T *position, const T &value)" << std::endl;
#endif
    insert(position, {value});
}

template<typename T>
void my_vector<T>::insert(const T *position, T &&value) {
#ifdef DEBUG
    std::cout << "void my_vector<T>::insert(const T *position, T &&value)" << std::endl;
#endif
    insert(position, {std::move(value)});
}

template<typename T>
void my_vector<T>::insert(const T *position, const T *begin, const T *end) {
#ifdef DEBUG
    std::cout << "void my_vector<T>::insert(const T *position, const T *begin, const T *end)" << std::endl;
#endif
    size_t start = position - &buffer_m[0];
    size_t sz = &buffer_m[size_m] - position;
    double_capacity_if_bound(end - begin); // at this moment position can be not relevant anymore
    std::unique_ptr<T[]> tmp_buffer = std::make_unique<T[]>(sz);
    std::copy(buffer_m.get() + start, buffer_m.get() + size_m, tmp_buffer.get());
    size_t counter = 0;
    for (const T *i = begin; i != end; ++i) {
        buffer_m[start + counter++] = *i;
    }
    for (size_t i = 0; i < sz; ++i) {
        buffer_m[start + (end - begin) + i] = tmp_buffer[i];
    }
    size_m += (end - begin);
}

template<typename T>
void my_vector<T>::insert(const T *position, std::initializer_list<T> elements) {
#ifdef DEBUG
    std::cout << "void my_vector<T>::insert(const T *position, std::initializer_list<T> elements)" << std::endl;
#endif
    insert(position, elements.begin(), elements.end());
}

template<typename T>
void my_vector<T>::pop_back() {
    if (size_m == 0) return;
    size_m -= 1;
}

//template<>
//void my_vector<size_t>::print() {
//    prt();
//}

//template<typename T>
//void my_vector<T>::prt() {
//    for (size_t i = 0; i < size_m; ++i) {
//        std::cout << buffer_m[i] << ", ";
//    }
//    std::cout << std::endl;
//}

//template<typename T>
//template<typename ...Args>
//T *my_vector<T>::emplace_back(Args &... args) {
//
//    return nullptr;
//}

template<typename T>
void my_vector<T>::resize(size_t new_sz) {
    // TODO
}

template<typename T>
bool my_vector<T>::is_empty() {
    return size_m == 0;
}

//template<>
//void my_vector<std::string>::print() {
//    prt();
//}

#endif //TEST_MY_VECTOR_REALIZATION_H
