#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<char> v;

set<set<char> > create_sets() {
  set<char> emp; emp.insert(' ');
  set<set<char> > s;
  s.insert(emp);

  for (vector<char>::iterator i = v.begin(); i != v.end(); i++) {
    set<set<char> > ss = s;

    for (set<set<char> >::iterator ii = ss.begin(); ii != ss.end(); ii++) {
      set<char> t = *ii;
      t.insert(*i);
      ss.insert(t);
    }
    s.insert(ss.begin(), ss.end());
  }
  return s;
}

int main() {
  int n; cin >> n;
  while (n--) {
    char c; cin >> c;
    v.push_back(c);
  }
  set<set<char> > s = create_sets();
  for (set<set<char> >::iterator i = s.begin(); i != s.end(); i++) {
    set<char> ss = *i;
    ss.erase(' ');
    if (ss.empty()) continue;
    for (set<char>::iterator ii = ss.begin(); ii != ss.end(); ii++) {
      if (distance(ss.begin(), ii)) cout << ", ";
      cout << (*ii);
    }
    cout << endl;
  }
}
