#include "nautilus/nautilus.h"
#include "nautilus/printk.h"
#include "rt/wamr/platform_api_vmcore.h" //TODO

int os_printf(const char* format, ...)
{
        return printk(format, ...);
}

int os_vprintf(const char* format, ...)
{
        return vprintk(format, ...);
}
