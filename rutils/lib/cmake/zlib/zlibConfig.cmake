
block ()
    include("${ruCMPath}/pkgInfo.cmake")
    _make_pkg_symbol(${CMAKE_CURRENT_LIST_FILE})
    if (NOT TARGET ${_cur_pkg_target})
        add_library(${_cur_pkg_target} SHARED IMPORTED)
        set_target_properties(${_cur_pkg_target} PROPERTIES
                INTERFACE_INCLUDE_DIRECTORIES   "${ruINCPath}/${_cur_pkg_name}"
                IMPORTED_IMPLIB_DEBUG           "${ruLIBPath}/${_cur_pkg_name}d.lib"
                IMPORTED_IMPLIB_RELEASE         "${ruLIBPath}/${_cur_pkg_name}.lib"
        )
    endif ()
endblock ()
