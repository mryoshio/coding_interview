#include <iostream>
#include "./node.h"
using namespace std;

void backward_nth(Node* n, int t) {
  int cnt = 0;
  Node* nn = n;
  while (nn != nullptr) {
    nn = nn->get_next();
    cnt++;
  }
  cnt -= t + 1;
  do {
    n = n->get_next();
  } while (cnt--);
  cout << "[backward " << t << "] " << n->get_data() << endl;
}

int main() {
  Node *n = create_list();
  dump_list(n);
  backward_nth(n, rand() % 10);
  return 0;
}
