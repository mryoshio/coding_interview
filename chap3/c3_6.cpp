#include <iostream>
#include "node.h"

using namespace std;

template <typename T>
class Stack {
  Node* n;
  int len;

public:
  Stack() {
    n = nullptr;
    len = 0;
  }

  void push(T v) {
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

  T peek() {
    return n->data;
  }

  bool isEmpty() {
    return len == 0;
  }
};

void dump_stack(Stack<int> st1) {
  cout << "--- dump stack:";
  for (Stack<int> t = st1; !t.isEmpty(); t.pop()) cout << " " << t.peek();
  cout << endl;
}

void sort_stack(Stack<int>* st1) {
  cout << "-------- sort stack" << endl;
  Stack<int> buf;

  buf.push(st1->peek());
  st1->pop();

  while (!st1->isEmpty()) {
    int v = st1->peek(); st1->pop();

    if (v >= buf.peek()) {
      buf.push(v);
      continue;
    }

    int c = 0;

    while (!buf.isEmpty() && v < buf.peek()) {
      st1->push(buf.peek());
      buf.pop();
      c++;
    }

    buf.push(v);

    while (c--) {
      buf.push(st1->peek());
      st1->pop();
    }
  }

  while (!buf.isEmpty()) {
    st1->push(buf.peek());
    buf.pop();
  }
}

int main() {
  Stack<int> st1;
  for (Node* n = create_list(5, 10); n != nullptr; n = n->next) {
    st1.push(n->data);
  }
  dump_stack(st1);
  sort_stack(&st1);
  dump_stack(st1);
}
