# define helper
function(add_and_link_and_test FILE GROUP)
  set(EX ${FILE}_${GROUP})
  add_executable(${EX} ${FILE}.cpp)
  target_link_libraries(${EX} ${PROJECT_NAME} catch)
  add_test(${EX} ${EX})
  set_tests_properties(${EX} PROPERTIES LABELS ${GROUP})
  unset(EX)
endfunction()

# setup Catch2
add_library(the_tests catch.cpp)
target_link_libraries(the_tests PUBLIC Catch2::Catch2)

# add subdirs
add_subdirectory(traits)
add_subdirectory(binary_plus)
add_subdirectory(minus_assign)
add_subdirectory(plus_assign)

