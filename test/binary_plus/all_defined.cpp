#include "../all_defined.hpp"
#include "../catch.hpp"
#include <kettle++/ops/minus_assign.hpp>
#include <kettle++/traits/trait_maker.hpp>

TEST_CASE("from binary plus", "[binary_plus]") {
  Int i{1};
  Int j{2};

  REQUIRE(i.x == 1);
  REQUIRE(j.x == 2);

  REQUIRE((i + j).x == 3);
}
