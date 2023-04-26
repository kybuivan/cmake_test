cmake_minimum_required(VERSION 3.14)
project(opencv_fetch CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
include(opencv)

add_executable(opencv_fetch)
target_sources(opencv_fetch PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

target_link_libraries(opencv_fetch PRIVATE ${OpenCV_LIBS})
target_include_directories(opencv_fetch PRIVATE ${OpenCV_INCLUDE_DIRS})