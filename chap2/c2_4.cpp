#include <algorithm>
#include <iostream>
#include "./node.h"
using namespace std;

void arrange_than(Node* n, int x) {
  cout << "arrange than " << x << endl;

  for (Node* r; r->next != nullptr;) {
    while (n->data < x && n->next != nullptr) n = n->next;
    if (n->next == nullptr) return;

    for (r = n; r->next != nullptr; r = r->next)
      if (r->data < x) break;

    if (r->data < x) swap(n->data, r->data);
  }
}

int main() {
  Node *n = create_list(3, 100);
  dump_list(n);
  arrange_than(n, rand() % 50 * 2);
  dump_list(n);
  return 0;
}
