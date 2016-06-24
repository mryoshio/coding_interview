#include <iostream>
#include "./node.h"
using namespace std;

int find_circle(Node* n) {
  Node* n1 = n->next;
  Node* n2 = n->next->next;

  while (n1 != n2) {
    n1 = n1->next;
    n2 = n2->next->next;
  }

  n1 = n;

  while (n1 != n2) {
    n1 = n1->next;
    n2 = n2->next;
  }

  return n1->data;
}

int main() {
  Node* n = create_circular_list(13, 100, 4);
  cout << find_circle(n) << endl;
}
