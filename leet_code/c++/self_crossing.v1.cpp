// https://leetcode.com/problems/self-crossing/submissions/
// time: 56ms, memory: 36.9MB
#include <vector>

using namespace std;

bool isCrossing(vector<vector<int>> a, vector<vector<int>> b) {
  if (a[0][0] != a[1][0]) {
    swap(a[0], b[0]);
    swap(a[1], b[1]);
  }

  int maxX = max(b[0][0], b[1][0]);
  int minX = min(b[0][0], b[1][0]);
  int maxY = max(a[0][1], a[1][1]);
  int minY = min(a[0][1], a[1][1]);

  return minY <= b[0][1] && b[0][1] <= maxY && minX <= a[0][0] &&
         a[0][0] <= maxX;
};

vector<int> movePoint(vector<int>& point, int by, int direction) {
  if (direction == 0) {
    point[1] += by;
  } else if (direction == 1) {
    point[0] -= by;
  } else if (direction == 2) {
    point[1] -= by;
  } else if (direction == 3) {
    point[0] += by;
  }
  return point;
};

class Solution {
 public:
  bool isSelfCrossing(vector<int>& x) {
    if (x.size() < 4)
      return false;

    vector<int> currentPos{0, 0};
    vector<vector<vector<int>>> slopes;

    for (int i = 0; i < x.size(); i++) {
      vector<int> prevPos = currentPos;
      movePoint(currentPos, x[i], i % 4);
      slopes.insert(slopes.begin(), vector<vector<int>>{prevPos, currentPos});
      if (slopes.size() > 3 && isCrossing(slopes[0], slopes[3])) {
        return true;
      }
      if (slopes.size() > 5 and isCrossing(slopes[0], slopes[5])) {
        return true;
      }
      if (i == 4 && isCrossing(slopes[0], slopes[4])) {
        return true;
      }
    }

    return false;
  };
};
