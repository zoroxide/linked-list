cmake_minimum_required(VERSION 3.29)
project(likedlist)

set(CMAKE_CXX_STANDARD 20)

add_executable(likedlist main.cpp
        List.cpp
        List.h
)
