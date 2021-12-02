cmake_minimum_required(VERSION 3.5)
project(factory)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CXX_FLAGS
 -O2
 -std=c++11
 -rdynamic
 -lpthread
 -fPIC
 -lstdc++
 -pipe
 )

if(CMAKE_BUILD_BITS EQUAL 32)
  list(APPEND CXX_FLAGS "-m32")
else()
  list(APPEND CXX_FLAGS "-m64")
endif()

if (WIN32)
add_definitions(-D__win__)
add_definitions(-D__use_iocp__)
endif ()

# 设置生成的可执行文件和库的路径，分别对应bin和lib文件夹中
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

add_library(factory SHARED 
    src/client.cpp)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# #设置链接库路径
# link_directories(  
#     ${CMAKE_CURRENT_SOURCE_DIR}/libs
# )

# #设置target需要链接的库
# target_link_libraries(factory
#     PATH
# )

add_executable(Factory_test
    src/client.cpp
)