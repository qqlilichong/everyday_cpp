
/*

////////////////////////////////////////////////////////////////////////////////////////

namespace unit0006 {

    template<size_t IL, size_t IR>
    using is_sameint = is_same< integral_constant< size_t, IL >, integral_constant< size_t, IR > > ;

    auto case1()
    {
        constexpr size_t a = 666 ;
        constexpr size_t b = 999 ;
        constexpr size_t c = 3 * 3 ;
        constexpr size_t d = 7 + 2 ;

        // ( a == b ) || ( c == d )
        cout << disjunction_v<
                is_sameint< a, b >,
                is_sameint< c, d >
        > << endl ;

        // ( a == b ) && ( c == d )
        cout << conjunction_v<
                is_sameint< a, b >,
                is_sameint< c, d >
        > << endl ;
    }

    auto test()
    {
        cout << "<type_traits> : " << FL << endl ;

        case1() ;

        cout << endl ;
    }

}

*/

////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <memory>
#include "e_variadic_templates.hpp"
#include "e_fold_expression.hpp"
#include "e_constexpr.hpp"
#include "e_structured_bindings.hpp"
#include "e_string_view.hpp"
#include "e_deduction_guide.hpp"
#include "zlib.h"
#include "lua.hpp"

int lua_test()
{
    std::shared_ptr<lua_State> spLuaState(luaL_newstate(), lua_close);
    luaL_openlibs(spLuaState.get());
    if (luaL_loadfile(spLuaState.get(), "test.lua") != LUA_OK)
    {
        return -1;
    }

    if (lua_pcall(spLuaState.get(), 0, 0, 0) != LUA_OK)
    {
        std::cout << lua_tostring(spLuaState.get(), -1) << std::endl;
        return -2;
    }

    if (lua_getglobal(spLuaState.get(), "width") == LUA_TNUMBER)
    {
        std::cout << "lua-env [width] : " << lua_tonumber(spLuaState.get(), -1) << std::endl;
    }

    if (lua_getglobal(spLuaState.get(), "height") == LUA_TNUMBER)
    {
        std::cout << "lua-env [height] : " << lua_tonumber(spLuaState.get(), -1) << std::endl;
    }

    return 0;
}

int unit_test()
{
    lua_test();
    std::cout << "zlib version : " << zlibVersion() << std::endl;
    std::cout << e_variadic_templates::ut() << std::endl;
    std::cout << e_fold_expression::ut() << std::endl;
    std::cout << e_constexpr::ut() << std::endl;
    std::cout << e_structured_bindings::ut() << std::endl;
    std::cout << e_string_view::ut() << std::endl;
    std::cout << e_deduction_guide::ut() << std::endl;
    return 0;
}

int main()
{
    unit_test();
    extern void boost_asio_spawn_test();
    boost_asio_spawn_test();
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////
