cmake_minimum_required(VERSION 2.6)
find_package(Nim REQUIRED)
include(${NIM_USE_FILE})

project(nim)

add_nim_executable(
	TARGET greeting
	SOURCES greetings.nim
)


