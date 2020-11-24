#include "../catch.hpp"
#include <kettle++/ops/binary_plus.hpp>
#include <kettle++/traits/trait_maker.hpp>

struct IntImpl {
  int x;
  explicit IntImpl(int a) : x{a} {}

  friend IntImpl operator+(IntImpl const &lhs, IntImpl const &rhs) {
    return IntImpl{lhs.x + rhs.x};
  }
};

struct Int : IntImpl, protected ktl::binary_plus<IntImpl> {
  using IntImpl::IntImpl;
};

TEST_CASE("from binary plus", "[binary_plus]") {
  Int i{1};
  Int j{2};

  REQUIRE(i.x == 1);
  REQUIRE(j.x == 2);

  REQUIRE((i + j).x == 3);
}
