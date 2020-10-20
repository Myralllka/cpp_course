//
// Created by myralllka on 10/20/20.
//

#ifndef TEST_MY_VECTOR_H
#define TEST_MY_VECTOR_H

#include "memory"
#include "node.hpp"

template<typename T>
class my_vector {
private:
//    std::unique_ptr<T[]> buffer;
    node<T> head;
    size_t real_size;
    size_t real_capacity;
public:
    my_vector() : head(), real_size(0), real_capacity(1) {};

    ~my_vector() {
        head = node<T>();
        real_size = 0;
        real_capacity = 1;
    };

    my_vector(std::initializer_list<T> elements) : head(), real_size(elements.size()), real_capacity(elements.size());
};

class vector_iterator {

};


#endif //TEST_MY_VECTOR_H
