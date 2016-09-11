#include <iostream>
#include <set>
#include <string>
using namespace std;

set<string> pers;

set<string> permutate(string s) {
  set<string> ps;

  if (s.size() == 1) {
    ps.insert(s);
    return ps;
  }

  char l = s[0];
  string ns = s.substr(1, string::npos);
  set<string> ws = permutate(ns);

  for (set<string>::iterator it = ws.begin(); it != ws.end(); it++) {
    string obj = *it;
    for (int i = 0; i <= obj.size(); i++) {
      string ss = obj;
      ss.insert(i, &l);
      ps.insert(ss);
    }
  }
  return ps;
}

int main() {
  string s; cin >> s;
  set<string> ps = permutate(s);
  
  for (set<string>::iterator it = ps.begin(); it != ps.end(); it++) {
    if (it != ps.begin()) cout << ", ";
    cout << (*it);
  }
  cout << endl;
}
