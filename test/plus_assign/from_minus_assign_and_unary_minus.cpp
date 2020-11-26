#include "../catch.hpp"
#include <kettle++/ops/plus_assign.hpp>
#include <kettle++/traits/trait_maker.hpp>

using ktl::operator+=;

struct Int {
  int x;
  explicit Int(int a) : x{a} {}

  friend Int &operator-=(Int &lhs, Int const &rhs) {
    lhs.x -= rhs.x;
    return lhs;
  }

  friend Int operator-(Int const &rhs) { return Int{-rhs.x}; }
};

TEST_CASE("from minus assign and unary plus", "[plus_assign]") {
  Int i{1};
  Int j{2};

  REQUIRE(i.x == 1);
  REQUIRE(j.x == 2);

  i += j;

  REQUIRE(i.x == 3);
}
