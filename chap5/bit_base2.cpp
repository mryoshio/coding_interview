#include <iostream>

#define df(f) cout << "# " << f << endl

using namespace std;

void get_bit(int num, int i) {
  df(__func__ << "(" << num << ", " << i << ")");
  cout << "Get " << i << "'th bit is : ";
  cout << ((num & (1 << i)) != 0) << endl;
}

void set_bit(int num, int i) {
  df(__func__ << "(" << num << ", " << i << ")");
  cout << "Set " << i << "'th bit => ";
  cout << (num | (1 << i)) << endl;
}

void clear_bit(int num, int i) {
  df(__func__ << "(" << num << ", " << i << ")");
  int mask = ~(1 << i);
  cout << "Clear " << i << "'th bit => ";
  cout << (num & mask) << endl;
}

int main() {
  get_bit(5, 1);
  set_bit(5, 1);
  clear_bit(5, 2);
  return 0;
}
