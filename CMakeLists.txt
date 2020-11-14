cmake_minimum_required(VERSION 3.17)
project(libra)

set(CMAKE_CXX_STANDARD 14)

include_directories(Book)

add_executable(libra
        Book/Book.cpp
        Book/Book.h
        LICENSE
        README.md)
