#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    if (amount < 1)
      return 0;

    vector<int> mem(amount);
    return topDown(coins, amount, mem);
  }

  int topDown(vector<int>& coins, int remaining, vector<int>& mem) {
    if (remaining < 0)
      return -1;

    if (remaining == 0)
      return 0;

    if (mem[remaining - 1] != 0)
      return mem[remaining - 1];

    int minCount = INT16_MAX;
    for (int coin : coins) {
      int res = topDown(coins, remaining - coin, mem);

      if (res >= 0 && res < minCount)
        minCount = 1 + res;
    }

    mem[remaining - 1] = (minCount == INT16_MAX) ? -1 : minCount;

    return mem[remaining - 1];
  }
};
