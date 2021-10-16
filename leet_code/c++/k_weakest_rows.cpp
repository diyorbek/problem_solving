#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    typedef pair<int, int> pr;
    vector<pr> mp;

    for (int i = 0; i < mat.size(); i++) {
      int j = 0, soldiers = 0;

      while (j < mat[i].size() && mat[i][j] == 1) {
        soldiers++;
        j++;
      }

      mp.push_back({soldiers, i});
    }

    sort(mp.begin(), mp.end(), [](pr a, pr b) {
      if (a.first == b.first)
        return a.second < b.second;

      return a.first < b.first;
    });

    vector<int> answer;
    int i = 0;

    while (i < k) {
      answer.push_back(mp[i].second);
      i++;
    }

    return answer;
  }
};