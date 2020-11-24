#include "catch.hpp"
#include "catch2/catch.hpp"
#include <crtp_interface/traits/trait_maker.hpp>

TEST_CASE("std::nullptr_t", "[has_checks]") {
  REQUIRE(crtpi::has_equals_v<std::nullptr_t>);
  REQUIRE(crtpi::has_not_equals_v<std::nullptr_t>);
  REQUIRE(crtpi::has_unary_logical_not_v<std::nullptr_t>);
  REQUIRE(crtpi::has_unary_logical_and_v<std::nullptr_t>);
  REQUIRE(crtpi::has_unary_logical_or_v<std::nullptr_t>);
  REQUIRE(!crtpi::has_less_than_v<std::nullptr_t>);
  REQUIRE(!crtpi::has_less_than_equals_v<std::nullptr_t>);
  REQUIRE(!crtpi::has_more_than_v<std::nullptr_t>);
  REQUIRE(!crtpi::has_more_than_equals_v<std::nullptr_t>);
  REQUIRE(!crtpi::has_plus_assign_v<std::nullptr_t>);
  REQUIRE(!crtpi::has_minus_assign_v<std::nullptr_t>);
  REQUIRE(!crtpi::has_mult_assign_v<std::nullptr_t>);
  REQUIRE(!crtpi::has_div_assign_v<std::nullptr_t>);
  REQUIRE(!crtpi::has_mod_assign_v<std::nullptr_t>);
  REQUIRE(!crtpi::has_pre_inc_v<std::nullptr_t>);
  REQUIRE(!crtpi::has_pre_dec_v<std::nullptr_t>);
  REQUIRE(!crtpi::has_post_inc_v<std::nullptr_t>);
  REQUIRE(!crtpi::has_post_dec_v<std::nullptr_t>);
  REQUIRE(!crtpi::has_unary_plus_v<std::nullptr_t>);
  REQUIRE(!crtpi::has_unary_minus_v<std::nullptr_t>);
  REQUIRE(!crtpi::has_unary_bit_not_v<std::nullptr_t>);
  REQUIRE(!crtpi::has_binary_plus_v<std::nullptr_t>);
  REQUIRE(!crtpi::has_binary_minus_v<std::nullptr_t>);
  REQUIRE(!crtpi::has_binary_mult_v<std::nullptr_t>);
  REQUIRE(!crtpi::has_binary_div_v<std::nullptr_t>);
  REQUIRE(!crtpi::has_binary_mod_v<std::nullptr_t>);
  REQUIRE(!crtpi::has_binary_bit_and_v<std::nullptr_t>);
  REQUIRE(!crtpi::has_binary_bit_or_v<std::nullptr_t>);
  REQUIRE(!crtpi::has_binary_bit_xor_v<std::nullptr_t>);
  REQUIRE(!crtpi::has_binary_bit_left_v<std::nullptr_t>);
  REQUIRE(!crtpi::has_binary_bit_right_v<std::nullptr_t>);
}
