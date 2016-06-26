#include <iostream>
#include <stack>
#include <thread>
#include "./node.h"
using namespace std;

int length(Node* n) {
  int cnt = 0;
  while (n != nullptr) {
    n = n->next;
    cnt++;
  }
  return cnt;
}

class Result {
public:
  bool result;
  Node* node;
  Result(bool r, Node* n): result(r), node(n) {};
};

Result* is_palindrome_recursive(Node* n, int cnt){
  if (cnt == 1) return new Result(true, n->next);
  if (cnt == 2) return new Result(n->data == n->next->data, n->next->next);

  Result* r = is_palindrome_recursive(n->next, cnt - 2);
  return new Result(n->data == r->node->data, r->node->next);
}

bool is_palindrome_stack(Node* n){
  Node* a = n;
  Node* b = n;
  stack<int> ST;
 
  int len = length(n);

  if (len == 1) return true;
  if (len == 2) {
    if (n->data == n->next->data) return true;
    else return false;
  }

  while (b != nullptr && b->next != nullptr) {
    ST.push(a->data);
    a = a->next;
    b = b->next->next;
  }

  if (len % 2 == 1) a = a->next;

  while (!ST.empty() && a != nullptr) {
    if (ST.top() != a->data) return false;
    ST.pop();
    a = a->next;
  }

  return true;  
}

int main() {
  for (int i = 1; i <= 7; i++) {
    Node* n;
    int x = rand() % 100;
    if (x % 2) n = create_palindrome_list(i, 100);
    else n = create_list(i, 100);
    dump_list(n);
    cout << " stack ed. => " << is_palindrome_stack(n) << endl;
    Result* r = is_palindrome_recursive(n, i);
    cout << " recursive ed. =>" << r->result << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
  }
}
