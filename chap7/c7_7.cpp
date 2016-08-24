#include <iostream>
#include <queue>
using namespace std;

int findKth(int k) {
  queue<int> q3, q5, q7;

  q3.push(3);
  q5.push(5);
  q7.push(7);

  int kth;

  while (k--) {
    kth = min(q3.front(), min(q5.front(), q7.front()));

    if (kth == q3.front()) {
      q3.pop();
      q3.push(kth * 3);
      q5.push(kth * 5);
    } else if (kth == q5.front()) {
      q5.pop();
      q5.push(kth * 5);
    } else if (kth == q7.front()) {
      q7.pop();
    }
    q7.push(kth * 7);
  }

  return kth;
}


int main() {
  int k; cin >> k;
  cout << k << "th: " << findKth(k) << endl;
}
