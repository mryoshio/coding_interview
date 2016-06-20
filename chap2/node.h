#include <iostream>
#include <ctime>
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
