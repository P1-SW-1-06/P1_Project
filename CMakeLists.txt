cmake_minimum_required(VERSION 3.23)
project(P1_Project C)

set(CMAKE_C_STANDARD 99)


add_subdirectory(src)

enable_testing()
add_subdirectory(test)