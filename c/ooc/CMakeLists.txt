cmake_minimum_required(VERSION 2.6)

project(fwc_ooc)

include_directories(    # add everything to include path
    include
)

set(OOC_SOURCES
    src/Object.c
)


add_library(libooc SHARED ${OOC_SOURCES})
add_library(libooc-static STATIC ${OOC_SOURCES})

set_target_properties(libooc-static PROPERTIES OUTPUT_NAME "libooc")
# Now the library target "libooc-static" will be named 
# "libooc.lib" with MS tools. This conflicts with the "libooc.lib" 
# import library corresponding to "libooc.dll",
# so we add a "lib" prefix (which is default on other platforms anyway):
set_target_properties(libooc-static PROPERTIES PREFIX "lib")

add_subdirectory(tests)
