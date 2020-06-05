#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int twoCitySchedCost(vector<vector<int>>& costs) {
    sort(costs.begin(), costs.end(), [](vector<int> a, vector<int> b) {
      return b[0] - b[1] > (a[0] - a[1]);
    });

    int totalCost = 0;

    for (int i = 0; i < costs.size(); i++) {
      if (i < costs.size() / 2) {
        totalCost += costs[i][1];
      } else {
        totalCost += costs[i][0];
      }
    }

    return totalCost;
  }
};