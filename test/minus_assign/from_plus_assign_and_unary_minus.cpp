#include "../catch.hpp"
#include <kettle++/ops/minus_assign.hpp>
#include <kettle++/traits/trait_maker.hpp>

struct IntImpl {
  int x;
  explicit IntImpl(int a) : x{a} {}

  friend IntImpl &operator+=(IntImpl &lhs, IntImpl const &rhs) {
    lhs.x += rhs.x;
    return lhs;
  }
  friend IntImpl operator-(IntImpl const &rhs) { return IntImpl{-rhs.x}; }
};

struct Int : IntImpl, protected ktl::minus_assign<IntImpl> {
  using IntImpl::IntImpl;
};

TEST_CASE("from plus assign and unary minus", "[minus_assign]") {
  Int i{1};
  Int j{2};

  REQUIRE(i.x == 1);
  REQUIRE(j.x == 2);

  i -= j;

  REQUIRE(i.x == -1);
}
