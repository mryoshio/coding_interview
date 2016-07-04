#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
  stack<int> stacks[2]; // 0: for push, 1: for pop
public:
  void dump() {
    cout << "------- dump" << endl;
    for (int i = 0; i < 2; i++) {
      stack<int> t = stacks[i];
      cout << "stacks[" << i << "]";
      while (!t.empty()) {
        cout << ' ';
        cout << t.top();
        t.pop();
      }
      cout << endl;
    }
  }

  bool empty() {
    return stacks[0].size() + stacks[1].size() == 0;
  }

  int pop() {
    transfer(0, 1);
    int d = stacks[1].top();
    stacks[1].pop();
    return d;
  }

  void push(int d) {
    stacks[0].push(d);
  }

  void transfer(int src, int dst) {
    if (!stacks[dst].empty()) return;

    cout << "---> transfer occurred" << endl;
    while (!stacks[src].empty()) {
      stacks[dst].push(stacks[src].top());
      stacks[src].pop();
    }
  }
};

int main() {
  MyQueue q;
  for (int i = 0; i < 10; i += 2) q.push(i);
  q.dump();
  for (int i = 0; i < 3; i += 2) cout << "pop: " << q.pop() << endl;
  q.dump();
  for (int i = 21; i < 30; i += 2) q.push(i);
  q.dump();
  for (int i = 0; i < 3; i += 2) cout << "pop: " << q.pop() << endl;
  q.dump();
  q.push(-1);
  for (int i = 0; i < 3; i += 2) cout << "pop: " << q.pop() << endl;
  q.dump();
  q.push(-99);
  q.dump();
  while (!q.empty()) cout << "pop: " << q.pop() << endl;
}
