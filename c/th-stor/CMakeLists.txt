cmake_minimum_required(VERSION 2.6)

project(fwc_thstor)

include_directories(    # add everything to include path
    $(FUNWITHC_SOURCE_DIR)/fwc_stdlib
    th-stor
)

#link_directories(
#    $(FUNWITHC_SOURCE_DIR)/fwc_stdlib
#)

add_executable(
    th-stor             # build th-stor binary
    th-stor.c           # from these sources
)

target_link_libraries(
    th-stor
    fwc_stdlib
)
