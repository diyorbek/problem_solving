// https://leetcode.com/problems/3sum/
// time: 8ms, memory: 9.4MB
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include "utils.cpp"

using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> table;

    for (int i = 0; i < nums.size(); i++) {
      cout << endl;
    }

    return vector<vector<int>>(table.begin(), table.end());
  }
};

int main() {
  vector<int> a{-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6};
  Solution s;
  // auto b = s.threeSum(a);
  bitset<16> e(10);
  cout << e;
  // print2dVector(b);
  return 0;
}