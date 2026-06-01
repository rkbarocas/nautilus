#ifndef _PLATFORM_INTERNAL_H
#define _PLATFORM_INTERNAL_H

#include <nautilus/naut_types.h>
#include <nautilus/paging.h>

// wamr expects types/functions from these; i'm not sure if nautilus has a pch or something i should use instead of including them individually
#include <stdint.h>
#include <string.h>
#include <stdarg.h>
// #include <stdlib.h>

// reimplementation of stdlib labs() to avoid pulling in conflicting off_t definition (is this the right approach?)
long int labs (long int n)
{
        if (n >= 0)
        {
                return n;
        } else
        {
                return -n;
        }
}

typedef bool_t bool;

typedef void* korp_thread;
typedef unsigned long korp_tid; //TODO: not sure if this is safe to do straight up korp_tid is pthread_t is unsigned int, nk uses ulong tids
typedef void* korp_mutex; //TODO
typedef void* korp_sem;

typedef uint32_t os_file_handle; //TODO: is this right?
typedef uint32_t os_raw_file_handle;

os_file_handle os_get_invalid_handle(void) //TODO: what does nautilus use? also should this be static inline (some implementations have)
{
        return 0;
}

uint64_t os_getpagesize(void)
{
        return nk_paging_default_page_size();
}

// Extension types (not implemented)
typedef void* korp_cond;
typedef void* korp_rwlock;
typedef void* os_dir_stream;
typedef void* os_poll_file_handle;
typedef void* os_nfds_t;

#endif
