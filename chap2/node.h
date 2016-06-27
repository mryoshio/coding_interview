#include <ctime>
#include <iostream>
#include <stack>
using namespace std;

class Node {
 public:
  Node* next;
  int data;

  Node() {};
  Node(int d) { data = d; next = nullptr; };
  ~Node() {}

  void append_to_tail(int d) {
    Node* new_n = new Node(d);
    Node* t = this;
    while (t->next != nullptr) t = t->next;
    t->next = new_n;
  }
};

void dump_list(Node* n) {
  Node* cur_n = n;
  while (cur_n != nullptr) {
    if (static_cast<void*>(cur_n) != static_cast<void*>(n)) cout << " -> ";
    cout << cur_n->data;
    cur_n = cur_n->next;
  }
  cout << endl;
}

Node* create_list(int size, int max_value) {
  srand((unsigned int)time(NULL));

  Node* n = new Node(rand() % max_value);

  for (Node* t = n; size-1; size--) {
    t->append_to_tail(rand() % max_value);
    t = t->next;
  }

  return n;
}

Node* create_palindrome_list(int size, int max_value) {
  if (size == 1) return create_list(1, max_value);

  Node *n = create_list(size / 2, max_value);
  Node *h = n;
  stack<int> ST;

  while (n->next != nullptr) {
    ST.push(n->data);
    n = n->next;
  }

  ST.push(n->data);
  if (size % 2) n->append_to_tail(rand() % max_value);

  while (!ST.empty()) {
    n->append_to_tail(ST.top());
    ST.pop();
  }

  return h;
}

Node* create_circular_list(int size, int max_value, int circle_size) {
  Node *n = create_list(size, max_value);
  Node *t = n;
  Node *h = n;

  for (int i = 0; i < size - 1; i++) {
    if (i < size - circle_size) t = t->next;
    n = n->next;
  }

  int begin_circle = t->data;
  n->next = t;
  n = h;

  for (int i = 0; i < size + circle_size + 1; i++) {
    if (i) cout << " -> ";
    if (n->data == begin_circle) cout << "[" << n->data << "]";
    else cout << n->data;
    n = n->next;
  }
  cout << " ..." << endl;

  return h;
}
