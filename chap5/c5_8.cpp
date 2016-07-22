#include <iostream>
#include "manipbit.h"
using namespace std;

typedef unsigned short byte;

void dump(byte s[1024], int w) {
  cout << "------- dump bytes";
  for (int i = 0; i < 1024; i++) {
    if (i % w) cout << ' ';
    else if (i % w == 0) cout << endl;
    //    cout << bits(s[i]);
    cout << (s[i]);
  }
  cout << endl;
}

void solve(byte screen[1024], int width, int x1, int x2, int y) {
  int s_offset = x1 % 8;
  int f_full_b = x1 / 8;
  if (s_offset != 0) f_full_b++;

  int e_offset = x2 % 8;
  int l_full_b = x2 / 8;
  if (e_offset != 7) l_full_b--;

  for (int b = f_full_b; b <= l_full_b; b++)
    screen[(width / 8) * y + b] = (byte) 0xFF;

  byte s_mask = (byte)(0xFF >> s_offset);
  byte e_mask = (byte)~(0xFF >> (e_offset + 1));

  cout << "width: " << width << endl
       << "x1: " << x1 << endl
       << "x2: " << x2 << endl
       << "y: " << y << endl
       << "s_offset: " << s_offset << endl
       << "first_full_byte: " << f_full_b << endl
       << "e_offset: " << e_offset << endl
       << "last_full_byte: " << l_full_b << endl
       << "s_mask: " << s_mask << endl
       << "e_mask: " << e_mask << endl;

  dump(screen, width);

  if ((x1 / 8) == (x2 / 8)) {
    byte mask = (byte) (s_mask & e_mask);
    screen[(width / 8) * y + (x1 / 8)] |= mask;
  } else {
    if (s_offset != 0) {
      int b_num =  (width / 8) * y + f_full_b - 1;
      screen[b_num] |= s_mask;
    }

    if (e_offset != 7) {
      int b_num =  (width / 8) * y + l_full_b + 1;
      screen[b_num] |= e_mask;
    }
  }

  dump(screen, width);
}

int main() {
  byte b[1024] = {0};
  int width = 8, x1 = 8, x2 = 128, y = 2;

  //solve(b, 16, 2, 129, 2);
  solve(b, width, x1, x2, y);
}
