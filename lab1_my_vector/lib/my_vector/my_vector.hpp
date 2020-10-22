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

    void prt();

    void double_capacity_if_bound();

public:
    my_vector() : buffer_m(new T[1]), size_m{0}, capacity_m{1} {};

    [[maybe_unused]] explicit my_vector(size_t size, T init_val = T{}) : size_m{size},
                                                                         capacity_m{size == 0 ? 2 : size} {
        buffer_m = std::make_unique<T[]>(size);
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

    my_vector(const my_vector &other) : size_m{other.size_m},
                                        capacity_m{other.capacity_m} {
        buffer_m = std::make_unique<T[]>(capacity_m);

        for (size_t i = 0; i < size_m; ++i) {
            buffer_m[i] = other.buffer_m[i];
        }
    }

    ~my_vector() {
        buffer_m.reset();
        buffer_m = nullptr;
    };

//GETTERS
    [[maybe_unused]] [[nodiscard]] size_t size() const;

    [[maybe_unused]] [[nodiscard]] size_t capacity() const;

    [[maybe_unused]] [[nodiscard]] size_t max_size() const;

    [[maybe_unused]] T front();

    [[maybe_unused]] T back();

// INSERTIONS
    [[maybe_unused]] void push_back(T &&element);

    [[maybe_unused]] void push_back(T &element);

//    [[maybe_unused]] void insert(const T *positin, const T &value);
//
//    [[maybe_unused]] void insert(const T *positin, T &value);
//
//    [[maybe_unused]] void insert(const T *positin, const T *begin, const T *end, T &value);
//
//    [[maybe_unused]] void insert(const T *positin, std::initializer_list<T> elements);

//    [[maybe_unused]] void pop_back(T &&element) {}
//
//    [[maybe_unused]] void pop_front(T &&element) {}
// ITERATORS
    [[nodiscard]] const T *begin() const;

    T *begin();

    [[nodiscard]] const T *end() const;

    T *end();

// OPERATORS
    [[maybe_unused]] const T &operator[](size_t index) const;

    [[maybe_unused]] const T &at(size_t index) const;

    [[maybe_unused]] T &operator[](size_t index);

    [[maybe_unused]] T &at(size_t index);

    [[maybe_unused]] my_vector<T> &operator=(const my_vector &other);

// OTHER
    [[maybe_unused]] [[maybe_unused]] void clear();

    [[maybe_unused]] void swap(my_vector<T> other);

    [[maybe_unused]] void print();

    [[maybe_unused]] void shrink_to_fit();

    [[maybe_unused]] void reserve(size_t size);
};

#include "my_vector_realization.hpp"

#endif //TEST_MY_VECTOR_H
