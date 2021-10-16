#include <algorithm>
#include <vector>
#include <list>

using namespace std;

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    vector<int> ans;
    list<pair<int, int>> bck;

    for (int i = 0; i < nums.size(); i++) {
      if (!bck.empty() && bck.front().second <= i - k) {
        bck.pop_front();
      }

      while (!bck.empty() && bck.back().first < nums[i]) {
        bck.pop_back();
      }

      bck.emplace_back(nums[i], i);

      if (i + 1 >= k) {
        ans.push_back(bck.front().first);
      }
    }

    return ans;
  }
};
