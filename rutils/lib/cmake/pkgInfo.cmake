
macro (_make_pkg_symbol pkgfile)
    get_filename_component(_cur_pkg_name ${pkgfile} NAME)
    string(REPLACE "Config.cmake" "" _cur_pkg_name ${_cur_pkg_name})
    set(_cur_pkg_target ${ruNameSpace}${_cur_pkg_name})
    message(STATUS "[${_cur_pkg_target}] loaded.")
endmacro ()
