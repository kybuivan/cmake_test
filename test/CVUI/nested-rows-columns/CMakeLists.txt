cmake_minimum_required(VERSION 3.14)

set(ApplicationName cvui_nested_rows_and_columns)

project(${ApplicationName} CXX)

include(FetchContent)
include(opencv)
include(cvui)

include_directories( ${OpenCV_INCLUDE_DIRS} ${cvui_INCLUDE_DIRS})
add_executable(${ApplicationName} main.cpp)
target_link_libraries( ${ApplicationName} ${OpenCV_LIBS} cvui::cvui)
set_property(TARGET ${ApplicationName} PROPERTY CXX_STANDARD 11)
install(TARGETS ${ApplicationName} DESTINATION bin)
