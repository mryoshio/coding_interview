#include <cmath>
#include <iostream>
using namespace std;

class Point {
public:
  double x, y;
  Point(double x, double y): x(x), y(y) {}
  bool operator==(const Point other) {
    return x == other.x && y == other.y;
  }
};

class Line {
public:
  Point p1, p2;
  Line(Point p1, Point p2): p1(p1), p2(p2) {}
  friend ostream& operator<<(ostream& os, const Line& line);
};

ostream& operator<<(ostream& os, const Line& line) {
  os << "p1(" << line.p1.x << ", " << line.p1.y << ")";
  os << ", p2(" << line.p2.x << ", " << line.p2.y << ") ";
  return os;
}

class Square {
public:
  double left, right, top, bottom;

  Point middle() {
    return Point((left + right) / 2.0, (top + bottom) / 2.0);
  }

  Point extend(Point mid1, Point mid2, double size) {
    double x_dir = mid1.x < mid2.x ? -1 : 1;
    double y_dir = mid1.y < mid2.y ? -1 : 1;

    if (mid1.x == mid2.x)
      return Point(mid1.x, mid1.y + y_dir * size / 2.0);

    double slope = (mid1.y - mid2.y) / (mid1.x - mid2.x);
    double x1 = 0, y1 = 0;

    if (abs(slope) == 1) {
      x1 = mid1.x + x_dir * size / 2;
      y1 = mid1.y + y_dir * size / 2;
    } else if (abs(slope) < 1) {
      x1 = mid1.x + x_dir * size / 2;
      y1 = slope * (x1 - mid1.x) + mid1.y;
    } else {
      y1 = mid1.y + y_dir * size / 2.0;
      x1 = (y1 = mid1.y) / slope + mid1.x;
    }
    return Point(x1, y1);
  }

  Line cut(Square other) {
    Point mid_a = middle();
    Point mid_b = other.middle();

    if (mid_a == mid_b) {
      Square bigger = bottom - top > other.bottom - other.top ? *this : other;
      return Line(Point(bigger.left, bigger.top),
                  Point(bigger.right, bigger.bottom));
    }

    Point p_a = extend(mid_a, mid_b, right - left);
    Point p_b = extend(mid_b, mid_a, other.right - other.left);
    return Line(p_a, p_b);
  }
};

int main() {
  /*
    input per line: top, right, bottom, left
    e.g.
    -1 4 -4 1
    -3 8 -6 5
  */
  Square ss[2];
  for (int i = 0; i < 2; i++) {
    Square s;
    cin >> s.top;
    cin >> s.right;
    cin >> s.bottom;
    cin >> s.left;
    ss[i] = s;
  }
  cout << ss[0].cut(ss[1]) << endl;
}
