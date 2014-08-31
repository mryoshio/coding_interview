#include <iostream>
#include <string>
using namespace std;

string replace_empty(string s, int n) {
  reverse_iterator<string::iterator> r = s.rbegin();
  int idx = n;

  for (int idx = n-1; idx >= 0; idx--) {
    if (s[idx] == ' ') {
      *r++ = '0';
      *r++ = '2';
      *r++ = '%';
    } else {
      *r++ = s[idx];
    }
  }
  return s;
}

int main() {
  string s;
  s = "Mr. John Smith    "; // really 14 chars 
  // cin >> s;
  cout << replace_empty(s, 14) << endl;
  return 0;
}
