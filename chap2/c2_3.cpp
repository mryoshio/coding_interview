#include <iostream>
#include "./node.h"
using namespace std;

void delete_mid(Node* n) {
  int c = 1;

  for (Node* nn = n; nn->next != nullptr; nn = nn->next) c++;

  for (int i = 1; i < c/2; i++)
    if (n->next != nullptr) n = n->next;

  cout << "delete: " << n->next->data << endl;

  n->next = n->next->next;
}

int main() {
  Node *n = create_list(7, 100);
  dump_list(n);
  delete_mid(n);
  dump_list(n);
  return 0;
}
