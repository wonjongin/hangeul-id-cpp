#ifndef HANGEUL_ID_HANGEULID_H
#define HANGEUL_ID_HANGEULID_H

#include <boost/multiprecision/cpp_int.hpp>
#include <string>

using namespace boost::multiprecision;
enum HangeulCharGroup { KSX1001, ALL_HANGEUL };

class HangeulId {
  private:
  HangeulCharGroup char_group;

  public:
  HangeulId();
  explicit HangeulId(HangeulCharGroup char_group);
  std::string integer_to_hangel_id(const uint1024_t &integer);
  std::string generate_hangeul_id_with_uuidv4();
};


#endif//HANGEUL_ID_HANGEULID_H
