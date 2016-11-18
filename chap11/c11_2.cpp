#include <iostream>
#include <map>
#include <vector>
using namespace std;

void solve(vector<string> v) {
  // main logic
  map<string, vector<string> >m;
  vector<string>::iterator v_it;
  for (v_it = v.begin(); v_it != v.end(); v_it++) {
    string k = *v_it;
    sort(k.begin(), k.end());
    if (m.count(k) == 0) m[k] = vector<string>();
    m[k].push_back(*v_it);
  }

  // build answer vector
  map<string, vector<string> >::iterator m_it;
  vector<string> ans;
  for (m_it = m.begin(); m_it != m.end(); m_it++) {
    vector<string> vv = m_it->second;
    for (v_it = vv.begin(); v_it != vv.end(); v_it++) ans.push_back(*v_it);
  }

  for (v_it = ans.begin(); v_it != ans.end(); v_it++) {
    if (distance(ans.begin(), v_it)) cout << ' ';
    cout << *v_it;
  }
  cout << endl;
}

int main() {
  int n; cin >> n;
  vector<string> v(n);
  while (n--) cin >> v[n]; // not care order
  solve(v);
}
