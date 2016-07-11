#include <iostream>
#include "node.h"
using namespace std;

Node* search_node(Node* n, int v) {
  if (n == nullptr) return nullptr;

  // cout << n->data << endl;
  Node* r;

  r = search_node(n->leftChild, v);
  if (r != nullptr && r->data == v) return r;

  if (n->data == v) return n;

  r = search_node(n->rightChild, v);
  if (r != nullptr && r->data == v) return r;

  return nullptr;
}

Node* firstCommonParent(Node* n, int a, int b) {
  Node* a_node = search_node(n, a);
  Node* b_node = search_node(n, b);

  if (a_node == nullptr || b_node == nullptr) {
    cout << "--- Node Not Found "
         << "a: " << (a_node == nullptr ? "not found" : "found")
         << ", b: " << (b_node == nullptr ? "not found" : "found")
         << endl;
    return nullptr;
  }

  a_node = a_node->parent;

  while (a_node != nullptr) {
    for (Node* cur = b_node->parent; cur != nullptr; cur = cur->parent) {
      if (a_node->data == cur->data) return cur;
    }
    a_node = a_node->parent;
  }
  return nullptr;
}

int main() {
  srand((unsigned int)time(NULL)); 
  int d = 3;
  int maxVal = 50;

  Node* n = makeUnbalancedBT(new Node(13), maxVal, d);
  dumpTree(n, 0);

  int a = rand() % maxVal;
  int b = rand() % maxVal;

  cout << "--- target " << "a: " << a << ", b: " << b << endl;

  Node* r = firstCommonParent(n, a, b);
  
  if (r == nullptr) cout << "--- None is common.";
  else cout << "--- " << r->data << " is first common parent node.";
  cout << endl;
}
