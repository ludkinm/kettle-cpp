#include "catch.hpp"
#include <kettle++/binary_plus.hpp>
#include <kettle++/traits/trait_maker.hpp>

struct IntImpl {
  int x;
  explicit IntImpl(int a) : x{a} {}

  friend IntImpl operator-(IntImpl const &lhs) {
    IntImpl ret{-lhs.x};
    return ret;
  }

  friend IntImpl &operator-=(IntImpl &lhs, IntImpl const &rhs) {
    lhs.x -= rhs.x;
    return lhs;
  }
};

struct Int : IntImpl, protected ktl::binary_plus<IntImpl> {
  using IntImpl::IntImpl;
};

TEST_CASE("binary plus from minus", "[addin]") {
  Int i{1};
  Int j{2};

  REQUIRE(i.x == 1);
  REQUIRE(j.x == 2);

  REQUIRE((i + j).x == 3);
}
