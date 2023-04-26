cmake_minimum_required(VERSION 3.14)

set(ApplicationName flecs_simple_module)

project(${ApplicationName} CXX)

include(FetchContent)
include(flecs)

add_executable(${ApplicationName} main.cpp simple_module.cpp simple_module.h)
target_link_libraries( ${ApplicationName} PRIVATE flecs_static)
set_property(TARGET ${ApplicationName} PROPERTY CXX_STANDARD 11)
install(TARGETS ${ApplicationName} DESTINATION bin)