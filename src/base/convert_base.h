#ifndef HANGEUL_ID_CONVERT_BASE_H
#define HANGEUL_ID_CONVERT_BASE_H

#include <boost/multiprecision/cpp_int.hpp>
#include <vector>

using namespace boost::multiprecision;
namespace convert_base {
  std::vector<int> convert_from_10(const uint1024_t &value, int to);
  uint1024_t convert_to_10(std::vector<int> value, int from);
  std::vector<int> convert(std::vector<int> value, int from, int to);
  uint1024_t powu(const uint1024_t &base, const uint1024_t &exp);
}// namespace convert_base

#endif//HANGEUL_ID_CONVERT_BASE_H
