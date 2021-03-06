#include "../catch.hpp"
#include <kettle++/ops/binary_plus.hpp>
#include <kettle++/traits/trait_maker.hpp>

using ktl::operator+;

struct Int {
  int x;
  explicit Int(int a) : x{a} {}

  friend Int operator-(Int const &lhs) {
    Int ret{-lhs.x};
    return ret;
  }

  friend Int &operator-=(Int &lhs, Int const &rhs) {
    lhs.x -= rhs.x;
    return lhs;
  }
};

TEST_CASE("from minus ops", "[binary plus]") {
  Int i{1};
  Int j{2};

  REQUIRE(i.x == 1);
  REQUIRE(j.x == 2);

  REQUIRE((i + j).x == 3);
}
