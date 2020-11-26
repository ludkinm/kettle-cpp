#include "../all_defined.hpp"
#include "../catch.hpp"
#include <kettle++/ops/plus_assign.hpp>
#include <kettle++/traits/trait_maker.hpp>

TEST_CASE("all defined", "[plus_assign]") {
  Int i{1};
  Int j{2};

  REQUIRE(i.x == 1);
  REQUIRE(j.x == 2);

  i += j;

  REQUIRE(i.x == 3);
}
