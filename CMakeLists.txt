cmake_minimum_required(VERSION 3.22)
project(meta)

set(CMAKE_CXX_STANDARD 17)

add_executable(meta main.cpp CPolynomial.cpp CPolynomial.h)
