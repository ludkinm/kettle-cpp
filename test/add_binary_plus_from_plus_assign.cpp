#include "catch.hpp"
#include <crtp_interface/binary_plus.hpp>
#include <crtp_interface/traits/trait_maker.hpp>

struct IntImpl {
  int x;
  explicit IntImpl(int a) : x{a} {}

  friend IntImpl &operator+=(IntImpl &lhs, IntImpl const &rhs) {
    lhs.x += rhs.x;
    return lhs;
  }
};

struct Int : IntImpl, protected crtpi::binary_plus<IntImpl> {
  using IntImpl::IntImpl;
};

TEST_CASE("binary plus", "[addin]") {
  Int i{1};
  Int j{2};

  REQUIRE(i.x == 1);
  REQUIRE(j.x == 2);
  i += j;
  REQUIRE(i.x == 3);
  REQUIRE(j.x == 2);

  REQUIRE((i + j).x == 5);
}
