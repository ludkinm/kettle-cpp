#include "../catch.hpp"
#include <kettle++/traits/trait_maker.hpp>

TEST_CASE("double", "[has_checks]") {
  REQUIRE(ktl::has_plus_assign_v<double>);
  REQUIRE(ktl::has_minus_assign_v<double>);
  REQUIRE(ktl::has_mult_assign_v<double>);
  REQUIRE(ktl::has_div_assign_v<double>);
  REQUIRE(!ktl::has_mod_assign_v<double>);
  REQUIRE(ktl::has_and_assign_v<int>);
  REQUIRE(ktl::has_or_assign_v<int>);
  REQUIRE(ktl::has_xor_assign_v<int>);
  REQUIRE(ktl::has_bit_left_assign_v<int>);
  REQUIRE(ktl::has_bit_right_assign_v<int>);
  REQUIRE(ktl::has_pre_inc_v<double>);
  REQUIRE(ktl::has_pre_dec_v<double>);
  REQUIRE(ktl::has_post_inc_v<double>);
  REQUIRE(ktl::has_post_dec_v<double>);
  REQUIRE(ktl::has_unary_plus_v<double>);
  REQUIRE(ktl::has_unary_minus_v<double>);
  REQUIRE(!ktl::has_unary_bit_not_v<double>);
  REQUIRE(ktl::has_binary_plus_v<double>);
  REQUIRE(ktl::has_binary_minus_v<double>);
  REQUIRE(ktl::has_binary_mult_v<double>);
  REQUIRE(ktl::has_binary_div_v<double>);
  REQUIRE(!ktl::has_binary_mod_v<double>);
  REQUIRE(!ktl::has_binary_bit_and_v<double>);
  REQUIRE(!ktl::has_binary_bit_or_v<double>);
  REQUIRE(!ktl::has_binary_bit_xor_v<double>);
  REQUIRE(!ktl::has_binary_bit_left_v<double>);
  REQUIRE(!ktl::has_binary_bit_right_v<double>);
  REQUIRE(ktl::has_unary_logical_not_v<double>);
  REQUIRE(ktl::has_unary_logical_and_v<double>);
  REQUIRE(ktl::has_unary_logical_or_v<double>);
  REQUIRE(ktl::has_unary_logical_or_v<double>);
  REQUIRE(ktl::has_equals_v<double>);
  REQUIRE(ktl::has_not_equals_v<double>);
  REQUIRE(ktl::has_less_than_v<double>);
  REQUIRE(ktl::has_less_than_equals_v<double>);
  REQUIRE(ktl::has_more_than_v<double>);
  REQUIRE(ktl::has_more_than_equals_v<double>);
}
