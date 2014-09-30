#include <iostream>
#include <ctime>
using namespace std;

const int n = 10;
const int cnt = 2;
int matrix[n][n];

void d() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << matrix[i][j] << " ";
    cout << endl;
  }
}

void solve() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      if (matrix[i][j] == 0) {
        for (int k = 0; k < n; k++) {
          matrix[i][k] = 0;
          matrix[k][j] = 0;
        }
        return;
      }
  }
}

int main() {
  srand((unsigned int)time(NULL));
  for (int i = 0; i < cnt; i++) {
    int r = rand() % n;
    int c = rand() % n;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        matrix[i][j] = (i == r && j == c) ? 0 : 1;
    cout << "<<<<<<<<<< before" << endl;
    d();
    solve();
    cout << "<<<<<<<<<< after" << endl;
    d();
  }
  return 0;
}
