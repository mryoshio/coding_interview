#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int t;

int solve(int l, int r) {
  int m = (l+r)/2;
  if (v[m] == t) return m;
  if (r < l) return -1;

  if (v[l] < v[m]) {
    if (v[l] <= t && t <= v[m]) return solve(l, m-1);
    else return solve(m+1, r);
  } else if (v[m] < v[l]) {
    if (v[m] <= t && t <= v[r]) return solve(m+1, r);
    else return solve(l, m-1);
  } else if (v[l] == v[m]) {
    if (v[m] != v[r]) return solve(m+1, r);
    else {
      int ret = solve(l, m-1);
      if (ret == -1) return solve(m+1, r);
      else return ret;
    }
  }
  return -1;
}

int main() {
  int n; cin >> n;
  v.resize(n, 0);
  for (int i = 0; i < n; i++) cin >> v[i];
  cin >> t;
  int a = solve(0, n-1);
  cout << t << " is at " << a << endl;
}
