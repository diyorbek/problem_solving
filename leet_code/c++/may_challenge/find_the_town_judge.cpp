#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  int findJudge(int N, vector<vector<int>>& trust) {
    vector<int> trusts(N, 0);
    vector<int> trustedBy(N, 0);

    for (auto p : trust) {
      trusts[p[0] - 1]++;
      trustedBy[p[1] - 1]++;
    }

    for (int i = 0; i < N; i++) {
      if (trusts[i] == 0 && trustedBy[i] == N - 1)
        return i + 1;
    }

    return -1;
  }
};
