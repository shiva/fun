include_directories(    # add everything to include path
    $(FUNWITHC_SOURCE_DIR)/fwc_stdlib
    th-stor
)

add_executable(
    th-stor             # build th-stor binary
    th-stor.c           # from these sources
)

target_link_libraries(
    th-stor
    fwc_stdlib
)
