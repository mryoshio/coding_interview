#include <iostream>
#include "node.h"
using namespace std;

Node* questInOrder(Node* n, int t, bool hit) {
  if (n == nullptr) return nullptr;

  Node* r = nullptr;

  r = questInOrder(n->leftChild, t, hit);
  if (r != nullptr) return r;

  if (hit) return n;
  if (n->data == t) hit = true;

  r = questInOrder(n->rightChild, t, hit);
  return r;
}

int main() {
  srand((unsigned int)time(NULL)); 
  Node* n = makeBST(new Node(13), 30, 2);
  cout << "----------- tree" << endl;
  dumpTree(n, 0);
  //int target = rand() % 50;
  //int target = n->data;
  // int target = n->leftChild->data;
  int target = n->rightChild->data;
  Node* next = questInOrder(n, target, false);
  cout << "t(" << target << ")' s next node is ";
  if (next == nullptr) cout << "None";
  else cout << next->data;
  cout << endl;
}
