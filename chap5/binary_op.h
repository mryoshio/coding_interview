#ifndef BINARY_OP_H

#define BINARY_OP_H

#include <vector>
#include <sstream>

using namespace std;

// see http://d.hatena.ne.jp/kobapan/20090208/1281901941
int strbin2i (const string &s) {
  int out = 0;
  for (int i = 0, size = s.size() ; i < size ; ++i ) {
    out *= 2;
    out += ((int)s[i] == 49) ? 1 : 0;
  }
  return out;
}

string i2strbin(int n) {
  vector<int> v;
  stringstream ss;

  while (true) {
    v.push_back(n % 2);
    n = n / 2;
    if (n == 0) break;
  }
  for (int i = v.size() - 1; i > -1; i--)
    ss << v[i];

  return ss.str();
}

#endif
