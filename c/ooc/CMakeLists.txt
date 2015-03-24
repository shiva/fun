include(UseCppUTest)

include_directories(    # add everything to include path
    include
    )

set(OOC_SOURCES
    src/Object.c
    )

add_library(ooc SHARED ${OOC_SOURCES})

# Now the library target "libooc-static" will be named
# "libooc.lib" with MS tools. This conflicts with the "libooc.lib"
# import library corresponding to "libooc.dll",
# so we add a "lib" prefix (which is default on other platforms anyway):
add_library(libooc-static STATIC ${OOC_SOURCES})
set_target_properties(libooc-static PROPERTIES OUTPUT_NAME "ooc")
set_target_properties(libooc-static PROPERTIES PREFIX "lib")

# TESTS
add_unit_test(
    TARGET ooc 
    SOURCES 
        ./tests/OOCTest.cpp 
        ./tests/RunAllTests.cpp 
        ${OOC_SOURCES})
