#include "rt/wamr/platform_api_vmcore.h"
#include "nautilus/thread.h"

typedef korp_tid unsigned long //TODO: not sure if this is safe to do straight up korp_tid is pthread_t is unsigned int, nk uses ulong tids
