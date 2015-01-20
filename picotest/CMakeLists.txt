cmake_minimum_required(VERSION 2.8.4)
project(sandbox)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(
    include
    ../deps/picotest
)

set(LIB_SOURCE_FILES
    lib/hello.c
    lib/where.c
    lib/utils.c
)

set(UNIT_TEST_SOURCE_FILES
    ${LIB_SOURCE_FILES}
    ../deps/picotest/picotest.c
    t/00unit/lib/where.c
    t/00unit/test.c
)

add_library(libsandbox STATIC ${LIB_SOURCE_FILES})

add_executable(sandbox main.c)
target_link_libraries(sandbox libsandbox)

# tests

add_executable(t-00unit.t t/00unit/test.c)
add_library(libtest STATIC ${UNIT_TEST_SOURCE_FILES})
target_link_libraries(t-00unit.t libtest)
