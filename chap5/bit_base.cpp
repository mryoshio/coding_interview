
#include <boost/utility/binary.hpp>
#include <iostream>

using namespace std;

#define B(x) BOOST_BINARY(x)

void row1() {
  cout << "# row1" << endl;
  cout << (B(0110) + B(0010)) << endl;
  cout << (B(0011) * B(0101)) << endl;

  cout << (B(0110) + B(0110)) << endl;
  cout << (B(0110) << 1) << endl;
}

void row2() {
  cout << "# row2" << endl;
  cout << (B(0011) + B(0010)) << endl;
  cout << (B(0011) * B(0011)) << endl;

  cout << (B(0100) * B(0011)) << endl;
  cout << (B(0011) << 2) << endl;
}

void row3() {
  cout << "# row3" << endl;
  cout << (B(0110) - B(0011)) << endl;
  cout << (B(1101) >> 2) << endl;

  cout << (B(1101) ^ ~B(1101)) << endl;
  cout << ~B(0) << endl;
}

void row4() {
  cout << "# row4" << endl;
  cout << (B(1000) - B(0110)) << endl;
  cout << (B(1101) ^ B(0101)) << endl;

  cout << (B(1011) & (~B(0) << 2)) << endl;
}

int main() {
  row1();
  row2();
  row3();
  row4();
  return 0;
}


