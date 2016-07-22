#include <iostream>
using namespace std;

int countBitsToChange(int a, int b) {
  int c = 0;
  int x = a ^ b;

  for (int i = 0; i < 32; i++) {
    if (x & 1) c++;
    x >>= 1;
  }

  return c;
}

int main() {
  int a, b; cin >> a >> b;
  cout << countBitsToChange(a, b) << endl;
}
