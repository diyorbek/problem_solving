#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
  int l = 0;
  int r = nums.size() - 1;
  int m;

  while (r >= l) {
    m = l + (r - l) / 2;

    if (nums[m] > target) {
      r = m - 1;
    } else if (nums[m] < target) {
      l = m + 1;
    } else {
      return m;
    }
  }

  return l;
}

int main() {
  vector<int> a{1, 3, 5, 7, 9, 11};

  cout << searchInsert(a, 0);

  return 0;
}