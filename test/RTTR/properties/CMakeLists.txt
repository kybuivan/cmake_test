cmake_minimum_required(VERSION 3.14)

set(ApplicationName rttr_properties)

project(${ApplicationName} CXX)

include(FetchContent)
include(rttr)

add_executable(${ApplicationName} main.cpp)
target_link_libraries( ${ApplicationName} PRIVATE RTTR::Core_Lib)
set_property(TARGET ${ApplicationName} PROPERTY CXX_STANDARD 11)
install(TARGETS ${ApplicationName} DESTINATION bin)