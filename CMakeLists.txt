
cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_STANDARD 17)

#if (DEFINED ENV{MINGW_INCLUDE})
#    include_directories($ENV{MINGW_INCLUDE})
#    link_libraries(Ws2_32.lib)
#    link_libraries(Mswsock.lib)
#endif ()
#
#link_libraries(boost_date_time)
#link_libraries(boost_regex)
#link_libraries(boost_system)
#link_libraries(boost_coroutine)
#link_libraries(boost_context)
#link_libraries(boost_thread)
#link_libraries(pthread)

project(everyday_cpp)

set(SOURCE_FILES
        main.cpp
        e_variadic_templates.hpp
        e_fold_expression.hpp
        e_constexpr.hpp
        e_structured_bindings.hpp
        )

add_executable(everyday_cpp ${SOURCE_FILES})
