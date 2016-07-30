#include <iostream>
using namespace std;

int my_negate(int a) {
  if (a == 0) return a;
  int aa = a, op = (a > 0 ? -1 : 1);
  while (a + aa != 0) aa += op;
  return aa;
}

int my_sub(int a, int b) {
  return a + my_negate(b);
}

int my_multi(int a, int b) {
  if (a == 0 || b == 0) return 0;
  int aa = 0, op = (b > 0 ? -1 : 1);
  for (int bb = b; bb != 0; bb += op) aa += a;
  return b >= 0 ? aa : my_negate(aa);
}

int my_div(int a, int b) {
  if (a == 0) return 0;
  if (b == 0) throw range_error("Divided by zero.");
  int aa = a > 0 ? a : my_negate(a);
  int bb = b > 0 ? b : my_negate(b);
  int x;
  for (x = 0; my_multi(bb, x + 1) <= aa; x++);
  return b > 0 ? x : my_negate(x);
}

int main() {
  int a, b; cin >> a >> b;
  cout << "*: " << my_multi(a, b) << endl;
  cout << "-: " << my_sub(a, b) << endl;
  cout << "/: " << my_div(a, b) << endl;
}
