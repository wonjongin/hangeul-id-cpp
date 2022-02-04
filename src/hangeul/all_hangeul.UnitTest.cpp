#include "all_hangeul.h"
#include "catch.hpp"

TEST_CASE("ALL Hangeul") {
  SECTION("One Letter") {
    REQUIRE(all_hangeul::all_hangeul_one_letter(0) == "가");
    REQUIRE(all_hangeul::all_hangeul_one_letter(10584) == "하");
    REQUIRE(all_hangeul::all_hangeul_one_letter(4680) == "빈");
    REQUIRE(all_hangeul::all_hangeul_one_letter(11171) == "힣");
  }

  SECTION("Letters") {
    REQUIRE(all_hangeul::all_hangeul_letters(11172) == "각가");
  }
}