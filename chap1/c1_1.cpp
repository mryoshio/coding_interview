#include <iostream>

using namespace std;

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

/*
  precondition: charcters are any of 'a-z'
*/
int main() {
  string s;
  cin >> s;
  cout << isUniqueChars(s) << endl;
  return 0;
}
