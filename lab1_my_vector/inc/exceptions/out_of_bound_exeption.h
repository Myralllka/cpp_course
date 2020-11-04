//
// Created by myralllka on 11/22/20.
//

#ifndef VECTOR_BOUNDS_EXCEPTION
#define VECTOR_BOUNDS_EXCEPTION

#include <exception>

class ArrayOutOfBoundsException : public std::exception {
public:
    [[nodiscard]] const char *what() const noexcept override {
        return "Exception! Array out of bounds!";
    }
};

#endif //VECTOR_BOUNDS_EXCEPTION
