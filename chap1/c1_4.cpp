#include <iostream>
#include <string>
using namespace std;

string replace_empty(string s, int n) {
  int space = 0;
  for (int i = 0; i < n; i++)
    if (s[i] == ' ') space++;

  int new_len = n + space * 2;

  for (int i = n-1; i >= 0; i--) {
    if (s[i] == ' ') {
      s[new_len--] = '0';
      s[new_len--] = '2';
      s[new_len--] = '%';
    } else {
      s[new_len--] = s[i];
    }
  }
  return s;
}

int main() {
  string s;
  s = "Mr. John Smith              "; // 14 chars actually
  cout << replace_empty(s, 14) << endl;
  return 0;
}
