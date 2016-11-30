#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

const int N = 8;
vector<vector<int> > v;

bool is_valid(int r, int c, vector<int> a) {
  for (int i = 0; i < r; i++) {
    if (a[i] == c) return false;
    if (r - i == abs(a[i] - c)) return false;
  }
  return true;
}

void solve(int r, vector<int> a) {
  if (r == N) {
    v.push_back(a);
    return;
  }
  for (int c = 0; c < N; c++) {
    if (is_valid(r, c, a)) {
      a[r] = c;
      solve(r + 1, a);
    }
  }
}

int main() {
  solve(0, vector<int>(N, 0));
  for (int i = 0; i < v.size(); i++) {
    cout << "[pattern " << i << "] ";
    for (int j = 0; j < v[i].size(); j++) {
      if (j) cout << ", ";
      cout << v[i][j];
    }
    cout << endl;
  }
}
