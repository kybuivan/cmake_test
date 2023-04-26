cmake_minimum_required(VERSION 3.24)
project(cxx_modules_library CXX)

include(cxx_modules_rules)

include(GenerateExportHeader)

add_library(library)
generate_export_header(library)
target_sources(library
  PUBLIC
    FILE_SET HEADERS
      BASE_DIRS
        "${CMAKE_CURRENT_BINARY_DIR}"
      FILES
        "${CMAKE_CURRENT_BINARY_DIR}/library_export.h"
    FILE_SET CXX_MODULES
      BASE_DIRS
        "${CMAKE_CURRENT_SOURCE_DIR}"
      FILES
        importable.cxx)
target_compile_features(library PUBLIC cxx_std_20)

add_executable(cxx_modules_library)
target_link_libraries(cxx_modules_library PRIVATE library)
target_sources(cxx_modules_library PRIVATE main.cxx)

add_test(NAME cxx_modules_library COMMAND cxx_modules_library)