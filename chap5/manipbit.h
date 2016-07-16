#include <sstream>

uint32_t getBits(uint32_t x, int p, int n) {
  return ((x >> p) & ~(~0x0000 << n));
}

std::string bits(uint32_t x) {
  std::string str;
  std::stringstream ss;
  int bytes = sizeof(x);

  for (int i = 1; i <= 8 * bytes; i++) {
    ss.str("");
    ss << getBits(x, 8 * bytes - i, 1);
    if (i % 4 == 0) ss << ' ';
    str.append(ss.str());
  }

  return str;
}
