#include <iostream>
#include <ctime>
using namespace std;

const int list_size = 10;

class Node {
  Node* next;
  int data;

public:
  Node(int d) { data = d; next = nullptr; };
  ~Node() {}

  void append_to_tail(int d) {
    Node* end = new Node(d);
    Node* n = this;
    while (n->get_next() != nullptr)
      n = n->get_next();
    n->set_next(end);
  }
  int get_data() { return data; };
  Node* get_next() { return next; };
  void set_next(Node* next) { this->next = next; }
};

Node* create_list() {
  srand((unsigned int)time(NULL));

  Node* node = new Node(rand() % 100);

  for (int i = 0; i < list_size-1; i++)
    node->append_to_tail(rand() % 100);

  Node* t = node;
  cout << t->get_data();
  while (t->get_next() != nullptr) {
    t = t->get_next();
    cout << " -> " << t->get_data();
  }
  cout << endl;

  return node;
}
