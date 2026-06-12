#include "nautilus/nautilus.h"
#include "nautilus/mm.h"

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
