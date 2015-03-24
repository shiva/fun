cmake_minimum_required(VERSION 2.6)

include_directories(    # add everything to include path
    $(FUNWITHC_SOURCE_DIR)/fwc_stdlib
    include
)

add_executable(
    cplug               # build cplug binary
    src/cplug.c         # from these sources
)

target_link_libraries(
    cplug
    fwc_stdlib
)
