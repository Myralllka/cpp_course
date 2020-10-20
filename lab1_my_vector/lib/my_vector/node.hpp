//
// Created by myralllka on 10/20/20.
//

#ifndef TEST_NODE_HPP
#define TEST_NODE_HPP

template<typename T>
class node {
private:
    node next_node;
    node prev_node;
    T item;
public:
    node() = default;

    ~node() = default;

    node(T i) : next_node(node()), prev_node(node()), item(i) {}

    node(node previous, T i, node next) : next_node(next), prev_node(previous), item(i) {}

    T get() {
        return item;
    }

    void set(T i) {
        item = i;
    }
};


#endif //TEST_NODE_HPP
