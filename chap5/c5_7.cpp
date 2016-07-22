#include <iostream>
#include <vector>
#include "manipbit.h"
using namespace std;

void dump(vector<int> v) {
  for (int i = 0; i < v.size(); i++) {
    if (i) cout << ' ';
    cout << v[i];
  }
  cout << endl;
}

int fetch(int v, int column) {
  return ((v >> column) & 1);
}

int findMissing(vector<int> v, int column) {
  if (column > 32) return 0;

  vector<int> zeros;
  vector<int> ones;

  for (int i = 0; i < v.size(); i++) {
    if (fetch(v[i], column) == 0) zeros.push_back(v[i]);
    else ones.push_back(v[i]);
  }

  if (zeros.size() <= ones.size()) {
    int x = findMissing(zeros, column + 1);
    //    cout << "c: " << column << ", " << bits((x << 1) | 0) << endl;
    return (x << 1) | 0;
  } else {
    int x = findMissing(ones, column + 1);
    //    cout << "c: " << column << ", " << bits((x << 1) | 1) << endl;
    return (x << 1) | 1;
  }
}

int main() {
  srand((unsigned int)time(NULL));
  int n; cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) v.push_back(i);
  v.erase(v.begin() + rand() % n);
  dump(v);
  cout << findMissing(v, 0) << endl;
}
