#include <iostream>
#include <queue>
#include <stack>
#include "node.h"
using namespace std;

void checkPath(Node* n, int t) {
  stack<int> s;

  while (n != nullptr && t > 0) {
    s.push(n->data);
    t -= n->data;
    n = n->parent;
  }

  if (t == 0) {
    cout << "path: " << s.top();
    s.pop();
    while (!s.empty()) {
      cout << " -> " << s.top();
      s.pop();
    }
    cout << endl;
  }
}

void solve(Node* n, int t) {
  queue<Node*> q;
  q.push(n);

  while (!q.empty()) {
    Node* start = q.front();

    if (start->leftChild != nullptr) q.push(start->leftChild);
    if (start->rightChild != nullptr) q.push(start->rightChild);

    checkPath(start, t);

    q.pop();
  }
}

int main() {
  srand((unsigned int)time(NULL)); 

  int maxVal = 20;
  int d = 3;
  int target = maxVal + rand() % maxVal;

  Node* tree = makeBalancedBT(new Node(rand() % maxVal), maxVal, d);

  dumpTree(tree, 0);
  cout << "--- target: " << target << endl;

  solve(tree, target);
}
