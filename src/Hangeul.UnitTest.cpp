#include "HangeulId.h"
#include "catch.hpp"
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

TEST_CASE("Hangeul id") {
  SECTION("Default") {
    HangeulId id;
    REQUIRE(id.integer_to_hangel_id(5529549) == "각간힝");
  }

  SECTION("KSX 1001") {
    HangeulId id(HangeulCharGroup::KSX1001);
    REQUIRE(id.integer_to_hangel_id(5529549) == "각간힝");
  }

  SECTION("ALL Hangeul") {
    HangeulId id(HangeulCharGroup::ALL_HANGEUL);
    REQUIRE(id.integer_to_hangel_id(11172) == "각가");
  }

  SECTION("UUID") {
    boost::uuids::random_generator gen;
    for (int i = 0; i < 10; i++) {
      boost::uuids::uuid id = gen();
      REQUIRE(to_string(id).length() == 36);
    }
  }

  SECTION("Big Integer Equal") {
    namespace mp = boost::multiprecision;
    mp::uint1024_t a("90299239848924893293923729832973137293");
    mp::uint1024_t b("12310423502492039420349203490213840139");
    REQUIRE(a >= b);
  }

  SECTION("KSX 1001 gen UUID") {
    HangeulId id(HangeulCharGroup::KSX1001);
    std::string res = id.generate_hangeul_id_with_uuidv4();
    REQUIRE(!res.empty());
  }

  SECTION("ALL Hangeul gen UUID") {
    HangeulId id(HangeulCharGroup::ALL_HANGEUL);
    std::string res = id.generate_hangeul_id_with_uuidv4();
    REQUIRE(!res.empty());
  }
}