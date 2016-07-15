#include <iostream>
#include <queue>
#include "node.h"
using namespace std;

bool checkRecursively(Node* a, Node* b) {
  if (a == nullptr && b == nullptr) return true;
  if (a == nullptr && b != nullptr) return false;
  if (a != nullptr && b == nullptr) return false;

  return (a->data == b->data &&
          checkRecursively(a->leftChild, b->leftChild) &&
          checkRecursively(a->rightChild, b->rightChild));
}

bool isSubTree(Node* tree, Node* subTree) {
  queue<Node*> q;
  q.push(tree);

  while (!q.empty()) {
    Node* n = q.front(); q.pop();
    if (n->data == subTree->data && checkRecursively(n, subTree)) return true;
    if (n->leftChild != nullptr) q.push(n->leftChild);
    if (n->rightChild != nullptr) q.push(n->rightChild);
  }
  return false;
}

Node* makeWholeTree(int d, Node* subTree, bool includes) {
  srand((unsigned int)time(NULL)); 

  Node* root = makeBalancedBT(new Node(37), 50, d);
  Node* bottom = root;

  while (d--)
    bottom = rand() % 2 ? bottom->leftChild : bottom->rightChild;

  bottom->leftChild = subTree; // append subTree's root to bottom's left

  if (!includes) {
    bottom->leftChild = new Node(99);
    bottom->leftChild->leftChild = subTree->leftChild;
    bottom->leftChild->rightChild = subTree->rightChild;
  }

  return root;
}

int main() {
  int maxVal = 50;
  int d = 2;

  Node* subTree = makeBalancedBT(new Node(13), maxVal, d);
  Node* trueTree = makeWholeTree(d, subTree, true);
  Node* falseTree = makeWholeTree(d, subTree, false);

  cout << "--------------------- subtree" << endl;
  dumpTree(subTree, 0);

  cout << "--------------------- includes: true" << endl;
  dumpTree(trueTree, 0);
  cout << "---> subtree? " << isSubTree(trueTree, subTree) << endl;

  cout << "--------------------- includes: false" << endl;
  dumpTree(falseTree, 0);
  cout << "---> subtree? " << isSubTree(falseTree, subTree) << endl;


}
