#include <iostream>
using namespace std;

void reverse(char* str) {
  char* s = str;
  char* p = str;
  while (*p != '\0')
    p++;
  p--;

  char tmp;
  while (str < p) {
    tmp = *p;
    *p-- = *str;
    *str++ = tmp;
  }
  cout << s << endl;
}

int main() {
  char s[] = "hello";
  reverse(s);
  return 0;
}
