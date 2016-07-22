#include <iostream>
#include <sstream>
using namespace std;

string bits(double n) {
  string str("0.");
  stringstream ss;
  double r = n;

  for (int i = 0; i < 32; i++) {
    ss.str("");

    r *= 2;

    if (r >= 1) {
      ss << '1';
      r -= 1;
    } else {
      ss << '0';
    }

    str.append(ss.str());

    if (r <= 0) break;
  }

  return str;
}

int main() {
  double n; cin >> n;
  cout << bits(n) << endl;
}
