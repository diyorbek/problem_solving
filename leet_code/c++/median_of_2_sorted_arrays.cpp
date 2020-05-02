#include <cmath>
#include <vector>

using namespace std;

class Solution {
 public:
  double calcMid(vector<int>& nums) {
    int isOdd = nums.size() % 2;

    if (isOdd) {
      return nums.at(nums.size() / 2);
    } else {
      int a = nums.size() / 2;
      return (nums.at(a) + nums.at(a - 1)) / 2.;
    }
  }

  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.empty()) {
      return calcMid(nums2);
    }

    int i = 0;

    while (!nums2.empty()) {
      if (nums1.at(i) < nums2.front()) {
        if (i + 1 >= nums1.size()) {
          nums1.push_back(nums2.front());
          nums2.erase(nums2.begin());
        }
        i++;
      } else {
        nums1.insert(nums1.begin() + i++, nums2.front());
        nums2.erase(nums2.begin());
      }
    }

    return calcMid(nums1);
  }
};