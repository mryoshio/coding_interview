#include <iomanip>
#include <iostream>
#include <ctime>
using namespace std;

const int M = 10;
const int N = 10;
bool R_ZERO[M];
bool C_ZERO[N];
int A[M][N];

void d() {
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (j) cout << ' ';
      cout << setw(3) << A[i][j];
    }
    cout << endl;
  }
}

void solve() {
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (A[i][j] == 0) R_ZERO[i] = C_ZERO[j] = true;
    }
  }

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (R_ZERO[i] == true || C_ZERO[j] == true) A[i][j] = 0;
    }
  }
}

int main() {
  srand((unsigned int)time(NULL));

  for (int i = 0; i < M; i++)
    for (int j = 0; j < N; j++)
      A[i][j] = rand() % 29;

  cout << "<<<<<<<<<< before" << endl;
  d();
  solve();
  cout << "<<<<<<<<<< after" << endl;
  d();

  return 0;
}
