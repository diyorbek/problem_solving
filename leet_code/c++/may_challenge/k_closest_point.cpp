#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    multimap<int, vector<int>, less<int>> d_map;

    for (auto point : points) {
      d_map.insert({point[0] * point[0] + point[1] * point[1], point});
    };

    auto cmp = [](pair<int, vector<int>> const& a,
                  pair<int, vector<int>> const& b) {
      return a.first < b.first;
    };

    vector<vector<int>> res;

    for (auto it = d_map.begin(); res.size() < K; it++) {
      res.push_back(it->second);
    }

    return res;
  }
};