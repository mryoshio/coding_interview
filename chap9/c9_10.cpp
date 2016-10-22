#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef vector<int> box;
vector<box> boxes;
map<box, vector<box> > tower_map;

bool can_be_bottom(box cur_bottom, box candidate) {
  for (int i = 0; i < 3; i++)
    if (cur_bottom[i] >= candidate[i]) return false;
  return true;  
}

int height(vector<box> tower) {
  int h = 0;
  for (int i = 0; i < tower.size(); i++) {
    h += tower[i][1];
  }
  return h;
}

vector<box> build_tower(box bottom) {
  if (tower_map.count(bottom) > 0)
    return tower_map[bottom];

  int max_h = 0;
  vector<box> max_tower;

  for (int i = 0; i < boxes.size(); i++) {
    if (can_be_bottom(boxes[i], bottom)) {
      vector<box> new_tower = build_tower(boxes[i]);
      int new_h = height(new_tower);
      if (new_h > max_h) {
        max_h = new_h;
        max_tower = new_tower;
      }
    }
  }

  max_tower.push_back(bottom);
  tower_map[bottom] = max_tower;
  return max_tower;
}

vector<box> build_tower() {
  vector<box> max_tower;
  int max_h = 0;
  map<box, vector<box> > tower_map;

  for (int i = 0; i < boxes.size(); i++) {
    vector<box> new_tower = build_tower(boxes[i]);
    int new_h = height(new_tower);
    if (new_h > max_h) {
      max_h = new_h;
      max_tower = new_tower;
    }
  }
  return max_tower;
}


int main() {
  int n; cin >> n;
  boxes.resize(n, vector<int>(3, 0));

  for (int i = 0; i < n; i++)
    cin >> boxes[i][0] >> boxes[i][1] >> boxes[i][2];

  vector<box> ans = build_tower();
  cout << height(ans) << endl;
}
