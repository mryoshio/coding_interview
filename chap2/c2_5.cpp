#include <algorithm>
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>
#include "./node.h"
using namespace std;

int len(Node* n) {
  int c = 0;
  while (n != nullptr) {
    n = n->next;
    c++;
  }
  return c;
}

Node* pad(Node* n, int len) {
  Node* pad_n1 = new Node(0) ;
  Node* head = pad_n1;
  for (int i = 0; i < len-1; i++) {
    pad_n1->append_to_tail(0);
    pad_n1 = pad_n1->next;
  }
  pad_n1->next = n;
  return head;
}

vector<int> calc_carry(Node* n1, Node* n2, int idx) {
  Node* t1;
  Node* t2;
  vector<int> carry(len(n1) + 1, 0);

  for (int i = carry.size() - 1; i > 0; i--) {
    t1 = n1;
    t2 = n2;
    for (int j = i - 1; j > 0; j--) {
      t1 = t1->next;
      t2 = t2->next;
    }
    carry[i - 1] = (t1->data + t2->data + carry[i]) / 10;
  }
  return carry;
}

Node* add_list(Node* n1, Node* n2) {
  vector<int> carry = calc_carry(n1, n2, 0);
  Node* n = new Node(carry[0]);
  Node* h = n;

  for (int i = 1; i < carry.size(); i++) {
    n->next = new Node(carry[i] + (n1->data + n2->data) % 10);
    if (i == 1 && n->data == 0) h = n->next;
    n1 = n1->next;
    n2 = n2->next;
    n = n->next;
  }

  return h;
}

Node* add_forward(Node* n1, Node* n2) {
  int len1 = len(n1);
  int len2 = len(n2);

  if (len1 > len2) n2 = pad(n2, len1 - len2);
  else if (len1 < len2) n1 = pad(n1, len2 - len1);

  return add_list(n1, n2);
}

Node* add_backward(Node* n1, Node* n2) {
  Node* r1 = new Node(-1);
  Node* r2 = r1;
  int div = 0;

  while (n1 != nullptr || n2 != nullptr) {
    int a = (n1 == nullptr ? 0 : n1->data);
    int b = (n2 == nullptr ? 0 : n2->data);
    int sum = a + b + div;
    int mod = sum % 10;
    div = sum / 10;
    if (r1->data == -1) r1->data = mod;
    else {
      r1->append_to_tail(mod);
      r1 = r1->next;
    }
    if (n1 != nullptr) n1 = n1->next;
    if (n2 != nullptr) n2 = n2->next;
  }

  if (div) r1->append_to_tail(div);

  return r2;
}

int main() {
  Node *n1 = create_list(3, 10);
  this_thread::sleep_for(chrono::seconds(1));
  Node *n2 = create_list(5, 10);

  Node* a = add_backward(n1, n2);
  cout << "##### backword" << endl;
  dump_list(n1);
  dump_list(n2);
  cout << "ans: "; dump_list(a);

  a = add_forward(n1, n2);
  cout << "##### forward" << endl;
  dump_list(n1);
  dump_list(n2);
  cout << "ans: "; dump_list(a);
}
