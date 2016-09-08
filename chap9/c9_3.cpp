#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> nums;

int advanced_magic_index(int b, int e) {
  if (b < 0 || nums.size() < e || e < b) return -1;

  int m = (b + e) / 2;
  if (m == nums[m]) return m;

  int l_idx = min(m - 1, nums[m]);
  int l = advanced_magic_index(b, l_idx);
  if (l >= 0) return l;

  int r_idx = max(m + 1, nums[m]);
  int r = advanced_magic_index(r_idx, e);
  return r;
}

int magic_index(int b, int e) {
  if (b < 0 || nums.size() < e) return -1;
  int m = (b + e) / 2;
  if (m == nums[m]) return m;
  if (m > nums[m]) return magic_index(m + 1, e);
  return magic_index(b, m);
}

int main() {
  int n; cin >> n;
  while (n--) {
    int x; cin >> x;
    nums.push_back(x);
  }
  cout << magic_index(0, nums.size()) << endl;
  cout << advanced_magic_index(0, nums.size()) << endl;
}
