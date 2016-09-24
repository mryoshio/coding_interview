#include <iostream>
using namespace std;

int count(int n, int d) {
  int next_d = 0;

  switch (d) {
  case 25:
    next_d = 10;
    break;
  case 10:
    next_d = 5;
    break;
  case 5:
    next_d = 1;
    break;
  case 1:
    return 1;  // always ok
  }

  int s = 0;
  for (int i = 0; i * d <= n; i++) {
    s += count(n - i * d, next_d);
  }
  return s;
}

int main() {
  int n; cin >> n;
  cout << count(n, 25) << endl;
}
