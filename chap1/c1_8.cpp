#include <iostream>
#include <string>
using namespace std;

bool isSubstring(string s1, string s2) {
  int i = s1.find(s2);
  if (i == string::npos)
    return false;
  return true;
}

void solve(string s1, string s2) {
  if (isSubstring(s1 + s1, s2)) {
    cout << true << endl;
    return;
  }
  cout << false << endl;
}

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  solve(s1, s2);
  return 0;
}
