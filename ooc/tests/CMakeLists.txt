enable_testing()

set(OOCTests_src
    OOCTest.c
)

add_executable(OOCTests ${OOCTests_src})
target_link_libraries(OOCTests libooc)
set_target_properties (OOCTests PROPERTIES LINK_FLAGS -Wl,-lcunit)

add_test(OOCTests ${EXECUTABLE_OUTPUT_PATH}/OOCTests)

