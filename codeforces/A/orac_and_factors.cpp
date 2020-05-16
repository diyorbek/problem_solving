#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    unsigned long n, k;
    cin >> n >> k;

    if (!(n % 2)) {
      cout << n + k * 2 << endl;
      continue;
    }

    int p = 0;
    for (int i = n; i >= 2; i--) {
      if (n % i == 0)
        p = i;
    }
    cout << n + p + 2 * (k - 1) << endl;
  }

  return 0;
}