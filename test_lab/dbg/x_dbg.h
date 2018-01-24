

#ifndef _DEBUG_H_
#define _DEBUG_H

#include <time.h>

#include "x_type.h"

#define DBG_PREFIX "[TEST] "

/** It is able to be changed dynamically by user */
extern enum x_dbg dbg_cur_lvl;



static inline void _dbg_naked(enum x_dbg level, const char *fmt, va_list args)
{
    if (dbg_cur_lvl > level)
        return ;

    x_vprintf(fmt, args);
}

static inline void dbg_naked(enum x_dbg level, const char *fmt, ...)
{
    va_list args;

    if (dbg_cur_lvl > level)
        return ;
    
    va_start(args, fmt);
    _dbg_naked(level, fmt, args);
    va_end(args);
}

static inline void _dbg(enum x_dbg level, const char *fmt, va_list args)
{
    time_t now;
    struct tm *tm_now;

    if (dbg_cur_lvl > level)
        return ;
    
    time(&now);
    tm_now = localtime(&now);

    if (tm_now)
        x_printf(DBG_PREFIX "%02u:%02u:%02u ",
                tm_now->tm_hour,
                tm_now->tm_min,
                tm_now->tm_sec);

    x_vprintf(fmt, args);
}

static inline void dbg(enum x_dbg level, const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    _dbg(level, fmt, args);
    va_end(args);
}

static inline void dbg_in(const char *func, const char *fmt, ...)
{
    va_list args;

    if (dbg_cur_lvl > X_DBG_MSG)
        return ;

    dbg(X_DBG_MSG, "IN  - %s(", func);

    va_start(args, fmt);
    x_vprintf(fmt, args);
    va_end(args);

    dbg_naked(X_DBG_MSG, ")\n");
}

static inline void dbg_out(const char *func)
{
    va_list args;

    if (dbg_cur_lvl > X_DBG_MSG)
        return ;

    dbg(X_DBG_MSG, "OUT - %s()\n", func);
}

#endif

