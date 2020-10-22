cmake_minimum_required(VERSION 3.17)
project(lib_ratio)

set(CMAKE_CXX_STANDARD 17)

add_library(lib_ratio SHARED library.cpp library.h)