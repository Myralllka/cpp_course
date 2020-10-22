//
// Created by myralllka on 10/21/20.
//

#ifndef RATIO_LIB_RATIO_H
#define RATIO_LIB_RATIO_H

#include <memory>

class ratio {
private:
    size_t numerator;
    size_t denominator;
public:
    ratio() : numerator(0), denominator(1) {}

    ~ratio();

    void reduce();


};


#endif //RATIO_LIB_RATIO_H
