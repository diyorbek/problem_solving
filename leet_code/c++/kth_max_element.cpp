#include <queue>

using namespace std;

class KthLargest {
  priority_queue<int, vector<int>, greater<int>> mn;
  int k;

 public:
  KthLargest(int kth, vector<int>& nums) : mn(nums.begin(), nums.end()) {
    k = kth;

    while (mn.size() > k) {
      mn.pop();
    }
  }

  int add(int val) {
    mn.push(val);

    if (mn.size() > k) {
      mn.pop();
    }

    return mn.top();
  }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */