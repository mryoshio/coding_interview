#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Position {
public:
  int x, y;
  Position(int x, int y): x(x), y(y) {}
  bool operator <(const Position& o) const {
    return x < o.x || y < o.y;
  }

  bool operator ==(const Position& o) const {
    return (x == o.x) && (y == o.y);
  }
};

map<Position, bool> c;
vector<Position> paths;
vector<vector<int> > states;

bool is_free(int x, int y) {
  if (states[x][y] == 0) return true;
  return false;
}

int route(int x, int y) {
  Position p(x, y);
  if (c.count(p) > 0) return c[p];
  paths.push_back(p);
  if (x == 0 && y == 0) return true;
  bool ret = false;
  if (x > 0 && is_free(x - 1, y)) ret = route(x - 1, y);
  if (!ret && y > 0 && is_free(x, y - 1)) ret = route(x, y - 1);
  if (!ret) paths.pop_back();
  return c[p] = ret;
}

/*
  sample input:
  3 3
  0 0 -1
  -1 0 0
  0 -1 0
 */
int main() {
  int s, x, y; cin >> x >> y;
  states.resize(x, vector<int>(y));
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      int s; cin >> s;
      states[i][j] = s;
    }
  }
  route(x - 1, y - 1);
  cout << "step: " << paths.size() << endl;
  for (vector<Position>::iterator i = paths.begin(); i != paths.end(); i++)
    cout << (*i).x << ", " << (*i).y << endl;
}
