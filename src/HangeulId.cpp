#include "HangeulId.h"
#include "hangeul/ksx1001.h"
#include <boost/algorithm/string/replace.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <iostream>

HangeulId::HangeulId() { this->char_group = HangeulCharGroup::KSX1001; }

HangeulId::HangeulId(HangeulCharGroup char_group) : char_group(char_group) {}

std::string HangeulId::integer_to_hangel_id(const uint1024_t &integer) {
  if (this->char_group == HangeulCharGroup::KSX1001) {
    return ksx1001::ksx1001_letters(integer);
  } else {
    return "ERROR";
  }
}

std::string HangeulId::generate_hangeul_id_with_uuidv4() {
  boost::uuids::random_generator gen;
  boost::uuids::uuid id = gen();
  std::string id_str = boost::uuids::to_string(id);
  boost::replace_all(id_str, "-", "");
  uint1024_t id_int("0x" + id_str);
  std::string res = this->integer_to_hangel_id(id_int);
  return res;
}