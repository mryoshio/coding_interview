#include <iostream>
#include <cmath>
using namespace std;

double E = 0.00001;

class Line {
public:
  double slope;
  double yintercept;
  Line(double s, double y): slope(s), yintercept(y) {}
  bool intersect(Line l2) {
    if (abs(slope - l2.slope) > E ||
        abs(yintercept - l2.yintercept) > E) return true;
    return false;
  }
};

int main() {
  Line l1(0.5, 2.0);
  Line l2(1.5, 2.0);
  cout << l1.intersect(l2) << endl;
}
