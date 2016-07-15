#include <iostream>
#include <sstream>
using namespace std;

uint32_t getBits(uint32_t x, int p, int n) {
  return ((x >> p) & ~(~0x0000 << n));
}

string bits(uint32_t x) {
  string str;
  stringstream ss;
  int bytes = sizeof(x);

  for (int i = 1; i <= 8 * bytes; i++) {
    ss.str("");
    ss << getBits(x, 8 * bytes - i, 1);
    if (i % 4 == 0) ss << ' ';
    str.append(ss.str());
  }

  return str;
}

string insertBits(uint32_t n, uint32_t m, int i, int j) {
  uint32_t left  =  ~0b0 << (j + 1);
  uint32_t right =  (1 << i) - 1;

  return bits((n & (left | right)) | (m << i));
}

int main() {
  uint32_t i, j, N, M;
  cin >> i >> j;

  N = 0b10000000000;
  M = 0b10011;

  cout << "N: " << bits(N) << endl;
  cout << "M: " << bits(M) << endl;
  cout << "i: " << i << ", j: " << j << endl;

  cout << insertBits(N, M, i, j) << endl;
}
