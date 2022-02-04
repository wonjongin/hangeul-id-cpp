#include "all_hangeul.h"
#include "../base/convert_base.h"

std::string UnicodeToUTF8(unsigned int codepoint) {
  std::string out;

  if (codepoint <= 0x7f) out.append(1, static_cast<char>(codepoint));
  else if (codepoint <= 0x7ff) {
    out.append(1, static_cast<char>(0xc0 | ((codepoint >> 6) & 0x1f)));
    out.append(1, static_cast<char>(0x80 | (codepoint & 0x3f)));
  } else if (codepoint <= 0xffff) {
    out.append(1, static_cast<char>(0xe0 | ((codepoint >> 12) & 0x0f)));
    out.append(1, static_cast<char>(0x80 | ((codepoint >> 6) & 0x3f)));
    out.append(1, static_cast<char>(0x80 | (codepoint & 0x3f)));
  } else {
    out.append(1, static_cast<char>(0xf0 | ((codepoint >> 18) & 0x07)));
    out.append(1, static_cast<char>(0x80 | ((codepoint >> 12) & 0x3f)));
    out.append(1, static_cast<char>(0x80 | ((codepoint >> 6) & 0x3f)));
    out.append(1, static_cast<char>(0x80 | (codepoint & 0x3f)));
  }
  return out;
}

std::string all_hangeul::all_hangeul_one_letter(int i) {
  int code_dec = i + 44032;
  return UnicodeToUTF8(code_dec);
}

std::string all_hangeul::all_hangeul_letters(const uint1024_t &i) {
  std::vector<int> i11172 = convert_base::convert_from_10(i, 11172);
  std::string res;
  for (const auto &item: i11172) { res += all_hangeul_one_letter(item); }
  return res;
}
