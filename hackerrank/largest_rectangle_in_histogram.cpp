#include <stack>
#include <vector>

using namespace std;

long largestRectangle(vector<int> h) {
  long max_rect = INT_MIN;
  int len = h.size();
  stack<int> indicies;

  vector<int> left_limit(len);
  for (int i = 0; i < len; i++) {
    if (indicies.empty()) {
      left_limit[i] = 0;
      indicies.push(i);
    } else {
      while (!indicies.empty() && h[i] <= h[indicies.top()]) {
        indicies.pop();
      }

      if (indicies.empty()) {
        left_limit[i] = 0;
      } else {
        left_limit[i] = indicies.top() + 1;
      }

      indicies.push(i);
    }
  }

  while (!indicies.empty()) {
    indicies.pop();
  }

  vector<int> right_limit(len);
  for (int i = len - 1; i >= 0; i--) {
    if (indicies.empty()) {
      right_limit[i] = len - 1;
      indicies.push(i);
    } else {
      while (!indicies.empty() && h[i] <= h[indicies.top()]) {
        indicies.pop();
      }

      if (indicies.empty()) {
        right_limit[i] = len - 1;
      } else {
        right_limit[i] = indicies.top() - 1;
      }

      indicies.push(i);
    }
  }

  for (int i = 0; i < len; i++) {
    long area = h[i] * (right_limit[i] - left_limit[i] + 1);
    max_rect = max(max_rect, area);
  }

  return max_rect;
}