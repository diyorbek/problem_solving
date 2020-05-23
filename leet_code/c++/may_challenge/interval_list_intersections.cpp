#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> intervalIntersection(vector<vector<int>>& A,
                                           vector<vector<int>>& B) {
    vector<vector<int>> res;
    vector<int> paired;
    int i = 0;
    int j = 0;

    while (i < A.size() && j < B.size()) {
      int start = max(A[i][0], B[j][0]);
      int end = min(A[i][1], B[j][1]);

      if (start <= end) {
        paired = {start, end};
        res.push_back(paired);
      }

      if (A[i][1] < B[j][1]) {
        i++;
      } else {
        j++;
      }
    }

    return res;
  }
};