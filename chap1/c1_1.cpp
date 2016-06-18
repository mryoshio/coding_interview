#include <iostream>
#include <map>

using namespace std;

/*
  precondition: charcters are any of 'a-z'
*/
bool isUniqueChars(string s) {
  int vs = 0, a = static_cast<int>('a');
  for (int i = 0; i < s.size(); i++) {
    int v = static_cast<int>(s[i]) - a;
    if ((vs & (1 << v)) > 0)
      return false;
    vs |= (1 << v);
  }
  return true;
}

bool isUniqueChars2(string s) {
  map<char, bool> m;
  for (int i = 0; i < s.size(); i++) {
    if (m[s[i]]) return false;
    m[s[i]] = true;
  }
  return true;
}


int main() {
  string s;
  cin >> s;
  cout << isUniqueChars(s) << endl;
  cout << isUniqueChars2(s) << endl;
  return 0;
}
