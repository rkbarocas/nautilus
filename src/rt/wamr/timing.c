#include "nautilus/nautilus.h"
#include "nautilus/libccompat.h"
#include "rt/wamr/platform_api_vmcore.h" //TODO
#include "nautilus/thread.h"

uint64 os_time_get_boot_us(void)
{
        struct timespec* time;
        clock_gettime(CLOCK_MONOTONIC, &time); //TODO: there is also a CLOCK_BOOTTIME option, but it doesn't seem supported and this looks to give boot time anyway
        return time.tv_nsec / 1000
}

uint64 os_time_thread_cputime_us(void)
{
        nk_thread_t* thread = get_cur_thread();
        return thread->sched_state->run_time;
}
        
