#include <iostream>
#include "./node.h"

using namespace std;

void delete_dup(Node* n) {
  Node *f = n->next;
  Node *s = n;

  while (f != nullptr) {
    while (s != f) {
      if (s->data == f->data) {
        cout << "[dup] " << f->data << endl;
        Node *t = s;
        while (t->next != f) t = t->next;
        t->next = f->next;
        break;
      }
      s = s->next;
    }
    f = f->next;
    s = n;
  }
}

int main() {
  Node *n = create_list(10, 10);
  dump_list(n);
  delete_dup(n);
  dump_list(n);
  return 0;
}
