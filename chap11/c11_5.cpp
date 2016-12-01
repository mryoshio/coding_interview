#include <iostream>
#include <vector>
using namespace std;

vector<string> v;
string t;

int solve(int l, int r) {
  if (r < l) return -1;
  int m = (l+r)/2;
  if (v[m].empty()) {
    int backward = m-1;
    int forward = m+1;
    while (true) {
      if (backward < l && r < forward) return -1;
      else if (l <= backward && v[backward] != "") {
        m = backward;
        break;
      } else if (forward <= r && v[forward] != "") {
        m = forward;
        break;
      }
      backward--;
      forward++;
    }
  }
  cout << l << ", " << r << ", " << m << endl;
  int cmp = t.compare(v[m]);
  if (cmp == 0) return m;
  else if (cmp < 0) return solve(l, m-1);
  else return solve(m+1, r);
}

int main() {
  int n; cin >> n;
  v.resize(n, "");
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if (v[i] == "x") v[i] = "";
  }
  cin >> t;
  int a = solve(0, n-1);
  cout << t << " is at " << a << endl;
}
