#include <queue>
#include <string>

using namespace std;

class Solution {
 public:
  vector<string> findRelativeRanks(vector<int>& score) {
    priority_queue<pair<int, int>> heap;

    for (int i = 0; i < score.size(); i++) {
      heap.push({score[i], i});
    }

    vector<string> answer(heap.size());

    int i = 1;
    while (!heap.empty()) {
      if (i == 1) {
        answer[heap.top().second] = "Gold Medal";
      } else if (i == 2) {
        answer[heap.top().second] = "Silver Medal";
      } else if (i == 3) {
        answer[heap.top().second] = "Bronze Medal";
      } else {
        answer[heap.top().second] = to_string(i);
      }
      i++;
      heap.pop();
    }

    return answer;
  }
};