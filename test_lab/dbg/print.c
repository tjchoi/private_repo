

#include <stdio.h>
#include <stdarg.h>

static FILE *dbg_file;

void x_vprintf(const char *fmt, va_list args)
{
    vfprintf(dbg_file ? dbg_file : stdout, fmt, args);
}

void x_printf(const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);

    x_vprintf(fmt, args);

    va_end(args);
}

void x_printfe(const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);

    vfprintf(dbg_file ? dbg_file : stderr, fmt, args);

    va_end(args);
}
