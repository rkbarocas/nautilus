#include "nautilus/nautilus.h"
#include "rt/wamr/platform_api_vmcore.h" //TODO
#include "nautilus/thread.h"

korp_tid os_self_thread(void)
{
        nk_thread_t* thread = get_cur_thread();
        return thread->tid;
}

uint8* os_thread_get_stack_boundary(void)
{
        nk_thread_t* thread = get_cur_thread();
        return uint8(thread->stack); //TODO: is this right? looks like stack marks boundary and rsp tracks current position?
}

void os_thread_jit_write_protect_np(bool enabled)
{} //TODO: most implementations seem to pass this, except on apple posix systems. does nautilus have an equivalent i should implement?

