#include <iostream>
#include <vector>

#include "../utils.cpp"

using namespace std;

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    printVector(nums);
    int l = 0;
    int r = nums.size() - 1;
    int m;

    while (l <= r) {
      m = l + (r - l) / 2;

      if (l == r) {
        break;
      }

      if (nums[m] != nums[m - 1] && nums[m] != nums[m + 1]) {
        break;
      }

      if ((r - l) % 2 == 0) {
        if (nums[m] == nums[m + 1] && nums[m] != nums[m - 1]) {
          l = m + 3;
        } else {
          r = m - 3;
        }
      } else {
        if (nums[m] == nums[m + 1] && nums[m] == nums[m - 1]) {
          l = m + 2;
        } else {
          r = m - 1;
        }
      }
    }

    return nums[m];
  }
};

int main() {
  Solution a;

  vector<int> b{2, 2, 3, 2};

  cout << a.singleNumber(b);

  return 0;
}