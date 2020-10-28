cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME test)
project(${PROJECT_NAME} CXX)

set(CMAKE_CXX_STANDARD 20)

# Options
option(WARNINGS_AS_ERRORS "Treat compiler warnings as errors." ON)
option(ENABLE_SANITIZERS "Use sanitizers to detect errors." ON)
option(ENABLE_CONAN "Use Conan as a package manager." OFF)
option(ENABLE_PVS_STUDIO "Check using command-line PVS-Studio." OFF)

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

# Warnings
if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror -Werror=vla)
endif()
# Include fixed CMake configuration
include(cmake/config.cmake)

# Include headers
include_directories(inc)

# compile with vector sub dir
add_subdirectory(lib_ratio)

# Project source compilation
add_executable(${PROJECT_NAME} src/main.cpp src/tests.cpp src/ratio_algorithm.cpp)

# Add external packages
find_package(Boost 1.71.0 COMPONENTS program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} Boost::program_options)


include_directories(lib_ratio)
target_link_libraries(${PROJECT_NAME} lib_ratio)
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/lib_ratio)


#####################################
# create own target for library
if(ENABLE_PVS_STUDIO)
    include(cmake/PVS-Studio.cmake)
    SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)
    # create own target for library
    pvs_studio_add_target(
            TARGET ${PROJECT_NAME}.analyze ALL
            ANALYZE ${PROJECT_NAME}
            OUTPUT FORMAT errorfile
            MODE GA:1,2,3 OP:1,2,3 GA:1,2,3 OP:1,2,3 64:1,2,3 CS:1,2,3 MISRA:1,2,3
            LOG target_${PROJECT_NAME}.err)
else()
    message("Consider checking using PVS-Studio with `cmake -DENABLE_PVS_STUDIO=ON <.....>` or Windows GUI application.")
endif()
#####################################
