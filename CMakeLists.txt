cmake_minimum_required(VERSION 3.10)

project(thrift_demo)

include(ThriftConfig.cmake)
include(FindLibevent.cmake)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(gen-cpp)

add_executable(client client.cpp)

add_executable(server server.cpp)

target_link_libraries(client AIFILTER)
target_link_libraries(server AIFILTER)

include_directories(${THRIFT_INCLUDE_DIR})



