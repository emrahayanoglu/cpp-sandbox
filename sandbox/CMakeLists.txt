cmake_minimum_required(VERSION 2.8.4)
project(sandbox)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(
    include
)

set(LIB_SOURCE_FILES
    lib/hello.c
    lib/where.c
)

add_library(libsandbox STATIC ${LIB_SOURCE_FILES})

add_executable(sandbox main.c)
target_link_libraries(sandbox libsandbox)
