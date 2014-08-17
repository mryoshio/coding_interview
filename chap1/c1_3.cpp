#include <iostream>
using namespace std;

bool is_anagram(string s1, string s2) {
  int sum = 0;
  for (int i = 0; i < s1.size(); i++) {
    sum += s1[i];
    sum -= s2[i];
  }
  if (sum == 0) return true;
  return false;
}

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  cout << is_anagram(s1, s2) << endl;
}
