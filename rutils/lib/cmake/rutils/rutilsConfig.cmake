
block (PROPAGATE rutils_LIBRARIES)
    set(ruNameSpace "rutils::")
    get_filename_component(ruCMPath "${CMAKE_CURRENT_LIST_DIR}/.." ABSOLUTE)
    get_filename_component(ruRTPath "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)
    get_filename_component(ruINCPath "${ruRTPath}/include" ABSOLUTE)
    get_filename_component(ruLIBPath "${ruRTPath}/lib/${CMAKE_BUILD_TYPE}" ABSOLUTE)

    if (${CMAKE_SIZEOF_VOID_P} STREQUAL "8")
        set(ruLIBPath "${ruLIBPath}/x64")
    else ()
        set(ruLIBPath "${ruLIBPath}/x86")
    endif ()

    foreach (__pkg IN LISTS rutils_FIND_COMPONENTS)
        if (${rutils_FIND_REQUIRED_${__pkg}})
            find_package(${__pkg} REQUIRED PATHS ${ruRTPath})
        else ()
            find_package(${__pkg} QUIET PATHS ${ruRTPath})
        endif ()

        if (${__pkg}_FOUND)
            list(APPEND rutils_LIBRARIES ${ruNameSpace}${__pkg})
        endif ()
    endforeach ()
endblock ()
