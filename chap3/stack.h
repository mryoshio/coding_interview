#include <iostream>
#include "node.h"

using namespace std;

class Stack {
 public:
  Node* n;
  int len;

  void push(int v) {
    len++;
    if (n == nullptr) {
      n = new Node(v);
      return;
    }
    Node* new_n = new Node(v);
    new_n->next = n;
    n = new_n;
  }

  void pop() {
    n = n->next;
    len--;
  }

  int top() {
    return n->data;
  }

  bool empty() {
    return len == 0;
  }

  int size() {
    return len;
  }

  void dump() {
    dump_list(n);
  }

  Stack() { n = nullptr; len = 0; }
  ~Stack() {}
};
