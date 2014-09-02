#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string compress(string str) {
  int cnt = 0;
  string compressed;
  stringstream ss;
  string::iterator s = str.begin();;
  char c = *s;
  for (; s != str.end(); s++) {
    if (*s == c) {
      cnt++;
    } else {
      compressed.append(1, c);
      ss << cnt;
      compressed.append(ss.str());
      ss.str("");
      ss.clear();
      cnt = 1;
      c = *s;
    }
  }
  compressed.append(1, c);
  ss << cnt;
  compressed.append(ss.str());

  if (str.size() > compressed.size())
    return compressed;
  return str;
}

int main() {
  string s;
  s = "aabbcccccaa";
  cout << compress(s) << endl;
  s = "abcccca";
  cout << compress(s) << endl;
  return 0;
}
