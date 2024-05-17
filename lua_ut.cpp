
#include <iostream>
#include <memory>
#include "lua.hpp"
using namespace std;

int lua_ut_test()
{
    shared_ptr<lua_State> spLuaState(luaL_newstate(), lua_close);
    luaL_openlibs(spLuaState.get());
    if (luaL_loadfile(spLuaState.get(), "test.lua") != LUA_OK)
    {
        return -1;
    }

    if (lua_pcall(spLuaState.get(), 0, 0, 0) != LUA_OK)
    {
        cout << lua_tostring(spLuaState.get(), -1) << endl;
        return -2;
    }

    if (lua_getglobal(spLuaState.get(), "width") == LUA_TNUMBER)
    {
        cout << "{lua_ut_test width} : " << lua_tonumber(spLuaState.get(), -1) << endl;

        if (lua_getglobal(spLuaState.get(), "height") == LUA_TNUMBER)
        {
            cout << "{lua_ut_test height} : " << lua_tonumber(spLuaState.get(), -1) << endl;
            return 116;
        }
    }

    return -3;
}
