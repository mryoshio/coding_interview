#include <iostream>
#include "binary_op.h"

using namespace std;

int insert(int n, int m, int i, int j) {
  int left_more_j_of_n = (n & ~((1 << j) - 1));
  int right_more_i_of_n = (n & ~((1 << i + 1) - 1));
  return (left_more_j_of_n | right_more_i_of_n | (m << i));
}

int insert_answer(int n, int m, int i, int j) {
  int all_ones = ~0;
  
  int left = all_ones << (j + 1);

  int right = ((1 << i) - 1);

  int mask = left | right;

  int n_cleared = n & mask;
  int m_shifted = m << i;

  return n_cleared | m_shifted;
}

int main() {
  string str_n = "10000000000";
  string str_m = "10011";
  int n = strbin2i(str_n);
  int m = strbin2i(str_m);
  int i = 2;
  int j = 6;

  cout << "n: " << str_n << endl;
  cout << "m: " << str_m << endl;
  cout << "i: " << i << endl;
  cout << "j: " << j << endl;

  int ans = insert(n, m, i, j);
  cout << "answer1: " << i2strbin(ans) << endl;

  int ans2 = insert_answer(n, m, 2, 6);
  cout << "answer2: " << i2strbin(ans2) << endl;

  return 0;
}
