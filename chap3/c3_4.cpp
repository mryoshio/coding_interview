#include <iostream>
#include <stack>

using namespace std;

stack<int> TOWERS[3] = { stack<int>() };

int step;

void dump() {
  cout << "------- dump" << endl;
  for (int i = 0; i < 3; i++) {
    stack<int> t = TOWERS[i];
    cout << "tower" << (i + 1) << ":";
    while (!t.empty()) {
      cout << ' ';  
      cout << t.top();
      t.pop();
    }
    cout << endl;
  }
}

void moveBottom(int src, int dst) {
  dump();
  int d = TOWERS[src].top();
  if (!TOWERS[dst].empty() && TOWERS[dst].top() <= d) {
    cout << "ERROR: cannot place " << d
         << " on " << "TOWERS[" << dst << "]" << endl;
  }
  TOWERS[dst].push(d);
  TOWERS[src].pop();
  step++;
}

void moveDisk(int n, int src, int dst, int buf) {
  if (n < 1) return;
  moveDisk(n - 1, src, buf, dst);
  moveBottom(src, dst);
  moveDisk(n - 1, buf, dst, src);
}

int main() {
  int n; cin >> n;
  for (int i = n; i > 0; i--) TOWERS[0].push(i);
  moveDisk(n, 0, 2, 1);
  dump();
  cout << "step: " << step << endl;  
}
