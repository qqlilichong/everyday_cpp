
cmake_minimum_required(VERSION 3.9)
project(everyday_cpp)

set(CMAKE_CXX_STANDARD 17)

if (DEFINED ENV{MINGW_INCLUDE})
    include_directories($ENV{MINGW_INCLUDE})
endif ()

link_libraries(boost_system)
link_libraries(boost_thread)

add_executable(everyday_cpp main.cpp)
