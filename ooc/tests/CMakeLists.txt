enable_testing()

set(OOCTests_src
    OOCTest.cpp
)

add_executable(OOCTests ${OOCTests_src})
target_link_libraries(OOCTests CppUTest)
add_test(OOCTests ${EXECUTABLE_OUTPUT_PATH}/OOCTests)

