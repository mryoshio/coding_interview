#include <iostream>

using namespace std;

int a[100], b[100];

void solve(int idx, int idx_a, int idx_b) {
  while (idx_a >= 0 && idx_b >= 0) {
    if (a[idx_a] > b[idx_b]) a[idx--] = a[idx_a--];
    else a[idx--] = b[idx_b--];
  }
  while (idx_b >= 0) a[idx--] = b[idx_b--];
}

int main() {
  int size_a, size_b;
  cin >> size_a >> size_b;
  for (int i = 0; i < size_a; i++) cin >> a[i];
  for (int i = 0; i < size_b; i++) cin >> b[i];
  solve(size_a+size_b-1, size_a-1, size_b-1);
  for (int i = 0; i < size_a+size_b; i++) {
    if (i) cout << ' ';
    cout << a[i];
  }
  cout << endl;
}
