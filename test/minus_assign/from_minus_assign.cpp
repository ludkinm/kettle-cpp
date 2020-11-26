#include "../catch.hpp"
#include <kettle++/ops/minus_assign.hpp>
#include <kettle++/traits/trait_maker.hpp>

using ktl::operator-=;

struct Int {
  int x;
  explicit Int(int a) : x{a} {}

  friend Int &operator-=(Int &lhs, Int const &rhs) {
    lhs.x -= rhs.x;
    return lhs;
  }
};

TEST_CASE("from minus_assign", "[minus_assign]") {
  Int i{1};
  Int j{2};

  REQUIRE(i.x == 1);
  REQUIRE(j.x == 2);

  i -= j;

  REQUIRE(i.x == -1);
}
