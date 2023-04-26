cmake_minimum_required(VERSION 3.24)
project(cxx_modules_duplicate CXX)

include(cxx_modules_rules)

add_executable(cxx_modules_duplicate)
target_sources(cxx_modules_duplicate
  PRIVATE
    main.cxx
  PRIVATE
    FILE_SET CXX_MODULES
      BASE_DIRS
        "${CMAKE_CURRENT_SOURCE_DIR}"
      FILES
        duplicate.cxx)
target_compile_features(cxx_modules_duplicate PRIVATE cxx_std_20)
target_compile_definitions(cxx_modules_duplicate PRIVATE NDUPLICATE=1)

add_executable(cxx_modules_duplicate2)
target_sources(cxx_modules_duplicate2
  PRIVATE
    main.cxx
  PRIVATE
    FILE_SET CXX_MODULES
      BASE_DIRS
        "${CMAKE_CURRENT_SOURCE_DIR}"
      FILES
        duplicate.cxx)
target_compile_features(cxx_modules_duplicate2 PRIVATE cxx_std_20)
target_compile_definitions(cxx_modules_duplicate2 PRIVATE NDUPLICATE=2)

add_test(NAME cxx_modules_duplicate COMMAND cxx_modules_duplicate)
set_property(TEST cxx_modules_duplicate
  PROPERTY
    PASS_REGULAR_EXPRESSION "From duplicate #1")
add_test(NAME cxx_modules_duplicate2 COMMAND cxx_modules_duplicate2)
set_property(TEST cxx_modules_duplicate2
  PROPERTY
    PASS_REGULAR_EXPRESSION "From duplicate #2")