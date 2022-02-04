#include "ksx1001.h"
#include "catch.hpp"
#include <vector>

TEST_CASE("KSX 1001") {
  SECTION("One Letter") { REQUIRE(ksx1001::ksx1001_one_letter(2349) == "힝"); }

  SECTION("Letters") { REQUIRE(ksx1001::ksx1001_letters(2350) == "각가"); }
}