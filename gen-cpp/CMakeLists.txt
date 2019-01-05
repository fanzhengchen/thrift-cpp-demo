cmake_minimum_required(VERSION 3.10)


add_library(AIFILTER SHARED AIFilterService.cpp AIFilterMessage_types.cpp AIFilterMessage_constants.cpp
        AIFilterService_server.skeleton.cpp)

#include_directories(${THRIFT_INCLUDE_DIR})
#link_libraries(${THRIFT_LIBRARIES})

message(ON " ${THRIFT_INCLUDE_DIR} || ${THRIFT_LIBRARIES} || ${THRIFTNB_LIBRARIES}")
message(ON " ${LIBEVENT_LIBRARIES} || ${LIBEVENT_INCLUDE_DIRS} ")

target_include_directories(AIFILTER SYSTEM
        PUBLIC ${THRIFT_INCLUDE_DIR})

target_link_libraries(AIFILTER ${THRIFT_LIBRARIES} ${THRIFTNB_LIBRARIES}
        ${LIBEVENT_LIBRARIES})