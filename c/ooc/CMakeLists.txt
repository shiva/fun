cmake_minimum_required(VERSION 2.6)

project(fwc_ooc)

include_directories(    # add everything to include path
    include
)

set(OOC_SOURCES
    src/Object.c
)

add_library(libooc SHARED ${OOC_SOURCES})

add_executable(OOC-tests tests/OOCTest.c ${OOC_SOURCES})
target_link_libraries(OOC-tests cunit)

add_test(
    NAME    OOC-tests 
    COMMAND ${EXECUTABLE_OUTPUT_PATH}/bin/OOC-tests
    )
