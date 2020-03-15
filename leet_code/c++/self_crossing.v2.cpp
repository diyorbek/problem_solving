// https://leetcode.com/problems/self-crossing/submissions/
// time: 0ms, memory: 7.9MB
#include <vector>
using namespace std;

class Solution {
 public:
  bool isSelfCrossing(vector<int>& x) {
    if (x.size() < 5)
      return x.size() >= 4 && x[3] >= x[1] && x[2] <= x[0];

    if ((x[3] < x[1] && x[4] >= x[2]) ||
        (x[3] == x[1] && x[0] + x[4] >= x[2])) {
      return true;
    }
    for (int i = 5; i < x.size(); i++) {
      if (x[i - 1] >= x[i - 3]) {
        continue;
      }
      if (x[i - 2] <= x[i - 4]) {
        if (x[i] < x[i - 2]) {
          continue;
        } else {
          return true;
        }
      }
      if (x[i - 1] + x[i - 5] >= x[i - 3] && x[i] + x[i - 4] >= x[i - 2]) {
        return true;
      }
    }

    return false;
  }
};