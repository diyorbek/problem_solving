#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    int i = 1;
    vector<int> adds;
    while (n) {
      int b = n % 10;
      if (b) {
        adds.push_back(b * i);
      }
      i *= 10;
      n /= 10;
    }

    cout << adds.size() << endl;
    for (int a : adds) {
      cout << a << " ";
    }
    cout << endl;
  }

  return 0;
}