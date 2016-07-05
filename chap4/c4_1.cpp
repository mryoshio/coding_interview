#include <algorithm>
#include <cstdlib>
#include <iostream>
#include "node.h"
using namespace std;

int getHeight(Node* n) {
  if (n == nullptr) return 0;

  return max(getHeight(n->leftChild),
             getHeight(n->rightChild)) + 1;
}

bool is_balanced(Node* n) {
  if (n == nullptr) return true;

  int h1 = getHeight(n->leftChild);
  int h2 = getHeight(n->rightChild);

  /*
  cout << "node: " << n->data
       << ", left: " << h1
       << ", right: " << h2 << endl;
  */

  if (abs(h1 - h2) > 1) return false;
  return is_balanced(n->leftChild) && is_balanced(n->rightChild);
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
