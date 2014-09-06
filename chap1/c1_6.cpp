#include <iostream>
#include <fstream>
using namespace std;

const int kLength = 8;

char image[kLength][kLength];

void d() {
  for (int i = 0; i < kLength; i++) {
    for (int j = 0; j < kLength; j++)
      cout << image[i][j];
    cout << endl;
  }
}

void rotate() {
  for (int i = 0; i < kLength/2; i++) {
    int first = i;
    int last = kLength -1 -i;
    for (int j = first; j < last; j++) {
      int offset = j - first;
      int t = image[first][j];

      image[first][j] = image[j][last]; // top <- right
      image[j][last] = image[last][last-offset]; // right <- bottom
      image[last][last-offset] = image[last-offset][first]; // bottom <- left
      image[last-offset][first] = t; // left <- top
    }
  }
}

int main() {
  ifstream ifs("rotate.txt");
  string s;
  int r = 0;
  while(getline(ifs, s)) {
    for (int i = 0; i < s.size(); i++)
      image[r][i] = s[i];
    r++;
  }
  d();
  rotate();
  cout << "---------------------------" << endl;
  d();
}
