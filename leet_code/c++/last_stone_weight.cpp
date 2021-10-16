#include <queue>

using namespace std;

class Solution {
 public:
  int lastStoneWeight(vector<int>& stones) {
    if (stones.size() <= 1)
      return stones[0];

    priority_queue<int> heap(stones.begin(), stones.end());

    while (heap.size() > 1) {
      int y = heap.top();
      heap.pop();

      int x = heap.top();
      heap.pop();

      if (y != x) {
        heap.push(y - x);
      }
    }

    return heap.empty() ? 0 : heap.top();
  }
};