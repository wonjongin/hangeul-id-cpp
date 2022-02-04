#include "convert_base.h"
#include "catch.hpp"
#include <boost/multiprecision/cpp_int.hpp>
#include <vector>

TEST_CASE("Convert Base", "[convert_base]") {

  SECTION("from decimal") {
    REQUIRE(convert_base::convert_from_10(2350, 2350) ==
            std::vector<int>{1, 0});
    REQUIRE(convert_base::convert_from_10(5529549, 2350) ==
            std::vector<int>{1, 2, 2349});
    REQUIRE(convert_base::convert_from_10(427567648, 61) ==
            std::vector<int>{30, 53, 43, 39, 43});
    REQUIRE(convert_base::convert_from_10(413561140, 78) ==
            std::vector<int>{11, 13, 37, 15, 70});
    REQUIRE(convert_base::convert_from_10(549974852, 27) ==
            std::vector<int>{1, 11, 8, 23, 16, 17, 26});
  }

  SECTION("to decimal") {
    REQUIRE(convert_base::convert_to_10(std::vector<int>{2, 5}, 8) == 21);
    REQUIRE(convert_base::convert_to_10(std::vector<int>{1, 0}, 2350) == 2350);
    REQUIRE(convert_base::convert_to_10(std::vector<int>{1, 2, 2349}, 2350) ==
            5529549);
    REQUIRE(convert_base::convert_to_10(
                    std::vector<int>{30, 53, 43, 39, 43}, 61) == 427567648);
    REQUIRE(convert_base::convert_to_10(
                    std::vector<int>{11, 13, 37, 15, 70}, 78) == 413561140);
  }

  SECTION("from any to any") {
    REQUIRE(convert_base::convert(std::vector<int>{2, 5}, 8, 2) ==
            std::vector<int>{1, 0, 1, 0, 1});
    REQUIRE(convert_base::convert(std::vector<int>{1, 5}, 16, 2) ==
            std::vector<int>{1, 0, 1, 0, 1});
    REQUIRE(convert_base::convert(std::vector<int>{1, 0}, 2350, 2) ==
            std::vector<int>{1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0});
    REQUIRE(convert_base::convert(std::vector<int>{1, 2, 2349}, 2350, 16) ==
            std::vector<int>{5, 4, 5, 15, 12, 13});
  }

  SECTION("powu") {
    REQUIRE(convert_base::powu(10000, 3) == 1000000000000);
    REQUIRE(convert_base::powu(2350, 4) == 30498006250000);
    REQUIRE(convert_base::powu(45, 12) ==
            boost::multiprecision::uint1024_t("68952523554931640625"));
    REQUIRE(convert_base::powu(2, 192) ==
            boost::multiprecision::uint1024_t("62771017353866807638357894232076"
                                              "66416102355444464034512896"));
    REQUIRE(convert_base::powu(2, 512) ==
            boost::multiprecision::uint1024_t(
                    "1340780792994259709957402499820584612747936582059239337772"
                    "3561443721764030073546976801874298166903427690031858186486"
                    "050853753882811946569946433649006084096"));
  }
}