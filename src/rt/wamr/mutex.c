#include "nautilus/nautilus.h"
#include "rt/wamr/platform_api_vmcore.h" //TODO
#include "nautilus/mcslock.h"

//TODO: not quite sure what to do here--does nk have a true mutex?
// this implementation spins

int os_mutex_init(korp_mutex* mutex)
{
        if (!mutex)
        {
                return 1;
        }
        nk_mcs_lock_t* new = malloc(sizeof(nk_mcs_lock_t));
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
        
        free(mutex); // we shouldn't have to clear the queue here, i think?
        
        return 0;
}

int os_mutex_lock(korp_mutex* mutex)
{
        if (!mutex) {
                return 1;
        }

        nk_mcs_lock_t me; // since this blocks, out of scope isn't an issue?
        nk_mcs_lock(mutex, &me);

        return 0;
}

int os_mutex_unlock(korp_mutex* mutex)
{
        if (!mutex) {
                return 1;
        }

        nk_mcs_unlock


// im not sure this will actually work--mcslocks need a persistent "me" between lock and unlock
