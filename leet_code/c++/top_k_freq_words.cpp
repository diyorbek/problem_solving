#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> mp;

    for (string& word : words) {
      mp[word]++;
    }

    typedef pair<string, int> pr;
    vector<pr> sorted(mp.begin(), mp.end());

    sort(sorted.begin(), sorted.end(), [](pr& a, pr& b) {
      if (a.second == b.second)
        return a.first.compare(b.first) < 0;

      return a.second > b.second;
    });

    vector<string> result;
    int i = 0;

    while (i < k) {
      result.push_back(sorted[i].first);
      i++;
    }

    return result;
  }
};