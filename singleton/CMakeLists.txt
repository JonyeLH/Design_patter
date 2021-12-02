cmake_minimum_required(VERSION 3.5)
project(Singleton)

add_library(Singleton SHARED
    src/
)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(Singleton_test
    src/
)