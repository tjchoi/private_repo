

#include <stdio.h>

#include "./lua-5.3.4/src/lua.h"
#include "./lua-5.3.4/src/lauxlib.h"


static int lua_print_hello(lua_State *L)
{
    printf("Hello!\n");
    
    return 1;
}

int luaopen_mylib(lua_State *L)
{
    lua_register(L, "print_hello", lua_print_hello);

    return 1;
}

