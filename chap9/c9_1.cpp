#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int steps(int n) {
  if (n < 0) return 0;
  if (n == 0) return 1;
  if (v[n] > -1) return v[n];
  return v[n] = steps(n - 1) + steps(n - 2) + steps(n - 3);
}

int main() {
  int n; cin >> n;
  v.resize(n + 1, -1);
  steps(n);
  cout << "ans: " << v[n] << endl;
}
