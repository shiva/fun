cmake_minimum_required(VERSION 2.6)

include_directories(    # add everything to include path
    $(PROJECT_SOURCE_DIR)/fwc_stdlib
    th-stor
)

link_directories(
    $(PROJECT_SOURCE_DIR)/fwc_stdlib
)

add_executable(
    th-stor             # build th-stor binary
    th-stor.c           # from these sources
)

target_link_libraries(
    th-stor
    fwc_stdlib
)
