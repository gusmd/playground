cmake_minimum_required(VERSION 3.8)
project(playground)

include (${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_subdirectory(embed)
