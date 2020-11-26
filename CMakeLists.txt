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
target_compile_options(${PROJECT_NAME} INTERFACE
  -Wall -Wpedantic -Wextra -fexceptions)
target_link_options(${PROJECT_NAME} INTERFACE
  "$<$<CONFIG:Debug>:-pg;>" "$<$<CONFIG:RelWithDebInfo>:-pg;>")

# helper function
function(add_and_link FILE)
add_executable(${FILE} ${FILE}.cpp)
target_link_libraries(${FILE} ${PROJECT_NAME})
endfunction()

if(KETTLE_BUILD_TESTS)
  enable_testing()
  add_subdirectory(lib/Catch2)
  add_subdirectory(test)
endif()
