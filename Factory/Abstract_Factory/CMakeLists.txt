cmake_minimum_required(VERSION 3.5)
project(abstract_factory)

add_library(abstract_factory SHARED
    src/main.cpp
)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(Abstract_Factory_Test
    src/main.cpp
)