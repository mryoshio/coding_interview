#include <iostream>
#include <vector>
#include "node.h"

using namespace std;

vector<int> v;

Node* createBinarySearchTree(Node* n, int left, int right) {
  if (left >= right) return nullptr;

  int mid = (left + right) / 2;

  n = new Node(v[mid]);
  n->leftChild = createBinarySearchTree(n, left, mid);
  n->rightChild = createBinarySearchTree(n, mid + 1, right);

  return n;
}

void solve() {
  Node* n = createBinarySearchTree(nullptr, 0, v.size());
  cout << "# dump binary search tree" << endl;
  dumpTree(n, 0);
}

int main() {
  srand((unsigned int)time(NULL));

  int size = rand() % 10;
  for (int i = 0; i < size; i++) v.push_back(rand() % 50);
  sort(v.begin(), v.end());

  cout << "# array" << endl;
  for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
  cout << endl;

  solve();
}
