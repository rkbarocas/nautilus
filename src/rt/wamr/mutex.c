#include "nautilus/nautilus.h"
#include "rt/wamr/platform_api_vmcore.h" //TODO
#include "nautilus/thread.h"
#include "nautilus/spinlock.h"

//TODO: not quite sure what to do here--does nk have a true mutex?

int os_mutex_init (korp_mutex* mutex)
{

