#include "../catch.hpp"
#include <kettle++/ops/minus_assign.hpp>
#include <kettle++/traits/trait_maker.hpp>

struct IntImpl {
  int x;
  explicit IntImpl(int a) : x{a} {}

  friend IntImpl operator-(IntImpl const &lhs, IntImpl const &rhs) {
    return IntImpl{lhs.x - rhs.x};
  }
};

struct Int : IntImpl, protected ktl::minus_assign<IntImpl> {
  using IntImpl::IntImpl;
};

TEST_CASE("binary binary minus", "[minus_assign]") {
  Int i{1};
  Int j{2};

  REQUIRE(i.x == 1);
  REQUIRE(j.x == 2);

  i -= j;

  REQUIRE(i.x == -1);
}
