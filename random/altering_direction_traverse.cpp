#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

/*
Traverse n by m matrix:
  1. if row index is even, from left to right;
  2. if row index is odd, from right to left;

Ex: n = 3, m = 4

1  2  3  4
8  7  6  5
9 10 11 12

*/

int main() {
  int n = 3, m = 4;
  vector<vector<int>> arr(n, vector<int>(m));
  int c = 1;

  for (int i = 0; i < n; i++) {
    int dir = pow(-1, i % 2);
    int j = i % 2 ? m - 1 : 0;

    while (j >= 0 && j < m) {
      arr[i][j] = c++;
      j += dir;
    }
  }

  for (auto r : arr) {
    for (int c : r)
      cout << c << " ";
    cout << endl;
  }

  return 0;
}
