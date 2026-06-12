#include "nautilus/nautilus.h"
#include "nautilus/semaphore.h"
#include "rt/wamr/platform_internal.h"

//TODO: not quite sure what to do here--does nk have a true mutex?
// this implementation spins

int os_mutex_init(korp_mutex* mutex)
{
        if (!mutex)
        {
                return 1;
        }
        struct nk_semaphore* new = nk_semaphore_create(NULL, 1, NK_SEMAPHORE_DEFAULT, NULL); // name, initial count, type, characteristics; name and characteristics are both optional
        if (!new) {
                return 2;
        }
        mutex = new;
        return 0;
}

int os_mutex_destroy(korp_mutex* mutex)
{
        if (!mutex) {
                return 1;
        }
        
        nk_semaphore_release(mutex); // i think this is the right function?
        
        return 0;
}

int os_mutex_lock(korp_mutex* mutex)
{
        if (!mutex) {
                return 1;
        }

        nk_semaphore_down(mutex);

        return 0;
}

int os_mutex_unlock(korp_mutex* mutex)
{
        if (!mutex) {
                return 1;
        }

        nk_semaphore_up(mutex);

        return 0;
}
