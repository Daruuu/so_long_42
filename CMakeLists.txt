cmake_minimum_required(VERSION 3.28)
project(so_long_42 C)

set(CMAKE_C_STANDARD 99)

add_executable(so_long_42 main.c
        include/so_long.h

)