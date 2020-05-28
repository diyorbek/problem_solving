#include <cmath>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> countBits(int num) {
    vector<int> res = {0};

    if (num == 0)
      return res;

    for (int i = 1; i <= num; i++) {
      int np2 = pow(2, floor(log2(i)));
      res.push_back(res[i - np2] + 1);
    }

    return res;
  }
};