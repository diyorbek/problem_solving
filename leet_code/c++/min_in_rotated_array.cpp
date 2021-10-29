#include <vector>

class Solution {
 public:
  int findMin(std::vector<int>& nums) {
    if (nums.size() == 1 || nums[0] < nums[nums.size() - 1])
      return nums[0];

    int l = 0, r = nums.size() - 1;

    while (r - l != 1) {
      int mid = (r + l) / 2;

      if (nums[mid] > nums[l])
        l = mid;
      else
        r = mid;
    }

    return nums[r];
  }
};