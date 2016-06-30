#include <iostream>
#include <vector>
#include "stack.h"

const int SIZE_PER_STACK = 5;

class SetOfStacks {
  vector<Stack> stacks;
public:
  void push(int data) {
    if (stacks.empty() || stacks.back().size() == SIZE_PER_STACK) {
      Stack st;
      stacks.push_back(st);
    }
    stacks.back().push(data);
  }

  int pop() {
    if (stacks.empty()) throw runtime_error("No stack here.");
    int d = stacks.back().top();
    stacks.back().pop();
    if (stacks.back().empty()) stacks.pop_back();
    return d;
  }

  int size() {
    int s = 0;
    for (vector<Stack>::iterator it = stacks.begin(); it != stacks.end(); it++) {
      s += (*it).size();
    }
    return s;
  }

  void dumpStacks() {
    for (vector<Stack>::iterator it = stacks.begin(); it != stacks.end(); it++) {
      (*it).dump();
    }
    
  }
};

int main() {
  SetOfStacks sos;
  for (int i = 0; i < SIZE_PER_STACK * 3 + 3; i++) sos.push(i);

  cout << "------------------- sos size: " << sos.size() << endl;
  sos.dumpStacks();

  for (int i = 0; i < SIZE_PER_STACK; i++) {
    cout << endl << "--- pop: " << sos.pop() << endl;
    cout << "------------------- sos size: " << sos.size() << endl;
    sos.dumpStacks();
  }

  for (int i = 0; i < SIZE_PER_STACK; i++) {
    int d = i + 100;
    cout << endl << "--- push: " << d << endl;
    sos.push(d);
    cout << "------------------- sos size: " << sos.size() << endl;
    sos.dumpStacks();
  }
}
