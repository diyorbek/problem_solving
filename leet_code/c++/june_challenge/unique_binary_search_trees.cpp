#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  unordered_map<int, int> dp;

  int numTrees(int n) {
    if (n < 2) {
      return 1;
    }

    auto from_cache = dp.find(n);
    if (from_cache != dp.end()) {
      return from_cache->second;
    }

    int count = 0;
    for (int i = 1; i <= n; i++) {
      count += numTrees(i - 1) * numTrees(n - i);
    }

    dp[n] = count;

    return count;
  }

  unsigned long factorial(int n) {
    unsigned long r = 1;

    for (int i = 1; i <= n; i++) {
      r *= i;
    }

    return r;
  }

  int numTrees2(int n) {
    if (n < 2) {
      return 1;
    }

    return factorial(2 * n) / factorial(n + 1) / factorial(n);
  }
};

int main(int argc, char const* argv[]) {
  cout << (long)(12341234123412423412 / 12342141242342134124);
  return 0;
}
