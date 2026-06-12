#include "rt/wamr/platform_internal.h"

// Set up platform resources (none currently)
int bh_platform_init(void)
{
        return 0;
}

// Destroy platform resources (none currently)
void bh_platform_destroy(void)
{
        return;
}

os_file_handle os_get_invalid_handle(void) //TODO: what does nautilus use? also should this be static inline (some implementations have)
{
        return 0;
}

uint64_t os_getpagesize(void)
{
        return nk_paging_default_page_size();
}


