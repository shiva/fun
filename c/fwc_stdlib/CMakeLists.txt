set(FWC_SOURCES
    error_functions.c
    get_num.c
)


add_library(fwc_stdlib SHARED ${FWC_SOURCES})
add_library(fwc_stdlib-static STATIC ${FWC_SOURCES})

set_target_properties(fwc_stdlib-static PROPERTIES OUTPUT_NAME "fwc_stdlib")
# Now the library target "fwc_stdlib-static" will be named 
# "fwc_stdlib.lib" with MS tools. This conflicts with the "fwc_stdlib.lib" 
# import library corresponding to "fwc_stdlib.dll",
# so we add a "lib" prefix (which is default on other platforms anyway):
set_target_properties(fwc_stdlib-static PROPERTIES PREFIX "lib")


