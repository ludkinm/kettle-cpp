#include "../all_defined.hpp"
#include "../catch.hpp"
#include <kettle++/ops/minus_assign.hpp>
#include <kettle++/traits/trait_maker.hpp>

struct Int : IntImpl, protected ktl::minus_assign<IntImpl> {
  using IntImpl::IntImpl;
};

TEST_CASE("all defined", "[minus_assign]") {
  Int i{1};
  Int j{2};

  REQUIRE(i.x == 1);
  REQUIRE(j.x == 2);

  i -= j;

  REQUIRE(i.x == -1);
}
