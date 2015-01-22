cmake_minimum_required(VERSION 2.8.4)
project(http_client_curl)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include(FindCURL)
include_directories(
    ../deps/picojson
)

add_executable(http_client_curl main.cpp)
target_link_libraries(http_client_curl ${CURL_LIBRARIES})
