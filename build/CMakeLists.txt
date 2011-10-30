#Specify the version being used aswell as the language
cmake_minimum_required(VERSION 2.6)
#Name your project here
project(funwithc)

#Sends the -std=c99 flag to the gcc compiler
add_definitions(-std=c99)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

include_directories("${PROJECT_SOURCE_DIR}/../fwc_stdlib")
add_subdirectory("${PROJECT_SOURCE_DIR}/../fwc_stdlib")

#This tells CMake to fib.c and name it fibonacci
#add_executable(fibonacci fib.c)



