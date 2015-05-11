cmake_minimum_required(VERSION 2.6)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules")

add_subdirectory(c)
add_subdirectory(node)
# add_subdirectory(nim) -- nim support on CI is a pain!!!
