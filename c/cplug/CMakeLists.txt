cmake_minimum_required(VERSION 2.6)

project(fwc_cplug)

include_directories(    # add everything to include path
    $(FUNWITHC_SOURCE_DIR)/fwc_stdlib
    include
)

#link_directories(
#    $(FUNWITHC_SOURCE_DIR)/fwc_stdlib
#)

add_executable(
    cplug               # build cplug binary
    src/cplug.c         # from these sources
)

target_link_libraries(
    cplug
    fwc_stdlib
)
