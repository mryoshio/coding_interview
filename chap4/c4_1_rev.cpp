#include <algorithm>
#include <cstdlib>
#include <iostream>
#include "node.h"
using namespace std;

int getHeight(Node* n) {
  if (n == nullptr) return 0;

  int h1 = getHeight(n->leftChild);
  if (h1 == -1) return -1;

  int h2 = getHeight(n->rightChild);
  if (h2 == -1) return -1;

  if (abs(h1 - h2) > 1) return -1;

  return max(h1, h2) + 1;
}

bool is_balanced(Node* n) {
  if (getHeight(n) == -1) return false;
  return true;
}

int main() {
  srand((unsigned int)time(NULL));
  Node* tree = makeBalancedBT(new Node(11), 50, 2);
  cout << "------- dump tree" << endl;
  dumpTree(tree, 0);
  cout << "ans: " << is_balanced(tree) << endl;

  tree = makeUnbalancedBT(new Node(11), 50, 2);
  cout << "------- dump tree" << endl;
  dumpTree(tree, 0);
  cout << "ans: " << is_balanced(tree) << endl;
}
