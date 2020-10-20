//
// Created by myralllka on 10/20/20.
//

#include "my_vector.hpp"

/*
 * my_vector() : buffer(new T[1]), real_size(0), real_capacity(1) {};

    [[maybe_unused]] my_vector(std::initializer_list<T> el) : buffer(new T[el.size()]), real_size(el.size()),
                                                              real_capacity(el.size() * 2) {
        size_t i = 0;
        for (auto &&entry:el) {
            buffer[i++] = std::move(entry);
        }
    }

    ~my_vector() {
        real_size = 0;
        real_capacity = 0;
    };

    [[maybe_unused]] size_t size() {
        return real_size;
    }

    [[maybe_unused]] size_t max_size() {
        return sizeof(size_t);
    }

    [[maybe_unused]] size_t capacity() {
        return real_capacity;
    }

    [[maybe_unused]] void reserve(size_t size) {
        real_size = size;
        real_capacity = size;
        std::unique_ptr<T[]> new_buffer{new T[size]};
        buffer.swap(new_buffer);
        new_buffer.release();
    }

    [[maybe_unused]] const T &operator[](size_t index) {
        return buffer.get(index);
    }

    [[maybe_unused]] T back() {
        return buffer[real_size];
    }

    [[maybe_unused]] T front() {
        return buffer[0];
    }

    [[maybe_unused]] void push_back(T &&element) {
//        if (real_size == real_capacity) {
//
//        }
    }

    [[maybe_unused]] void pop_back(T &&element) {}

    [[maybe_unused]] void pop_front(T &&element) {}

    [[maybe_unused]] void push_front(T &&element) {}

    [[maybe_unused]] void emplace_back(T &&element) {}

    [[maybe_unused]] void emplace_front(T &&element) {}

    [[maybe_unused]] void clear() {
        buffer.release();
        buffer = new T[1];
        real_size = 0;
        real_capacity = 1;
    }*/