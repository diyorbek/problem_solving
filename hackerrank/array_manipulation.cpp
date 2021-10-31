#include <vector>

using namespace std;

long arrayManipulation(int n, vector<vector<int>> queries) {
  vector<long> arr(n);

  for (auto query : queries) {
    arr[query[0] - 1] += query[2];

    if (query[1] < n)
      arr[query[1]] -= query[2];
  }

  long maxCarry = 0;
  for (int i = 1; i < n; i++) {
    arr[i] += arr[i - 1];
    maxCarry = max(arr[i], maxCarry);
  }

  return maxCarry;
}