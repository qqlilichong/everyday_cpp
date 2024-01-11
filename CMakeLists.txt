
cmake_minimum_required(VERSION 3.27)
string(REGEX REPLACE "/$" "" CURRENT_FOLDER_ABSOLUTE ${CMAKE_CURRENT_SOURCE_DIR})
string(REGEX REPLACE ".*/(.*)" "\\1" PROJID ${CURRENT_FOLDER_ABSOLUTE})

# project
set(CMAKE_CXX_STANDARD 20)
project(${PROJID})
MESSAGE(STATUS "ProjectID : ${PROJID}")
add_executable(${PROJID} main.cpp boost.cpp)

# import Boost
find_package(Boost REQUIRED COMPONENTS ALL PATHS ${BOOST_LIBS_PATH})
if (Boost_FOUND)
        MESSAGE(STATUS "Boost LIBS : ${Boost_LIBRARIES}")
        target_link_libraries(${PROJID} ${Boost_LIBRARIES})
endif ()

# import winsock
if (WIN32)
        target_link_libraries(${PROJID} ws2_32 Mswsock)
endif ()
