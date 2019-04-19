cmake_minimum_required(VERSION 3.8)
project(playground_embed)

add_executable(playground_embed src/main.cpp)

find_package(pybind11 REQUIRED)

target_link_libraries(playground_embed PRIVATE pybind11::embed)
