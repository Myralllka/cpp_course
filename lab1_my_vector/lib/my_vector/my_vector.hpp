// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

//
// Created by myralllka on 10/20/20.
//

#ifndef TEST_MY_VECTOR_H
#define TEST_MY_VECTOR_H

#include <memory>
#include <iostream>

template<typename T>
class my_vector {
private:
    std::unique_ptr<T[]> buffer_m;
    size_t size_m;
    size_t capacity_m;

    void prt();

    void double_capacity_if_bound(size_t sz = 0);

public:
    my_vector() : buffer_m(new T[1]), size_m{0}, capacity_m{1} {};

    explicit my_vector(size_t size, T init_val = T{}) : size_m{size},
                                                        capacity_m{size == 0 ? 2 : size} {
        buffer_m = std::make_unique<T[]>(size);
        for (size_t i = 0; i < size; ++i) {
            buffer_m[i] = init_val;
        }
    }

    my_vector(std::initializer_list<T> el) : buffer_m{new T[el.size()]},
                                             size_m{el.size()},
                                             capacity_m{el.size() * 2} {
        size_t i = 0;
        for (auto &&entry:el) {
            buffer_m[i++] = std::move(entry);
        }
    }
//TODO
//    my_vector(const T *begin, const T *end) {
//
//    }

    my_vector(const my_vector &other) : size_m{other.size_m},
                                        capacity_m{other.capacity_m} {
        buffer_m = std::make_unique<T[]>(capacity_m);

        for (size_t i = 0; i < size_m; ++i) {
            buffer_m[i] = other.buffer_m[i];
        }
    }

    my_vector(my_vector &&other) noexcept: size_m{other.size_m},
                                           capacity_m{other.capacity_m} {

        buffer_m = std::make_unique<T[]>(capacity_m);
        for (size_t i = 0; i < size_m; ++i) {
            buffer_m[i] = std::move(other.buffer_m[i]);
        }
    }

    ~my_vector() {
        buffer_m.release();
        buffer_m.reset(nullptr);
    };

//GETTERS
    [[nodiscard]] size_t size() const;

    [[nodiscard]] size_t capacity() const;

    [[nodiscard]] size_t max_size() const;

    T &front();

    T &back();

    const T &front() const;

    const T &back() const;

    bool is_empty();

// INSERTIONS
    void insert(const T *position, const T &value);

    void insert(const T *position, T &&value);

    void insert(const T *position, const T *begin, const T *end);

    //[[maybe_unused]] void insert(const T *position, std::initializer_list<T> elements);

    template<typename ...Args>
    T *emplace_back(Args &... args);

    void push_back(T &&element);

    void push_back(T &element);

// ERASEMENTS
//TODO
//    T *erase(T *position);
//
//    T *erase(const T *position);
//
//    T *erase(const T *position, const T *begin, const T *end);

// ITERATORS
    [[nodiscard]] const T *cbegin() const;

    T *begin();

    [[nodiscard]] const T *cend() const;

    T *end();

// OPERATORS
    const T &operator[](size_t index) const;

    bool operator==(const my_vector<T> &other);

    bool operator<=(const my_vector<T> &other);

    bool operator>=(const my_vector<T> &other);

    bool operator<(const my_vector<T> &other);

    bool operator>(const my_vector<T> &other);

    bool operator!=(const my_vector<T> &other);

    T &operator[](size_t index);

    const T &at(size_t index) const;

    T &at(size_t index);

    my_vector<T> &operator=(const my_vector &other);

// OTHER
    void pop_back();

    void clear();

    void fast_clear();

    void resize(size_t new_sz);

    void swap(my_vector<T> other);

//    void print();

    void shrink_to_fit();

    void reserve(size_t size);

};

#include "my_vector_realization.hpp"

#endif //TEST_MY_VECTOR_H
