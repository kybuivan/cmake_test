cmake_minimum_required (VERSION 3.9)

set(ApplicationName cvplot_plot_basic)

project(${ApplicationName} CXX)

include(FetchContent)
include(opencv)
include(cvplot)

include_directories( ${OpenCV_INCLUDE_DIRS})
add_executable(${ApplicationName} main.cpp)
target_link_libraries( ${ApplicationName} ${OpenCV_LIBS} CvPlot::CvPlot)
set_property(TARGET ${ApplicationName} PROPERTY CXX_STANDARD 11)
install(TARGETS ${ApplicationName} DESTINATION bin)