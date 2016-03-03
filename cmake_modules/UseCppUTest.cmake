include(CMakeParseArguments)
include(CodeCoverage)


function(add_unit_test)
    cmake_parse_arguments(ARGS "" "TARGET" "SOURCES" ${ARGN})

    # set the target binary and nim cache directory
    set(ut_target "test-${ARGS_TARGET}")
    
    SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
    SET(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
    SET(CMAKE_EXE_LINKER_FLAGS="-fprofile-arcs -ftest-coverage")

    include_directories($ENV{CPPUTEST_HOME}/include)
    add_library(imp_cpputest STATIC IMPORTED)
    set_property(TARGET imp_cpputest PROPERTY
            IMPORTED_LOCATION $ENV{CPPUTEST_HOME}/lib/libCppUTest.a)

    add_executable(
        ${ut_target}
        EXCLUDE_FROM_ALL
        ${ARGS_SOURCES}
    )
    
    target_link_libraries(${ut_target} imp_cpputest) 
    add_custom_target(
        run-${ut_target}
        COMMAND ${ut_target} -v
        DEPENDS ${ut_target}
        WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
        )

    if (NOT TARGET unit-test)
        add_custom_target(unit-test)
    endif()
    add_dependencies(unit-test run-${ut_target})


    SETUP_TARGET_FOR_COVERAGE(cov-${ut_target} ${ut_target} coverage-repot-${ut_target} "-v")
    if (NOT TARGET coverage)
        add_custom_target(coverage)
    endif()
    add_dependencies(coverage cov-${ut_target})

endfunction(add_unit_test)
