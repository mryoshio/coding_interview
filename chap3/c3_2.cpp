#include <iostream>
#include "stack.h"

using namespace std;

const int MAX_N = 10;

class StackWithMin {
  Stack ST;
  Stack ST_MIN;
  Stack ST_MIN_WHEN;

public:
  void push(int data) {
    ST.push(data);
    if (ST_MIN.empty() || ST_MIN.top() > data) {
      ST_MIN.push(data);
      ST_MIN_WHEN.push(ST.size());
    }
  }

  int pop() {
    int d = ST.top();
    ST.pop();
    if (d <= ST_MIN.top() && ST_MIN_WHEN.top() == ST.size()+1) {
      ST_MIN.pop();
      ST_MIN_WHEN.pop();
    }
    return d;
  }

  int min() {
    return ST_MIN.top();
  }

  void dumpStack() {
    cout << "- dumpStack() " << endl;
    if (ST.empty()) {
      cout << "stack is empty." << endl;
      return;
    }
    ST.dump();
    ST_MIN.dump();
    // ST_MIN_WHEN.dump();
  }

  int size() {
    return ST.size();
  }

  bool empty() {
    return ST.empty();
  }
};


int main() {
  StackWithMin st;
  for (int i = MAX_N; i >= 0 ; i -= 2) st.push(i);
  for (int i = 1; i <= MAX_N; i++) st.push(i);
  st.push(0);

  while (!st.empty()) {
    cout << "------------------- stack size: " << st.size() << endl;
    cout << "min: " << st.min() << endl;
    st.dumpStack();
    cout << "pop: " << st.pop() << endl;
  }
  cout << "------------------- stack size: " << st.size() << endl;
  cout << "min: " << st.min() << endl;
  st.dumpStack();
}
