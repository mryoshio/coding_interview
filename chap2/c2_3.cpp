#include <iostream>
#include "./node.h"
using namespace std;

void delete_mid(Node* n, int t) {
  int cnt = 0;
  Node* nn = n->get_next();
  while (nn != nullptr && nn->get_data() != t) {
    nn = nn->get_next();
    n = n->get_next();
  }
  if (nn->get_data() == t)
    n->set_next(nn->get_next());
}

int main() {
  Node *n = create_list();
  Node *mid = n;
  for (int i = 0; i < 5; i++)
    mid = mid->get_next();
  dump_list(n);
  cout << "delete: " << mid->get_data() << endl;
  delete_mid(n, mid->get_data());
  dump_list(n);
  return 0;
}
