cmake_minimum_required(VERSION 3.22)
project(meta)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(google/googletest-main)
include_directories(google/googletest-main/googletest/include)
set(SOURCE_FILES main.cpp)
add_executable(meta ${SOURCE_FILES})
target_link_libraries(meta gtest)