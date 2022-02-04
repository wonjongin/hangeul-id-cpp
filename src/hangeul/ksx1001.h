#ifndef HANGEUL_ID_KSX1001_H
#define HANGEUL_ID_KSX1001_H
#include <boost/multiprecision/cpp_int.hpp>
#include <string>

using namespace boost::multiprecision;
namespace ksx1001 {
  std::string ksx1001_one_letter(int i);
  std::string ksx1001_letters(const uint1024_t &i);
};// namespace ksx1001


#endif//HANGEUL_ID_KSX1001_H
