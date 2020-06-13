#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    vector<int> best;

    // sort(nums.begin(), nums.end());

    for (int n1 : nums) {
      vector<int> current;

      for (int n2 : nums) {
        bool check = true;

        for (int c : current) {
          if (n2 % c > 0 && c % n2 > 0) {
            check = false;
            break;
          }
        }
        // cout << n1 << " " << n2 << " => ";
        // printVector(current);
        // cout << endl;
        if (check && (n2 % n1 == 0 || n1 % n2 == 0)) {
          current.push_back(n2);
        }
      }

      if (current.size() > best.size()) {
        best = current;
      }
    }

    return best;
  }
};
