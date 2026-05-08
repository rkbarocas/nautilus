#include "nautilus/nautilus.h"
#include "nautilus/mm.h"
#include "rt/wamr/platform_api_vmcore.h" //TODO

void* os_malloc(unsigned size)
{
        return malloc(size);
}

void* os_realloc(void* ptr, unsigned size)
{
        return realloc(ptr, size);
}

void os_free(void* ptr)
{
        free(ptr);
}
