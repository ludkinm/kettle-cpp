#include "catch.hpp"
#include <crtp_interface/traits/trait_maker.hpp>

TEST_CASE("double", "[has_checks]") {
  REQUIRE(crtpi::has_plus_assign_v<double>);
  REQUIRE(crtpi::has_minus_assign_v<double>);
  REQUIRE(crtpi::has_mult_assign_v<double>);
  REQUIRE(crtpi::has_div_assign_v<double>);
  REQUIRE(!crtpi::has_mod_assign_v<double>);
  REQUIRE(crtpi::has_and_assign_v<int>);
  REQUIRE(crtpi::has_or_assign_v<int>);
  REQUIRE(crtpi::has_xor_assign_v<int>);
  REQUIRE(crtpi::has_bit_left_assign_v<int>);
  REQUIRE(crtpi::has_bit_right_assign_v<int>);
  REQUIRE(crtpi::has_pre_inc_v<double>);
  REQUIRE(crtpi::has_pre_dec_v<double>);
  REQUIRE(crtpi::has_post_inc_v<double>);
  REQUIRE(crtpi::has_post_dec_v<double>);
  REQUIRE(crtpi::has_unary_plus_v<double>);
  REQUIRE(crtpi::has_unary_minus_v<double>);
  REQUIRE(!crtpi::has_unary_bit_not_v<double>);
  REQUIRE(crtpi::has_binary_plus_v<double>);
  REQUIRE(crtpi::has_binary_minus_v<double>);
  REQUIRE(crtpi::has_binary_mult_v<double>);
  REQUIRE(crtpi::has_binary_div_v<double>);
  REQUIRE(!crtpi::has_binary_mod_v<double>);
  REQUIRE(!crtpi::has_binary_bit_and_v<double>);
  REQUIRE(!crtpi::has_binary_bit_or_v<double>);
  REQUIRE(!crtpi::has_binary_bit_xor_v<double>);
  REQUIRE(!crtpi::has_binary_bit_left_v<double>);
  REQUIRE(!crtpi::has_binary_bit_right_v<double>);
  REQUIRE(crtpi::has_unary_logical_not_v<double>);
  REQUIRE(crtpi::has_unary_logical_and_v<double>);
  REQUIRE(crtpi::has_unary_logical_or_v<double>);
  REQUIRE(crtpi::has_unary_logical_or_v<double>);
  REQUIRE(crtpi::has_equals_v<double>);
  REQUIRE(crtpi::has_not_equals_v<double>);
  REQUIRE(crtpi::has_less_than_v<double>);
  REQUIRE(crtpi::has_less_than_equals_v<double>);
  REQUIRE(crtpi::has_more_than_v<double>);
  REQUIRE(crtpi::has_more_than_equals_v<double>);
}
