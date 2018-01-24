

#include <stdarg.h>

#include "print.h"
#include "x_type.h"
#include "x_dbg.h"

enum x_dbg dbg_cur_lvl = 0;

int sub_func(int argc)
{
    dbg_in(__func__, "%d ", argc);
    dbg(X_DBG_MSG, "tjchoi\n");


    dbg_out(__func__);
    return 0;

}

int main(int argc, char **argv)
{
    x_printf("Hello\n");

    dbg(X_DBG_MSG, "dbg%d \n", 1);
    
    dbg(X_DBG_MSG, "Success file read\n");
        
    sub_func(4);

    return 0;

}


