
cmake_minimum_required(VERSION 3.9)
project(everyday_cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")

add_executable(everyday_cpp main.cpp)
