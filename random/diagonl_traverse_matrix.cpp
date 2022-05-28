#include <iostream>
#include <vector>

using namespace std;

/*
Fill n by m matrix diagonally starting from top right corner.
Diagonal direction is from top left to bottom right (\).

Ex: n = 3, m = 4

 7  4  2  1
10  8  5  3
12 11  9  6

*/

int main() {
  int n = 3, m = 4;
  int c = 1;
  vector<vector<int>> arr(n, vector<int>(m));
  int l = n + m - 1;

  for (int k = 0; k < l; k++) {
    int i = k < m ? 0 : k - (m - 1);
    int j = k < m ? m - k - 1 : 0;

    while (j < m && i < n) {
      arr[i++][j++] = c++;
    }
  }

  for (auto r : arr) {
    for (int c : r)
      cout << c << " ";
    cout << endl;
  }

  return 0;
}
