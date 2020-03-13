#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;
    map<int, int> table;
    int i = nums.size();
    while (i--) {
      table[nums[i]] = i;
    }

    for (int i = 0; i < nums.size(); i++) {
      if (table.find(target - nums[i]) != table.end() &&
          i != table[target - nums[i]]) {
        result.push_back(table[target - nums[i]]);
        result.push_back(i);
        break;
      }
    }
    return result;
  }
};

int main() {
  int myints[] = {3, 3};
  vector<int> a(myints, myints + sizeof(myints) / sizeof(int));
  Solution s;

  vector<int> k = s.twoSum(a, 6);
  for (int d : k)
    cout << d << endl;
  return 0;
}