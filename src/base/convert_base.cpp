#include "convert_base.h"
#include <cmath>

uint1024_t convert_base::powu(const uint1024_t &base, const uint1024_t &exp) {
  uint1024_t res = base;
  for (int i = 1; i < exp; ++i) { res *= base; }
  return res;
}

std::vector<int>
convert_base::convert_from_10(const uint1024_t &value, int to) {
  uint1024_t mid_int = value;
  int i = 1;
  while (true) {
    uint1024_t d = powu(to, i);
    if (value / d < 1) {
      break;
    } else {
      i += 1;
    }
  }
  int max_digit = i;
  std::vector<int> res;
  for (int j = max_digit - 1; j > 0; j--) {
    uint1024_t p = powu(to, j);
    int a = (int) (mid_int / p);
    mid_int -= a * p;
    res.push_back(a);
  }
  res.push_back((int) mid_int);
  return res;
}

uint1024_t convert_base::convert_to_10(std::vector<int> value, int from) {
  uint1024_t res = 0;
  for (int i = 0; i < value.size(); i++) {
    res += value[i] * (int) std::pow(from, value.size() - 1 - i);
  }
  return res;
}

uint1024_t convert_base::convert_from_16_to_10(const std::string &value) {
  return uint1024_t("0x" + value);
}

std::string convert_base::convert_from_10_to_16(const uint1024_t &value) {
  std::vector<std::string> hex{
          "0", "1", "2", "3", "4", "5", "6", "7",
          "8", "9", "A", "B", "C", "D", "E", "F",
  };
  std::string res;
  std::vector<int> i16 = convert_from_10(value, 16);
  for (const auto &item: i16) { res += hex[item]; }
  return res;
}

std::vector<int>
convert_base::convert(std::vector<int> value, int from, int to) {
  return convert_from_10(convert_to_10(std::move(value), from), to);
}