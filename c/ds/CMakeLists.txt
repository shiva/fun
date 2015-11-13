include(UseCppUTest)

include_directories(    # add everything to include path
    include
)

set(DS_SOURCES
	src/mem.c
    src/linkedlist.c
    )

add_library(ds SHARED ${DS_SOURCES})

# Now the library target "libds-static" will be named
# "libds.lib" with MS tools. This conflicts with the "libds.lib"
# import library corresponding to "libds.dll",
# so we add a "lib" prefix (which is default on other platforms anyway):
add_library(libds-static STATIC ${DS_SOURCES})
set_target_properties(libds-static PROPERTIES OUTPUT_NAME "ds")
set_target_properties(libds-static PROPERTIES PREFIX "lib")

# TESTS
add_unit_test(
    TARGET ds
    SOURCES 
    	${DS_SOURCES}
    	tests/BasicTests.cpp
    	tests/LinkedListTests.cpp
    	tests/RunAllTests.cpp
    )
