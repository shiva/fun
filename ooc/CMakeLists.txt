cmake_minimum_required(VERSION 2.6)

project(fwc_ooc)

include_directories(    # add everything to include path
    include
)

add_executable(
    ooc-test            # build ooc test binary
    src/Object.c
    src/ooc.c           
)

add_subdirectory(tests)
