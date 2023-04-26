cmake_minimum_required(VERSION 3.14)

set(ApplicationName flecs_observers_basics)

project(${ApplicationName} CXX)

include(FetchContent)
include(flecs)

add_executable(${ApplicationName} main.cpp)
target_link_libraries( ${ApplicationName} PRIVATE flecs_static)
set_property(TARGET ${ApplicationName} PROPERTY CXX_STANDARD 11)
install(TARGETS ${ApplicationName} DESTINATION bin)