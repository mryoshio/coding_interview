#include <iostream>
#include "./node.h"
using namespace std;

void delete_dup(Node* n) {
  Node *f = n->get_next();
  Node *s = n;

  while (f != nullptr) {
    while (s != f) {
      if (s->get_data() == f->get_data()) {
        cout << "[dup] " << f->get_data() << endl;
        Node *t = s;
        while (t->get_next() != f)
          t = t->get_next();
        t->set_next(f->get_next());
        break;
      }
      s = s->get_next();
    }
    f = f->get_next();
    s = n;
  }
}

int main() {
  Node* n = create_list();
  dump_list(n);
  delete_dup(n);
  dump_list(n);
  return 0;
}
