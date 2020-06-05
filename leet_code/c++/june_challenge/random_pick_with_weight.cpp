#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  vector<int> ws;

 public:
  Solution(vector<int>& w) {
    for (int i = 0; i < w.size(); i++) {
      ws.push_back(w[i] + (i > 0 ? ws[i - 1] : 0));
    }
  }

  int pickIndex() {
    int r = rand() % ws[ws.size() - 1];
    auto found = upper_bound(ws.begin(), ws.end(), r);
    return distance(ws.begin(), found);
  }
};