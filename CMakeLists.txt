cmake_minimum_required(VERSION 3.23)
project(P1_Project C)

set(CMAKE_C_STANDARD 99)

add_executable(main src/main.c src/import_handler.c src/import_handler.h src/user_input.c src/user_input.h)