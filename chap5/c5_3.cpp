#include <iostream>
#include "manipbit.h"
using namespace std;

int count_one(uint32_t n) {
  int c = 0;
  for (int i = 0; i < 31; i++) {
    if (n & 1) c++;
    n >>= 1;
  }
  return c;
}

void solve(uint32_t n) {
  int cnt_n = count_one(n);
  int cnt_tmp;
  uint32_t before_n, after_n;

  for (before_n = n - 1; before_n > 0; before_n--)
    if (cnt_n == count_one(before_n)) break;

  for (after_n = n + 1; after_n < ~0; after_n++)
    if (cnt_n == count_one(after_n)) break;

  cout << "--- before: ";
  if (before_n == 0) cout << "None";
  else cout << before_n;
  cout << endl;

  cout << "--- after: ";
  if (after_n == ~0) cout << "None";
  else cout << after_n;
  cout << endl;
}

int main() {
  uint32_t n; cin >> n;
  solve(n);
}
