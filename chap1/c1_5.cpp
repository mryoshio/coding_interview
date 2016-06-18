#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string compress(string str) {
  int cnt = 0;
  string compressed;
  stringstream ss;
  char c = *str.begin();

  for (string::iterator s = str.begin();; s++) {
    if (s == str.end()) {
      compressed.append(1, c);
      ss << cnt; compressed.append(ss.str());
      if (str.size() > compressed.size()) return compressed;
      else return str;
    }

    if (*s == c) {
      cnt++;
      continue;
    }

    compressed.append(1, c);
    ss << cnt; compressed.append(ss.str());
    ss.str(""); ss.clear();
    cnt = 1;
    c = *s;
  }
}

int main() {
  string strings[] = {
    "aabbbbbbbccccdddddddcaa",
    "aabbcccccaa",
    "abcccca",
    "abcde"
  };

  for (int i = 0; i < 4; i++)
    cout << strings[i] << " -> " << compress(strings[i]) << endl;
  return 0;
}
