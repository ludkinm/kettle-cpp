cmake_minimum_required(VERSION 3.13)

project(KETTLE
  VERSION 0.0.1
  DESCRIPTION "Uses CRTP to reduce boilerplate."
  LANGUAGES CXX)

option(KETTLE_BUILD_TESTS "ON if tests should be built" ON)

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

target_compile_features(${PROJECT_NAME} INTERFACE
  cxx_std_17)

if(KETTLE_BUILD_TESTS)
  enable_testing()
  add_subdirectory(lib/Catch2)
  add_subdirectory(test)
endif()
