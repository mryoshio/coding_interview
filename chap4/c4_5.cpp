#include <iostream>
#include "node.h"
using namespace std;

bool isBST(Node* n) {
  if (n == nullptr) return true;

  if (n->leftChild != nullptr) {
    if (n->data < n->leftChild->data) return false;
  }

  if (n->rightChild != nullptr) {
    if (n->data > n->rightChild->data) return false;
  }

  return isBST(n->leftChild) && isBST(n->rightChild);
}

int main() {
  srand((unsigned int)time(NULL)); 
  int d = 2;
  Node* n = makeBalancedBT(new Node(13), 50, d);
  cout << "----------- Tree" << endl;
  dumpTree(n, 0);
  cout << ">Binary Search Tree?: " << (isBST(n) ? "yes" : "no") << endl;

  n = makeUnbalancedBT(new Node(13), 50, d);
  cout << "----------- Tree" << endl;
  dumpTree(n, 0);
  cout << ">Binary Search Tree?: " << (isBST(n) ? "yes" : "no") << endl;

  n = makeBST(new Node(13), 50, d);
  cout << "----------- Tree" << endl;
  dumpTree(n, 0);
  cout << ">Binary Search Tree?: " << (isBST(n) ? "yes" : "no") << endl;
}
