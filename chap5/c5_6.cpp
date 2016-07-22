#include <iomanip>
#include <iostream>
#include "manipbit.h"
using namespace std;

uint32_t swapEvenOdd(uint32_t n) {
  return ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1);
}

void solve(uint32_t n) {
  cout << setw(10) << "before: " << bits(n) << endl;
  cout << setw(10) << "after: " << bits(swapEvenOdd(n)) << endl;
}

int main() {
  uint32_t n = 2682757190; // cin >> n;
  solve(n);
}
