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
    int last = kLength -1 -i;

    for (int j = i; j < last; j++) {
      int offset = j - i;
      int t = image[i][j];

      image[i][j] = image[j][last]; // top <- right
      image[j][last] = image[last][last-offset]; // right <- bottom
      image[last][last-offset] = image[last-offset][i]; // bottom <- left
      image[last-offset][i] = t; // left <- top
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
