#include <cmath>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

const double EPS = 0.000001;

class Point {
public:
  double x, y;
  Point(double x, double y): x(x), y(y) {}
  friend ostream& operator<<(ostream& os, const Point& point);
};

ostream& operator<<(ostream& os, const Point& point) {
  os << "Point(x: " << point.x << ", y: " << point.y << ")";
  return os;
}

class Line {
public:
  bool inf;
  double epsillon, slope, intercept;

  Line() {}

  Line(double slope, double intercept, double inf) {
    slope = slope;
    intercept = intercept;
    inf = inf;
  }

  Line(Point p1, Point p2) {
    if (abs(p1.x - p2.x) > EPS) {
      slope = (p1.y - p2.y) / (p1.x - p2.x);
      intercept = p1.y - slope * p1.x;
      inf = false;
    } else {
      intercept = p1.x;
      inf = true;
    }
  }

  bool operator<(const Line o) const {
    if (o.slope == slope)
      if (abs(o.intercept - intercept) > EPS)
        return true;

    if (abs(o.slope - slope) > EPS)
      return true;

    return false;
  }

  friend ostream& operator<<(ostream& os, const Line& line);
};

ostream& operator<<(ostream& os, const Line& line) {
  os << "Line(slope: " << line.slope
     << ", intercept: " << line.intercept
     << ", inf: " << line.inf << ")";
  return os;
}

Line best_line(vector<Point> v) {
  map<Line, int> m;
  Line best;
  m[best] = 0;

  for (int i = 0; i < v.size(); i++) {
    for (int j = i + 1; j < v.size(); j++) {
      Line l(v[i], v[j]);

      if (m.count(l) > 0) m[l]++;
      else m[l] = 1;

      if (m[l] > m[best]) best = l;
    }
  }

  return best;
}

int main() {
  int n; cin >> n;
  vector<Point> v;
  while (n--) {
    double x, y;
    cin >> x >> y;
    v.push_back(Point(x, y));
  }
  cout << "best_line: " << best_line(v) << endl;
}
