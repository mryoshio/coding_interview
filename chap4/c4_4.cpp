#include <algorithm>
#include <iostream>
#include <vector>
#include "node.h"

using namespace std;

vector<vector<int> > L;

void traceTree(Node* n, int d) {
  if (n == nullptr) return;
  L[d].push_back(n->data);
  d++;
  traceTree(n->leftChild, d);
  traceTree(n->rightChild, d);
}

void solve() {
  int d = 2;

  cout << "----------- Tree" << endl;
  Node* n = makeBalancedBT(new Node(13), 50, d);
  dumpTree(n, 0);

  L.resize(d + 1, vector<int>(0));
  traceTree(n, 0);

  cout << "----------- List" << endl;
  for (int i = 0; i < L.size(); i++) {
    cout << "level[" << i << ']';
    for (int j = 0; j < L[i].size(); j++) {
      cout << ' ' << L[i][j];
    }
    cout << endl;
  }
}

int main() {
  solve();
}
