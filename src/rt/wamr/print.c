#include "nautilus/nautilus.h"
#include "nautilus/printk.h"

int os_printf(const char* format, ...)
{
        va_list args;
        return vprintk(format, args);
}

int os_vprintf(const char* format, ...)
{
        va_list args;
        return vprintk(format, args);
}
