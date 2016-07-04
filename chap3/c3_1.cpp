#include <iostream>
using namespace std;

const int ARRAY_SIZE = 30;

class ArrayStack {
  int a[ARRAY_SIZE];
  int s0_s, s0_p, s1_s, s1_p, s2_s, s2_p;

public:
  ArrayStack() {
    s0_s = s0_p = ARRAY_SIZE * 0 / 3;
    s1_s = s1_p = ARRAY_SIZE * 1 / 3;
    s2_s = s2_p = ARRAY_SIZE * 2 / 3;
  }

  void push(int stackNum, int data) {
    switch(stackNum) {
    case 0:
      if (s0_p == s1_s) break;
      a[s0_p++] = data; return;
    case 1:
      if (s1_p == s2_s) break;
      a[s1_p++] = data; return;
    case 2:
      if (s2_p == ARRAY_SIZE) break;
      a[s2_p++] = data; return;
    }
    throw overflow_error("in push");
  }

  void pop(int stackNum) {
    switch(stackNum) {
    case 0:
      if (s0_p == s0_s) break;
      --s0_p; return;
    case 1:
      if (s1_p == s1_s) break;
      --s1_p; return;
    case 2:
      if (s2_p == s2_s) break;
      --s2_p; return;
    }
    throw underflow_error("in pop");
  }

  int top(int stackNum) {
    switch(stackNum) {
    case 0: return a[s0_p-1];
    case 1: return a[s1_p-1];
    case 2: return a[s2_p-1];
    }
    throw invalid_argument("in top");
  }

  bool empty(int stackNum) {
    switch(stackNum) {
    case 0: return s0_p == s0_s;
    case 1: return s1_p == s1_s;
    case 2: return s2_p == s2_s;
    }
    throw invalid_argument("in top");
  }
};

void dumpArrayStack(ArrayStack st, int s, int n) {
  cout << "-------------" << endl;
  for (int i = s; i < s + n; i++) {
    cout << "stack[" << i << "]";
    while (!st.empty(i)) {
      cout << ' ' << st.top(i);
      st.pop(i);
    }
    cout << endl;
  }
}

int main() {
  ArrayStack st;
  for (int i = 0; i < ARRAY_SIZE/3; i += 2) st.push(0, i);
  for (int i = 1; i < ARRAY_SIZE/3; i += 2) st.push(1, i);
  for (int i = 0; i < ARRAY_SIZE/3; i++) st.push(2, i);
  dumpArrayStack(st, 0, 3);

  for (int i = 1; i < ARRAY_SIZE/3; i += 2) st.push(0, i);
  for (int i = 0; i < ARRAY_SIZE/3; i += 2) st.push(1, i);
  dumpArrayStack(st, 0, 3);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      cout << "pop " << st.top(i) << " from stack[" << i << "]" << endl;
      st.pop(i);
    }
  }

  dumpArrayStack(st, 0, 3);

  cout << "## cause overflow in stack[1]" << endl;
  try {
    for (int i = 0; i < ARRAY_SIZE; i++) {
      st.push(1, i);
      dumpArrayStack(st, 1, 1);
    }
  } catch (exception &e) {
    cout << "exception caught: " << e.what() << endl;
  }

  dumpArrayStack(st, 0, 3);

  cout << "## cause underflow in stack[2]" << endl;
  try {
    for (int i = 0; i < ARRAY_SIZE; i++) {
      st.pop(2);
      dumpArrayStack(st, 2, 1);
    }
  } catch (exception &e) {
    cout << "exception caught: " << e.what() << endl;
  }

  dumpArrayStack(st, 0, 3);
}
