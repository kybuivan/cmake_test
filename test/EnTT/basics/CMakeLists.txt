cmake_minimum_required(VERSION 3.14)

set(ApplicationName entt_basics)

project(${ApplicationName} CXX)

include(FetchContent)
include(entt)

add_executable(${ApplicationName} main.cpp)
target_link_libraries( ${ApplicationName} PRIVATE EnTT::EnTT)
set_property(TARGET ${ApplicationName} PROPERTY CXX_STANDARD 11)
install(TARGETS ${ApplicationName} DESTINATION bin)