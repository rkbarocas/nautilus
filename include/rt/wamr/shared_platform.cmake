add_definitions(-DBH_PLATFORM_NAUTILUS)

set (PLATFORM_SHARED_DIR ${CMAKE_CURRENT_LIST_DIR})

set (NAUTILUS_DIR "~/nautilus")

include_directories(${PLATFORM_SHARED_DIR})
include_directories(${PLATFORM_SHARED_DIR}/../include)

file (GLOB_RECURSE source ${NAUTILUS_DIR}/src/rt/wamr/*.c)

file (GLOB_RECURSE header ${NAUTILUS_DIR}/include/rt/wamr/*.c)

LIST (APPEND RUNTIME_LIB_HEADER_LIST ${header})
