cmake_minimum_required(VERSION 3.13)

project(CRTPI
  VERSION 0.0.1
  DESCRIPTION "Uses CRTP to redue boilerplate."
  LANGUAGES CXX)

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

function(add_and_link FILE LIBS)
add_executable(${FILE} ${FILE}.cpp)
target_link_libraries(${FILE} ${LIBS})
endfunction()

add_subdirectory(src)
