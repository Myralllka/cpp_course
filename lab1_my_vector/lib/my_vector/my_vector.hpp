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
class back_iterator {
private:
    T *begin_m;
    T *end_m;
    size_t index_m;
public:

    back_iterator() = default;

    back_iterator(T *begin, T *end) : begin_m(begin), end_m(end) {
        index_m = 0;
    };

    ~back_iterator() = default;

    T &operator++() {
        index_m--;
        return *this;
    }

    T operator--() {
        index_m++;
        return *this;
    }

    const T operator++(int) {
        T copy{*this};
        --(*this);
        return copy;
    }

    const T operator--(int) {
        T copy{*this};
        ++(*this);
        return copy;
    }

    T *begin() {
        return end;
    }

    T *end() {
        return begin;
    }

    auto operator<=>(const back_iterator<T> &) const = default;
};


template<typename T>
class my_vector {
private:
    std::unique_ptr<T[]> buffer_m;
    size_t size_m;
    size_t capacity_m;
    back_iterator<T> biter_m{};

    void double_capacity_if_bound(size_t sz = 0);

public:
    my_vector() : buffer_m(new T[2]), size_m{0}, capacity_m{2} {};

    explicit my_vector(size_t size, T init_val = T{}) : size_m{size},
                                                        capacity_m{size == 0 ? 2 : size} {
        buffer_m = std::make_unique<T[]>(capacity_m);
        for (size_t i = 0; i < size; ++i) {
            buffer_m[i] = init_val;
        }
    }

    my_vector(std::initializer_list<T> el) : buffer_m{new T[el.size() * 2]},
                                             size_m{el.size()},
                                             capacity_m{el.size() * 2} {
        size_t i = 0;
        for (auto &&entry:el) {
            buffer_m[i++] = std::move(entry);
        }
    }

    my_vector(const my_vector<T> *bgn, const my_vector<T> *nd) : size_m(0) {
        capacity_m = (nd - bgn) * 2;
        buffer_m = std::make_unique<T>(capacity_m);
        for (T *el = bgn; el != nd; ++el) {
            buffer_m[size_m++] = *el;
        }

    }

    my_vector(const my_vector &other) : size_m{other.size_m},
                                        capacity_m{other.capacity_m} {
        capacity_m = other.capacity_m;
        buffer_m = std::make_unique<T[]>(capacity_m);
        size_m = other.size_m;
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

    [[maybe_unused]] [[nodiscard]] size_t max_size() const;

    T &front();

    T &back();

    [[maybe_unused]] const T &front() const;

    [[maybe_unused]] const T &back() const;

    bool is_empty();

// INSERTIONS
    void insert(const T *position, const T &value);

    void insert(const T *position, T &&value);

    void insert(const T *position, const T *begin, const T *end);

    void insert(const T *position, std::initializer_list<T> elements);

//    template<typename ...Args>
//    T *emplace_back(Args &&... args);

    void push_back(T &&element);

    void push_back(T &element);

// ERASEMENTS
//TODO
    T *erase(T *position);

    T *erase(const T *cbegin, const T *cend);

// ITERATORS
    [[nodiscard]] const T *cbegin() const;

    back_iterator<T> rbegin();

    T *begin();

    [[nodiscard]] const T *cend() const;

    back_iterator<T> rend();

    T *end();

// OPERATORS
    my_vector<T> &operator=(const my_vector &other);

    const T &operator[](size_t index) const;

    bool operator==(const my_vector<T> &other);

    bool operator<=(const my_vector<T> &other);

    bool operator>=(const my_vector<T> &other);

    bool operator<(const my_vector<T> &other);

    bool operator>(const my_vector<T> &other);

    bool operator!=(const my_vector<T> &other);

    T &operator[](size_t index);

    const T &at(size_t index) const;

    const T &at(ssize_t index) const = delete;

    T &at(size_t index);

    T &at(ssize_t index) = delete;

// OTHER
    void pop_back();

    void clear();

    void fast_clear();

    void resize(size_t new_sz);

    void swap(my_vector<T> &other);

    void shrink_to_fit();

    void reserve(size_t size);

};

#include "my_vector_realization.hpp"

#endif //TEST_MY_VECTOR_H
