cmake_minimum_required(VERSION 2.6)
project(funwithc)

#Sends the -std=c99 flag to the gcc compiler
add_definitions(-std=c99)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

add_subdirectory(fwc_stdlib)
add_subdirectory(th-stor)
add_subdirectory(cplug)
