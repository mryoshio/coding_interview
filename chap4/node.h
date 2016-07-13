#include <iostream>

class Node {
public:
  Node* parent;
  Node* leftChild;
  Node* rightChild;
  int data;
 Node(int d): data(d), parent(nullptr), leftChild(nullptr), rightChild(nullptr) {}
 Node(int d, Node* p_node): data(d), parent(p_node), leftChild(nullptr), rightChild(nullptr) {}
};

Node* makeBST(Node* parent, int maxVal, int depth) {
  if (depth == 0) return nullptr;
  depth--;

  parent->leftChild = new Node(parent->data - rand() % maxVal);
  parent->rightChild = new Node(parent->data + rand() % maxVal);

  makeBST(parent->leftChild, maxVal, depth);
  makeBST(parent->rightChild, maxVal, depth);

  return parent;
}

Node* makeBalancedBT(Node* parent, int maxVal, int depth) {
  if (depth == 0) return nullptr;
  depth--;

  parent->leftChild = new Node(rand() % maxVal, parent);
  parent->rightChild = new Node(rand() % maxVal, parent);

  makeBalancedBT(parent->leftChild, maxVal, depth);
  makeBalancedBT(parent->rightChild, maxVal, depth);

  return parent;
}

Node* makeUnbalancedBT(Node* parent, int maxVal, int depth) {
  if (depth == 0) {
    parent->rightChild = new Node(rand() % maxVal, parent);

    for (int i = 0; i < 2; i++) {
      parent->leftChild = new Node(rand() % maxVal, parent);
      parent = parent->leftChild;
    }

    return nullptr;
  }

  depth--;

  parent->leftChild = new Node(rand() % maxVal, parent);
  parent->rightChild = new Node(rand() % maxVal, parent);

  makeUnbalancedBT(parent->leftChild, maxVal, depth);
  makeUnbalancedBT(parent->rightChild, maxVal, depth);

  return parent;
}

void dumpTree(Node* n, int inc) {
  if (n == nullptr) return;
  inc++;
  dumpTree(n->leftChild, inc);
  for (int i = 0; i < inc * 2; i++) std::cout << ' ';
  std::cout << n->data << std::endl;
  dumpTree(n->rightChild, inc);
}
