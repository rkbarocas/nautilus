#ifndef _PLATFORM_INTERNAL_H
#define _PLATFORM_INTERNAL_H

#include <nautilus/naut_types.h>
#include <nautilus/paging.h>
#include <nautilus/printk.h>
#include <nautilus/semaphore.h>
#include <nautilus/libccompat.h>

// wamr expects types/functions from these; i'm not sure if nautilus has a pch or something i should use instead of including them individually
/*
#include <stdint.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
*/

/* // reimplementation of stdlib labs() to avoid pulling in conflicting off_t definition (is this the right approach?)
long int labs (long int n)
{
        if (n >= 0)
        {
                return n;
        } else
        {
                return -n;
        }
}*/

typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

typedef bool_t bool;

typedef void* korp_thread;
typedef unsigned long korp_tid; //TODO: not sure if this is safe to do straight up korp_tid is pthread_t is unsigned int, nk uses ulong tids
typedef struct nk_semaphore korp_mutex; // the mutex functions all use binary semaphores
typedef struct nk_semaphore korp_sem; // regular semaphores

typedef uint32_t os_file_handle; //TODO: is this right?
typedef uint32_t os_raw_file_handle;

os_file_handle os_get_invalid_handle(void); //TODO: what does nautilus use? also should this be static inline (some implementations have)
uint64_t os_getpagesize(void);

// Extension types (not implemented)
typedef void* korp_cond;
typedef void* korp_rwlock;
typedef void* os_dir_stream;
typedef void* os_poll_file_handle;
typedef void* os_nfds_t;

/*unsigned long strtoul(const char* str, char** end, unsigned int base)
{
        return simple_strtoul(str, end, base);
}
*/

#endif
