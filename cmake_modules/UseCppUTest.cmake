include(CMakeParseArguments)

function(add_unit_test)
    cmake_parse_arguments(ARGS "" "TARGET" "SOURCES" ${ARGN})

    # collect set of input source files
    set(in_files "")
    foreach(src ${ARGS_SOURCES} ${ARGS_UNPARSED_ARGUMENTS})
        list(APPEND in_files "${CMAKE_CURRENT_SOURCE_DIR}/${src}")
    endforeach(src ${ARGS_SOURCES} ${ARGS_UNPARSED_ARGUMENTS})

    # set the target binary and nim cache directory
    set(ut_target "test-${ARGS_TARGET}")
    
    include_directories($ENV{CPPUTEST_HOME}/include)
    add_library(imp_cpputest STATIC IMPORTED)
    set_property(TARGET imp_cpputest PROPERTY
            IMPORTED_LOCATION $ENV{CPPUTEST_HOME}/lib/libCppUTest.a)

    add_executable(
        ${ut_target}
        EXCLUDE_FROM_ALL
        ${in_files}
    )
    target_link_libraries(${ut_target} imp_cpputest) 
    add_custom_target(
        run-${ut_target}
        COMMAND ${ut_target} -v
        DEPENDS ${ut_target}
        WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
        )

    if (NOT TARGET test)
        add_custom_target(test)
    endif()
    add_dependencies(test run-${ut_target})

endfunction(add_unit_test)
