# define helper
function(add_and_link_and_test FILE GROUP)
  add_executable(${FILE} ${FILE}.cpp)
  target_link_libraries(${FILE} ${PROJECT_NAME} catch)
  add_test(${FILE} ${FILE})
  set_tests_properties(${FILE} PROPERTIES LABELS ${GROUP})
endfunction()

# setup Catch2
add_library(catch catch.cpp)
target_link_libraries(catch PUBLIC Catch2::Catch2)
add_custom_target(the_tests)

# add subdirs
add_subdirectory(traits)
add_subdirectory(binary_plus)
add_subdirectory(minus_assign)

