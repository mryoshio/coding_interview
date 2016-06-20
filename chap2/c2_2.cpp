#include <iostream>
#include "./node.h"
using namespace std;

int backward_nth_recursive(Node* n, int k) {
  if (n == nullptr) return 0;

  int nth = backward_nth_recursive(n->next, k);

  if (nth == k)
    cout << "backward (rucursive): " << k+1 << " -> " << n->data << endl;

  return nth + 1;
}

void backward_nth_runner(Node* n, int k) {
  Node* runner = n;
  int cnt = k;

  while (cnt--) {
    runner = runner->next;
    if (runner == nullptr) {
      cout << "list is shorter than " << k << endl;
      return;
    }
  }

  while (runner->next != nullptr) {
    n = n->next;
    runner = runner->next;
  }

  cout << "backward (runner): " << k+1 << " -> " << n->data << endl;
}

int main() {
  int list_size = 10;
  Node *n = create_list(list_size, 100);
  dump_list(n);
  int k = rand() % list_size;
  backward_nth_runner(n, k);
  backward_nth_recursive(n, k);
  return 0;
}
