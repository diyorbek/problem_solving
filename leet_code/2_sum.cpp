#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;
    map<int, int> table;

    for (int i = 0; i < nums.size(); i++) {
      map<int, int>::iterator diff = table.find(target - nums[i]);

      if (diff != table.end()) {
        result.push_back(diff->second);
        result.push_back(i);
        break;
      }

      table.insert(make_pair(nums[i], i));
    }

    return result;
  }
};