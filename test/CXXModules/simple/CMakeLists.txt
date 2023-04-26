cmake_minimum_required(VERSION 3.24)
project(cxx_modules_simple CXX)

include(cxx_modules_rules)

add_executable(cxx_modules_simple)
target_sources(cxx_modules_simple
  PRIVATE
    main.cxx
  PRIVATE
    FILE_SET CXX_MODULES
      BASE_DIRS
        "${CMAKE_CURRENT_SOURCE_DIR}"
      FILES
        importable.cxx)
target_compile_features(cxx_modules_simple PUBLIC cxx_std_20)

add_test(NAME cxx_modules_simple COMMAND cxx_modules_simple)