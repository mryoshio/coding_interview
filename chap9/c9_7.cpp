#include <iostream>
using namespace std;

const int MAX_N = 5;
int screen[MAX_N][MAX_N];
int xdir[] = {0, 1, 0, -1};
int ydir[] = {1, 0, -1, 0};

void debug() {
  cout << "------------------" << endl;
  for (int r = 0; r < MAX_N; r++) {
    for (int c = 0; c < MAX_N; c++) {
      if (c) cout << ' ';
      cout << screen[r][c];
    }
    cout << endl;
  }
}

void paint(int r, int c, int t_color, int n_color) {
  screen[r][c] = n_color;
  for (int i = 0; i < 4; i++) {
    int new_r = r + ydir[i];
    int new_c = c + xdir[i];
    if (0 <= new_r && new_r < MAX_N && 0 <= new_c && new_c < MAX_N) {
      if (screen[new_r][new_c] == t_color)
        paint(new_r, new_c, t_color, n_color);
    }
  }
}

int main() {
  for (int r = 0; r < MAX_N; r++) {
    for (int c = 0; c < MAX_N; c++) {
      int v; cin >> screen[r][c];
    }
  }
  debug();
  cout << "specify point (r c): ";
  int r, c; cin >> r >> c;
  paint(r, c, screen[r][c], 9);
  debug();
}
