enable_testing()

set(OOCTests_src
    OOCTest.c
)

add_executable(OOCTests ${OOCTests_src})
target_link_libraries(OOCTests libooc cunit)

add_test(OOCTests ${EXECUTABLE_OUTPUT_PATH}/OOCTests)

