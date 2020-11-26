#include "../catch.hpp"
#include <kettle++/ops/binary_plus.hpp>
#include <kettle++/traits/trait_maker.hpp>

using ktl::operator+;

struct Int {
  int x;
  explicit Int(int a) : x{a} {}

  friend Int operator+(Int const &lhs, Int const &rhs) {
    return Int{lhs.x + rhs.x};
  }
};

TEST_CASE("from binary plus", "[binary_plus]") {
  Int i{1};
  Int j{2};

  REQUIRE(i.x == 1);
  REQUIRE(j.x == 2);

  REQUIRE((i + j).x == 3);
}
