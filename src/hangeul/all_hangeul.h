#ifndef HANGEUL_ID_ALL_HANGEUL_H
#define HANGEUL_ID_ALL_HANGEUL_H
#include <boost/multiprecision/cpp_int.hpp>
#include <string>

using namespace boost::multiprecision;
namespace all_hangeul {
  std::string all_hangeul_one_letter(int i);
  std::string all_hangeul_letters(const uint1024_t &i);
};// namespace all_hangeul


#endif//HANGEUL_ID_ALL_HANGEUL_H
