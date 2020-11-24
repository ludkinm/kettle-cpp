# define helper
function(add_and_link_and_test FILE)
  add_executable(${FILE} ${FILE}.cpp)
  target_link_libraries(${FILE} ${PROJECT_NAME} catch)
  add_test(${FILE} ${FILE})
endfunction()

add_library(catch catch.cpp)
target_link_libraries(catch PUBLIC Catch2::Catch2)
add_custom_target(the_tests)

add_and_link_and_test(has_checks_void)
add_and_link_and_test(has_checks_int)
add_and_link_and_test(has_checks_int_ptr)
add_and_link_and_test(has_checks_double)
add_and_link_and_test(has_checks_nullptr)
