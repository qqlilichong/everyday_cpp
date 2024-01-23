
cmake_minimum_required(VERSION 3.27)

# Project Config
project(everyday_cpp)
add_executable(${CMAKE_PROJECT_NAME})
target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE
        $<$<CXX_COMPILER_ID:MSVC>:/bigobj>
        $<$<CXX_COMPILER_ID:GNU>:-Wa,-mbig-obj>
)
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
        UNICODE
        _UNICODE
)
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
        CXX_STANDARD            20
        CXX_STANDARD_REQUIRED   ON
        CXX_EXTENSIONS          OFF
        OUTPUT_NAME             ${CMAKE_PROJECT_NAME}
        DEBUG_POSTFIX           "d"
        UNITY_BUILD             OFF
        QT_USED                 OFF
)

# Qt Config
get_target_property(QtUsed ${CMAKE_PROJECT_NAME} QT_USED)
if (QtUsed)
        set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
                AUTOMOC                 ON
                AUTOUIC                 ON
                AUTORCC                 ON
                INCLUDE_CURRENT_DIR     ON
                QT_VER                  "Qt5"
                QT_COMPS                "Widgets;Xml;Sql;Network"
        )
        get_target_property(QtVer ${CMAKE_PROJECT_NAME} QT_VER)
        get_target_property(QtComps ${CMAKE_PROJECT_NAME} QT_COMPS)
        find_package(${QtVer} CONFIG REQUIRED COMPONENTS ${QtComps})
        foreach (CurComp ${QtComps})
                target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${QtVer}::${CurComp})
        endforeach ()
endif ()

# Project Files
# file(GLOB_RECURSE sources CONFIGURE_DEPENDS *.cpp *.h *.ui)
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
        main.cpp
        boost_asio_spawn.cpp
)

# Import Boost
find_package(Boost CONFIG REQUIRED PATHS ${BOOST_LIBS_PATH} COMPONENTS ALL)
if (Boost_FOUND)
        target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${Boost_LIBRARIES})
        MESSAGE(STATUS "Boost LIBS : ${Boost_LIBRARIES}")
endif ()

# Import WinSock
if (WIN32)
        target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ws2_32 Mswsock)
endif ()

# Demon Import Package
find_package(rutils CONFIG REQUIRED PATHS ${CMAKE_CURRENT_LIST_DIR} COMPONENTS collection)
if (rutils_FOUND)
        target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${rutils_LIBRARIES})
        MESSAGE(STATUS "rutils LIBS : ${rutils_LIBRARIES}")
endif ()
