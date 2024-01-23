
block ()
    include("${ruCMPath}/pkgInfo.cmake")
    _make_pkg_symbol(${CMAKE_CURRENT_LIST_FILE})
    if (NOT TARGET ${_cur_pkg_target})
        add_library(${_cur_pkg_target} INTERFACE IMPORTED)

        list(APPEND _RUpkgs zlib)
        list(APPEND _RUpkgs lua)

        foreach(__pkg IN LISTS _RUpkgs)
            find_package(${__pkg} CONFIG REQUIRED PATHS ${ruRTPath})
            if (${__pkg}_FOUND)
                target_link_libraries(${_cur_pkg_target} INTERFACE ${ruNameSpace}${__pkg})
            endif ()
        endforeach ()
    endif ()
endblock ()
